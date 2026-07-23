from opensky_api import OpenSkyApi
api = OpenSkyApi()
arrivals = api.get_arrivals_by_airport("VNKT", 1782825985-3600, 1782825985)
departures = api.get_departures_by_airport("VNKT", 1782825985-3600, 1782825985)
print("Arrivals:")
for flight in arrivals:
    print(flight)
print("Departures:")
for flight in departures:
    print(flight)