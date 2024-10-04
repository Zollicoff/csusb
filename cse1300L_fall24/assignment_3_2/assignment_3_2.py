# The intelligence quotient (IQ) of a randomly selected person follows a normal distribution with a mean of 100 and a standard deviation of 15. Use the scipy function norm and user input values for IQ1 and IQ2 to perform the following tasks:
# Calculate the probability that a randomly selected person will have an IQ less than or equal to IQ1.
# Calculate the probability that a randomly selected person will have an IQ between IQ1 and IQ2.
# If you toss a coin you might ask yourself “Will I get a heads?”
# Calculate the probability that you toss a coin Coin2 times, and you have Coin1 heads.
# Calculate the probability that you toss a coin Coin2 times, and you have at least Coin1 heads.

# For example, if the input is:
# 105
# 110
# 0
# 2

# the output is:

# The probability that a randomly selected person has an IQ less than or equal to 105.0 is 0.631.
# The probability that a randomly selected person has an IQ between 105.0 and 110.0 is 0.117.
# The probability that you toss a coin 2 times, and you have 0 heads is 0.250.
# The probability that you toss a coin 2 times, and you have at least 0 heads is 1.000.

# Here is the template:

# Import norm and binom from scipy.stats
import scipy.stats as st
from scipy.stats import norm, binom

# Mean and standard deviation of the IQ distribution
mean_IQ = 100
std_IQ = 15

# Input two IQs, making sure that IQ1 is less than IQ2
IQ1 = float(input())
IQ2 = float(input())

while IQ1 > IQ2:
    print("IQ1 should be less than IQ2. Enter numbers again.")
    IQ1 = float(input())
    IQ2 = float(input())

# Input two Coins, making sure that Coin1 is less than Coin2
Coin1 = int(input())
Coin2 = int(input())

while Coin1 > Coin2:
    print("Coin1 should be less than Coin2. Enter numbers again.")
    Coin1 = int(input())
    Coin2 = int(input())

# Calculate the probability that a randomly selected person has an IQ less than or equal to IQ1
probLT = norm.cdf(IQ1, loc=mean_IQ, scale=std_IQ)

# Calculate the probability that a randomly selected person has an IQ between IQ1 and IQ2
probBetw = norm.cdf(IQ2, loc=mean_IQ, scale=std_IQ) - norm.cdf(IQ1, loc=mean_IQ, scale=std_IQ)

# Calculate the probability that you toss a coin Coin2 times, and you have Coin1 heads
probEqual = binom.pmf(Coin1, Coin2, 0.5)

# Calculate the probability that you toss a coin Coin2 times, and you have at least Coin1 heads
probAtLeast = 1 - binom.cdf(Coin1 - 1, Coin2, 0.5)

print("The probability that a randomly selected person \n has an IQ less than or equal to " + str(IQ1) + " is ", end="")
print('%.3f' % probLT + ".")
print("The probability that a randomly selected person \n has an IQ between " + str(IQ1) + " and " + str(IQ2)+ " is ", end="")
print('%.3f' % probBetw + ".")
print("The probability that you toss a coin " + str(Coin2) + " times, and you have " + str(Coin1) + " heads" + " is ", end="")
print('%.3f' % probEqual + ".")
print("The probability that you toss a coin " + str(Coin2) + " times, and you have at least " + str(Coin1) + " heads" + " is ", end="")
print('%.3f' % probAtLeast + ".")
