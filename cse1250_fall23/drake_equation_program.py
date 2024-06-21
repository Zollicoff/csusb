import time

# SETI Program

print('Welcome to the SETI program.\n')
time.sleep(1)

print('The drake equation, developed by Frank Drake in the 1960s,\n'
    'attempts to estimate how many extraterrestrial civilizations,\n'
    'N, may exist in our galaxy at any given time that we might come in contact with,\n\n')
time.sleep(1)

print('N = R * P * n * f * i * c * L\n\n'
    'where,\n'
    'R = estimated rate of star creation in our galaxy\n'
    'p = estimated percent of stars that have planets\n'
    'n = estimated average number of planets that can potentially support life for each start with planets\n'
    'f = estimated percent of those planets that actually go on to develop life\n'
    'i = estimated percent of those planets that go on to develop intelligent life\n'
    'c = estimated percent of those that are willing and able to communicate\n'
    'L = estimated expected lifetime of such civilizations\n\n')
time.sleep(1)

print('Given that the value for R, 7 per year, is the least disputed of the values,\n'
    'the user will be prompted to enter estimated values for the remaining six factors.\n'
    'The estimated number of civilizations that may be detected in our galaxy will then be displayed.\n\n')
time.sleep(1)

def get_float_input(prompt):
    while True:
        try:
            value = float(input(prompt))
            return value
        except ValueError:
            print('Invalid input. Please enter a number.')

p = get_float_input('Please enter the estimated percent of stars that have planets: ')
n = get_float_input('Please enter the estimated average number of planets that can potentially support life for each star with planets: ')
f = get_float_input('Please enter the estimated percent of those planets that actually go on to develop life: ')
i = get_float_input('Please enter the estimated percent of those planets that go on to develop intelligent life: ')
c = get_float_input('Please enter the estimated percent of those that are willing and able to communicate: ')
Lc = get_float_input('Please enter the estimated expected lifetime of such civilizations: \n')

num_detectable_civilizations = 7 * (p / 100) * n * (f / 100) * (i / 100) * (c / 100) * Lc

print('Based on the values entered... there are an estimated', round(num_detectable_civilizations), 'potentially detectable civilizations in our galaxy.')
time.sleep(1)

input('Press enter to exit.')