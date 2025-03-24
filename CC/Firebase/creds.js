import { initializeApp } from "https://www.gstatic.com/firebasejs/11.5.0/firebase-app.js";
import { getAnalytics } from "https://www.gstatic.com/firebasejs/11.5.0/firebase-analytics.js";

const firebaseConfig = {
    apiKey: "AIzaSyCcs7a28VoyXE61It2kk68ev8Mvhi_jQ2M",
    authDomain: "argon-computer-454407-u4.firebaseapp.com",
    projectId: "argon-computer-454407-u4",
    storageBucket: "argon-computer-454407-u4.firebasestorage.app",
    messagingSenderId: "729076842626",
    appId: "1:729076842626:web:d8a87d2beefe53d7d3749b",
    measurementId: "G-3P6HMJDPQT"
};


const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);
console.log(analytics);
export default app;