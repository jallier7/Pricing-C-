#ifndef OPTION_CPP
#define OPTION_CPP

#include <cmath>
#include <iostream>
#include <algorithm>
#include "Option.h"
#include "BSmodel.h"

using namespace std;

//// CDF for Price ////

double norm_cdf(double x) {
    return 0.5 * std::erfc(-x * M_SQRT1_2);
};


//// OPTION ////

Option::Option(){

};

Option::Option(double maturity, double strikePrice){
    this->maturity = maturity;    
    this->strikePrice = strikePrice;
};

// Getters

void Option::set_maturity(double maturity){this->maturity = maturity;};
double Option::get_maturity() const {return maturity;};


void Option::set_strikePrice(double strikePrice){this->strikePrice = strikePrice;};
double Option::get_strikePrice() const {return strikePrice;};



//// EuroCall ////

double EuroCall::payoff(double maturityPrice){
    double strike = get_strikePrice();
    return std::max<double>(maturityPrice-strike,0);
};

double EuroCall::price(const BlackScholes& BS){

    double tau = get_maturity()- BS.get_time(); // time left to maturity
    double stockPrice = BS.get_stockPrice();
    double volatility = BS.get_volatility();
    double riskFreeRate = BS.get_riskFreeRate();
    double strike = get_strikePrice();

    double d1 = (std::log(stockPrice / strike) + (riskFreeRate + 0.5 * volatility * volatility) * tau) / (volatility * std::sqrt(tau));
    double d2 = d1 - volatility * std::sqrt(tau);

    double P = stockPrice * norm_cdf(d1) - strike * std::exp(-riskFreeRate * tau) * norm_cdf(d2);
    return P;
};



//// EuroPut ////

double EuroPut::payoff(double maturityPrice){
    double strike = get_strikePrice();
    return std::max<double>(strike-maturityPrice,0);
};

double EuroPut::price(const BlackScholes& BS){

    double tau = get_maturity()- BS.get_time(); // time left to maturity
    double stockPrice = BS.get_stockPrice();
    double volatility = BS.get_volatility();
    double riskFreeRate = BS.get_riskFreeRate();
    double strike = get_strikePrice();

    double d1 = (std::log(stockPrice / strike) + (riskFreeRate + 0.5 * volatility * volatility) * tau) / (volatility * std::sqrt(tau));
    double d2 = d1 - volatility * std::sqrt(tau);

    double P = stockPrice * (norm_cdf(d1)-1) - strike * std::exp(-riskFreeRate * tau) * (norm_cdf(d2)-1);
    return P;
};

#endif