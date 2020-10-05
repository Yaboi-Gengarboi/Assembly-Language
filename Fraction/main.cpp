// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-05

// extern "C" long* make_fraction(long numerator, long denominator);
// extern "C" int   delete_fraction(long* ptr);
// extern "C" long* add_fraction(long* fr1, long* fr2);

extern "C" int test();

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

void print_fraction(long* fr)
{
	cout << to_string(fr[0]) << " / " << to_string(fr[1]);
}

int main()
{
	// long* fr = make_fraction(1, 2);
	// int del = delete_fraction(fr);

	return test();
}