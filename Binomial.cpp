//
//  Binomial.cpp
//
//  Created by man xin on 2019-04-03.
//  Copyright © 2019 man xin. All rights reserved.
//

#include "Binomial.hpp"
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

Binomial::Binomial(double _S0,double _Sigma,unsigned int _N,double _T):S0(_S0),Sigma(_Sigma),N(_N),T(_T){

}

double Binomial::GetUD1FV(const PayOff* PayOff){
    double FV;
    //set parameters
    u=exp(Sigma*sqrt(T/N));
    d=1/u;
    p=(1-d)/(u-d);
    q=1-p;
    
    FV=GetPrice(PayOff,p,q,u,d);
    return FV;
}

double Binomial::GetPQ05FV(const PayOff* PayOff){

    double FV;
    //set parameters
    p=.5;
    q=.5;
    d=1-Sigma*sqrt(T/N);
    u=1+Sigma*sqrt(T/N);
    
    FV=GetPrice(PayOff,p,q,u,d);
    
    return FV;
    
}

//Return the option present value from the binomial tree
double Binomial::GetPrice(const PayOff* PayOffPtr,double p,double q,double u,double d){
    vector<vector<double>> stockPrice(N+1,vector<double>(N+1));
    vector<vector<double>> optionValue(N+1,vector<double>(N+1));
    
    //setup and initialise the stock and option value
    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            stockPrice[i][j]=S0*pow(u,j)*pow(d,i-j);
        }
    }
    for(int j=0;j<=N;j++){
        optionValue[N][j]=PayOffPtr->operator ()(stockPrice[N][j]);
    }
    //earlier steps
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            optionValue[i][j] =p*optionValue[i+1][j+1] + q*optionValue[i+1][j];
        }
    }
    return optionValue[0][0];
}


