const { MongoClient, ObjectId } = require('mongodb');
const url_mongo = 'mongodb://127.0.0.1:27017/';
const mongoClient = new MongoClient(url_mongo);

module.exports = {
    async_getArticles: async_getArticles,
    async_getArticlesByAuthor: async_getArticlesByAuthor,
    async_getArticlesByTitle: async_getArticlesByTitle,
    async_getFullInfo: async_getFullInfo,
    async_delete: async_delete,
    async_getBestArticles: async_getBestArticles,
    async_getArticlesByDate: async_getArticlesByDate,
    async_addArticle: async_addArticle,
}

async function async_getArticles() {
    let result = null;
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.aggregate([
            {$project: {_id: 1, title: 1, author: 1, date_of_public: 1}}
        ]).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}

async function async_getArticlesByTitle(title) {
    let result = null;
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.aggregate([
            {$addFields: {result: {$regexMatch: {input: '$title', regex: title}}}},
            {$match: {result: true}},
            {$project: {_id:0, title: 1, author: 1, date_of_public: 1}}
        ]).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}

async function async_getArticlesByAuthor(author) {
    let result = null;
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.aggregate([
            {$addFields: {result: {$regexMatch: {input: '$author', regex: author}}}},
            {$match: {result: true}},
            {$project: {_id: 0,title: 1}}
        ]).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}

async function async_getFullInfo(object_id) {
    let result = [];
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.find(
            {_id: ObjectId(object_id)},
        ).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}

async function async_delete(object_id) {
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        await articles.deleteOne(
            {_id: ObjectId(object_id)}
        );
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
}

async function async_getBestArticles() {
    let result = [];
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.aggregate([
            {$addFields: {sumRatings: {$sum: "$comments.rating"}}},
            {$addFields: {countComments: {$size: "$comments"}}},
            {$match: {countComments: {$gt: 0}}},
            {$addFields: {rate: {$divide: ["$sumRatings", "$countComments"]}}},
            {$project: {_id: 0, rate: 1}}
        ]).toArray();
        let max = -1;
        result.forEach(obj => {
            if (obj["rate"] > max) {
                max = obj["rate"];
            }
        });
        result = await articles.aggregate([
            {$addFields: {sumRatings: {$sum: "$comments.rating"}}},
            {$addFields: {countComments: {$size: "$comments"}}},
            {$match: {countComments: {$gt: 0}}},
            {$addFields: {rate: {$divide: ["$sumRatings", "$countComments"]}}},
            {$match: {rate: {$eq: max}}},
            {$sort: {countReviews: -1}},
            {$project: {_id:0, title: 1, author: 1, date_of_public: 1, rate: {$round: ['$rate', 2]}, countComments: 1}}
        ]).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}

async function async_getArticlesByDate(start_date, end_date) {
    let result = [];
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.aggregate([
            {$match: {date_of_public: {$gte: new Date(start_date), $lte: new Date(end_date)}}},
            {$project: {_id:0, title: 1, author: 1, date_of_public: 1}}
        ]).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}

async function async_addArticle(article) {
    article.date_of_public = new Date(article.date_of_public);
    article["comments"] = [];
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        await articles.insertOne(article);
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
}
