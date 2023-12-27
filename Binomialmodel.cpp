#include "Binomialmodel.h"
#include <cmath>
#include <algorithm>
#include <vector>

// Constructor for the Binomial model class
BinomialModel::BinomialModel(double spotPrice, double interestRate, double volatility, 
                             double timeToMaturity, int numSteps, bool isAmerican)
    : spotPrice(spotPrice), interestRate(interestRate), volatility(volatility), 
      timeToMaturity(timeToMaturity), numSteps(numSteps), isAmerican(isAmerican) {}

// Private method to calculate the price of an option
double BinomialModel::calculateOptionPrice(const Option& option) {
    // Set up the parameters of the binomial tree
    double dt = timeToMaturity / numSteps;            // Duration of one step
    double upFactor = exp(volatility * sqrt(dt));     // Upward price movement factor
    double downFactor = 1 / upFactor;                 // Downward price movement factor
    double discountFactor = exp(-interestRate * dt);  // Discount factor
    double q = (exp(interestRate * dt) - downFactor) / (upFactor - downFactor); // Risk-neutral probability

    // Initialize the vector to store option values at expiration
    std::vector<double> optionValues(numSteps + 1);

    // Calculate the option values at expiration for each final node
    for (int i = 0; i <= numSteps; ++i) {
        double stockPriceAtNode = spotPrice * pow(upFactor, numSteps - i) * pow(downFactor, i);
        optionValues[i] = option.payoff(stockPriceAtNode);
    }

    // Backward induction through the tree to calculate the option's present value
    for (int step = numSteps - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            optionValues[i] = discountFactor * (q * optionValues[i] + (1 - q) * optionValues[i + 1]);

            // For American options, check for early exercise
            if (isAmerican) {
                double stockPriceAtNode = spotPrice * pow(upFactor, step - i) * pow(downFactor, i);
                optionValues[i] = std::max(optionValues[i], option.payoff(stockPriceAtNode));
            }
        }
    }

    return optionValues[0]; // Return the current value of the option
}

// Implementation of priceOption() calling calculateOptionPrice()
double BinomialModel::priceOption(const Option& option) {
    return calculateOptionPrice(option);
}
