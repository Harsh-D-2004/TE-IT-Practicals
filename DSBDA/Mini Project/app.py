import streamlit as st
import joblib
import re
import nltk
from nltk.corpus import stopwords

model = joblib.load('sentiment_model.pkl')
vectorizer = joblib.load('vectorizer.pkl')

nltk.download('stopwords')
nltk.download('wordnet')
stop_words = set(stopwords.words('english'))

def clean_text(text):
    text = text.lower()
    text = re.sub(r'[^\w\s]', '', text)
    text = re.sub(r'\d+', '', text)
    text = ' '.join([word for word in text.split() if word not in stop_words])
    text = re.sub(r'\s+', ' ', text).strip()
    return text

st.set_page_config(page_title="Amazon Food Reviews Sentiment Analysis", page_icon="🍽️", layout="centered")

st.markdown("<h1 style='text-align: center; color: #ff6600;'>🍽️ Amazon Food Review Sentiment Analysis</h1>", unsafe_allow_html=True)

st.markdown("### 📝 Enter your product review:")
user_input = st.text_area("", placeholder="Type your review here...")

with st.expander("🔍 See Sample Reviews"):
    st.markdown("*I absolutely loved this product! The flavor was rich and satisfying, and the texture was perfect.*")
    st.markdown("*The product was fine for the price, though nothing particularly outstanding. It served its purpose.*")
    st.markdown("*I was very disappointed. The taste was off, and it arrived stale. I expected better.*")

if st.button("🚀 Predict Sentiment"):
    if user_input.strip() == "":
        st.warning("Please enter a review text first.")
    else:
        clean_input = clean_text(user_input)
        vector = vectorizer.transform([clean_input])
        prediction = model.predict(vector)[0]

        st.markdown("---")
        if prediction == 0:
            st.error("**Negative Sentiment Detected**")
        elif prediction == 1:
            st.info("**Neutral Sentiment Detected**")
        elif prediction == 2:
            st.success("**Positive Sentiment Detected**")
        else:
            st.error("Unexpected error occurred.")

st.markdown("---")
st.markdown("<p style='text-align: center; font-size: 0.9em; color: gray;'>DSBDA Mini Project by Harsh Doshi , Yash Alai , Varad Chaskar , Sudesh Bansode</p>", unsafe_allow_html=True)
