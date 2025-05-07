import app from "./creds.js";
import { getFirestore, collection, addDoc, getDocs,deleteDoc, doc, updateDoc} 
from "https://www.gstatic.com/firebasejs/11.5.0/firebase-firestore.js"

const db = getFirestore(app);

const medName = document.getElementById("medicineName");
const medDose = document.getElementById("medicineDose");
const medPrice = document.getElementById("medicinePrice");
const addBtn = document.getElementById("addMedicineBtn");
const medicineList = document.getElementById("medicineList");

// Add Medicine Function
addBtn.addEventListener("click", async () => {
    const medicineName = medName.value.trim();
    const medicineDose = medDose.value.trim();
    const medicinePrice = medPrice.value.trim();
    if (medicineName === "") return;

    try{
      await addDoc(collection(db, "medicines"), { name: medicineName , dose: medicineDose , price: medicinePrice });
      loadMedicines();
    } catch (error) {
      console.log(error);
    }

    medName.value = "";
    medDose.value = "";
    medPrice.value = "";

    console.log("Medicine Added Successfully");
});

// Get ALL Medicine Function
async function loadMedicines() {
    medicineList.innerHTML = "";
    let querySnapshot;
    try{
      querySnapshot = await getDocs(collection(db, "medicines"));
    }catch(error){
      console.log(error);
    }

    querySnapshot.forEach(doc => {
        const medicine = doc.data();
        const listItem = document.createElement("li");
        listItem.innerHTML = `
            <span>Name : ${medicine.name}</span>
            <span>Dose : ${medicine.dose}</span>
            <span>Price : ${medicine.price}</span>
            <div>
                <button class="editBtn" data-id="${doc.id}">Edit</button>
                <button class="deleteBtn" data-id="${doc.id}">Delete</button>
            </div>
        `;

        medicineList.appendChild(listItem);
    });

    attachEventListeners();

    console.log("Medicine List Loaded Successfully");
}


function attachEventListeners() {

  // Update Medicine by id Function
    document.querySelectorAll(".editBtn").forEach(button => {
        button.addEventListener("click", async (e) => {
            const id = e.target.getAttribute("data-id");
            const newName = prompt("Enter new medicine name:");
            const newDose = prompt("Enter new medicine dose:");
            const newPrice = prompt("Enter new medicine price:");
            if (newName , newDose , newPrice) {
                try{
                  await updateDoc(doc(db, "medicines", id), { name: newName  , dose: newDose , price: newPrice });
                  loadMedicines();
                  console.log("Medicine Updated Successfully");
                }catch(error){
                  console.log(error);
                }
            }
        });
    });

    // Delete Medicine by id Function
    document.querySelectorAll(".deleteBtn").forEach(button => {
        button.addEventListener("click", async (e) => {
            const id = e.target.getAttribute("data-id");
            try{
              await deleteDoc(doc(db, "medicines", id));
              loadMedicines();
              console.log("Medicine Deleted Successfully");
            }catch(error){
              console.log(error);
            }
        });
    });
}

loadMedicines();
