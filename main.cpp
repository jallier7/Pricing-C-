#include <iostream>
#include <vector>
#include <tuple>

#include "Option.h"
#include "BinomialModel.h"

// Define a struct to hold the results
struct OptionPricingResult {
    double spotPrice;
    double strikePrice;
    double maturity;
    double interestRate;
    double volatility;
    double euroCallPrice;
    double euroPutPrice;
    double ameriCallPrice;
    double ameriPutPrice;
};

int main() {
    std::vector<double> strikePrices = {90, 95, 100, 105, 110};
    std::vector<double> maturities = {1, 2, 5};
    std::vector<double> interestRates = {0.01, 0.02, 0.05};
    std::vector<double> volatilities = {0.1, 0.2, 0.3};
    double spotPrice = 100;
    int numSteps = 100;

    std::vector<OptionPricingResult> results;

    for (double strikePrice : strikePrices) {
        for (double maturity : maturities) {
            for (double interestRate : interestRates) {
                for (double volatility : volatilities) {
                    EuroCall euroCall(maturity, strikePrice);
                    EuroPut euroPut(maturity, strikePrice);
                    BinomialModel binomialModelEuro(spotPrice, interestRate, volatility, maturity, numSteps, false);
                    BinomialModel binomialModelAmeri(spotPrice, interestRate, volatility, maturity, numSteps, true);

                    OptionPricingResult result;
                    result.spotPrice = spotPrice;
                    result.strikePrice = strikePrice;
                    result.maturity = maturity;
                    result.interestRate = interestRate;
                    result.volatility = volatility;
                    result.euroCallPrice = binomialModelEuro.priceOption(euroCall);
                    result.euroPutPrice = binomialModelEuro.priceOption(euroPut);
                    result.ameriCallPrice = binomialModelAmeri.priceOption(euroCall);
                    result.ameriPutPrice = binomialModelAmeri.priceOption(euroPut);

                    results.push_back(result);
                }
            }
        }
    }

    // Output the results
    for (const auto& res : results) {
        std::cout << "Spot Price: " << res.spotPrice
                  << ", Strike Price: " << res.strikePrice
                  << ", Maturity: " << res.maturity
                  << ", Interest Rate: " << res.interestRate
                  << ", Volatility: " << res.volatility
                  << ", European Call Price: " << res.euroCallPrice
                  << ", European Put Price: " << res.euroPutPrice
                  << ", American Call Price: " << res.ameriCallPrice
                  << ", American Put Price: " << res.ameriPutPrice
                  << std::endl;
    }
    
    return 0;
}



