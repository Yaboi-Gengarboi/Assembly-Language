// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-08
// Header file for Fraction class.

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <ostream>
#include <string>

extern "C" int*   make_empty_fraction();
extern "C" int*   make_fraction(int numer, int denom);
extern "C" void   delete_fraction(int* ptr);
extern "C" void   set_numer(int* ptr, int numer);
extern "C" void   set_denom(int* ptr, int denom);
extern "C" double evaluate_fraction(int* ptr);
extern "C" int*   add_fraction(int* fr1, int* fr2);

class Fraction
{
	int* _ptr = nullptr;

	public:

	Fraction();

	Fraction(int numer, int denom);

	~Fraction();

	int numer() const;

	int denom() const;

	void setNumer(int numer);

	void setDenom(int denom);

	double evaluate() const;

	std::string toString() const;
};

std::ostream& operator << (std::ostream& os, const Fraction& fr);

#endif // FRACTION_H_INCLUDED