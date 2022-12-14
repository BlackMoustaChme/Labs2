db.articles.insertMany([
        {
            title: "Происшествие в Заводском районе",
            author: "Курчатов Павел Владиславович",
            date_of_public: new Date("2021-10-06"),
            text: "A",
            tags: ["происшествие", "срочно", "новость"],
            comments: [{
                name:"UserAB",
                text_comment: "textAB",
                rating: 6,
            },
                {
                    name:"UserAC",
                    text_comment: "textAC",
                    rating: 5,
                }],
        },

        {
            title: "Научные исследования МГУ помогли калекам",
            author: "Образин Антон Степанович",
            date_of_public: new Date("2022-10-06"),
            text: "B",
            tags: ["МГУ", "наука", "больные"],
            comments: [{
                name:"UserBA",
                text_comment: "textBA",
                rating: 8,
            },
                {
                    name:"Иванов",
                    text_comment: "textBC",
                    rating: 7,
                }],
        },

        {
            title: "Массовые беспорядки во время городского мероприятия в Санкт-Петербурге",
            author: "Нефитов Григорий Александрович",
            date_of_public: new Date("2018-07-24"),
            text: "C",
            tags: ["петербург", "беспорядки", "погибшие"],
            comments: [{
                name:"Образин Антон Степанович",
                text_comment: "textCA",
                rating: 3,
            },
                {
                    name:"UserCB",
                    text_comment: "textCB",
                    rating: 9,
                }],
        },

        {
            title: "Видео последних событий в Санкт-Петербурге",
            author: "Нефитов Григорий Александрович",
            date_of_public: new Date("2018-07-24"),
            text: "4",
            tags: ["петербург", "беспорядки", "видео"],
            comments: [{
                name:"UserDA",
                text_comment: "textDA",
                rating: 2,
            },
                {
                    name:"UserDB",
                    text_comment: "textDB",
                    rating: 2,
                }],
        },

        {
            title: "Новости из зарубежья",
            author: "Кимурин Евгений Олегович",
            date_of_public: new Date("1989-07-06"),
            text: "F",
            tags: ["зарубежье"],
            comments: [{
                name:"UserFA",
                text_comment: "textFA",
                rating: 10,
            },
                {
                    name:"UserFB",
                    text_comment: "textFB",
                    rating: 10,
                }],
        }
    ]
)