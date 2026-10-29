import streamlit as st
import re
from datetime import datetime

# -------------------------
# Small curated Gita mapping
# -------------------------
VERSE_DB = {
    "effort": {
        "verse_ref": "Bhagavad Gita 2.47",
        "verse_text": "You have the right to work, but never to the fruits of work.",
        "paraphrase": "Focus on your effort, not on the result. Do your duty without being attached to outcomes.",
        "action": "Pick one small task you can complete in 15 minutes and do it — focus only on the task."
    },
    "anxiety": {
        "verse_ref": "Bhagavad Gita 6.25",
        "verse_text": "Calm the mind and senses — discipline leads to peace.",
        "paraphrase": "A calmer mind sees better. Small regular steps calm anxiety.",
        "action": "Try this: breathe in for 4, hold 4, breathe out 6 — repeat 6 times."
    },
    "anger": {
        "verse_ref": "Bhagavad Gita 2.63",
        "verse_text": "From anger comes delusion, from delusion confusion of memory.",
        "paraphrase": "Anger clouds judgment — pause, breathe, and return to clarity.",
        "action": "Step away for 60 seconds, take 3 long breaths, then reply or act."
    },
    "confused": {
        "verse_ref": "Bhagavad Gita 18.66",
        "verse_text": "Abandon all varieties of dharma and just surrender to me alone.",
        "paraphrase": "When overwhelmed by choices, go with what aligns with your duty and honesty.",
        "action": "Write pros/cons for 2 options, then pick the one that keeps your values intact."
    },
    "lonely": {
        "verse_ref": "Bhagavad Gita 6.5",
        "verse_text": "Let a man lift himself by his own self; let him not lower himself.",
        "paraphrase": "You can be your own helper — small self-kindnesses matter.",
        "action": "Write one loving sentence to yourself as if you're comforting a friend."
    },
    "default": {
        "verse_ref": "Bhagavad Gita 2.50",
        "verse_text": "One who performs his duty with wisdom attains tranquility.",
        "paraphrase": "Balance thought and action. Calm effort is powerful.",
        "action": "Tell me more. Or try a 2-minute breathing reset: inhale 4, exhale 6."
    }
}

# -------------------------
# Crisis patterns & helplines
# -------------------------
CRISIS_PATTERNS = [
    r"\bkill myself\b", r"\bi want to die\b", r"\bim going to end\b", r"\bcommit suicide\b",
    r"\bi will end my life\b", r"\bsuicid(e|al)\b", r"\bhurt myself\b"
]

HEPLINES = {
    "India": {"number": "9152987821/9152987822 (Aasra/24x7 helpline)"},
    "USA": {"number": "988 (Suicide & Crisis Lifeline)"},
    "UK": {"number": "Samaritans: 116 123"},
    "GlobalAdvice": "If you are in immediate danger, call your local emergency number."
}
# -------------------------
# Utility functions
# -------------------------
def detect_intent(text):
    t = text.lower()
    # Basic keyword mapping - simple but effective for prototype
    if any(w in t for w in ["sad", "depressed", "hopeless", "useless", "worthless", "down"]):
        return "effort"
    if any(w in t for w in ["anxious", "anxiety", "worried", "panic", "nervous", "stress"]):
        return "anxiety"
    if any(w in t for w in ["angry", "mad", "hate", "furious", "frustrat"]):
        return "anger"
    if any(w in t for w in ["confused", "decision", "choose", "what to do", "doubt"]):
        return "confused"
    if any(w in t for w in ["alone", "lonely", "friendless", "isolated"]):
        return "lonely"
    return "default"
def check_crisis(text):
    t = text.lower()
    for pattern in CRISIS_PATTERNS:
        if re.search(pattern, t):
            return True
    return False
def build_reply(user_text, intent):
    mapped = VERSE_DB.get(intent, VERSE_DB["default"])
    # empathetic opener
    openers = [
        "I hear you — thank you for sharing that with me.",
        "That sounds really heavy. I'm listening.",
        "I’m sorry you’re going through this. Let’s take it one step at a time."
    ]
    opener = openers[hash(user_text) % len(openers)]
    reply = {
        "opener": opener,
        "verse_ref": mapped["verse_ref"],
        "verse_text": mapped["verse_text"],
        "paraphrase": mapped["paraphrase"],
        "action": mapped["action"]
    }
    return reply

# -------------------------
# Streamlit UI
# -------------------------
st.set_page_config(page_title="SAARATHI — Your Inner Guide", page_icon="🛡️", layout="centered")

st.title("SAARATHI — Your Inner Guide")
st.caption("Ancient wisdom. Modern support. (Prototype — not a replacement for professional help)")

# Sidebar: brief info & helpline quick access
with st.sidebar:
    st.header("About")
    st.write("SAARATHI uses short, respectful ideas from the Bhagavad Gita to offer calm, practical steps for everyday struggles.")
    st.markdown("**Safety note:** This is not therapy. If you are in crisis, call emergency services.")
    st.divider()
    st.subheader("Quick Helplines")
    st.write("India:", HEPLINES["India"]["number"])
    st.write("USA:", HEPLINES["USA"]["number"])
    st.write("UK:", HEPLINES["UK"]["number"])
    st.write(HEPLINES["GlobalAdvice"])

# Conversation history (session)
if "history" not in st.session_state:
    st.session_state.history = []

# Input area
st.write("### Talk to Saarathi")
user_input = st.text_area("Share how you feel or describe your problem:", height=120)

col1, col2 = st.columns([1,1])
with col1:
    send_btn = st.button("Send")
with col2:
    breathe_btn = st.button("2-min Breathing")

# handle breathing button
if breathe_btn and user_input.strip() == "":
    st.info("Try this quick breathing: inhale 4 seconds → hold 4 → exhale 6. Repeat 6 times.")
elif breathe_btn:
    st.info("You can do the breathing now. Inhale 4, hold 4, exhale 6. Repeat 6 times.")

# handle send
if send_btn and user_input.strip() != "":
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    # crisis check first
    if check_crisis(user_input):
        crisis_msg = (
            "I’m really sorry you’re feeling so distressed. "
            "If you are in immediate danger or might hurt yourself, please call your local emergency number now (for example, 112 in India). "
            "You can also call the suicide/crisis helpline shown in the sidebar. "
            "Would you like me to show breathing steps or local helplines?"
        )
        # save to history
        st.session_state.history.append({"who":"user","text":user_input,"time":now})
        st.session_state.history.append({"who":"saarathi","text":crisis_msg,"time":now})
        st.error("⚠️ Crisis detected — follow the instructions above. If you are in danger, call emergency services now.")
    else:
        intent = detect_intent(user_input)
        reply = build_reply(user_input, intent)
        # save both messages
        st.session_state.history.append({"who":"user","text":user_input,"time":now})
        st.session_state.history.append({"who":"saarathi","text":reply,"time":now})

# display conversation
st.write("### Conversation")
for item in st.session_state.history[::-1]:
    if item["who"] == "user":
        st.markdown(f"**You — {item['time']}**")
        st.write(item["text"])
        st.markdown("---")
    else:  # saarathi
        if isinstance(item["text"], dict):
            r = item["text"]
            st.markdown(f"**Saarathi — {item['time']}**")
            st.write(r["opener"])
            st.markdown(f"**Verse:** *{r['verse_ref']}*")
            st.write(f"_{r['verse_text']}_")
            st.write(f"**Simple meaning:** {r['paraphrase']}")
            st.write(f"**Practical step:** {r['action']}")
            st.info("This is supportive guidance. For medical or severe mental health problems, please seek a professional.")
            st.markdown("---")
        else:
            st.markdown(f"**Saarathi — {item['time']}**")
            st.write(item["text"])
            st.markdown("---")

# small footer controls
st.write("")
if st.button("Clear conversation"):
    st.session_state.history = []
    st.success("Conversation cleared.")

