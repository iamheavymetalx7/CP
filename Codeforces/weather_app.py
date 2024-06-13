import requests
import json
from collections import defaultdict
import dicttoxml

url = "https://weatherapi-com.p.rapidapi.com/current.json"

headers = {
    "X-RapidAPI-Key": "31371bc5c3msh34f399b07961d46p192883jsn2ba7562e3194",
    "X-RapidAPI-Host": "weatherapi-com.p.rapidapi.com"
}

def get_current_weather(city_name,type):
    querystring = {"q": city_name}

    response = requests.get(url, headers=headers, params=querystring)
    data = response.json()  # Convert the response to JSON
    
    # Extract the desired fields
    temp_c = data['current']['temp_c']
    lat = data['location']['lat']
    lon = data['location']['lon']
    name = data['location']['name']
    country = data['location']['country']

    # Create the return JSON object
    return_json = defaultdict()
    return_json["Weather"] = f"{temp_c} C"
    return_json["Latitude"] = lat
    return_json["Longitude"] = lon
    return_json["City"] = f"{name}, {country}"

    # Convert dictionary to JSON string
    if type=="json":
        return json.dumps(return_json, indent=4)
    else:
        xml_data = dicttoxml.dicttoxml(return_json, custom_root='weather', attr_type=False)

        return xml_data.decode()


print(get_current_weather("Bengaluru","xml"))
