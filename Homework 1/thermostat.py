class thermostat:

    FAN_AUTO = 4
    FAN_HIGH = 3
    FAN_MEDIUM = 2
    FAN_LOW = 1
    FAN_OFF = 0

    def __init__(self):
        self._temp = 75
        self._tempType = "F"
        self._fanStrength = thermostat.FAN_AUTO

    def checkTemp(self, temp):
        if not (isinstance(temp, float) or isinstance(temp, int)):
            raise ValueError("temp must be a number")

    def getTemp(self):
        return self._temp

    def setTemp(self, temp):
        thermostat.checkTemp(self, temp)
        self._temp = temp

    def checkTempType(self, tempType):
        if not isinstance(tempType, str):
            raise ValueError("tempType must be a string")
        if not (tempType == "F" or tempType == "C"):
            raise ValueError("tempType must be either C or F")

    def getTempType(self):
        return self._tempType

    def setTempType(self, tempType):
        thermostat.checkTempType(self, tempType)
        self._tempType = tempType

    def checkFanStrength(self, fanStrength):
        if not isinstance(fanStrength, int):
            raise ValueError("fanStrength must be an int")
        if not (fanStrength == thermostat.FAN_AUTO or fanStrength == thermostat.FAN_HIGH or fanStrength == thermostat.FAN_MEDIUM or
        fanStrength == thermostat.FAN_LOW or fanStrength == thermostat.FAN_OFF):
            raise ValueError("fanStrength can only be FAN_AUTO, FAN_HIGH, FAN_MEDIUM, FAN_LOW or FAN_OFF")

    def getFanStrength(self):
        return self._fanStrength

    def setFanStrength(self, fanStrength):
        thermostat.checkFanStrength(self, fanStrength)
        self._fanStrength = fanStrength
