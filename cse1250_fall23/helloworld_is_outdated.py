"""
Hello World!!!
"""
import time

def print_slow(text):
    for char in text:
        print(char, end='', flush=True)
        time.sleep(0.05)
    print()

print_slow("Hello World!!!\n")
print_slow("Don't you think it's strange the professor didn't have us write this program for CS1250?\n")
print_slow("I mean, it's the first program you write in every programming class, right?\n")
print_slow("I guess he's trying to save time, but I think it's important to write it anyway.\n")
print_slow("I mean, it's tradition, right?\n")
print_slow("Hellloooooooo worlddddddddddddddddddddddd!!!\n")
print_slow("I'm alive!!!\n")
print_slow("I'm a ")
print_slow("program!!!\n")
print_slow("PEACE!!!\n")

input("Press Enter to exit the program...")
