
#task2

#Get your public IP
import requests
url=requests.get("https://api.ipify.org/?format=json")
print(url.text)
print(" ")
#Get your location
url2=requests.get("https://ipinfo.io/197.60.236.15/geo")
print(url2.text)

