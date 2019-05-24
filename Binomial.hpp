//
//  Binomial.hpp
//
//  Created by man xin on 2019-04-03.
//  Copyright © 2019 man xin. All rights reserved.

#ifndef Binomial_hpp
#define Binomial_hpp

#include <stdio.h>
#include <stdio.h>
//#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include <vector>

class Binomial{
public:
    Binomial(double _S0,double _Sigma,unsigned int _N,double _T);
    
    double GetPQ05FV(const PayOff* PayOff);
    double GetUD1FV(const PayOff* PayOff);
    
private:
    double GetPrice(const PayOff* PayOff,double p,double q,double u,double d);
    
protected:
    double S0;
    double Sigma;
    int N;
    double T;
    
    double p;
    double q;
    double u;
    double d;
    
};

#endif /* Binomial_hpp */
