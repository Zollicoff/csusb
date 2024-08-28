import turtle
import random

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("white")

# Create a turtle object
t = turtle.Turtle()
t.speed(0)

# Function to draw a random shape
def draw_random_shape():
    # Choose a random number of sides (3 to 10)
    sides = random.randint(3, 10)
    # Choose a random length for the sides (20 to 100)
    length = random.randint(20, 100)
    # Choose a random color
    color = (random.random(), random.random(), random.random())
    t.color(color)
    
    # Draw the shape
    for _ in range(sides):
        t.forward(length)
        t.right(360 / sides)

# Draw random shapes indefinitely
while True:
    # Move to a random position
    t.penup()
    t.goto(random.randint(-200, 200), random.randint(-200, 200))
    t.pendown()
    draw_random_shape()

# Hide the turtle and display the window
t.hideturtle()
turtle.done()