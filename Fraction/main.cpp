// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-12-01
// Test file for Fraction class.

#include "Fraction.h"

#include <array>
using std::array;

#include <chrono>
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::chrono::time_point;

#include <cmath>
using std::pow;

#include <cstddef>
using std::size_t;

#include <fstream>
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

#include <random>
using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;

#include <string>
using std::string;
using std::to_string;

array<int, 15> rand_int_arr;
array<float, 15> rand_float_arr;
random_device rand_dev;
default_random_engine rand_engine(rand_dev());
uniform_int_distribution<int> rand_dist(1, 10);
Fraction fr;
float f = 0;
int arr1[2] = { 0, 0 };
int arr2[2] = { 0, 0 };
int arr3[2] = { 0, 0 };
int arr4[2] = { 0, 0 };
int arr5[2] = { 0, 0 };
int arr6[2] = { 0, 0 };
time_point<system_clock> start_time;
time_point<system_clock> end_time;
duration<float> time_elapsed_fr;
duration<float> time_elapsed_f;
duration<float> time_elapsed_dif;
float time_elapsed_dif_avg = 0;
string str;
ofstream fout("test_results_1.txt");

void write_rand_arr()
{
	for (size_t i = 0; i < 15; ++i)
	{
		rand_int_arr[i] = rand_dist(rand_engine);
		rand_float_arr[i] = rand_int_arr[i] * 1.0f;
	}
}

void test_fraction_normal()
{
	start_time = system_clock::now();
	fr.setFraction(rand_int_arr[0], rand_int_arr[1]);
	fr += Fraction(rand_int_arr[2], rand_int_arr[3]);
	fr *= Fraction(rand_int_arr[4], rand_int_arr[5]);
	fr.power(rand_int_arr[6]);
	fr /= Fraction(rand_int_arr[7], rand_int_arr[8]);
	fr -= rand_int_arr[9];
	fr /= rand_int_arr[10];
	fr *= Fraction(rand_int_arr[11] + rand_int_arr[12], rand_int_arr[13] + rand_int_arr[14]);
	end_time = system_clock::now();

	time_elapsed_fr = end_time - start_time;
	str = "Fraction:   " + to_string(time_elapsed_fr.count() * 1000);
	cout << str << endl;
	fout << str << endl;
}

void test_fraction_array_assignment()
{
	arr1[0] = rand_int_arr[2];
	arr1[1] = rand_int_arr[3];

	arr2[0] = rand_int_arr[4];
	arr2[1] = rand_int_arr[5];

	arr3[0] = rand_int_arr[7];
	arr3[1] = rand_int_arr[8];

	arr4[0] = rand_int_arr[9];
	arr4[1] = 1;

	arr5[0] = rand_int_arr[10];
	arr5[1] = 1;

	arr6[0] = rand_int_arr[11] + rand_int_arr[12];
	arr6[1] = rand_int_arr[13] + rand_int_arr[14];

	start_time = system_clock::now();
	fr.setFraction(rand_int_arr[0], rand_int_arr[1]);
	fr += arr1;
	fr *= arr2;
	fr.power(rand_int_arr[6]);
	fr /= arr3;
	fr -= arr4;
	fr /= arr5;
	fr *= arr6;
	end_time = system_clock::now();

	time_elapsed_fr = end_time - start_time;
	str = "Fraction:   " + to_string(time_elapsed_fr.count() * 1000);
	cout << str << endl;
	fout << str << endl;
}

void test_float()
{
	start_time = system_clock::now();
	f = rand_float_arr[0] / rand_float_arr[1];
	f += rand_float_arr[2] / rand_float_arr[3];
	f *= rand_float_arr[4] / rand_float_arr[5];
	f = float(pow(f, rand_float_arr[6]));
	f /= rand_float_arr[7] / rand_float_arr[8];
	f -= rand_float_arr[9];
	f /= rand_float_arr[10];
	f *= ((rand_float_arr[11] + rand_float_arr[12]) / (rand_float_arr[13] + rand_float_arr[14]));
	end_time = system_clock::now();

	time_elapsed_f = end_time - start_time;
	str = "Float:      " + to_string(time_elapsed_f.count() * 1000);
	cout << str << endl;
	fout << str << endl;
}

int main()
{
	Fraction fr(1, 2);

	if (fr)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}