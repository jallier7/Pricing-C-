#ifndef BINOMIAL_MODEL_H
#define BINOMIAL_MODEL_H

#include "Option.h"

// BinomialModel class for pricing options using the binomial method
class BinomialModel {
public:
    // Constructor with parameters necessary for the binomial model
    BinomialModel(double spotPrice, double interestRate, double volatility, 
                  double timeToMaturity, int numSteps, bool isAmerican);

    // Method to price an option (either Call or Put) using the binomial model
    double priceOption(const Option& option);

private:
    double spotPrice;         // Current price of the underlying asset
    double interestRate;      // Risk-free interest rate
    double volatility;        // Volatility of the underlying asset
    double timeToMaturity;    // Time remaining until option's maturity
    int numSteps;             // Number of steps in the binomial tree
    bool isAmerican;          // Indicates if the option is American (true) or European (false)

    // Private method to calculate the option price
    double calculateOptionPrice(const Option& option);
};

#endif // BINOMIAL_MODEL_H
