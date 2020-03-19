#ifndef GenericInequalities_CPP
#define Genericinequalities_CPP

#include "GenericInequalities.hpp"

////// Useful Functions //////
// Max and Min of two numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y) {
	if (x > y)
		return x;
	return y;
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y) {
	if (x > y)
		return y;
	return x;
}

// Max and Min of three numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y, const Numeric& z) {
	return Max<Numeric>(x, Max<Numeric>(y, z));
}
template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z) {
	return Min<Numeric>(x, Min<Numeric>(y, z));
}

#endif