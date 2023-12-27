#ifndef MONTECARLO_CPP
#define MONTECARLO_CPP

#include "Option.h"
#include "BSmodel.h"
#include "MonteCarlo.h"
#include <cmath>


// Const.

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

double MonteCarlo::pricing(const Option& opt, const BlackScholes& BS) const {

    std::vector<double> PricePath;
    double date=opt.get_maturity();
    double maturityPrice; 
    double payoffAvg =0;

    for(int i=0; i<nbrPaths; i++){

        PricePath = BS.pricePath(date,nbrSteps);
        payoffAvg += opt.payoff(PricePath.back());

    };

    double currentPrice; 
    currentPrice = std::exp(-BS.get_riskFreeRate()*(date-BS.get_time()))*payoffAvg/nbrPaths;

    return currentPrice;

}



#endif