#pragma once
#include <stdexcept>

namespace thermostat{
    class smartTemperatureDevice{
    protected: int currentTemp;
    public: virtual int validateCurrentTemp(int _currentTemp) {
            if (_currentTemp <  -200 || _currentTemp > 200)
                throw std::invalid_argument("temp was " + std::to_string(_currentTemp) + ". It should be  <= 200 or => -200");
            else
                return _currentTemp;
        }
    public: smartTemperatureDevice()
            : currentTemp(50)
        {}
    public: smartTemperatureDevice(int _currentTemp)
                : currentTemp(validateCurrentTemp(_currentTemp))
        {}
    public: virtual void setCurrentTemp(int _temp) {
            validateCurrentTemp(_temp);
            currentTemp = _temp;
        }
    public: virtual int getCurrentTemp() {
            return currentTemp;
        }
    public: virtual ~smartTemperatureDevice() {};
    };
}