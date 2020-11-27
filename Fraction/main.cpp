// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-11-27
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

void test_fraction()
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
	for (int i = 0; i < 500; ++i)
	{
		write_rand_arr();
		test_fraction();
		test_float();

		time_elapsed_dif = time_elapsed_fr - time_elapsed_f;
		time_elapsed_dif_avg += time_elapsed_fr.count();
		str = "Difference: " + to_string(time_elapsed_dif.count() * 1000.0f);
		cout << str << endl << endl;
		fout << str << endl << endl;
	}

	cout << "Average time difference: " << time_elapsed_dif_avg / 500.0f * 1000.0f << endl;
	fout << "Average time difference: " << time_elapsed_dif_avg / 500.0f * 1000.0f << endl;

	return 0;
}