#include "smartThermostat.h"
#include <stdexcept>

namespace thermostat {
    smartThermostat::smartThermostat()
    : currentTemp(50)
    {
        testState();
    }
    
    smartThermostat::smartThermostat(int _temp, int _currentTemp, tempType _type, fanSpeed _speed)
    : Thermostat(_temp, _type, _speed), currentTemp(((_currentTemp < 200 && _currentTemp > -200) ? _currentTemp : -201))
    {
        if (currentTemp < -200)
            throw std::invalid_argument("currentTemp was " + std::to_string(_currentTemp) + ". It should be between 0 and 100.");
        testState(); 
    }

    int smartThermostat::getCurrentTemp() {
        return currentTemp;
    } 

    void smartThermostat::setCurrentTemp(int _temp) {
        if (_temp > -200 && _temp < 200)
            currentTemp = _temp;
        else {
            throw std::invalid_argument("currentTemp was " + std::to_string(_temp) + ". It should be between -200 and 200.");
        }
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
