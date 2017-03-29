/*
* Calculate_probability.h
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#ifndef PROBABILITY_CALCULATOR_H_
#define PROBABILITY_CALCULATOR_H_

#include <iostream>
#include <string>
#include <math.h>

#include "Data_getter.h"
#include "Critical_path_designation.h"
#include "Process.h"

using namespace std;

class Probability_calculator
{
private:
	Process *processes;
	int *critical_path_processes;
	int amount_of_processes;
	double realization_time, directive_time, path_wariancja, X, probability;

public:
	Probability_calculator();
	double calculate_probability(string data_file, string result_file);
	double get_directive_time();

private:
	void Calculate_critical_path_parameters();
	double Get_value_from_dystrybuanta_table();
	void Write_results_to_file(string file_name);

};

#endif /* PROBABILITY_CALCULATOR_H_ */