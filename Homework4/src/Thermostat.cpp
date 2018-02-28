#include "Thermostat.h"
#include <stdexcept>

namespace thermostat{
    
    Thermostat::Thermostat() 
        : temp(75), type(tempType::F), speed(fanSpeed::AUTO) {}
    
    Thermostat::Thermostat(int _temp, tempType _type, fanSpeed _speed)
        : temp(_temp > 0 && _temp < 100 ? _temp : 0), type(_type), speed(_speed)
    {
        if (temp <= 0) {
            throw std::invalid_argument("Temp was " + std::to_string(temp) + ". It should be between 0 and 100.");
        }
    }

    int Thermostat::getTemp() const {
        return temp;
    }

    tempType Thermostat::getTempType() const {
        return type;
    }

    fanSpeed Thermostat::getFanSpeed() const {
        return speed;
    }

    void Thermostat::setTemp(int _temp) {
        if(_temp > 0 && _temp < 100)
            temp = _temp;
        else
            throw std::invalid_argument("Temp was " + std::to_string(_temp) + ". It should be between 0 and 100.");
    }

    void Thermostat::setTempType(tempType _type) {
        type = _type;
    }

    void Thermostat::setFanSpeed(fanSpeed _speed) {
        speed = _speed;
    }
}
