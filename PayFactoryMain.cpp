//
//  PayFactoryMain.cpp
//
//  Created by man xin on 2019-04-03.
//  Copyright © 2019 man xin. All rights reserved.

// This project is to price the vanilla option with binomial tree. A factory pattern is used to add new pay-offs without changing any files. When start the program, the user would type the name of the pay-off and the prices based on two required constructions will be calculated based on this payoff function. When new payoff function is added in, please add the namespace into file PayOffConstructible.cpp. The factory pattern idea and related codes are from Ch10 C++ Design Patterns and Derivatives Pricing by Mark Joshi.

#include "PayOff.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include "Binomial.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Q1 parameters
    double S0=100.,Sigma=0.2,K=100.,T=1;
    
    //input which payoff function to use
    std::string name;
    //name="call";
    cout << "\npay-off name (eg, call) \n";
    cin >> name;
    
    PayOff* PayOffPtr =PayOffFactory::Instance().CreatePayOff(name,K);

    std::fstream fs;
    fs.open ("/Users/manxin/Dropbox/FinCad/binomialTree.csv", std::fstream::in | std::fstream::out | std::fstream::app);

    for (int N=1; N<=1000; N++)
    {
        Binomial Tree=Binomial(S0, Sigma, N, T);
        fs<<Tree.GetPQ05FV(PayOffPtr)<<","<<Tree.GetUD1FV(PayOffPtr)<<"\n";
    }
    fs.close();
    
    delete PayOffPtr;

    return 0;
}
