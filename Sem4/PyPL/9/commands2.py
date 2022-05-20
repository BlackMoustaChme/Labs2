# Импортируем необходимые классы.
from telegram.ext import Updater, MessageHandler, Filters
from Tokens import token
from telegram.ext import CommandHandler
import time
import datetime


# Определяем функцию-обработчик сообщений.
# У неё два параметра, сам бот и класс updater, принявший сообщение.


# Напишем соответствующие функции.
# Их сигнатура и поведение аналогичны обработчикам текстовых сообщений.
def tg_time(update, context):
   # t = time.localtime()
   update.message.reply_text(time.strftime("%H:%M"))


def tg_date(update, context):
   update.message.reply_text(time.strftime("%A %d of %B %Y"))


def main():
   # Создаём объект updater.
   # Вместо "TG_TOKEN" надо разместить полученный от @BotFather токен
   updater = Updater(token.TG_TOKEN, use_context=True)

   # Получаем из него диспетчер сообщений.
   dp = updater.dispatcher

   # Создаём обработчик сообщений типа Filters.text
   # из описанной выше функции echo()
   # После регистрации обработчика в диспетчере
   # эта функция будет вызываться при получении сообщения
   # с типом "текст", т. е. текстовых сообщений.
   #text_handler = MessageHandler(Filters.text, echo)
   # Регистрируем обработчик в диспетчере.


   # Зарегистрируем их в диспетчере рядом
   # с регистрацией обработчиков текстовых сообщений.
   # Первым параметром конструктора CommandHandler
   # является название команды.
   dp.add_handler(CommandHandler("time", tg_time))
   dp.add_handler(CommandHandler("date", tg_date))

   # dp.add_handler(text_handler)


   # Запускаем цикл приема и обработки сообщений.
   updater.start_polling()

   # Ждём завершения приложения.
   # (например, получения сигнала SIG_TERM при нажатии клавиш Ctrl+C)
   updater.idle()


# Запускаем функцию main() в случае запуска скрипта.
if __name__ == '__main__':
   main()

