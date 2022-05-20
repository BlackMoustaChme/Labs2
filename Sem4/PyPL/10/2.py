import requests
from tokens import token_ya

#A

geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Якутск&format=json"
response = requests.get(geocoder_request)
if response:
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
# "boundedBy":{"Envelope":{"lowerCorner":"129.737963 62.031309","upperCorner":"129.803846 62.062238"}},"Point":{"pos":"129.770904 62.046777"}}}]}}}
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Магадан&format=json"
response = requests.get(geocoder_request)
if response:
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
# "boundedBy":{"Envelope":{"lowerCorner":"177.86975 64.773027","upperCorner":"177.901658 64.782065"}},"Point":{"pos":"177.886117 64.778953"}}}]}}}

#B
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Кемерово&format=json"
response = requests.get(geocoder_request)
if response:
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#"boundedBy":{"Envelope":{"lowerCorner":"86.08629 55.263352","upperCorner":"86.152173 55.300957"}},"Point":{"pos":"86.119232 55.282159"}}}]}}}
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Торонто&format=json"
response = requests.get(geocoder_request)
if response:
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#"Envelope":{"lowerCorner":"-96.708087 44.525678","upperCorner":"-96.576286 44.619889"}},"Point":{"pos":"-96.642187 44.572803"}}}]}}}

#C

geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Хабаровск&format=json"
response = requests.get(geocoder_request)
if response:
   text_file = "C1.txt"
   with open(text_file, "wb") as file:
      file.write(response.content)
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#C1.txt
#"AdministrativeArea":{"AdministrativeAreaName":"\xd0\xa5\xd0\xb0\xd0\xb1\xd0\xb0\xd1\x80\xd0\xbe\xd0\xb2\xd1\x81\xd0\xba\xd0\xb8\xd0\xb9 \xd0\xba\xd1\x80\xd0\xb0\xd0\xb9","SubAdministrativeArea":{"SubAdministrativeAreaName":"\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4\xd1\x81\xd0\xba\xd0\xbe\xd0\xb9 \xd0\xbe\xd0\xba\xd1\x80\xd1\x83\xd0\xb3 \xd0\xa5\xd0\xb0\xd0\xb1\xd0\xb0\xd1\x80\xd0\xbe\xd0\xb2\xd1\x81\xd0\xba","Locality":{"LocalityName":"\xd0\xa5\xd0\xb0\xd0\xb1\xd0\xb0\xd1\x80\xd0\xbe\xd0\xb2\xd1\x81\xd0\xba"}}}}}}}
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Уфа&format=json"
response = requests.get(geocoder_request)
if response:
   text_file = "C2.txt"
   with open(text_file, "wb") as file:
      file.write(response.content)
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#C2.txt
#"AdministrativeArea":{"AdministrativeAreaName":"\xd0\xa0\xd0\xb5\xd1\x81\xd0\xbf\xd1\x83\xd0\xb1\xd0\xbb\xd0\xb8\xd0\xba\xd0\xb0 \xd0\x91\xd0\xb0\xd1\x88\xd0\xba\xd0\xbe\xd1\x80\xd1\x82\xd0\xbe\xd1\x81\xd1\x82\xd0\xb0\xd0\xbd","SubAdministrativeArea":{"SubAdministrativeAreaName":"\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4\xd1\x81\xd0\xba\xd0\xbe\xd0\xb9 \xd0\xbe\xd0\xba\xd1\x80\xd1\x83\xd0\xb3 \xd0\xa3\xd1\x84\xd0\xb0","Locality":{"LocalityName":"\xd0\xa3\xd1\x84\xd0\xb0"}}}}}}}
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Нижний+Новгород&format=json"
response = requests.get(geocoder_request)
if response:
   text_file = "C3.txt"
   with open(text_file, "wb") as file:
      file.write(response.content)
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#C3.txt
#"AdministrativeArea":{"AdministrativeAreaName":"\xd0\x9d\xd0\xb8\xd0\xb6\xd0\xb5\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4\xd1\x81\xd0\xba\xd0\xb0\xd1\x8f \xd0\xbe\xd0\xb1\xd0\xbb\xd0\xb0\xd1\x81\xd1\x82\xd1\x8c","SubAdministrativeArea":{"SubAdministrativeAreaName":"\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4\xd1\x81\xd0\xba\xd0\xbe\xd0\xb9 \xd0\xbe\xd0\xba\xd1\x80\xd1\x83\xd0\xb3 \xd0\x9d\xd0\xb8\xd0\xb6\xd0\xbd\xd0\xb8\xd0\xb9 \xd0\x9d\xd0\xbe\xd0\xb2\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4","Locality":{"LocalityName":"\xd0\x9d\xd0\xb8\xd0\xb6\xd0\xbd\xd0\xb8\xd0\xb9 \xd0\x9d\xd0\xbe\xd0\xb2\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4"}}}}}}}
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Калининград&format=json"
response = requests.get(geocoder_request)
if response:
   text_file = "C4.txt"
   with open(text_file, "wb") as file:
      file.write(response.content)
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#C4.txt
#"AdministrativeArea":{"AdministrativeAreaName":"\xd0\x9a\xd0\xb0\xd0\xbb\xd0\xb8\xd0\xbd\xd0\xb8\xd0\xbd\xd0\xb3\xd1\x80\xd0\xb0\xd0\xb4\xd1\x81\xd0\xba\xd0\xb0\xd1\x8f \xd0\xbe\xd0\xb1\xd0\xbb\xd0\xb0\xd1\x81\xd1\x82\xd1\x8c","SubAdministrativeArea":{"SubAdministrativeAreaName":"\xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4\xd1\x81\xd0\xba\xd0\xbe\xd0\xb9 \xd0\xbe\xd0\xba\xd1\x80\xd1\x83\xd0\xb3 \xd0\x9a\xd0\xb0\xd0\xbb\xd0\xb8\xd0\xbd\xd0\xb8\xd0\xbd\xd0\xb3\xd1\x80\xd0\xb0\xd0\xb4","Locality":{"LocalityName":"\xd0\x9a\xd0\xb0\xd0\xbb\xd0\xb8\xd0\xbd\xd0\xb8\xd0\xbd\xd0\xb3\xd1\x80\xd0\xb0\xd0\xb4"}}}}}}}
geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Кемерово&format=json"
response = requests.get(geocoder_request)
if response:
   text_file = "C5.txt"
   with open(text_file, "wb") as file:
      file.write(response.content)
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#C5.txt
#"AdministrativeArea":{"AdministrativeAreaName":"\xd0\x9a\xd0\xb5\xd0\xbc\xd0\xb5\xd1\x80\xd0\xbe\xd0\xb2\xd1\x81\xd0\xba\xd0\xb0\xd1\x8f \xd0\xbe\xd0\xb1\xd0\xbb\xd0\xb0\xd1\x81\xd1\x82\xd1\x8c","SubAdministrativeArea":{"SubAdministrativeAreaName":"\xd0\x9a\xd0\xb5\xd0\xbc\xd0\xb5\xd1\x80\xd0\xbe\xd0\xb2\xd1\x81\xd0\xba\xd0\xb8\xd0\xb9 \xd0\xb3\xd0\xbe\xd1\x80\xd0\xbe\xd0\xb4\xd1\x81\xd0\xba\xd0\xbe\xd0\xb9 \xd0\xbe\xd0\xba\xd1\x80\xd1\x83\xd0\xb3","Locality":{"LocalityName":"\xd0\x9a\xd0\xb5\xd0\xbc\xd0\xb5\xd1\x80\xd0\xbe\xd0\xb2\xd0\xbe"}}}}}}}


#D

geocoder_request = f"http://geocode-maps.yandex.ru/1.x/?apikey={token_ya.YA_TOKEN}&geocode=Кемерово,+ул.+Красная+6&format=json"
response = requests.get(geocoder_request)
if response:
   print(response.content)
else:
   print("Error")
   print("Http статус:", response.status_code, "(", response.reason, ")")
#"postal_code":"650000"

