#include <iostream>
#include "./include/Option.h"
#include "./include/BSmodel.h"
#include "./include/MonteCarlo.h"
#include "./include/Binomialmodel.h"

int main(){

    // Parameters for the Asset in BlackScholes Model

    double time = 0;
    double stockPrice = 40.0;
    double volatility = 0.1;
    double drift = 0.01;
    double riskFreeRate = 0.03;

    BlackScholes asset(time,stockPrice,volatility,drift,riskFreeRate); // Creation of the asset

    // Parameters for the Contract

    double maturity = 2.0;
    double strikePrice = 40.0;


    EuroPut put(maturity,strikePrice); // Creation of the European Put


    // Parameters for the MonteCarlo Princing method

    int nbrSteps = 1000;
    int nbrPaths = 100000;
    
    MonteCarlo MC(nbrSteps,nbrPaths); // Creation of the MC class
    


    // Computation of the financial instrument's price 

    double p=put.price(asset);
    std::array<double, 2> mcResults=MC.pricing(put,asset);

    std::cout<<"Theoretical Price: "<<p<<std::endl;
    std::cout<<"MonteCarlo Price: "<<mcResults[0]<<" +/- "<<mcResults[1]<<std::endl;

    return 0;
}
