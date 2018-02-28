#pragma once

#include "tempType.h"
#include "fanSpeed.h"


namespace thermostat {
    class Thermostat{
        private: int temp;
        private: tempType type;
        private: fanSpeed speed;

        public: Thermostat();
        public: Thermostat(int _temp, tempType _type, fanSpeed _speed);

        public: int getTemp() const ;
        public: tempType getTempType() const ;
        public: fanSpeed getFanSpeed() const ;
        public: void setTemp(int _temp);
        public: void setTempType(tempType _type);
        public: void setFanSpeed(fanSpeed _speed);
    };
}
