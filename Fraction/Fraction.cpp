// Fraction
// Fraction.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-11-27
// Source file for Fraction class.

#include "Fraction.h"

// Allocates an 8-byte array to hold 2 integers and
// returns the pointer to it.
extern "C" int* make_fr(int numer, int denom);

// Deallocates the passed 8-byte array.
extern "C" void delete_fr(int* f);

// Sets f[0] to numer.
extern "C" void set_numer(int* f, int numer);

// Sets f[1] to denom.
extern "C" void set_denom(int* f, int denom);

// Sets f[0] to numer and f[1] to denom.
extern "C" void set_fr(int* f, int numer, int denom);

// Raises both f[0] and f[1] to the nth power.
extern "C" void pow_fr(int* f, unsigned int n);

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

#include <ostream>
using std::ostream;

#include <stdexcept>
using std::domain_error;

#include <string>
using std::string;
using std::to_string;

Fraction::Fraction()
{
	_ptr = make_fr(0, 0);
}

Fraction::Fraction(const Fraction& f)
{
	_ptr = make_fr(f._ptr[0], f._ptr[1]);
}

Fraction::Fraction(Fraction&& f) noexcept
{
	_ptr = f._ptr;
	f._ptr = nullptr;
}

Fraction::Fraction(int numer)
{
	_ptr = make_fr(numer, 1);
}

Fraction::Fraction(int numer, int denominator)
{
	_ptr = make_fr(numer, denominator);
}

Fraction::Fraction(const int arr[2])
{
	_ptr = make_fr(arr[0], arr[1]);
}

Fraction& Fraction::operator = (const Fraction& f)
{
	set_fr(_ptr, f._ptr[0], f._ptr[1]);
	return *this;
}

Fraction& Fraction::operator = (Fraction&& f) noexcept
{
	delete_fr(_ptr);
	_ptr = f._ptr;
	f._ptr = nullptr;
	return *this;
}

Fraction& Fraction::operator = (const int arr[2])
{
	set_fr(_ptr, arr[0], arr[1]);
	return *this;
}

Fraction::~Fraction() noexcept
{
	delete_fr(_ptr);
}

int Fraction::numer() const noexcept
{
	return _ptr[0];
}

int Fraction::denom() const noexcept
{
	return _ptr[1];
}

void Fraction::setNumer(int numer) noexcept
{
	set_numer(_ptr, numer);
}

void Fraction::setDenom(int denom) noexcept
{
	set_denom(_ptr, denom);
}

void Fraction::setFraction(int numer, int denom) noexcept
{
	set_fr(_ptr, numer, denom);
}

void Fraction::power(unsigned int n) noexcept
{
	pow_fr(_ptr, n);
}

float Fraction::evaluate() const
{
	if (_ptr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return evaluate_fr(_ptr[0], _ptr[1]);
}

bool Fraction::isValid() const noexcept
{
	return _ptr[1] == 0;
}

Fraction::operator bool() const noexcept
{
	return isValid();
}

Fraction Fraction::reciprocal() const
{
	return Fraction(_ptr[0], _ptr[1]);
}

void Fraction::swap_with(Fraction& f2) noexcept
{
	int* tmp = _ptr;
	_ptr = f2._ptr;
	f2._ptr = tmp;
}

string Fraction::toString() const
{
	return to_string(_ptr[0]) + " / " + to_string(_ptr[1]);
}

Fraction& Fraction::operator += (const Fraction& f2)
{
	add_fr(_ptr, f2._ptr);
	return *this;
}

Fraction& Fraction::operator += (int i)
{
	add_fr(_ptr, make_fr(i * _ptr[1], _ptr[1]));
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& f2)
{
	sub_fr(_ptr, f2._ptr);
	return *this;
}

Fraction& Fraction::operator -= (int i)
{
	sub_fr(_ptr, make_fr(i * _ptr[1], _ptr[1]));
	return *this;
}

Fraction& Fraction::operator *= (const Fraction& f2)
{
	mul_fr(_ptr, f2._ptr);
	return *this;
}

Fraction& Fraction::operator *= (int i)
{
	mul_fr(_ptr, make_fr(i, 1));
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& f2)
{
	div_fr(_ptr, f2._ptr);
	return *this;
}

Fraction& Fraction::operator /= (int i)
{
	div_fr(_ptr, make_fr(i, 1));
	return *this;
}

Fraction Fraction::operator + (const Fraction& f2)
{
	Fraction f1(*this);
	add_fr(f1._ptr, f2._ptr);
	return f1;
}

Fraction Fraction::operator + (int i)
{
	Fraction f1(*this);
	add_fr(f1._ptr, make_fr(i * f1._ptr[1], f1._ptr[1]));
	return f1;
}

Fraction Fraction::operator - (const Fraction& f2)
{
	Fraction f1(*this);
	sub_fr(f1._ptr, f2._ptr);
	return f1;
}

Fraction Fraction::operator - (int i)
{
	Fraction f1(*this);
	sub_fr(f1._ptr, make_fr(i * f1._ptr[1], f1._ptr[1]));
	return f1;
}

Fraction Fraction::operator * (const Fraction& f2)
{
	Fraction f1(*this);
	mul_fr(f1._ptr, f2._ptr);
	return f1;
}

Fraction Fraction::operator * (int i)
{
	Fraction f1(*this);
	mul_fr(f1._ptr, make_fr(i, 1));
	return f1;
}

Fraction Fraction::operator / (const Fraction& f2)
{
	Fraction f1(*this);
	div_fr(f1._ptr, f2._ptr);
	return f1;
}

Fraction Fraction::operator / (int i)
{
	Fraction f1(*this);
	div_fr(f1._ptr, make_fr(i, 1));
	return f1;
}

bool operator == (const Fraction& f1, const Fraction& f2) noexcept
{
	return f1.evaluate() == f2.evaluate();
}

bool operator == (const Fraction& fr, float f) noexcept
{
	return fr.evaluate() == f;
}

bool operator != (const Fraction& f1, const Fraction& f2) noexcept
{
	return f1.evaluate() != f2.evaluate();
}

bool operator != (const Fraction& fr, float f) noexcept
{
	return fr.evaluate() != f;
}

bool operator < (const Fraction& f1, const Fraction& f2) noexcept
{
	return f1.evaluate() < f2.evaluate();
}

bool operator < (const Fraction& fr, float f) noexcept
{
	return fr.evaluate() < f;
}

bool operator <= (const Fraction& f1, const Fraction& f2) noexcept
{
	return f1.evaluate() <= f2.evaluate();
}

bool operator <= (const Fraction& fr, float f) noexcept
{
	return fr.evaluate() <= f;
}

bool operator > (const Fraction& f1, const Fraction& f2) noexcept
{
	return f1.evaluate() > f2.evaluate();
}

bool operator > (const Fraction& fr, float f) noexcept
{
	return fr.evaluate() > f;
}

bool operator >= (const Fraction& f1, const Fraction& f2) noexcept
{
	return f1.evaluate() >= f2.evaluate();
}

bool operator >= (const Fraction& fr, float f) noexcept
{
	return fr.evaluate() >= f;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << f.toString();
	return os;
}