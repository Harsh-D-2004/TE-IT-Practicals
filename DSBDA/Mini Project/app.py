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

st.set_page_config(page_title="Sentiment Classifier", page_icon="🎯")

st.title("🎯 Amazon Food Review Sentiment Classifier")

user_input = st.text_area("Enter your product review below:")

if st.button("Predict Sentiment"):
    if user_input.strip() == "":
        st.warning("Please enter a review text.")
    else:
        clean_input = clean_text(user_input)
        vector = vectorizer.transform([clean_input])
        prediction = model.predict(vector)[0]
        if prediction == 0:
            st.error("This review is negative.")
        elif prediction == 1:
            st.warning("This review is neutral.")
        elif prediction == 2:
            st.success("This review is positive.")
        else:
            st.error("Something went wrong.")