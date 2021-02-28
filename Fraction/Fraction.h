// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2021-02-27
// Header file for the Fraction class.

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <cstddef>
#include <ostream>
#include <string>

class Fraction
{
	std::int64_t* ptr_ = nullptr;

	void allocate();

	void deallocate() noexcept;

	public:

	// Default constructor.
	// Sets the numerator and denominator of the fraction to 0.
	Fraction();

	// Copy constructor.
	// Copies the values from the passed fraction into the
	// new fraction.
	Fraction(const Fraction& other);

	// Move constructor.
	// Moves the passed fraction into the new fraction.
	Fraction(Fraction&& other) noexcept;

	// 1-std::int64_t constructor.
	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to 1.
	Fraction(std::int64_t numer);

	// 2-std::int64_t constructor.
	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to denom.
	Fraction(std::int64_t numer, std::int64_t denom);

	// Array constructor.
	// Sets the numerator of the fraction to arr[0].
	// Sets the denominator of the fraction to arr[1].
	Fraction(std::int64_t arr[2]);

	// Copy assignment operator.
	// Copies the values from the passed fraction into the
	// new fraction.
	Fraction& operator = (const Fraction& other);

	// Move assignment operator.
	// Moves the passed fraction into the new fraction.
	Fraction& operator = (Fraction&& other) noexcept;

	// Array assignment operator.
	// Sets the numerator of the fraction to arr[0].
	// Sets the denominator of the fraction to arr[1].
	Fraction& operator = (std::int64_t arr[2]);

	// Destructor.
	// Destroys the fraction and its data.
	~Fraction() noexcept;

	// Returns the numerator of the fraction.
	std::int64_t numer() const noexcept;

	// Returns the denominator of the fraction.
	std::int64_t denom() const noexcept;

	// Sets the numerator of the fraction to numer.
	void setNumer(std::int64_t numer) noexcept;

	// Sets the denominator of the fraction to denom.
	void setDenom(std::int64_t denom) noexcept;

	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to 1.
	void setFraction(std::int64_t numer) noexcept;

	// Sets the numerator of the fraction to numer.
	// Sets the denominator of the fraction to denom.
	void setFraction(std::int64_t numer, std::int64_t denom) noexcept;

	// Sets the numerator of the fraction to arr[0].
	// Sets the denominator of the fraction to arr[1].
	void setFraction(std::int64_t arr[2]) noexcept;

	// Raises both the numerator and denominator of the
	// fraction to the nth power.
	void power(std::uint64_t n) noexcept;

	// Returns the result of the fraction as a double.
	// This function will throw a std::domain_error if
	// a division by 0 is attempted.
	double evaluate() const;

	// Returns true if the denominator of the fraction is
	// NOT equal to 0.
	bool isValid() const noexcept;
	operator bool() const noexcept;

	// Returns the reciprical of this fraction.
	Fraction reciprocal() const;

	// Swaps this Fraction with the passed Fraction.
	void swap_with(Fraction& other) noexcept;

	// Returns a std::string representation of the fraction.
	std::string toString() const;

	// Increment addition operators.
	Fraction& operator ++ ();
	Fraction operator ++ (int);

	// Increment subtraction operators.
	Fraction& operator -- ();
	Fraction operator -- (int);

	// Addition assignment operators.
	Fraction& operator += (const Fraction& other);
	Fraction& operator += (std::int64_t arr[2]);
	Fraction& operator += (std::int64_t i);

	// Subtraction assignment operators.
	Fraction& operator -= (const Fraction& other);
	Fraction& operator -= (std::int64_t arr[2]);
	Fraction& operator -= (std::int64_t i);

	// Multiplication assignment operators.
	Fraction& operator *= (const Fraction& other);
	Fraction& operator *= (std::int64_t arr[2]);
	Fraction& operator *= (std::int64_t i);

	// Division assignment operators.
	Fraction& operator /= (const Fraction& other);
	Fraction& operator /= (std::int64_t arr[2]);
	Fraction& operator /= (std::int64_t i);

	// Addition operators.
	Fraction operator + (const Fraction& other);
	Fraction operator + (std::int64_t i);

	// Subtraction operators.
	Fraction operator - (const Fraction& other);
	Fraction operator - (std::int64_t i);

	// Multiplication operators.
	Fraction operator * (const Fraction& other);
	Fraction operator * (std::int64_t i);

	// Division operators.
	Fraction operator / (const Fraction& other);
	Fraction operator / (std::int64_t i);
};

// Returns true if f1.evaluate() == f2.evaluate().
bool operator == (const Fraction& f1, const Fraction& f2);

// Returns true if fr.evaluate() == arr[0] / arr[1].
bool operator == (const Fraction& fr, std::int64_t arr[2]);

// Returns true if fr.evaluate() == d.
bool operator == (const Fraction& fr, double d);

// Returns true if f1.evaluate() != f2.evaluate().
bool operator != (const Fraction& f1, const Fraction& f2);

// Returns true if fr.evaluate() != arr[0] / arr[1].
bool operator != (const Fraction& fr, std::int64_t arr[2]);

// Returns true if fr.evaluate() != d.
bool operator != (const Fraction& fr, double d);

// Returns true if f1.evaluate() < f2.evaluate().
bool operator < (const Fraction& f1, const Fraction& f2);

// Returns true if fr.evaluate() < arr[0] / arr[1].
bool operator < (const Fraction& fr, std::int64_t arr[2]);

// Returns true if fr.evaluate() < d.
bool operator < (const Fraction& fr, double d);

// Returns true if f1.evaluate() <= f2.evaluate().
bool operator <= (const Fraction& f1, const Fraction& f2);

// Returns true if fr.evaluate() <= arr[0] / arr[1].
bool operator <= (const Fraction& fr, std::int64_t arr[2]);

// Returns true if fr.evaluate() <= d.
bool operator <= (const Fraction& fr, double d);

// Returns true if f1.evaluate() > f2.evaluate().
bool operator > (const Fraction& f1, const Fraction& f2);

// Returns true if fr.evaluate() > arr[0] / arr[1].
bool operator > (const Fraction& fr, std::int64_t arr[2]);

// Returns true if fr.evaluate() > d.
bool operator > (const Fraction& fr, double d);

// Returns true if f1.evaluate() >= f2.evaluate().
bool operator >= (const Fraction& f1, const Fraction& f2);

// Returns true if fr.evaluate() >= arr[0] / arr[1].
bool operator >= (const Fraction& fr, std::int64_t arr[2]);

// Returns true if fr.evaluate() >= d.
bool operator >= (const Fraction& fr, double d);

// std::ostream insertion operator.
// Prints fr.toString() to the passed std::ostream.
std::ostream& operator << (std::ostream& os, const Fraction& fr);

#endif // FRACTION_H_INCLUDED