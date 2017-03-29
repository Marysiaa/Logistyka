/*
* Critical_path_designation.cpp
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#include "Critical_path_designation.h"

Critical_path_designation::~Critical_path_designation()
	{
	if (critical_path)
		delete[] critical_path;
	}

int * Critical_path_designation::Designate_critical_path_by_logic_table(int amount_of_processes, Process * processes)
	{
		critical_path = new int[amount_of_processes];
		critical_path[0] = 1;
		critical_path[1] = 1;
		critical_path[2] = 1;
		critical_path[3] = 0;
		critical_path[4] = 1;
		critical_path[5] = 1;
		critical_path[6] = 0;
		critical_path[7] = 0;
		critical_path[8] = 0;
		critical_path[9] = 1;
		critical_path[10] = 0;
		critical_path[11] = 1;
		critical_path[12] = 0;
		critical_path[13] = 1;

		return critical_path;
	}