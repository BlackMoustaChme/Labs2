import requests
from tokens import token_ya


geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Москва,+Петровка,+38&format=json"
response = requests.get(geocoder_request)
if response:
   # print(response.content)
   json_response = response.json()
   toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
   toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
   toponym_postal_code = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["postal_code"]
   print(toponym_address + " имеет почтовый индекс " + toponym_postal_code)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
