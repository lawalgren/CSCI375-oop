package thermostat;

public class thermostat
{
    private int temp;
    private tempType type;
    private fanSpeed speed;

    public thermostat() {
        setTemp(75);
        setTempType(tempType.F);
        setFanSpeed(fanSpeed.AUTO);
    }

    public thermostat(int _temp, tempType _type, fanSpeed _speed) {
        setTemp(_temp);
        setTempType(_type);
        setFanSpeed(_speed);
    }

    public int getTemp() {
        return temp;
    }

    public tempType getTempType() {
        return type;
    }

    public fanSpeed getFanSpeed() {
        return speed;
    }

    public void setTemp(int _temp) {
        if(_temp > 0 && _temp < 100)
            temp = _temp;
        else {
            throw new IllegalArgumentException("Temp was " + _temp + ". It should be between 0 and 100.");
        }
    }

    public void setTempType(tempType _type) {
        type = _type;
    }

    public void setFanSpeed(fanSpeed _speed) {
        speed = _speed;
    }
}
