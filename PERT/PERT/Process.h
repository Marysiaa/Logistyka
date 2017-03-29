/*
* Process.h
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#ifndef PROCESS_H_
#define PROCESS_H_

#include <iostream>
#include <string>

using namespace std;

class Process
{
public:
	double directive_time;
	int process_id, *previous_processes_ids;
	int amount_of_processes, amount_of_previous_proccesses;
	double optimistic_time, probable_time, pesimistic_time, expected_time, wariancja ;

	Process();
	~Process();
	void calculate_expected_time();
	void calculate_wariancja();

};

#endif /*PROCESS_H_*/