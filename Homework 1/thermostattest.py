import unittest
from thermostat import thermostat

class thermostattest(unittest.TestCase):

    def testinit(self):
        unit = thermostat()
        self.assertTrue(unit.getTemp() == 75 and unit.getTempType() == "F" and unit.getFanStrength() == thermostat.FAN_AUTO, "Initial values for unit are incorrect")

    def testSetTemp(self):
        unit = thermostat()
        unit.setTemp(50)
        expresult = 50
        self.assertEqual(unit.getTemp(), expresult, "temp should be 50")

    def testSetTempType(self):
        unit = thermostat()
        unit.setTempType("C")
        expresult = "C"
        self.assertEqual(unit.getTempType(), expresult, "tempType should be 'C'")

    def testSetFanStrength(self):
        unit = thermostat()
        unit.setFanStrength(thermostat.FAN_OFF)
        expresult = thermostat.FAN_OFF
        self.assertEqual(unit.getFanStrength(), expresult, "fanStrength should be FAN_OFF")

    def testSetTempInvalid(self):
        unit = thermostat()
        OK = False
        try:
            unit.setTemp("abcd")
        except ValueError:
            OK = True
        self.assertTrue(OK)

    def testSetTempTypeInvalid(self):
        unit = thermostat()
        OK = False
        try:
            unit.setTempType(75)
        except ValueError:
            OK = True
        self.assertTrue(OK)

    def testSetFanStrengthInvalid(self):
        unit = thermostat()
        OK = False
        try:
            unit.setFanStrength("FAN_OFF")
        except ValueError:
            OK = True
        self.assertTrue(OK)

if __name__ == '__main__':
    unittest.main()
