#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "Option.h"
#include "BSmodel.h"


class MonteCarlo{

    private:

    int nbrSteps;
    int nbrPaths; 

    public:

    MonteCarlo();
    MonteCarlo(int nbrSteps, int nbrPaths);
    ~MonteCarlo(){};

    void set_nbrSteps(int nbrSteps);
    int get_nbrSteps() const;

    void set_nbrPaths(int nbrPaths);
    int get_nbrPaths() const;

    double pricing(const Option& opt, const BlackScholes& BS) const;

};


#endif