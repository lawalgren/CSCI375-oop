//
// Created by lucas on 4/10/2018.
//

#include "../include/smartWindow.h"

namespace thermostat {

    smartWindow::smartWindow()
            : open(false), automatic(true)
    {}

    smartWindow::smartWindow(bool _isOpen, int _currentTemp, bool _automatic)
            : smartTemperatureDevice(_currentTemp), open(_isOpen), automatic(_automatic)
    {
        if (automatic)
            testPosition();
    }

    void smartWindow::setOpen(bool _open) {
        open = _open;
    }

    void smartWindow::openWindow() {
        automatic = false;
        open = true;
    }

    void smartWindow::closeWindow() {
        automatic = false;
        open = false;
    }

    void smartWindow::setAutomatic(bool _automatic) {
        automatic = _automatic;
        testPosition();
    }

    void smartWindow::testPosition() {
        open = ((getCurrentTemp() > 80) ? true : false);
    }

    bool smartWindow::isOpen() {
        return open;
    }

    bool smartWindow::isAutomatic() {
        return automatic;
    }

    void smartWindow::setCurrentTemp(int _currentTemp) {
        smartTemperatureDevice::setCurrentTemp(_currentTemp);
        testPosition();
    }

}