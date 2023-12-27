#ifndef BSMODEL_CPP
#define BSMODEL_CPP

#include"BSmodel.h"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

// Constructors


BlackScholes::BlackScholes(){

};


BlackScholes::BlackScholes(double time, double stockPrice, double volatility,double drift, double riskFreeRate){

        this->time = time;
        this->stockPrice = stockPrice; 
        this->volatility = volatility;
        this->drift = drift;
        this->riskFreeRate = riskFreeRate;
};



// Getters

void BlackScholes::set_time(double time){this->time = time;};
double BlackScholes::get_time() const {return time;};


void BlackScholes::set_stockPrice(double stockPrice){this->stockPrice = stockPrice;};
double BlackScholes::get_stockPrice() const {return stockPrice;};


void BlackScholes::set_volatility(double volatility){this->volatility = volatility;};
double BlackScholes::get_volatility() const {return volatility;};


void BlackScholes::set_drift(double drift){this->drift = drift;};
double BlackScholes::get_drift() const {return drift;};


void BlackScholes::set_riskFreeRate(double riskFreeRate){this->riskFreeRate = riskFreeRate;};
double BlackScholes::get_riskFreeRate() const {return riskFreeRate;};

// Price Path

std::vector<double> BlackScholes::pricePath(double date, int steps){

    double dt=(date-time)/steps;

    // vector of steps+1 elements since the actual price is known and we compute 'steps' more prices
    std::vector<double> prices(steps+1,stockPrice);
     
    // Initialize the random number generator
    std::random_device rd; // seed
    std::mt19937 gen(rd()); 
    std::normal_distribution<double> distribution(0.0, 1.0);

    double term1 =(riskFreeRate-0.5*volatility*volatility)*dt;
    double term2 = volatility*std::sqrt(dt);

    for(int i=1;i<steps+1;i++){
        // Random Number ~ N(0,1)
        double eps = distribution(gen);
        prices[i] = prices[i-1]*std::exp(term1 + term2*eps);
    }
    
    return prices;

}


#endif