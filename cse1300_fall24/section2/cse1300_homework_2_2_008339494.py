# Create a list practiceList1 with elements 3, 'b', and 11.
# Replace the third element with 'v'.
# Append 26 to practiceList1.
# Remove the first element from practiceList1.
# Combine practiceList1 with the list practiceList2.
# The code provided displays all results and creates the second list, practiceList2.

# Code:

practiceList2 = ['cat', 105]

# Create a list with elements 3, 'b', 11
practiceList1 = [3, 'b', 11]
print(practiceList1)

# Replace the third element with 'v'
practiceList1[2] = 'v'
print(practiceList1)

# Append 26 to the list
practiceList1.append(26)
print(practiceList1)

# Remove the first element from the list
practiceList1.pop(0)
print(practiceList1)

# Combine practiceList1 and practiceList2
combinedList = practiceList1 + practiceList2
print(combinedList)

