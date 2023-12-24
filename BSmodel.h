#ifndef BSMODEL_H
#define BSMODEL_H

#include <iostream>
#include <vector>

class BlackScholes{

    private:

    double time;
    double stockPrice;
    double volatility;
    double drift;
    double riskFreeRate;

    public:

    BlackScholes();
    BlackScholes(double time, double stockPrice, double volatility,
    double drift, double riskFreeRate);


    void set_time(double time);
    double get_time() const;

    void set_stockPrice(double stockPrice);
    double get_stockPrice() const;

    void set_volatility(double volatility);
    double get_volatility() const;

    void set_drift(double drift);
    double get_drift() const;

    void set_riskFreeRate(double riskFreeRate);
    double get_riskFreeRate() const;

    std::vector<double> pricePath(double date, int steps);


};

#endif