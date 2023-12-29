#ifndef OPTION_CPP
#define OPTION_CPP

#include <cmath>
#include <iostream>
#include <algorithm>
#include "Option.h"
#include "BSmodel.h"
#include "Binomialmodel.h"

using namespace std;

//// CDF for Price ////

double norm_cdf(double x) {
    return 0.5 * std::erfc(-x * M_SQRT1_2);
};


//// OPTION ////

Option::Option(){
};

Option::~Option(){

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

EuroCall::EuroCall(){};

EuroCall::~EuroCall(){};

EuroCall::EuroCall(double maturity, double strikePrice): Option(maturity,strikePrice){};

double EuroCall::payoff(double maturityPrice) const {
    double strike = get_strikePrice();
    return std::max<double>(maturityPrice-strike,0);
};

double EuroCall::price(const BlackScholes& BS) const {

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

EuroPut::EuroPut(){
};

EuroPut::~EuroPut(){
};

EuroPut::EuroPut(double maturity, double strikePrice): Option(maturity,strikePrice){};

double EuroPut::payoff(double maturityPrice) const {
    double strike = get_strikePrice();
    return std::max<double>(strike-maturityPrice,0);
};

double EuroPut::price(const BlackScholes& BS) const {

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


//// AmeriCall ////

AmeriCall::AmeriCall(){};

AmeriCall::~AmeriCall(){};

AmeriCall::AmeriCall(double maturity, double strikePrice): Option(maturity,strikePrice){};

double AmeriCall::payoff(double Price) const {
    double strike = get_strikePrice();
    return std::max<double>(Price-strike,0);
};
double AmeriCall::price(const BlackScholes& BS, int numSteps) const {
    // Create a BinomialModel object
    // Note: You'll need to determine the appropriate parameters (e.g., numSteps)
    BinomialModel binomialModel(BS.get_stockPrice(), BS.get_riskFreeRate(), 
                                BS.get_volatility(), get_maturity() - BS.get_time(), 
                                numSteps, true); // true for American option

    // Call priceOption method
    return binomialModel.priceOption(*this);}

//// AmeriPut ////

AmeriPut::AmeriPut(){};

AmeriPut::~AmeriPut(){};

AmeriPut::AmeriPut(double maturity, double strikePrice): Option(maturity,strikePrice){};

double AmeriPut::payoff(double Price) const {
    double strike = get_strikePrice();
    return std::max<double>(strike-Price,0);
};
double AmeriPut::price(const BlackScholes& BS, int numSteps) const {
    BinomialModel binomialModel(BS.get_stockPrice(), BS.get_riskFreeRate(), 
                                BS.get_volatility(), get_maturity() - BS.get_time(), 
                                numSteps, true); // Use appropriate numSteps

    return binomialModel.priceOption(*this); // Passing the current object
}

#endif