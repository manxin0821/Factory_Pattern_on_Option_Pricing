# Option pricing with binomial tree

This project is to price the vanilla option with binomial tree. A factory pattern is used to add new pay-offs without changing any files. 

When start the program, the user need to type in a pay-off name (eg. "call" in this question) and the prices from the two required constructions will be calculated based on this payoff function.

When new payoff function is added in, please add the namespace into file "PayOffConstructible.cpp".

The factory pattern idea and related codes are from Ch10 "C++ Design Patterns and Derivatives Pricing" by Mark Joshi.

## File Structure
- PayFactoryMain.cpp : Main function.
- Binomial.cpp : Calculate the option fair value using binomial tree.
- PayOff.cpp : European call option payoff function. (Joshi, 2002)
- PayOffBridge.cpp : A pointer to an option payoff. (Joshi, 2002)
- PayOffConstructible.cpp : Create a payoff object of the relevant type and return a pointer to it. (Joshi, 2002)
- PayOffFactory.cpp: Factory pattern. (Joshi, 2002)
