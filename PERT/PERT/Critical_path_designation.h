/*
* Critical_path_designation.h
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#ifndef CRITICAL_PATH_DESIGNATION_H_
#define CRITICAL_PATH_DESIGNATION_H_

#include <iostream>
#include <string>
#include "Process.h"
using namespace std;

class Critical_path_designation
{
private:
	int *critical_path;

public:
	int number_of_critical_path_processes;
	Critical_path_designation() {}
	~Critical_path_designation();
	int * Designate_critical_path_by_logic_table(int amount_of_processes, Process * processes);
};

#endif /*CRITICAL_PATH_DESIGNATION_H_*/
