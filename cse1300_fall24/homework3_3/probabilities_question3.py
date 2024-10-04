# A clothing retailer uses a rewards program to track and reward customer spending. The retailer estimates that 62% of rewards members have made an online purchase in the past year. 35% of rewards members have made an in-store purchase, and 27% of rewards members have purchased both online and in-store.
# Suppose that P(A) = 0.62, P(B) = 0.35, and P(A and B) = 0.27.
# What is P(B|A)?
# What does P(B|A) represent, in words? E.g. "P(B|A) is the probability that..."

# Given probabilities
P_A = 0.62            # P(A): Probability of making an online purchase
P_B = 0.35            # P(B): Probability of making an in-store purchase
P_A_and_B = 0.27      # P(A and B): Probability of both A and B occurring

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
