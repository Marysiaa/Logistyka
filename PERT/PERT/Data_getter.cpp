/*
* Data_getter.cpp
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#include "Data_getter.h"

Data_getter::Data_getter(string file_name)
{
	this->file_name = file_name;
}

Data_getter::~Data_getter()
{
	if (processes)
		delete[] processes;
}

Process * Data_getter::get_data()
{
	ifstream data_file;
	data_file.open(file_name.c_str());

	if (!data_file.is_open()) {
		cout << "problem with opening file to read." << endl;
		system("pause");
		exit(1);
	}

	a_processes = 0;
	string wiersz;
	while (!data_file.eof())
	{
		getline(data_file, wiersz);
		a_processes++;
	}
	a_processes -= 1;
	cout << endl << a_processes << endl;
	data_file.seekg(0);

	processes = new Process[a_processes];

	for (int i = 0; i < a_processes; i++)
	{
		processes[i].amount_of_processes = a_processes;
		data_file >> processes[i].process_id >> processes[i].optimistic_time >> processes[i].probable_time >> processes[i].pesimistic_time >> processes[i].amount_of_previous_proccesses;

		processes[i].previous_processes_ids = new int[processes[i].amount_of_previous_proccesses];
		for (int j = 0; j < processes[i].amount_of_previous_proccesses; j++)
		{
			data_file >> processes[i].previous_processes_ids[j];
		}
	}

	data_file >> d_time;
	for (int i = 0; i < a_processes; i++)
		processes[i].directive_time = d_time;

	data_file.close();
	return processes;
}

int Data_getter::get_amount_of_processes()
{
	return a_processes;
}