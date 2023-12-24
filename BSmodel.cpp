#ifndef BSMODEL_CPP
#define BSMODEL_CPP

#include"BSmodel.h"
#include <iostream>


// Constructors


BlackScholes::BlackScholes(){

};


BlackScholes::BlackScholes(double time, double stockPrice, double volatility,
    double drift, double riskFreeRate){

        this->time = time;
        this->stockPrice = stockPrice; 
        this->volatility = volatility;
        this->drift = drift;
        this->riskFreeRate = riskFreeRate;
};



// Getters

void BlackScholes::set_time(double time){this->time = time;};
double BlackScholes::get_time() const {return time;};


void BlackScholes::set_stockPrice(double time){this->stockPrice = stockPrice;};
double BlackScholes::get_stockPrice() const {return stockPrice;};


void BlackScholes::set_volatility(double volatility){this->volatility = volatility;};
double BlackScholes::get_volatility() const {return volatility;};


void BlackScholes::set_drift(double drift){this->drift = drift;};
double BlackScholes::get_drift() const {return drift;};


void BlackScholes::set_riskFreeRate(double riskFreeRate){this->riskFreeRate = riskFreeRate;};
double BlackScholes::get_riskFreeRate() const {return riskFreeRate;};




#endif