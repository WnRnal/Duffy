#pragma once

//Preprocessor directives; ensures that we do not 
// include a file twice (give compiler error)
#ifndef GenericInequalities_HPP
#define GenericIniequalities_HPP
//사실 #pragma once를 썼으면 필요 없음.

/////// Useful Functions ///////
// Max and Min of two numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y);
template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y);

// Max and Min of three nubmers
template<class Numeric>
Numeric Max(const Numeric& x, const Numeric& y, const Numeric& z);
template<class Numeric>
Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z);
#endif