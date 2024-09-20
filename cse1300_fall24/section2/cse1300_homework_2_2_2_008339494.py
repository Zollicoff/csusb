# Convert the list practiceList to a set convertedSet.
# Remove element 5 from convertedSet.
# Find the intersection of convertedSet and the set newSet.

# The code provided creates the list practiceList and the set newSet and prints all results.

# Code:

# Create a list
practiceList = [39, 5, 111]

# Create the set newSet
newSet = {39, 23}

# Convert practiceList to a set
convertedSet = set(practiceList)
print(sorted(convertedSet))

# Remove 5 from the set 
convertedSet.remove(5)
print(sorted(convertedSet))

# Find the intersection of convertedSet and newSet
convertedSetIntersection = convertedSet.intersection(newSet)
print(sorted(convertedSetIntersection))

