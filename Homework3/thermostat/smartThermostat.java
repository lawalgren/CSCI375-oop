package thermostat;

public class smartThermostat extends thermostat{

    private int currentTemp;
    private thermostatMode state;

    public smartThermostat(){
        super();
        currentTemp = 50;
        testState();
    }

    public smartThermostat(int _temp, int _currentTemp, tempType _type, fanSpeed _speed) {
        super(_temp, _type, _speed);
        setCurrentTemp(_currentTemp);
        testState();
    }

    public int getCurrentTemp() {
        return currentTemp;
    }

    public void setCurrentTemp(int _temp) {
        if (_temp > -200 && _temp < 200)
            currentTemp = _temp;
        else {
            throw new IllegalArgumentException("currentTemp was " + _temp + ". It should be between -200 and 200.");
        }
        testState();
    }

    private void testState() {
        if(currentTemp < super.getTemp())
            state = thermostatMode.HEAT;
        else if(currentTemp > super.getTemp())
            state = thermostatMode.COOL;
        else
            state = thermostatMode.WAIT;
    }

    public thermostatMode getState() {
        return state;
    }

}
