import requests

map_request = "https://static-maps.yandex.ru/1.x/?ll=136.737180%2C-26.661921&spn=18.0,18.0&l=sat"
response = requests.get(map_request)
if not response:
    print("Error")
else:
    map_file = "map_australia.png"
    with open(map_file, "wb") as file:
        file.write(response.content)
