#include <iostream>
#include "Option.h"
#include "BinomialModel.h"

int main() {
    // Parameters for the options and the model
    double spotPrice = 100; // Example spot price of the underlying asset
    double strikePrice = 100; // Example strike price
    double maturity = 1; // Time to maturity in years
    double interestRate = 0.05; // Risk-free interest rate
    double volatility = 0.2; // Volatility of the underlying asset
    int numSteps = 100; // Number of steps in the binomial model

    // Create the European Call and Put options
    EuroCall euroCall(maturity, strikePrice);
    EuroPut euroPut(maturity, strikePrice);

    // Create BinomialModel instances for European and American options
    BinomialModel binomialModelEuro(spotPrice, interestRate, volatility, maturity, numSteps, false); // false for European
    BinomialModel binomialModelAmeri(spotPrice, interestRate, volatility, maturity, numSteps, true); // true for American

    // Pricing European options
    double euroCallPrice = binomialModelEuro.priceOption(euroCall);
    double euroPutPrice = binomialModelEuro.priceOption(euroPut);

    // Pricing American options (assuming EuroCall and EuroPut can be used for American options)
    double ameriCallPrice = binomialModelAmeri.priceOption(euroCall); // Use EuroCall for American option pricing
    double ameriPutPrice = binomialModelAmeri.priceOption(euroPut);   // Use EuroPut for American option pricing

    // Output the results
    std::cout << "European Call Option Price: " << euroCallPrice << std::endl;
    std::cout << "European Put Option Price: " << euroPutPrice << std::endl;
    std::cout << "American Call Option Price: " << ameriCallPrice << std::endl;
    std::cout << "American Put Option Price: " << ameriPutPrice << std::endl;

    return 0;
}

