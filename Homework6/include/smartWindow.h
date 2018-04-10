//
// Created by lucas on 4/10/2018.
//

#pragma once
#include "smartTemperatureDevice.h"
namespace thermostat {
    class smartWindow : public virtual smartTemperatureDevice {
    private: bool open;
    private: bool automatic;
    public: smartWindow();
    public: smartWindow(bool _open, int _currentTemp, bool _automatic);
    protected: void setOpen(bool _open);
    public: virtual void openWindow();
    public: virtual void closeWindow();
    public: virtual void setAutomatic(bool _automatic);
    protected: virtual void testPosition();
    public: virtual bool isOpen();
    public: virtual bool isAutomatic();
    public: virtual void setCurrentTemp(int _currentTemp);
    public: virtual ~smartWindow() {};
    };
}
