/*
* Critical_path_designation.h
*
*  Created on: Mar 16, 2017
*      Author: Maria, Wojciech
*/

#ifndef CRITICAL_PATH_DESIGNATION_H_
#define CRITICAL_PATH_DESIGNATION_H_

#include <iostream>
#include <string>
#include "Process.h"
using namespace std;

struct nodeLS
{
	int Do;
	double Dys;
	nodeLS* next;
};

struct Kraw
{
	int Od, Do;
	double Dys;
	Kraw* next;
};

class Critical_path_designation
{
private:
	int *critical_path;

public:
	int number_of_critical_path_processes;
	Critical_path_designation() {}
	~Critical_path_designation();
	int * Designate_critical_path_by_logic_table(int amount_of_processes, Process * processes);

private:
	int * Calculate_critical_path(int amount_of_processes, Process * processes);
	double* AlgorytmDijkstry(nodeLS** LS, int size, int S, int *critical_path);

	void DeleteKraw(Kraw *&Q);
	void DodajKraw(Kraw *&Q, int Od, int Do, int Dys);
	void DodajDoKraw(Kraw *&Q, int Od, int Do, int Dys);

	void WyswietlLS(nodeLS **LS, int size);
	void CzytajLS(nodeLS *Q);

	nodeLS **StworzListeSasiedztwa(double **MS, int size);
	double **StworzMacierzSasiedztwa(double **MS, int amount_of_processes, Process *processes);

};

#endif /*CRITICAL_PATH_DESIGNATION_H_*/
