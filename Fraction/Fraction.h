// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-06

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

extern "C" long* make_fraction(long numer, long denom);
extern "C" int   delete_fraction(long* ptr);
extern "C" long* add_fraction(long* fr1, long* fr2);

extern "C" long  test(long i1, long i2);

struct Fraction
{
	long* _ptr = nullptr;

	Fraction(long numer, long denom);

	~Fraction();
};

#endif // FRACTION_H_INCLUDED