import streamlit as st

st.title("City Navigation System 🏙️")
city = st.text_input("Enter a city name:")
if st.button("Show Info"):
    st.write(f"Searching routes for {city}...")
