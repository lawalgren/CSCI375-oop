package thermostat;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class smartThermostatTest extends thermostatTest {

    @Test
    void testConstruct() {
        smartThermostat unit = new smartThermostat();
        assertTrue(unit.getCurrentTemp() == 50 && unit.getState() == thermostatMode.HEAT
                && unit.getTemp() == 75 && unit.getTempType() == tempType.F && unit.getFanSpeed() == fanSpeed.AUTO, "Initial values are not correct");
    }

    @Test
    void testNonDefaultConstruct() {
        smartThermostat unit = new smartThermostat(15, 24, tempType.C, fanSpeed.HIGH);
        assertTrue(unit.getCurrentTemp() == 24 && unit.getState() == thermostatMode.COOL
                && unit.getTemp() == 15 && unit.getTempType() == tempType.C && unit.getFanSpeed() == fanSpeed.HIGH, "Initial values are not correct");
    }

    @Test
    void testSetCurrentTemp() {
        smartThermostat unit = new smartThermostat();
        unit.setCurrentTemp(60);
        int expResult = 60;
        assertEquals(expResult, unit.getCurrentTemp(), "currentTemp was " + unit.getCurrentTemp() + " . It should be 60");
    }

    @Test
    void testSetCurrentTempInvalid() {
        smartThermostat unit = new smartThermostat();
        boolean OK = false;
        try {
            unit.setCurrentTemp(201);
        } catch(IllegalArgumentException ex) {
            OK = true;
        }
        assertTrue(OK, "This should have thrown an exception.");
    }

    @Test
    void testTestState() {
        smartThermostat unit = new smartThermostat();
        unit.setCurrentTemp(95);
        thermostatMode expResult = thermostatMode.COOL;
        assertEquals(expResult, unit.getState(), "thermostatMode should be thermostatMode.COOL.");
    }
}