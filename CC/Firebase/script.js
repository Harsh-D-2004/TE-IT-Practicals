import app from "./creds.js";
import { getFirestore, collection, addDoc, getDocs, onSnapshot, deleteDoc, doc, updateDoc,setDoc } 
from "https://www.gstatic.com/firebasejs/11.5.0/firebase-firestore.js"

const db = getFirestore(app);

const itemInput = document.getElementById("item");
const addBtn = document.getElementById("addBtn");
const itemList = document.getElementById("itemList");

let editStatus = false;
let id = "";

console.log("db", db);

// Firestore function to save an item
async function addCity() {
  try {
    await addDoc(collection(db, "items"), { item: "Los Angeles" });
    console.log("Document successfully written!");
  } catch (error) {
    console.error("Error writing document: ", error);
  }
}

addCity();
