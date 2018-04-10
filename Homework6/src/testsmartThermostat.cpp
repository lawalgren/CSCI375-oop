#include <gtest/gtest.h>

#include "../include/smartThermostat.h"

TEST(smartThermostat, defaultConstruct) {
    thermostat::smartThermostat unit;
    ASSERT_TRUE(unit.getTemp() == 75 && unit.getTempType() == thermostat::tempType::F && unit.getFanSpeed() == thermostat::fanSpeed::AUTO
        && unit.getCurrentTemp() == 50 && unit.getState() == thermostat::thermostatMode::HEAT);
}

TEST(smartThermostat, Construct) {
    thermostat::smartThermostat unit(20, 30, thermostat::tempType::C, thermostat::fanSpeed::MEDIUM);
    ASSERT_TRUE(unit.getTemp() == 20 && unit.getTempType() == thermostat::tempType::C && unit.getFanSpeed() == thermostat::fanSpeed::MEDIUM && unit.getCurrentTemp() == 30 && unit.getState() == thermostat::thermostatMode::COOL);
}

TEST(smartThermostat, setCurrentTemp) { 
    thermostat::smartThermostat unit;
    unit.setCurrentTemp(60);
    int expResult = 60;
    ASSERT_EQ(unit.getCurrentTemp(), expResult);
}

TEST(smartThermostat, setCurrentTempInvalid) {
    thermostat::smartThermostat unit;
    bool OK = false;
    try {
        unit.setCurrentTemp(201);
    } catch(std::invalid_argument ex) {
        OK = true;
    }
    ASSERT_TRUE(OK);
}

TEST(smartThermostat, getState) {
    thermostat::smartThermostat unit;
    unit.setCurrentTemp(90);
    thermostat::thermostatMode expResult = thermostat::thermostatMode::COOL;
    ASSERT_EQ(unit.getState(), expResult);
}

TEST(smartThermostat, getFanSpeed) {
    thermostat::smartThermostat unit;
    unit.setCurrentTemp(75);
    thermostat::fanSpeed expResult = thermostat::fanSpeed::OFF;
    ASSERT_EQ(unit.getFanSpeed(), expResult);
    unit.setCurrentTemp(50);
    expResult = thermostat::fanSpeed::AUTO;
    ASSERT_EQ(unit.getFanSpeed(), expResult);
}
