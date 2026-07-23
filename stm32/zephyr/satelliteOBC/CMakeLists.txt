cmake_minimum_required(VERSION 3.13.1)

set(BOARD nucleo_f303re)
#Applications

#Services
list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_LIST_DIR}/services/SPI_Service)


#Genral
find_package(Zephyr)
project(SatelliteOBC)
target_sources(app PRIVATE applications/main.c)
target_include_directories(app PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/services/SPI_Service
)
