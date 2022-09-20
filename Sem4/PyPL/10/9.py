import requests
from tokens import token_ya

print("Для ввода назвния города введите: 1")
print("Для выхода и получения ответа введите: 0")

while True:
    key = ''
    key = input(key)
    if key == "1":
        print("Введите название города: ")
        city_name = ''
        city_name = input(key)
        geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode={city_name}&format=json"
        response = requests.get(geocoder_request)
        toponym_coodrinates_z = 0
        if response:
           # print(response.content)
           json_response = response.json()
           toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
           toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
           toponym_coodrinates = toponym["Point"]["pos"]
           #print(toponym_address, "имеет координаты:", toponym_coodrinates)
        else:
           print("Error")
           print("Http статус:", response.status_code, "(", response.reason, ")")
    if key == '0':
        break