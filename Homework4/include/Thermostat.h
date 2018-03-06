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

        public: virtual int getTemp() const ;
        public: virtual tempType getTempType() const ;
        public: virtual fanSpeed getFanSpeed() const ;
        public: virtual void setTemp(int _temp);
        public: virtual void setTempType(tempType _type);
        public: virtual void setFanSpeed(fanSpeed _speed);
    };
}
