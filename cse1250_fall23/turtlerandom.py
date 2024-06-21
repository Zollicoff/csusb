import turtle
import random

t = turtle.Turtle()
t.speed(0)

for i in range(10000):
    t.forward(random.randint(-100, 100))
    t.right(random.randint(-180, 180))