#include <iostream>
#include "Option.h"
#include "BSmodel.h"
#include "MonteCarlo.h"

int main(){

    EuroPut put(2.0,40.0);
    BlackScholes asset(0,40,0.3,1,0.03);
    MonteCarlo MC(1000,100000);
    

    double mat=put.get_maturity();
    double strike=put.get_strikePrice();
    double p=put.price(asset);

    double mcPrice=MC.pricing(put,asset);

    std::cout<<"Theoretical Price: "<<p<<std::endl;
    std::cout<<"MonteCarlo Price: "<<mcPrice<<std::endl;

    return 0;
}
