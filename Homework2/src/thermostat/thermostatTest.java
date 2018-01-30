package thermostat;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;


class thermostatTest {

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
    }

    @org.junit.jupiter.api.AfterEach
    void tearDown() {
    }

    @Test
    public void testConstructor() {
        thermostat unit = new thermostat(36, tempType.C, fanSpeed.MEDIUM);
        assertTrue(unit.getTemp() == 36 && unit.getTempType() == tempType.C && unit.getFanSpeed() == fanSpeed.MEDIUM);
    }

    @Test
    public void testDefaultConstructor() {
        thermostat unit = new thermostat();
        assertTrue(unit.getTemp() == 75 && unit.getTempType() == tempType.F && unit.getFanSpeed() == fanSpeed.AUTO);
    }

    @Test
    public void testSetTemp() {
        thermostat unit = new thermostat();
        unit.setTemp(45);
        int expResult = 45;
        assertEquals(expResult, unit.getTemp());
    }

    @Test
    public void testSetTempInvalid() {
        thermostat unit = new thermostat();
        boolean ok = false;
        try {
            unit.setTemp(-1);
        } catch(IllegalArgumentException ex) {
            ok = true;
        }
        assertTrue(ok);
    }

    @Test
    public void testSetTempType() {
        thermostat unit = new thermostat();
        unit.setTempType(tempType.C);
        tempType expResult = tempType.C;
        assertEquals(unit.getTempType(), expResult);
    }

    @Test
    public void testSetFanSpeed() {
        thermostat unit = new thermostat();
        unit.setFanSpeed(fanSpeed.HIGH);
        fanSpeed expResult = fanSpeed.HIGH;
        assertEquals(unit.getFanSpeed(), expResult);
    }

}