//
// Created by lucas on 4/10/2018.
//

#pragma once

#include "smartThermostat.h"
#include "smartWindow.h"
#include "Thermostat.h"
#include "smartTemperatureDevice.h"

namespace thermostat {
   class smartWindowThermostat : public virtual smartThermostat, public virtual smartWindow {
    public:virtual void setCurrentTemp(int _currentTemp);
   public: virtual void automate();
   public: virtual void openWindow();
   public: virtual void closeWindow();
   public: virtual ~smartWindowThermostat() {};
    };
}
