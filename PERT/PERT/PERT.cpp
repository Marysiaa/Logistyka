//============================================================================
// Name        : PERT.cpp
// Author      : Maria
// Description : Application to calculate probability of finishing process before directive time in C++
//============================================================================

#include <iostream>
#include <string>
#include "Probability_calculator.h"

using namespace std;

int main()
{
	cout << "PERT" << endl;

	string data_file = "dane.txt", result_file = "result.txt";

	Probability_calculator calc;
	double probability = calc.calculate_probability(data_file, result_file);

	cout << "Probability of finishing process before directive time (" << calc.get_directive_time() << ") is = " << probability << "%" << endl;

	system("pause");
	return 0;
}

