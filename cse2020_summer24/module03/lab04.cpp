/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 04
 * Date: June 10, 2024
 * 
 * This program compares the execution time of two functions that calculate the sum of a geometric series.
 * The first function uses nested loops to calculate the sum, while the second function uses a single loop.
 * The second function uses Horner's rule to calculate the sum.
 * The program prompts the user to enter the base x and the number of terms n in the series.
 * The program then calculates the sum using both functions and displays the results along with the execution times.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// Function to calculate geometric series sum using nested loops
double geom_sum1 (int x, int n) {
    double result = 0;
    // Loop over series terms
    for (int i = 0; i <= n; i++) {
        double xpow = 1;  // To hold powers of x
        // Compute power of x using a nested loop
        for (int j = 0; j < i; j++)
            xpow *= x;
        // Sum the powers of x
        result += xpow;
    }
    return result;
}

// Function to calculate geometric series sum using Horner's rule
double geom_sum2 (int x, int n) {
    double result = 0;
    // Efficiently calculate the sum using Horner's rule
    for (int i = 0; i <= n; i++) {
        result = result * x + 1;
    }
    return result;
}

// Main function to test the two geometric sum calculation functions
int main() {
    int x = 1;
    int n = 1;

    // Prompt the user for input values
    cout << "Please enter x: ";
    cin >> x;
    cout << "Please enter n: ";
    cin >> n;

    // Calculate and display the sum and execution time for geom_sum1
    using clock = chrono::steady_clock;
    
    clock::time_point start = clock::now();  // Record start time
    cout << geom_sum1(x, n) << endl;  // Display the sum
    clock::time_point end = clock::now();  // Record end time
    
    clock::duration time_span = end - start;  // Calculate duration
    double nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
    cout << "The execution time is : " << nseconds << endl;
        
    // Calculate and display the sum and execution time for geom_sum2
    start = clock::now();
    cout << geom_sum2(x, n) << endl;
    end = clock::now();

    time_span = end - start;  // Calculate duration for geom_sum2
    nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
    cout << "The execution time is : " << nseconds;

    return 0;
}
