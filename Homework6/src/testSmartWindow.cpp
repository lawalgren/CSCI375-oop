//
// Created by lucas on 4/10/2018.
//

#include <gtest/gtest.h>

#include "../include/smartWindow.h"

TEST(smartWindow, defaultConstruct) {
    thermostat::smartWindow unit;
    ASSERT_TRUE(unit.getCurrentTemp() == 50
                && !unit.isOpen() && unit.isAutomatic());
}

TEST(smartWindow, Construct) {
    thermostat::smartWindow unit(true, 75, false);
    ASSERT_TRUE(unit.getCurrentTemp() == 75 && unit.isOpen() && !unit.isAutomatic());
}

TEST(smartThermostat, setCurrentTemp) {
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