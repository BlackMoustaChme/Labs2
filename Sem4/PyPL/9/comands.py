from telegram.ext import Updater, MessageHandler, Filters
from Tokens import token
from telegram.ext import CommandHandler


def echo(update, context):
    update.message.reply_text(update.message.text)


def tg_start(update, context):
    update.message.reply_text(
        "Привет! Я Эхо-бот. Напишите мне что-нибудь и я пришлю это в ответ!"
    )


def tg_help(update, context):
    update.message.reply_text(
        "Извините ничем не могу помочь. Я всего лишь эхо"
    )


def main():
    updater = Updater(token.TG_TOKEN, use_context=True)
    dp = updater.dispatcher
    text_handler = MessageHandler(Filters.text, echo)
    dp.add_handler(CommandHandler("start", tg_start))
    dp.add_handler(CommandHandler("help", tg_help))

    dp.add_handler(text_handler)

    updater.start_polling()

    updater.idle()


if __name__ == '__main__':
    main()
