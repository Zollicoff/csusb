# A medical device manufacturer is producing ball bearings for hip replacements.
# The manufacturing process has natural variability, so not every ball bearing is exactly the same.
# A certain type of ball bearing has a mean diameter of 35 mm, with a standard deviation of 0.32 mm.
# A recently manufactured ball bearing was selected at random for quality control testing.
# The randomly selected ball bearing has a diameter of 34.46 mm.
# What is the ball bearing's z-score? How many standard deviations above or below the mean is it?

# Function to calculate z-score
def calculate_z_score(X, mu, sigma):
    z = (X - mu) / sigma
    return z

# Hardcoded values
X = 34.46
mu = 35
sigma = 0.32 

# Checking if sigma is non-zero
if sigma != 0:
    # Calculate z-score
    z_score = calculate_z_score(X, mu, sigma)
    print(f"The z-score is: {z_score}")
else:
    print("Standard deviation cannot be zero.")
