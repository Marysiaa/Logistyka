/*
* Data_getter.h
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#ifndef DATA_GETTER_H_
#define DATA_GETTER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Process.h"

using namespace std;

class Data_getter
{
private:
	string file_name;
	Process * processes;
	int a_processes;
	double d_time;

public:
	Data_getter(string file_name);
	~Data_getter();

	Process * get_data();
	int get_amount_of_processes();
};

#endif /* DATA_GETTER_H_ */
/*
* Data_getter.h
*
*  Created on: Mar 16, 2017
*      Author: Maria
*/

#ifndef DATA_GETTER_H_
#define DATA_GETTER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Process.h"

using namespace std;

class Data_getter
{
private:
	string file_name;
	Process * processes;
	int a_processes;
	double d_time;

public:
	Data_getter(string file_name);
	~Data_getter();

	Process * get_data();
	int get_amount_of_processes();
};

#endif /* DATA_GETTER_H_ */
