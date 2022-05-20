import requests
map_request = "https://static-maps.yandex.ru/1.x/?ll=86.092040,55.351662&z=17&l=map"
response = requests.get(map_request)
if not response:
   print("Error")
map_file = "map.png"
with open(map_file, "wb") as file:
   file.write(response.content)
#print(response.content)
map_request2 = "https://static-maps.yandex.ru/1.x/?ll=86.117112,55.347013&size=650,450&z=17&spn=0.003,0.003&l=map"
response = requests.get(map_request2)
if not response:
   print("Error")
map_file2 = "map2.png"
with open(map_file2, "wb") as file:
   file.write(response.content)
map_request3 = "https://static-maps.yandex.ru/1.x/?ll=2.294906,48.857779&z=17&spn=0.002,0.002&l=sat"
response = requests.get(map_request3)
if not response:
   print("Error")
map_file3 = "map3.png"
with open(map_file3, "wb") as file:
   file.write(response.content)
map_request4 = "https://static-maps.yandex.ru/1.x/?ll=158.843679,53.390051&z=9&l=sat"
response = requests.get(map_request4)
if not response:
   print("Error")
map_file4 = "map4.png"
with open(map_file4, "wb") as file:
   file.write(response.content)
map_request5 = "https://static-maps.yandex.ru/1.x/?ll=107.336949%2C53.409261&z=6&l=sat"
response = requests.get(map_request5)
if not response:
   print("Error")
map_file5 = "map5.png"
with open(map_file5, "wb") as file:
   file.write(response.content)
map_request6 = "https://static-maps.yandex.ru/1.x/?ll=63.293766%2C45.923745&z=12&l=sat"
response = requests.get(map_request6)
if not response:
   print("Error")
map_file6 = "map6.png"
with open(map_file6, "wb") as file:
   file.write(response.content)
