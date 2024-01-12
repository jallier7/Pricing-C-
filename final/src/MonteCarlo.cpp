#ifndef MONTECARLO_CPP
#define MONTECARLO_CPP

#include "../include/Option.h"
#include "../include/BSmodel.h"
#include "../include/MonteCarlo.h"
#include <cmath>


// Constructors

MonteCarlo::MonteCarlo(){};
MonteCarlo::MonteCarlo(int nbrPaths, int nbrSteps){
    this->nbrPaths = nbrPaths; 
    this->nbrSteps = nbrSteps;
}

// Getters

int MonteCarlo::get_nbrPaths() const {return nbrPaths;}
void MonteCarlo::set_nbrPaths(int nbrPaths){this->nbrPaths = nbrPaths;}

int MonteCarlo::get_nbrSteps() const {return nbrSteps;}
void MonteCarlo::set_nbrSteps(int nbrSteps){this->nbrSteps = nbrSteps;}


// Method



/**
 * @brief Computes the price of an European contract at time (defined in BS model) using MonteCarlo simulations.
 *
 * @param opt Contract model (either Call or Put).
 * @param BS BlackScholes model for the underlying asset.
 * @return An array containing the estimated price of the contract price at defined time along with the error of the simulation.
 */
std::array<double, 2> MonteCarlo::pricing(const Option& opt, const BlackScholes& BS) const {

    // For Price Path
    std::vector<double> PricePath;
    double date=opt.get_maturity();
    double maturityPrice; 
    
    
    // For Average result and Error
    double payoffAvg =0;
    double payoffSumSqr=0;

    // Verbose
    std::cout<<"Starting..."<<std::endl;
    int lastPrintedProgress = -1;

    for(int i=0; i<nbrPaths; i++){

        PricePath = BS.pricePathNeutral(date,nbrSteps);
        double maturityPayOff = opt.payoff(PricePath.back());
        payoffAvg += maturityPayOff;
        payoffSumSqr += maturityPayOff*maturityPayOff;
    
        // Calculate progress percentage
        int progress = static_cast<int>((static_cast<double>(i + 1) / nbrPaths) * 100);

        // Check if it's time to print a progress message
        if (progress % 10 == 0 && progress != lastPrintedProgress) {
            std::cout << "Progress: " << progress << "%" << std::endl;
            lastPrintedProgress = progress;
        }
    
};

    // Compute the variance

    double mean = payoffAvg/nbrPaths;
    double variance = payoffSumSqr/nbrPaths - mean*mean;
    double standardError = std::sqrt(variance) / std::sqrt(nbrPaths);

    // Compute the current price of the contract

    double currentPrice; 
    currentPrice = std::exp(-BS.get_riskFreeRate()*(date-BS.get_time()))*payoffAvg/nbrPaths;


    // Return an array containing the current price of the contract along with the error of the simulation
    
    std::array<double, 2> result;
    result[0]=currentPrice; 
    result[1]=standardError;
    
    std::cout<<"Finished."<<std::endl;

    return result;

}



#endif