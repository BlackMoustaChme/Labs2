const { MongoClient } = require('mongodb');
const url_mongo = 'mongodb://127.0.0.1:27017/';
const mongoClient = new MongoClient(url_mongo);

module.exports = {
    async_getArticles: async_getArticles,
    async_getArticlesByAuthor: async_getArticlesByAuthor,
    async_getArticlesByTitle: async_getArticlesByTitle,
}

async function async_getArticles() {
    let result = null;
    try {
        await mongoClient.connect();
        const fb = mongoClient.db('articledb');
        const articles = fb.collection('articles');
        result = await articles.aggregate([
            { $project: { title: 1, author: 1, date_of_public: 1 } }
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
            { $addFields: { result: { $regexMatch: { input: '$title', regex: title } } } },
            { $match: { result: true } },
            { $project: { title: 1, author: 1, date_of_public: 1 } }
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
            { $addFields: { result: { $regexMatch: { input: '$author', regex: author } } } },
            { $match: { result: true } },
            { $project: { title: 1 } }
        ]).toArray();
    } catch (err) {
        console.log(err);
    } finally {
        await mongoClient.close();
    }
    return result;
}