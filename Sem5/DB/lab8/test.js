const MongoClient = require("mongodb").MongoClient;

const url = "mongodb://localhost:27017/";
const mongoClient = new MongoClient(url, { useUnifiedTopology: true });

mongoClient.connect(function(err, client){

    const db = client.db("articledb");
    const collection = db.collection("articles");
    let user = {
        title: "Открытие нового стадиона",
        author: "Пелевин Антон Дмитриевич",
        date_of_public: new Date("2022-08-11"),
        text: "Открытие",
        tags: ["череповец", "стадион", "новость"],
        comments: [{
            name:"User1",
            text_comment: "text1",
            rating: 8,
        },
            {
                name:"User2",
                text_comment: "text2",
                rating: 10,
            }],
    };
    collection.insertOne(user, function( result){
        client.close();
    });
});