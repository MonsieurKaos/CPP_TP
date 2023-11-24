cmake_minimum_required(VERSION 3.26)
project(TP4)

set(CMAKE_CXX_STANDARD 23)

add_executable(TP4
        appThermostat.cpp
        appThermostat.hpp
        appThermostat_main.cpp
        CapteurTemp.hpp
        Chaudiere.cpp
        Chaudiere.hpp
        CapteurTemp.cpp
)
