//
// Created by lucas on 4/10/2018.
//

#include "../include/smartWindowThermostat.h"

namespace thermostat {

    void smartWindowThermostat::setCurrentTemp(int _currentTemp){
        smartTemperatureDevice::setCurrentTemp(_currentTemp);
        automate();
    }

    void smartWindowThermostat::automate() {
        if (isAutomatic()) {
            testState();
            if (getState() == thermostatMode::COOL)
                openWindow();
            else if (getState() == thermostatMode::HEAT)
                closeWindow();
        }
    }

    void smartWindowThermostat::openWindow() {
        setOpen(true);
    }

    void smartWindowThermostat::closeWindow() {
        setOpen(false);
    }
}