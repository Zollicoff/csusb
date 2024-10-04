# In a certain hospital's cancer ward, 30% of patients have chronic kidney disease (CKD). 82.5% of patients in the cancer ward are receiving IV chemotherapy. 19.5% of patients have chronic kidney disease and are receiving IV chemotherapy.
# Define A as a person with chronic kidney disease and B as a person receiving IV chemotherapy.
# What is P(A)?
# What is P(B)?
# What is P(A and B)?
# (Give decimal values, not percentages.)

# Given probabilities
P_A = 0.3            # P(A): Probability of chronic kidney disease (CKD)
P_B = 0.825          # P(B): Probability of receiving IV chemotherapy
P_A_and_B = 0.195    # P(A and B): Probability of both A and B occurring

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
