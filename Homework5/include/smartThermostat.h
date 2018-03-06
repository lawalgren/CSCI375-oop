#pragma once
#include "Thermostat.h"
#include "thermostatMode.h"

namespace thermostat {
    class smartThermostat: public Thermostat {
        private: int currentTemp;
        private: thermostatMode state;        

        public: smartThermostat();
        public: smartThermostat(int _temp, int _currentTemp, tempType _type, fanSpeed _speed);

        public: void setCurrentTemp(int _temp);
        public: int getCurrentTemp();

        private: void testState();
        public: thermostatMode getState();

        public: fanSpeed getFanSpeed();
    };
}
