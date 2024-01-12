#include <iostream>
#include <vector>
#include <fstream>

#include "./include/Option.h"
#include "./include/Binomialmodel.h"

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
    std::vector<double> strikePrices = {100};
    std::vector<double> maturities = {1,};
    std::vector<double> interestRates = {0.01};
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

    // Create and open a file
    std::ofstream outFile("option_pricing_results4.csv");

    // Write the header
    outFile << "Spot Price,Strike Price,Maturity,Interest Rate,Volatility,Euro Call Price,Euro Put Price,American Call Price,American Put Price\n";

    // Write data
    for (const auto& res : results) {
        outFile << res.spotPrice << ","
                << res.strikePrice << ","
                << res.maturity << ","
                << res.interestRate << ","
                << res.volatility << ","
                << res.euroCallPrice << ","
                << res.euroPutPrice << ","
                << res.ameriCallPrice << ","
                << res.ameriPutPrice << "\n";
    }

    // Close the file
    outFile.close();

    std::cout << "CSV file created: option_pricing_results.csv" << std::endl;

    return 0;
}


