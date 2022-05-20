import requests
from tokens import token_ya


geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Москва,+Красная+площадь,+1&format=json"
response = requests.get(geocoder_request)
if response:
   # print(response.content)
   json_response = response.json()
   toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
   toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
   toponym_coodrinates = toponym["Point"]["pos"]
   print(toponym_address, "имеет координаты:", toponym_coodrinates)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
