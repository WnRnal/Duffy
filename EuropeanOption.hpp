#pragma once
#include <string>
using namespace std;
#include"Nfunc.hpp"
#define EuropeanOption_HPP

class EuropeanOption {
private:
	void init();
	void copy(const EuropeanOption& o2);

	//Kernel functions
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;

public:
	double r;	//interest rate
	double sig;	//volatility
	double K;	//strike price
	double T;	//Expiry date (Maturity)
	double U;	//Current price of underlying asset
	double b;	//Cost of carry

	string optType;	//Option name (call / put)

public:
	//constructor
	EuropeanOption();	//default call of option
	EuropeanOption(const EuropeanOption& option2);	//copy constructor
	EuropeanOption(const string& optionType);	//Create option type

	//destructor
	virtual ~EuropeanOption();

	//Assignment operator
	EuropeanOption& operator = (const EuropeanOption& option2);

	//Functions that calculate option price and (some) sensitivities
	double Price() const;
	double Delta() const;

	//Modifier functions
	void toggle();	//Change option type (C/P, P/C)
};
