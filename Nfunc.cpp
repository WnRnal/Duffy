#include "Nfunc.hpp"
#include<math.h>

double N(double value)
{
	return 0.5 * erfc(-value * 1 / sqrt(2));
}