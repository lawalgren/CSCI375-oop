#include <gtest/gtest.h>
#include <stdexcept>

#include "../include/Thermostat.h"

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
