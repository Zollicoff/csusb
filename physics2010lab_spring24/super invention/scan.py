from machine import I2C, Pin

# Initialize the I2C bus
i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)

# Scan the I2C bus for devices
devices = i2c.scan()

# Print the addresses of all found devices
for device in devices:
    print("Found device at address:", hex(device))