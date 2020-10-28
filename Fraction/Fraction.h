// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-28
// Header file for Fraction class.

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <ostream>
#include <string>

// Allocates an 8-byte array to hold 2 integers and
// returns the pointer to it.
extern "C" int* make_fr(int numer, int denom);

// Deallocates the passed 8-byte array.
extern "C" void delete_fr(int* f);

// Sets f[0] to numer.
extern "C" void set_numer(int* f, int numer);

// Sets f[1] to denom.
extern "C" void set_denom(int* f, int denom);

// Returns the float result of numer / denom.
extern "C" float evaluate_fr(int numer, int denom);

// Adds the 2 Fractions.
extern "C" void add_fr(int* f1, int* f2);

// Subtracts the 2 Fractions.
extern "C" void sub_fr(int* f1, int* f2);

// Multiplies the 2 Fractions.
extern "C" void mul_fr(int* f1, int* f2);

// Divides the 2 Fractions.
extern "C" void div_fr(int* f1, int* f2);

class Fraction
{
	int* _ptr = nullptr;

	public:

	// Default constructor.
	// Sets the numerator and denominator of the fraction to 0.
	Fraction();

	// Copy constructor.
	// Copies the values from the passed fraction into the
	// new fraction.
	Fraction(const Fraction& f);

	// Move constructor.
	// Moves the passed fraction into the new fraction.
	Fraction(Fraction&& f) noexcept;

	// 2-int constructor.
	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to denom.
	Fraction(int numer, int denom);

	// Copy assignment operator.
	// Copies the values from the passed fraction into the
	// new fraction.
	Fraction& operator = (const Fraction& f);

	// Move assignment operator.
	// Moves the passed fraction into the new fraction.
	Fraction& operator = (Fraction&& f) noexcept;

	// Destructor.
	// Destroys the fraction and its data.
	~Fraction() noexcept;

	// Returns the numerator of the fraction.
	int numer() const noexcept;

	// Returns the denominator of the fraction.
	int denom() const noexcept;

	// Sets the numerator of the fraction to numer.
	void setNumer(int numer);

	// Sets the denominator of the fraction to numer.
	void setDenom(int denom);

	// Returns the result of the fraction as a float.
	float evaluate() const;

	// Returns true if the denominator of the fraction is
	// NOT equal to 0.
	bool isValid() const noexcept;
	operator bool() const noexcept;

	// Returns the reciprical of this fraction.
	Fraction reciprocal() const;

	// Swaps the 2 passed Fractions.
	void swap(Fraction& f2) noexcept;

	// Returns a std::string representation of the fraction.
	std::string toString() const;

	// Addition assignment operators.
	Fraction& operator += (const Fraction& f2);
	Fraction& operator += (int i);

	// Subtraction assignment operators.
	Fraction& operator -= (const Fraction& f2);
	Fraction& operator -= (int i);

	// Multiplication assignment operators.
	Fraction& operator *= (const Fraction& f2);
	Fraction& operator *= (int i);

	// Division assignment operators.
	Fraction& operator /= (const Fraction& f2);
	Fraction& operator /= (int i);
};

// Addition operators.
Fraction operator + (const Fraction& f1, const Fraction& f2);
Fraction operator + (const Fraction& f, int i);

Fraction operator - (const Fraction& f1, const Fraction& f2);
Fraction operator - (const Fraction& f, int i);

Fraction operator * (const Fraction& f1, const Fraction& f2);
Fraction operator * (const Fraction& f, int i);

Fraction operator / (const Fraction& f1, const Fraction& f2);
Fraction operator / (const Fraction& f, int i);

// Equality comparison operators.
bool operator == (const Fraction& f1, const Fraction& f2);
bool operator == (const Fraction& fr, float f);

// Inequality comparison operators.
bool operator != (const Fraction& f1, const Fraction& f2);
bool operator != (const Fraction& fr, float f);

// Less-than comparison operators.
bool operator < (const Fraction& f1, const Fraction& f2);
bool operator < (const Fraction& fr, float f);

// Less-than-or-equal comparison operators.
bool operator <= (const Fraction& f1, const Fraction& f2);
bool operator <= (const Fraction& fr, float f);

// Greater-than comparison operators.
bool operator > (const Fraction& f1, const Fraction& f2);
bool operator > (const Fraction& fr, float f);

// Less-than-or-equal comparison operators.
bool operator >= (const Fraction& f1, const Fraction& f2);
bool operator >= (const Fraction& fr, float f);

// std::ostream insertion operator.
std::ostream& operator << (std::ostream& os, const Fraction& f);

#endif // FRACTION_H_INCLUDED