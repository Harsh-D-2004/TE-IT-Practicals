import express from 'express';
import { MongoClient } from 'mongodb';
import dotenv from 'dotenv';
import { User } from './models/user.js';
import cors from 'cors';

dotenv.config();



const app = express();
const port = 3000;

app.use(cors(
    {
        origin: 'http://localhost:4200',
        methods: ['GET', 'POST' , 'PUT', 'DELETE'],
        credentials: true,
        allowedHeaders: ['Content-Type', 'Authorization'],
    }
));

const uri = "mongodb://root:h1yoVQDdUbz2D57M@ac-1vayapq-shard-00-00.yhftboa.mongodb.net:27017,ac-1vayapq-shard-00-01.yhftboa.mongodb.net:27017,ac-1vayapq-shard-00-02.yhftboa.mongodb.net:27017/?replicaSet=atlas-11jud3-shard-0&ssl=true&authSource=admin&retryWrites=true&w=majority&appName=test101"
const client = new MongoClient(uri);
const dbName = 'wad';
const collectionName = 'profiles';

app.use(express.json());

app.post("/register" , async(req , res) =>{
    const { name , email , password } = req.body;

    const user = new User({ name , email , password });

    await client.connect();
    const db = client.db(dbName);
    const collection = db.collection(collectionName);

    const result = await collection.insertOne(user);

    client.close();

    if (result != null) {
        res.status(200).json({user });
    }
    else{
        res.status(401).json({ message: "Error registering user" });
    }
});

app.post("/login" , async (req , res) =>{
    const { email , password } = req.body;

    await client.connect();
    const db = client.db(dbName);
    const collection = db.collection(collectionName);

    const user = await collection.findOne({ email , password });

    client.close();

    if (user) {
        res.status(200).json({ user });
    }
    else{
        res.status(401).json({ message: "Invalid credentials" });
    }
});

app.put("/update" , async (req , res) =>{
    const { name , email , password } = req.body;

    await client.connect();
    const db = client.db(dbName);
    const collection = db.collection(collectionName);

    const user = await collection.findOne({ email });

    user.name = req.body.name;
    user.email = req.body.email;    
    user.password = req.body.password;

    
    if (user) {
        const result = await collection.updateOne({ email }, {$set : user});
        res.status(200).json({ result });
        client.close();
    }
    else{
        res.status(401).json({ message: "Invalid credentials" });
    }
})

app.delete("/delete" , async (req , res) =>{
    const { email } = req.body;

    await client.connect();
    const db = client.db(dbName);
    const collection = db.collection(collectionName);

    const user = await collection.findOne({ email });

    if (user) {
        const result = await collection.deleteOne({ email });
        res.status(200).json({ result });
        client.close();
    }
    else{
        res.status(401).json({ message: "Invalid credentials" });
    }
})

app.listen(port , () => {
    console.log(`Server is running on port ${port}`);
})