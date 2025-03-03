**CSE 5160 Machine Learning
Dr. Haiyan Qiao

Giovanni Almaraz, Doug Fry, Zachary Hampton
01-02-2025

Part A
Question 1:

Question 6:
Our givens are β_0 = -6, β_1 = 0.05, β_2 = 1
a) Estimate the probability that a student who studies for 40 hours and has a GPA of 3.5 gets an A: P(Y=1) = (1+e(−6+0.05(40)+1(3.5)) / (e(−6+0.05(40)+1(3.5))
The probability that a student who studies for 40 hours and has an undergrad GPA of 3.5 gets an A is approximately 0.378 (37.8%).

b) We set P(Y=1) = 0.5 and solve for X_1 we get X_1 = (2.5)/0.05
To have a 50% chance of getting an A in the class, the student would need to study 50 hours.

Question 8:
We have two classification methods:

1. Logistic Regression:
   * Training error: 20%
   * Test error: 30%
2. 1-Nearest Neighbor (K=1):

* Average error : 18%

### Logistic Regression Is Better

Even though KNN (K=1) has a lower average error, it is prone to overfitting and does not generalize well. Logistic regression, despite having a higher test error, is more stable and interpretable.

Thus, logistic regression is the better choice for classifying new observations in this case. However, using a better K value (e.g., K=5 or K=10) for KNN might improve its performance.

Part B:
Question 1
a) Screenshot down below.

b) We analyze statistical significance using p-values from the logistic regression model. Predictors with high p-values (above 0.05 or 0.1) contribute less to the model and should be removed.

c) We refit the model with only Lag1 and Lag2: Using the test dataset (Year=2005\text{Year} = 2005Year=2005), we recompute the test error rate.

 d) We use the logistic function to compute the probability: This means that given Lag1 = 2.1 and Lag2 = -0.5, the probability that the market will go up is 57%.

Question 2:
a) LDA calculates the prior probabilities based on the training dataset (Year<2005\text{Year} < 2005Year<2005) so this means This means that, historically, the market has gone UP about 53% of the time and DOWN about 47% of the time in the training data.

b) When the market goes UP, the previous day's return Lag 1tends to be slightly positive (0.06%).

When the market goes DOWN, the previous day's return Lag1 is slightly negative (-0.08%).

c) While using a 70% threshold makes predictions more conservative, it reduces recall misses UP predictions that were only slightly above 50%

Screenshots:

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfXzkWkTJo4EMRG_XnAZDir4nFsazjMeiCREs4u9iBUUXPEKG32vTKv6Avh2JKSIvQ694ZOq4gaPTpoVN4p-KL0ksUnYxM4UnsFcexThh8jB02ELUvYmxLlzYzYWOQE6KgedoR42w?key=OipumJmSi_ZfD-8LkmD30TsU)![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdWvEMNeSZAkQqUfiaKEzCXCecHXzC7p-T6PjS2ofWy-v6lL3MPj0j_d1_V7HDmtoGCkCLAmeIMqcGBtTRWPFngqnT1YNWtjt1-ligxruOtYlCAlGhqu-Y-JDb9esefCRFA_cUzmA?key=OipumJmSi_ZfD-8LkmD30TsU)![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfa8tJ0DFgnPoKv7RVAVB2TI5kxuwqd-oYtah11a9W67CWdie_G1GSkblI4XTt5VSa544f3DvbW_yVN1kH2fcRn2cVNTde_K49fNLxbB4IdUEtNnpMrvJBpsZnmZyYlzUcrnc7N8Q?key=OipumJmSi_ZfD-8LkmD30TsU)

**
