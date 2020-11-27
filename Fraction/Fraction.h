// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-11-27
// Header file for Fraction class.

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <ostream>
#include <string>

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

	// 1-int constructor.
	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to 1.
	Fraction(int numer);

	// 2-int constructor.
	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to denom.
	Fraction(int numer, int denom);

	// Array constructor.
	// Sets the numerator of the fraction to arr[0].
	// Sets the denominator of the fraction to arr[1].
	Fraction(int arr[2]);

	// Copy assignment operator.
	// Copies the values from the passed fraction into the
	// new fraction.
	Fraction& operator = (const Fraction& f);

	// Move assignment operator.
	// Moves the passed fraction into the new fraction.
	Fraction& operator = (Fraction&& f) noexcept;

	// Array assignment operator.
	// Sets the numerator of the fraction to arr[0].
	// Sets the denominator of the fraction to arr[1].
	Fraction& operator = (int arr[2]);

	// Destructor.
	// Destroys the fraction and its data.
	~Fraction() noexcept;

	// Returns the numerator of the fraction.
	int numer() const noexcept;

	// Returns the denominator of the fraction.
	int denom() const noexcept;

	// Sets the numerator of the fraction to numer.
	void setNumer(int numer) noexcept;

	// Sets the denominator of the fraction to denom.
	void setDenom(int denom) noexcept;

	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to denom.
	void setFraction(int numer, int denom) noexcept;

	// Sets the numerator of the fraction to arr[0].
	// Sets the denominator of the fraction to arr[1].
	void setFraction(int arr[2]) noexcept;

	// Raises both the numerator and denominator of the
	// fraction to the nth power.
	void power(unsigned int n) noexcept;

	// Returns the result of the fraction as a float.
	// This function will throw a std::domain_error if
	// a division by 0 is attempted.
	float evaluate() const;

	// Returns true if the denominator of the fraction is
	// NOT equal to 0.
	bool isValid() const noexcept;
	operator bool() const noexcept;

	// Returns the reciprical of this fraction.
	Fraction reciprocal() const;

	// Swaps this Fraction with the passed Fraction.
	void swap_with(Fraction& f2) noexcept;

	// Returns a std::string representation of the fraction.
	std::string toString() const;

	// Addition assignment operators.
	Fraction& operator += (const Fraction& f2);
	Fraction& operator += (int arr[2]);
	Fraction& operator += (int i);

	// Subtraction assignment operators.
	Fraction& operator -= (const Fraction& f2);
	Fraction& operator -= (int arr[2]);
	Fraction& operator -= (int i);

	// Multiplication assignment operators.
	Fraction& operator *= (const Fraction& f2);
	Fraction& operator *= (int arr[2]);
	Fraction& operator *= (int i);

	// Division assignment operators.
	Fraction& operator /= (const Fraction& f2);
	Fraction& operator /= (int arr[2]);
	Fraction& operator /= (int i);

	// Addition operators.
	Fraction operator + (const Fraction& f2);
	Fraction operator + (int i);

	// Subtraction operators.
	Fraction operator - (const Fraction& f2);
	Fraction operator - (int i);

	// Multiplication operators.
	Fraction operator * (const Fraction& f2);
	Fraction operator * (int i);

	// Division operators.
	Fraction operator / (const Fraction& f2);
	Fraction operator / (int i);
};

// Equality comparison operators.
bool operator == (const Fraction& f1, const Fraction& f2) noexcept;
bool operator == (const Fraction& fr, int arr[2]) noexcept;
bool operator == (const Fraction& fr, float f) noexcept;

// Inequality comparison operators.
bool operator != (const Fraction& f1, const Fraction& f2) noexcept;
bool operator != (const Fraction& fr, int arr[2]) noexcept;
bool operator != (const Fraction& fr, float f) noexcept;

// Less-than comparison operators.
bool operator < (const Fraction& f1, const Fraction& f2) noexcept;
bool operator < (const Fraction& fr, int arr[2]) noexcept;
bool operator < (const Fraction& fr, float f) noexcept;

// Less-than-or-equal comparison operators.
bool operator <= (const Fraction& f1, const Fraction& f2) noexcept;
bool operator <= (const Fraction& fr, int arr[2]) noexcept;
bool operator <= (const Fraction& fr, float f) noexcept;

// Greater-than comparison operators.
bool operator > (const Fraction& f1, const Fraction& f2) noexcept;
bool operator > (const Fraction& fr, int arr[2]) noexcept;
bool operator > (const Fraction& fr, float f) noexcept;

// Less-than-or-equal comparison operators.
bool operator >= (const Fraction& f1, const Fraction& f2) noexcept;
bool operator >= (const Fraction& fr, int arr[2]) noexcept;
bool operator >= (const Fraction& fr, float f) noexcept;

// std::ostream insertion operator.
std::ostream& operator << (std::ostream& os, const Fraction& f);

#endif // FRACTION_H_INCLUDED