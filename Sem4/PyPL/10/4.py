import requests
from tokens import token_ya


geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Барнаул&format=json"
response = requests.get(geocoder_request)
if response:
   #print(response.content)
   json_response = response.json()
   toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
   toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
   toponym_region = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
   print("Барнаул: " + toponym_region)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")


geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Мелеуз&format=json"
response = requests.get(geocoder_request)
if response:
   # print(response.content)
   json_response = response.json()
   toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
   toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
   toponym_region = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
   print("Мелеуз: " + toponym_region)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")

geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Йошкар-Ола&format=json"
response = requests.get(geocoder_request)
if response:
   # print(response.content)
   json_response = response.json()
   toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
   toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
   toponym_region = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
   print("Йошкар-Ола: " + toponym_region)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
