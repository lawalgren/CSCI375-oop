cmake_minimum_required(VERSION 3.9)
project(Homework6)

set(CMAKE_CXX_STANDARD 11)

include_directories(../../googletest/googletest/include ../../googletest/googletest)

add_library(gtest ../../googletest/googletest/include ../../googletest/googletest/src/gtest-all)
add_executable(testThermostat src/Thermostat.cpp include/Thermostat.h include/fanSpeed.h
        include/tempType.h src/testThermostat.cpp src/testMain.cpp include/smartTemperatureDevice.h)
add_executable(testsmartThermostat src/Thermostat.cpp include/Thermostat.h include/fanSpeed.h
        include/tempType.h include/thermostatMode.h include/smartThermostat.h src/testMain.cpp
        src/testsmartThermostat.cpp src/smartThermostat.cpp include/smartTemperatureDevice.h)
add_executable(testSmartWindow src/testSmartWindow.cpp src/smartWindow.cpp include/smartWindow.h
        include/smartTemperatureDevice.h src/testMain.cpp)
add_executable(testsmartWindowThermostat src/testsmartWindowThermostat.cpp include/smartWindowThermostat.h
        src/smartWindowThermostat.cpp src/testMain.cpp include/smartWindow.h src/smartWindow.cpp include/smartThermostat.h
        src/smartThermostat.cpp include/smartTemperatureDevice.h src/smartWindow.cpp include/smartWindow.h include/Thermostat.h src/Thermostat.cpp)
target_link_libraries(testThermostat gtest)
target_link_libraries(testsmartThermostat gtest)
target_link_libraries(testSmartWindow gtest)
target_link_libraries(testsmartWindowThermostat gtest)