myFlower1 = input("Enter your first flower: ")
myFlower2 = input("Enter your second flower: ")
myFlower3 = input("Enter your third flower: ")

yourFlower1 = input("Enter your first flower: ")    
yourFlower2 = input("Enter your second flower: ")

theirFlower = input('Enter their flower: ')

# Define myList containing myFlower1, myFlower2, and myFlower3 in that order
myList = [myFlower1, myFlower2, myFlower3]
print(myList)

# Define yourList containing yourFlower1 and yourFlower2 in that order
yourList = [yourFlower1, yourFlower2]
print(yourList)

# Define ourList by concatenating myList and yourList
ourList = myList + yourList
print(ourList)

# Append theirFlower to the end of ourList
ourList.append(theirFlower)
print(ourList)

# Replace myFlower2 in ourList with theirFlower
ourList[1] = theirFlower
print(ourList)

# Remove the third element of ourList
del ourList[2]
print(ourList)