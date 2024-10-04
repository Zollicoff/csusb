# In a certain city, 46% of residents own a house and 67% of residents own a car. 21% of residents own both a house and a car.
# Suppose that P(A) = 0.46, P(B) = 0.67, and P(A and B) = 0.21.
# What is P(A or B)?

# Given probabilities
P_A = 0.46            # P(A): Probability of owning a house
P_B = 0.67            # P(B): Probability of owning a car
P_A_and_B = 0.21      # P(A and B): Probability of both A and B occurring

# Compute additional probabilities
P_A_or_B = P_A + P_B - P_A_and_B  # P(A or B)
P_A_given_B = P_A_and_B / P_B     # P(A|B): Probability of A given B
P_B_given_A = P_A_and_B / P_A     # P(B|A): Probability of B given A

# Output the probabilities
print("P(A) =", P_A)
print("P(B) =", P_B)
print("P(A and B) =", P_A_and_B)
print("P(A or B) =", P_A_or_B)
print("P(A|B) =", P_A_given_B)
print("P(B|A) =", P_B_given_A)
