all : tests

# https://github.com/google/googletest
GTEST_DIR=${HOME}/projects/googletest/googletest
CXXFLAGS= -std=c++11 -isystem ${GTEST_DIR}/include -pthread -Iinclude
LDFLAGS= -Llib -lgtest

# build gtest library
lib/libgtest.a : ${GTEST_DIR}/src/gtest-all.cc
	$(CXX) -c $(CXXFLAGS) -o $@ -I${GTEST_DIR} $<

# main suitable for all tests
tmp/testMain.o : src/testMain.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

tmp/Thermostat.o : src/Thermostat.cpp include/Thermostat.h include/fanSpeed.h include/tempType.h
	$(CXX) -c $(CXXFLAGS) -o $@ $<

tmp/smartThermostat.o : src/smartThermostat.cpp tmp/Thermostat.o include/fanSpeed.h include/tempType.h include/thermostatMode.h
	$(CXX) -c $(CXXFLAGS) -o $@ $<

bin/testThermostat : src/testThermostat.cpp tmp/Thermostat.o tmp/testMain.o lib/libgtest.a
	$(CXX) $(CXXFLAGS) -o $@ src/testThermostat.cpp tmp/Thermostat.o tmp/testMain.o $(LDFLAGS)

bin/testSmartThermostat : src/testSmartThermostat.cpp tmp/smartThermostat.o tmp/testMain.o lib/libgtest.a tmp/Thermostat.o
	$(CXX) $(CXXFLAGS) -o $@ src/testSmartThermostat.cpp tmp/smartThermostat.o tmp/testMain.o tmp/Thermostat.o $(LDFLAGS)

tests : bin/testThermostat bin/testSmartThermostat

clean : 
	rm bin/* tmp/* lib/*
