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
    virtual ~Option(){};

    void set_maturity(double maturity);
    double get_maturity() const;

    void set_strikePrice(double strikePrice);
    double get_strikePrice() const;

    virtual double payoff(double maturityPrice);
    virtual double price(const BlackScholes& BS);

};

class Call : public Option {

    public:

    ~Call(){};

    double payoff(double maturityPrice);
    double price(const BlackScholes& BS);


};

class Put : public Option {

    public:

    ~Put(){};

    double payoff(double maturityPrice);
    double price(const BlackScholes& BS);


};

#endif