//
// Created by lucas on 4/10/2018.
//

#include <gtest/gtest.h>

#include "../include/smartWindowThermostat.h"

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
    ASSERT_TRUE(unit.getState() == thermostat::thermostatMode::COOL);
    ASSERT_TRUE(unit.isOpen());
}
