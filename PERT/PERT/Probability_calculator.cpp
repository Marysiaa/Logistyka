/*
* Calculate_probability.cpp
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#include "Probability_calculator.h"

Probability_calculator::Probability_calculator()
{
	realization_time = 0;
	directive_time = 0;
	path_wariancja = 0;
	X = 0;
	probability = -1;
}

double Probability_calculator::calculate_probability(string data_file, string result_file)
{
	Data_getter *data_getter = new Data_getter(data_file);
	processes = data_getter->get_data();
	amount_of_processes = data_getter->get_amount_of_processes();
	directive_time = processes[0].directive_time;

	for (int i = 0; i < amount_of_processes; i++)
	{
		processes[i].calculate_expected_time();
	}
	Critical_path_designation path_designer;
	critical_path_processes = path_designer.Designate_critical_path_by_logic_table(amount_of_processes, processes);
	for (int i = 0; i < amount_of_processes; i++)
	{
		if (critical_path_processes[i] == 1)
		{
			processes[i].calculate_wariancja();
		}
	}

	Calculate_critical_path_parameters();
	probability = 100 * Get_value_from_dystrybuanta_table();
	Write_results_to_file(result_file);
	return probability;
}

double Probability_calculator::get_directive_time()
{
	return directive_time;
}

void Probability_calculator::Calculate_critical_path_parameters()
{
	realization_time = 0;
	path_wariancja = 0;
	X = 0;
	for (int i = 0; i < amount_of_processes; i++)
	{
		if (critical_path_processes[i] == 1)
		{
			path_wariancja += processes[i].wariancja;
			realization_time += processes[i].expected_time;
		}
	}

	path_wariancja = sqrt(path_wariancja);
	X = (directive_time - realization_time) / path_wariancja;
}

double Probability_calculator::Get_value_from_dystrybuanta_table()
{
	double result = -1;

	if (X > 0)
		result = Tablica_dystrybuanty(X);
	else
		result = 1 - Tablica_dystrybuanty(-X);
	
	return result;
}

void Probability_calculator::Write_results_to_file(string file_name)
{
	ofstream data_file;
	data_file.open(file_name.c_str());

	if (!data_file.is_open()) {
		cout << "problem with opening file to write." << endl;
		system("pause");
		exit(1);
	}

	data_file << "critical path processes (by id):" << endl;
	for (int i = 0; i < amount_of_processes; i++)
	{
		if (critical_path_processes[i] == 1)
		{
			data_file << "\t" << processes[i].process_id;
		}
	}

	data_file << endl;
	data_file << "realization time = \t" << realization_time << endl;
	data_file << "directive time = \t" << directive_time << endl;
	data_file << "wariancja = \t" << path_wariancja << endl;
	data_file << "X = \t" << X << endl;
	data_file << "probability of finishing process before directive time is = \t" << probability << endl;

	data_file.close();
}

double Probability_calculator::Tablica_dystrybuanty(double x)
{
	if (x >= 0 && x < 0.03)
		return 0.5;
	else if (x >= 0.03 && x < 0.06)
		return 0.51;
	else if (x >= 0.06 && x < 0.08)
		return 0.52;
	else if (x >= 0.08 && x < 0.11)
		return 0.53;
	else if (x >= 0.11 && x < 0.13)
		return 0.54;
	else if (x >= 0.13 && x < 0.16)
		return 0.55;
	else if (x >= 0.16 && x < 0.18)
		return 0.56;
	else if (x >= 0.18 && x < 0.21)
		return 0.57;
	else if (x >= 0.21 && x < 0.23)
		return 0.58;
	else if (x >= 0.23 && x < 0.26)
		return 0.59;
	else if (x >= 0.26 && x < 0.28)
		return 0.6;
	else if (x >= 0.28 && x < 0.31)
		return 0.61;
	else if (x >= 0.31 && x < 0.34)
		return 0.62;
	else if (x >= 0.34 && x < 0.36)
		return 0.63;
	else if (x >= 0.36 && x < 0.39)
		return 0.64;
	else if (x >= 0.39 && x < 0.42)
		return 0.65;
	else if (x >= 0.42 && x < 0.44)
		return 0.66;
	else if (x >= 0.44 && x < 0.47)
		return 0.67;
	else if (x >= 0.47 && x < 0.5)
		return 0.68;
	else if (x >= 0.5 && x < 0.53)
		return 0.69;
	else if (x >= 0.53 && x < 0.56)
		return 0.7;
	else if (x >= 0.56 && x < 0.59)
		return 0.71;
	else if (x >= 0.59 && x < 0.62)
		return 0.72;
	else if (x >= 0.62 && x < 0.65)
		return 0.73;
	else if (x >= 0.65 && x < 0.68)
		return 0.74;
	else if (x >= 0.68 && x < 0.71)
		return 0.75;
	else if (x >= 0.71 && x < 0.74)
		return 0.76;
	else if (x >= 0.74 && x < 0.78)
		return 0.77;
	else if (x >= 0.78 && x < 0.81)
		return 0.78;
	else if (x >= 0.81 && x < 0.85)
		return 0.79;
	else if (x >= 0.85 && x < 0.88)
		return 0.8;
	else if (x >= 0.88 && x < 0.92)
		return 0.81;
	else if (x >= 0.92 && x < 0.96)
		return 0.82;
	else if (x >= 0.96 && x < 1)
		return 0.83;
	else if (x >= 1 && x < 1.04)
		return 0.84;
	else if (x >= 1.04 && x < 1.09)
		return 0.85;
	else if (x >= 1.09 && x < 1.13)
		return 0.86;
	else if (x >= 1.13 && x < 1.18)
		return 0.87;
	else if (x >= 1.18 && x < 1.23)
		return 0.88;
	else if (x >= 1.23 && x < 1.29)
		return 0.89;
	else if (x >= 1.29 && x < 1.35)
		return 0.9;
	else if (x >= 1.35 && x < 1.41)
		return 0.91;
	else if (x >= 1.41 && x < 1.48)
		return 0.92;
	else if (x >= 1.48 && x < 1.56)
		return 0.93;
	else if (x >= 1.56 && x < 1.65)
		return 0.94;
	else if (x >= 1.65 && x < 1.76)
		return 0.95;
	else if (x >= 1.76 && x < 1.89)
		return 0.96;
	else if (x >= 1.89 && x < 2.06)
		return 0.97;
	else if (x >= 2.06 && x < 2.33)
		return 0.98;
	else if (x >= 2.33 && x < 4.9)
		return 0.99;
	else if (x >= 4.9)
		return 1;
	else
		return -0.01;
}