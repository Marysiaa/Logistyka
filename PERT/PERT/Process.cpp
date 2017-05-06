/*
* Process.cpp
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#include "Process.h"

Process::Process()
{
	expected_time = -1;
	wariancja = 0;
}

Process::~Process()
{
	if (previous_processes_ids)
		delete[]previous_processes_ids;
}

void Process::calculate_expected_time()
{
	expected_time = (optimistic_time + 4 * probable_time + pesimistic_time) / 6;
}

void Process::calculate_wariancja()
{
	wariancja = ((pesimistic_time - optimistic_time) / 6)*((pesimistic_time - optimistic_time) / 6);
}