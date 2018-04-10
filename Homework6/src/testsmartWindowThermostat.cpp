//
// Created by lucas on 4/10/2018.
//

#include <gtest/gtest.h>

#include "../include/smartWindowThermostat.h"

TEST(Thermostat, defaultConstruct) {
    thermostat::Thermostat unit;
    ASSERT_TRUE(unit.getTemp() == 75 && unit.getTempType() == thermostat::tempType::F && unit.getFanSpeed() == thermostat::fanSpeed::AUTO);
}

TEST(Thermostat, Construct) {
    thermostat::Thermostat unit(36, thermostat::tempType::C, thermostat::fanSpeed::HIGH);
    ASSERT_TRUE(unit.getTemp() == 36 && unit.getTempType() == thermostat::tempType::C && unit.getFanSpeed() == thermostat::fanSpeed::HIGH);
}

TEST(Thermostat, setTemp) {
    thermostat::Thermostat unit;
    unit.setTemp(45);
    int expResult = 45;
    ASSERT_EQ(unit.getTemp(), expResult);
}

TEST(Thermostat, setTempInvalid) {
    thermostat::Thermostat unit;
    bool ok = false;
    try {
        unit.setTemp(-1);
    } catch(std::invalid_argument ex) {
        ok = true;
    }
    ASSERT_TRUE(ok);
}

TEST(Thermostat, setTempType) {
    thermostat::Thermostat unit;
    unit.setTempType(thermostat::tempType::C);
    thermostat::tempType expResult = thermostat::tempType::C;
    ASSERT_EQ(unit.getTempType(), expResult);
}

TEST(Thermostat, setFanSpeed) {
    thermostat::Thermostat unit;
    unit.setFanSpeed(thermostat::fanSpeed::LOW);
    thermostat::fanSpeed expResult = thermostat::fanSpeed::LOW;
    ASSERT_EQ(unit.getFanSpeed(), expResult);
}

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

TEST(smartWindow, defaultConstruct) {
    thermostat::smartWindow unit;
    ASSERT_TRUE(unit.getCurrentTemp() == 50
                && !unit.isOpen() && unit.isAutomatic());
}

TEST(smartWindow, Construct) {
    thermostat::smartWindow unit(true, 75, false);
    ASSERT_TRUE(unit.getCurrentTemp() == 75 && unit.isOpen() && !unit.isAutomatic());
}

TEST(smartWindow, setCurrentTemp) {
    thermostat::smartWindow unit;
    unit.setCurrentTemp(85);
    ASSERT_TRUE(unit.getCurrentTemp() == 85);
}

TEST(smartWindow, Automatic) {
    thermostat::smartWindow unit;
    unit.setCurrentTemp(85);
    ASSERT_TRUE(unit.isOpen());
    unit.setCurrentTemp(35);
    ASSERT_FALSE(unit.isOpen());
    unit.openWindow();
    ASSERT_TRUE(unit.isOpen() && !unit.isAutomatic());
    unit.setAutomatic(true);
    ASSERT_FALSE(unit.isOpen());
    unit.closeWindow();
    ASSERT_FALSE(unit.isOpen() || unit.isAutomatic());
}

TEST(smartWindowThermostat, defaultConstruct) {
    thermostat::smartWindowThermostat unit;
    ASSERT_TRUE(unit.getCurrentTemp() == 50 && !unit.isOpen() && unit.isAutomatic() &&
                unit.getTemp() == 75 && unit.getTempType() == thermostat::tempType::F && unit.getFanSpeed() == thermostat::fanSpeed::AUTO
                && unit.getState() == thermostat::thermostatMode::HEAT);
}

TEST(smartWindowThermostat, setCurrentTemp) {
    thermostat::smartWindowThermostat unit;
    unit.setCurrentTemp(30);
    ASSERT_TRUE(unit.getState() == thermostat::thermostatMode::HEAT && !unit.isOpen());
    unit.setCurrentTemp(90);
    ASSERT_TRUE(unit.getState() == thermostat::thermostatMode::COOL && unit.isOpen());
}
