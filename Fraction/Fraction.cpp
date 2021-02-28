// Fraction
// Fraction.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2021-02-27
// Source file for the Fraction class.

#include "Fraction.h"

// include <cstddef>
using std::int64_t;
using std::uint64_t;

// include <ostream>
using std::ostream;

// include <stdexcept>
using std::domain_error;

// include <string>
using std::string;
using std::to_string;

// Sets fr[0] to numer.
extern "C" void set_numer(int64_t* fr, int64_t numer);

// Sets fr[1] to denom.
extern "C" void set_denom(int64_t* fr, int64_t denom);

// Sets fr[0] to numer and fr[1] to denom.
extern "C" void set_fr(int64_t* fr, int64_t numer, int64_t denom);

// Raises both fr[0] and fr[1] to the nth power.
extern "C" void pow_fr(int64_t* fr, uint64_t n);

// Returns the double result of numer / denom.
extern "C" double evaluate_fr(int64_t numer, int64_t denom);

// Adds numer onto fr[0].
// Adds denom onto fr[1].
extern "C" void add_fr(int64_t* fr, int64_t numer, int64_t denom);

// Subtracts numer from fr[0].
// Subtracts denom from fr[1].
extern "C" void sub_fr(int64_t* fr, int64_t numer, int64_t denom);

// Multiplies fr[0] by numer.
// Multiplies fr[1] by denom.
extern "C" void mul_fr(int64_t* fr, int64_t numer, int64_t denom);

// Multiplies fr[0] by denom.
// Multiplies fr[1] by numer.
extern "C" void div_fr(int64_t* fr, int64_t numer, int64_t denom);

void Fraction::allocate()
{
	ptr_ = new int64_t[2];
}

void Fraction::deallocate() noexcept
{
	delete[] ptr_;
}

Fraction::Fraction()
{
	allocate();
}

Fraction::Fraction(const Fraction& other)
{
	allocate();
	set_fr(ptr_, other.ptr_[0], other.ptr_[1]);
}

Fraction::Fraction(Fraction&& other) noexcept
{
	ptr_ = other.ptr_;
	other.ptr_ = nullptr;
}

Fraction::Fraction(int64_t numer)
{
	allocate();
	set_numer(ptr_, numer);
}

Fraction::Fraction(int64_t numer, int64_t denom)
{
	allocate();
	set_fr(ptr_, numer, denom);
}

Fraction::Fraction(int64_t arr[2])
{
	allocate();
	set_fr(ptr_, arr[0], arr[1]);
}

Fraction& Fraction::operator = (const Fraction& other)
{
	set_fr(ptr_, other.ptr_[0], other.ptr_[1]);
	return *this;
}

Fraction& Fraction::operator = (Fraction&& other) noexcept
{
	deallocate();
	ptr_ = other.ptr_;
	other.ptr_ = nullptr;
	return *this;
}

Fraction& Fraction::operator = (int64_t arr[2])
{
	set_fr(ptr_, arr[0], arr[1]);
	return *this;
}

Fraction::~Fraction() noexcept
{
	deallocate();
}

int64_t Fraction::numer() const noexcept
{
	return ptr_[0];
}

int64_t Fraction::denom() const noexcept
{
	return ptr_[1];
}

void Fraction::setNumer(int64_t numer) noexcept
{
	set_numer(ptr_, numer);
}

void Fraction::setDenom(int64_t denom) noexcept
{
	set_denom(ptr_, denom);
}

void Fraction::setFraction(int64_t numer) noexcept
{
	set_fr(ptr_, numer, 1);
}

void Fraction::setFraction(int64_t numer, int64_t denom) noexcept
{
	set_fr(ptr_, numer, denom);
}

void Fraction::setFraction(int64_t arr[2]) noexcept
{
	set_fr(ptr_, arr[0], arr[1]);
}

void Fraction::power(uint64_t n) noexcept
{
	pow_fr(ptr_, n);
}

double Fraction::evaluate() const
{
	if (ptr_[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return evaluate_fr(ptr_[0], ptr_[1]);
}

bool Fraction::isValid() const noexcept
{
	return ptr_[1] != 0;
}

Fraction::operator bool() const noexcept
{
	return isValid();
}

Fraction Fraction::reciprocal() const
{
	return Fraction(ptr_[0], ptr_[1]);
}

void Fraction::swap_with(Fraction& other) noexcept
{
	int64_t* tmp = ptr_;
	ptr_ = other.ptr_;
	other.ptr_ = tmp;
}

string Fraction::toString() const
{
	return to_string(ptr_[0]) + " / " + to_string(ptr_[1]);
}

Fraction& Fraction::operator ++ ()
{
	ptr_[0] += ptr_[1];
	return *this;
}

Fraction Fraction::operator ++ (int)
{
	Fraction fr(*this);
	++(*this);
	return fr;
}

Fraction& Fraction::operator -- ()
{
	ptr_[0] -= ptr_[1];
	return *this;
}

Fraction Fraction::operator -- (int)
{
	Fraction fr(*this);
	--(*this);
	return fr;
}

Fraction& Fraction::operator += (const Fraction& other)
{
	add_fr(ptr_, other.ptr_[0], other.ptr_[1]);
	return *this;
}

Fraction& Fraction::operator += (int64_t arr[2])
{
	add_fr(ptr_, arr[0], arr[1]);
	return *this;
}

Fraction& Fraction::operator += (int64_t i)
{
	add_fr(ptr_, i, 1);
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& other)
{
	sub_fr(ptr_, other.ptr_[0], other.ptr_[1]);
	return *this;
}

Fraction& Fraction::operator -= (int64_t arr[2])
{
	sub_fr(ptr_, arr[0], arr[1]);
	return *this;
}

Fraction& Fraction::operator -= (int64_t i)
{
	sub_fr(ptr_, i, 1);
	return *this;
}

Fraction& Fraction::operator *= (const Fraction& other)
{
	mul_fr(ptr_, other.ptr_[0], other.ptr_[1]);
	return *this;
}

Fraction& Fraction::operator *= (int64_t arr[2])
{
	mul_fr(ptr_, arr[0], arr[1]);
	return *this;
}

Fraction& Fraction::operator *= (int64_t i)
{
	mul_fr(ptr_, i, 1);
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& other)
{
	div_fr(ptr_, other.ptr_[0], other.ptr_[1]);
	return *this;
}

Fraction& Fraction::operator /= (int64_t arr[2])
{
	div_fr(ptr_, arr[0], arr[1]);
	return *this;
}

Fraction& Fraction::operator /= (int64_t i)
{
	div_fr(ptr_, i, 1);
	return *this;
}

Fraction Fraction::operator + (const Fraction& other)
{
	Fraction f1(*this);
	add_fr(f1.ptr_, other.ptr_[0], other.ptr_[1]);
	return f1;
}

Fraction Fraction::operator + (int64_t i)
{
	Fraction f1(*this);
	add_fr(f1.ptr_, i, 1);
	return f1;
}

Fraction Fraction::operator - (const Fraction& other)
{
	Fraction f1(*this);
	sub_fr(f1.ptr_, other.ptr_[0], other.ptr_[1]);
	return f1;
}

Fraction Fraction::operator - (int64_t i)
{
	Fraction f1(*this);
	sub_fr(f1.ptr_, i, 1);
	return f1;
}

Fraction Fraction::operator * (const Fraction& other)
{
	Fraction f1(*this);
	mul_fr(f1.ptr_, other.ptr_[0], other.ptr_[1]);
	return f1;
}

Fraction Fraction::operator * (int64_t i)
{
	Fraction f1(*this);
	mul_fr(f1.ptr_, i, 1);
	return f1;
}

Fraction Fraction::operator / (const Fraction& other)
{
	Fraction f1(*this);
	div_fr(f1.ptr_, other.ptr_[0], other.ptr_[1]);
	return f1;
}

Fraction Fraction::operator / (int64_t i)
{
	Fraction f1(*this);
	div_fr(f1.ptr_, i, 1);
	return f1;
}

bool operator == (const Fraction& f1, const Fraction& f2)
{
	return f1.evaluate() == f2.evaluate();
}

bool operator == (const Fraction& fr, int64_t arr[2])
{
	if (arr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return fr.evaluate() == ((1.0f * arr[0]) / (1.0f * arr[1]));
}

bool operator == (const Fraction& fr, double d)
{
	return fr.evaluate() == d;
}

bool operator != (const Fraction& f1, const Fraction& f2)
{
	return f1.evaluate() != f2.evaluate();
}

bool operator != (const Fraction& fr, int64_t arr[2])
{
	if (arr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return fr.evaluate() != ((1.0f * arr[0]) / (1.0f * arr[1]));
}

bool operator != (const Fraction& fr, double d)
{
	return fr.evaluate() != d;
}

bool operator < (const Fraction& f1, const Fraction& f2)
{
	return f1.evaluate() < f2.evaluate();
}

bool operator < (const Fraction& fr, int64_t arr[2])
{
	if (arr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return fr.evaluate() < ((1.0f * arr[0]) / (1.0f * arr[1]));
}

bool operator < (const Fraction& fr, double d)
{
	return fr.evaluate() < d;
}

bool operator <= (const Fraction& f1, const Fraction& f2)
{
	return f1.evaluate() <= f2.evaluate();
}

bool operator <= (const Fraction& fr, int64_t arr[2])
{
	if (arr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return fr.evaluate() <= ((1.0f * arr[0]) / (1.0f * arr[1]));
}

bool operator <= (const Fraction& fr, double d)
{
	return fr.evaluate() <= d;
}

bool operator > (const Fraction& f1, const Fraction& f2)
{
	return f1.evaluate() > f2.evaluate();
}

bool operator > (const Fraction& fr, int64_t arr[2])
{
	if (arr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return fr.evaluate() > ((1.0f * arr[0]) / (1.0f * arr[1]));
}

bool operator > (const Fraction& fr, double d)
{
	return fr.evaluate() > d;
}

bool operator >= (const Fraction& f1, const Fraction& f2)
{
	return f1.evaluate() >= f2.evaluate();
}

bool operator >= (const Fraction& fr, int64_t arr[2])
{
	if (arr[1] == 0)
		throw domain_error("Domain Error: Division by 0.");

	return fr.evaluate() >= ((1.0f * arr[0]) / (1.0f * arr[1]));
}

bool operator >= (const Fraction& fr, double d)
{
	return fr.evaluate() >= d;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << f.toString();
	return os;
}