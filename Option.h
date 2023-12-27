#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include "BSmodel.h"

class Option{

    private:

    double maturity;
    double strikePrice;

    public:

    Option();
    Option(double maturity, double strikePrice);
    virtual ~Option();


    void set_maturity(double maturity);
    double get_maturity() const;

    void set_strikePrice(double strikePrice);
    double get_strikePrice() const;

    virtual double payoff(double maturityPrice) const=0;
    virtual double price(const BlackScholes& BS) const=0;

};

class EuroCall : public Option {

    public:

    EuroCall();
    EuroCall(double maturity, double strikePrice);
    ~EuroCall();

    double payoff(double maturityPrice) const;
    double price(const BlackScholes& BS) const;


};

class EuroPut : public Option {

    public:

    EuroPut();
    EuroPut(double maturity, double strikePrice);
    ~EuroPut();

    double payoff(double maturityPrice) const;
    double price(const BlackScholes& BS) const;


};

#endif