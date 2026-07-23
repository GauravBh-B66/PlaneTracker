from opensky_api import OpenSkyApi
from datetime import datetime
import time


epoch = int (time.time())
print(epoch)
api = OpenSkyApi()
arrivals = api.get_arrivals_by_airport("RJTT", epoch-3600, epoch)
# prxint(arrivals)
departures = api.get_departures_by_airport("RJTT", epoch-3600, epoch)
# print(departures)
print("Arrivals:")
for flight in arrivals:
    print(flight)
# print("Departures:")
# for flight in departures:
#     print(flight)