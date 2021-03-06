#pragma once
#include "Thermostat.h"
#include "thermostatMode.h"

namespace thermostat {
    class smartThermostat: public Thermostat {
        private: int currentTemp;
        private: thermostatMode state;        

        public: smartThermostat();
        public: smartThermostat(int _temp, int _currentTemp, tempType _type, fanSpeed _speed);

        public: virtual void setCurrentTemp(int _temp);
        public: virtual int getCurrentTemp();

        private: virtual void testState();
        public: virtual thermostatMode getState();

        public: virtual fanSpeed getFanSpeed();
        public: virtual ~smartThermostat() {};
    };
}
