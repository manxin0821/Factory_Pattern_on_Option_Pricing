/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
 */

#include "PayOff.h"
#include <algorithm>


PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
    
}

double PayOffCall::operator() (double Spot) const
{
    return std::max(Spot - Strike,0.0);
}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this); // return a copy of current payoff class
}

