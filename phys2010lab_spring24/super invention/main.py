import time
from INA219 import INA219
from machine import I2C, Pin
from I2C_LCD import I2CLcd

sda = machine.Pin(14)
scl = machine.Pin(15)
i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)
devices = i2c.scan()

currentSensor = INA219(i2c)
currentSensor.set_calibration_16V_400mA()
lcd = I2CLcd(i2c, devices[0], 2, 16)
 
lcd.clear()
lcd.display_on()
lcd.blink_cursor_off()
lcd.hide_cursor()
counter = 1
 
while True:
    current = currentSensor.current
    busVoltage = currentSensor.bus_voltage

    lcd.putstr("Voltage:  {:4.2f}V\n".format(busVoltage))
    lcd.putstr("Current: {:4.0f}mA\n".format(current))

    print(f"{counter} seconds has elapsed")
    print("Source Voltage: {:.2f}V".format(busVoltage))
    print("Current:  {:6.3f} A".format(current / 1000))
    print("")
    print("")

    counter += 1
    time.sleep(1)

