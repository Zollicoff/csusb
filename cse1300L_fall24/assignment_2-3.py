# Given the user inputs, complete a program that does the following tasks:

    # Define a set, fruits, containing the user inputs myFruit1, myFruit2, and myFruit3.
    # Add the user input theirFruit to fruits.
    # Find the intersection of fruits and yourFruit1 and yourFruit2
    # Remove myFruit1 from fruits.

# Note: For testing purposes, sets are printed using sorted() for comparison.

# Ex: If the input is:

# apple
# peach
# lemon
# apple
# pear
# plum

# the output is:

# ['apple', 'lemon', 'peach']
# ['apple', 'lemon', 'peach', 'plum']
# ['apple']
# ['lemon', 'peach', 'plum']

myFruit1 = input()
myFruit2 = input()
myFruit3 = input()

yourFruit1 = input()
yourFruit2 = input()

theirFruit = input()

# Define a set, fruits, containing myFruit1, myFruit2, and myFruit3
fruits = {myFruit1, myFruit2, myFruit3}
print(sorted(fruits))

# Add theirFruit to fruits
fruits.add(theirFruit)
print(sorted(fruits))

# Find the intersection of fruits and yourFruit1 and yourFruit2
fruitsInter = fruits.intersection({yourFruit1, yourFruit2})
print(sorted(fruitsInter))

# Remove myFruit1 from fruits
fruits.remove(myFruit1)
print(sorted(fruits))