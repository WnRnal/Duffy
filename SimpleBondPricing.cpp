#pragma once

#define SimpleBondPricing_CPP
#include "SimpleBondPricing.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;
//using namespace Chapter3CPPBook;
// 안쓰는게 맞았음.

typedef vector<double> Vector;
namespace Chapter3CPPBook { // namespace Chapter3CPPBook {} 안해줘서 시간 날렸음!!!!!!!!!!
	// Recursive function to calculate power of a number. This
	// function calls itself, either directly or indirectly 
	double power(double d, long n) {
		if (n == 0) return 1.0;
		if (n == 1) return d;
		double result = d;
		for (long j = 1; j < n; j++)
			result *= d;
		return result;
	}

	// Future value of a sum of money invested today
	double FutureValue(double P0, long nPeriods, double r) {
		double factor = 1.0 + r;
		return P0 * power(factor, nPeriods);
	}

	// Future value of a sum of money invested today, m periods (days) ***
	// per year. r is annual interest rate
	double FutureValue(double P0, long nPeriods, double r, long m) {
		double factor = 1.0 + r / m;
		return P0 * power(factor, nPeriods*m);
	}

	// Continuous compounding, i.e. limit as m->INFINITY ***
	double FutureValueContinuous(double P0, long nPeriods, double r) {
		double factor = 1.0 + r / 250;
		return P0 * power(factor, nPeriods * 250);
	}

	// Future value of an ordinary annuity ***
	double OrdinaryAnnuity(double A, long nPeriods, double r) {
		return A * (power(1.0 + r, nPeriods) - 1) / r;
	}

	// Present Value of a series of future values ***
	double PresentValue(double Pn, long nPeriods, double r) {
		double factor = 1.0 + r;
		return Pn / power(factor, nPeriods);
	}

	// Present Value of a series of future values
	double PresentValue(const Vector& prices, long nPeriods, double r) {
		//Number of periods MUST == size of the vector. (nPeriods와 참조한 period별 prices data의 개수가 같음을 확인)
		assert(nPeriods == prices.size());

		double factor = 1.0 + r;

		double PV = 0.0;
		for (long t = 0; t < nPeriods; t++)
			PV += prices[t] / power(factor, t + 1);
		return PV;
	}


	//Present Value of an ordinary annuity ***
	double PresentValueOrdinaryAnnuity(double A, long nPer, double r) {
		long n = nPer;
		Vector* prices = new Vector[n]{ static_cast<Vector>(A) };
		/*for (long t = 0; t < n; t++)
			prices[t] = (Vector)A;
		}*/
		Vector const &P = *prices;
		double result = PresentValue(P, nPer, r);
		return result;
	}
	double convertCtoM(double rc, long m) // ***
	{
		return m * exp(rc / m) - 1;
	}
	double convertMtoC(double rm, long m) // ***
	{
		return m * log(1 + rm / m);
	}
}

// 테스트 겸 주석 추가