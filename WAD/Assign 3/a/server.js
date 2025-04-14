import express from 'express';
import { MongoClient } from 'mongodb';


const app = express();
const port = 3000;

app.use(express.static("public"));
app.use(express.urlencoded({ extended: true }));

const uri = "mongodb://root:h1yoVQDdUbz2D57M@ac-1vayapq-shard-00-00.yhftboa.mongodb.net:27017,ac-1vayapq-shard-00-01.yhftboa.mongodb.net:27017,ac-1vayapq-shard-00-02.yhftboa.mongodb.net:27017/?replicaSet=atlas-11jud3-shard-0&ssl=true&authSource=admin&retryWrites=true&w=majority&appName=test101"
const client = new MongoClient(uri);
const dbName = 'wad';
const collectionName = 'contact_us';

app.get("/" , (req , res)  => {
    res.send(__dirname + "/public/index.html");
});

app.post("/submit" , async (req , res) => {
    console.log(req.body);
    const name = req.body.name;
    const email = req.body.email;
    const message = req.body.message;

    await client.connect();
    const db = client.db(dbName);
    const collection = db.collection(collectionName);

    const result = await collection.insertOne({
        name : name ,
        email : email ,
        message : message
    });

    client.close();

    if (result != null) {
        console.log("Document inserted successfully");
        res.send("Successfull")
    }
    else{
        console.log("Failed to insert document");
        res.send("Failed")
    }
})

app.listen(port , () => {
    console.log(`Server is running on port ${port}`);
})