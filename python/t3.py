import requests
url='https://code.visualstudio.com/sha/download?build=insider&os=linux-x64'
req=requests.get(url,allow_redirects=False)
print(req.status_code)
print(req.url)
print(req.headers)
