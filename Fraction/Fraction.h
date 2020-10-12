// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-12
// Header file for Fraction class.

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <ostream>
#include <string>

extern "C" int*   make_empty_fraction();
extern "C" int*   make_fraction(int numer, int denom);
extern "C" void   delete_fraction(int* f);
extern "C" void   set_numer(int* f, int numer);
extern "C" void   set_denom(int* f, int denom);
extern "C" double evaluate_fraction(int numer, int denom);
extern "C" void   add_fraction(int* f1, int* f2);
extern "C" void   sub_fraction(int* f1, int* f2);
extern "C" void   mul_fraction(int* f1, int* f2);
extern "C" void   div_fraction(int* f1, int* f2);

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

	Fraction& operator += (const Fraction& f2);
};

Fraction operator + (const Fraction& f1, const Fraction& f2);

Fraction operator - (const Fraction& f1, const Fraction& f2);

Fraction operator * (const Fraction& f1, const Fraction& f2);

Fraction operator / (const Fraction& f1, const Fraction& f2);

std::ostream& operator << (std::ostream& os, const Fraction& f);

#endif // FRACTION_H_INCLUDED