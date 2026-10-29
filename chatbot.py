import google.generativeai as genai
from google.generativeai import types

def generate():
    # ✅ Directly use your API key (safe for local testing only)
    api_key = "AIzaSyCjm8uz02emP-ZAz6CGbyhv1gAj9TM98vY"
    client = genai.Client(api_key=api_key)

    model = "gemini-1.5-pro-latest" 

    contents = [
        types.Content(
            role="user",
            parts=[types.Part.from_text(text="hi")],
        ),
        types.Content(
            role="model",
            parts=[types.Part.from_text(text="Hello! How can I help you today?")],
        ),
        types.Content(
            role="user",
            parts=[types.Part.from_text(text="Explain quantum computing in simple terms.")],
        ),
    ]

    tools = [
        types.Tool(googleSearch=types.GoogleSearch()),
    ]

    generate_content_config = types.GenerateContentConfig(
        temperature=1.0,
        thinking_config=types.ThinkingConfig(thinking_budget=32768),
        safety_settings=[
            types.SafetySetting(
                category="HARM_CATEGORY_DANGEROUS_CONTENT",
                threshold="BLOCK_ONLY_HIGH",
            ),
        ],
        tools=tools,
    )

    print(f"--- Generating response for model: {model} ---")
    for chunk in client.models.generate_content_stream(
        model=model,
        contents=contents,
        config=generate_content_config,
    ):
        print(chunk.text, end="")
    print("\n--- End of response ---")


if __name__ == "__main__":
    generate()
clear
