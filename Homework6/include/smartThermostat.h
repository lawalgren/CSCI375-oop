#pragma once
#include "Thermostat.h"
#include "thermostatMode.h"
#include "smartTemperatureDevice.h"

namespace thermostat {
    class smartThermostat: public Thermostat, public virtual smartTemperatureDevice {
        private: thermostatMode state;

        public: smartThermostat();
        public: smartThermostat(int _temp, int _currentTemp, tempType _type, fanSpeed _speed);


        protected: virtual void testState();
        public: virtual thermostatMode getState();
        public: virtual void setCurrentTemp(int _currentTemp);

        public: virtual fanSpeed getFanSpeed();
        public: virtual ~smartThermostat() {};
    };
}
