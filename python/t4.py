import requests
url='https://code.visualstudio.com/sha/download?build=insider&os=linux-x64'
response=requests.get(url)
for resp in response.history:
    print(resp.url)
