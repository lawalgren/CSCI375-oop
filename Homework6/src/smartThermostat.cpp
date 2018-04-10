#include "../include/smartThermostat.h"

namespace thermostat {
    smartThermostat::smartThermostat()
    {
       testState();
    }
    
    smartThermostat::smartThermostat(int _temp, int _currentTemp, tempType _type, fanSpeed _speed)
    : Thermostat(_temp, _type, _speed), smartTemperatureDevice(_currentTemp)
    {
        testState();
    }

    void smartThermostat::testState() {
        if(currentTemp < Thermostat::getTemp())
            state = thermostatMode::HEAT;
        else if(currentTemp > Thermostat::getTemp())
            state = thermostatMode::COOL;
        else
            state = thermostatMode::WAIT;
    }

    void smartThermostat::setCurrentTemp(int _currentTemp) {
        smartTemperatureDevice::setCurrentTemp(_currentTemp);
        testState();
    }

    thermostatMode smartThermostat::getState() {
        return state;
    }

    fanSpeed smartThermostat::getFanSpeed() {
        if(state != thermostatMode::WAIT)
            return Thermostat::getFanSpeed();
        else
            return fanSpeed::OFF;
    }
}
