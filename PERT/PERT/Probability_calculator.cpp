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
	return erf(X);
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
