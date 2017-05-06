/*
* Critical_path_designation.cpp
*
*  Created on: Mar 16, 2017
*      Author: Maria, Wojciech
*/

#include "Critical_path_designation.h"

Critical_path_designation::~Critical_path_designation()
{
	if (critical_path)
		delete[] critical_path;
}

int * Critical_path_designation::Designate_critical_path_by_logic_table(int amount_of_processes, Process * processes)
{
	critical_path = Calculate_critical_path(amount_of_processes, processes);
	return critical_path;
}

nodeLS **Critical_path_designation::StworzListeSasiedztwa(double **MS, int size)
{
	nodeLS **LS = new nodeLS *[size];
	for (int i = 0; i<size; i++)
		LS[i] = NULL;
	for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			if (MS[i][j]>-1)
			{
				nodeLS *pom = new nodeLS;
				pom->Do = j;
				pom->Dys = MS[i][j];
				pom->next = LS[i];
				LS[i] = pom;
				pom = NULL;
			}
	return LS;
}

void Critical_path_designation::CzytajLS(nodeLS *Q)
{
	nodeLS *p = Q;
	while (p != NULL)
	{
		cout << "--(" << p->Dys << ")" << "-->" << p->Do << endl;
		cout << " ";
		p = p->next;
	}
	cout << endl;
}

void Critical_path_designation::WyswietlLS(nodeLS **LS, int size)
{
	for (int i = 0; i<size; i++)
	{
		cout << i;
		CzytajLS(LS[i]);
		cout << endl;
	}
}

void Critical_path_designation::DodajDoKraw(Kraw *&Q, int Od, int Do, int Dys)
{
	Kraw *p = new Kraw;
	p->Od = Od;
	p->Do = Do;
	p->Dys = Dys;
	p->next = Q;
	Q = p;
}

void Critical_path_designation::DodajKraw(Kraw *&Q, int Od, int Do, int Dys)
{
	if (Q == NULL || Q->Dys<Dys)
		DodajDoKraw(Q, Od, Do, Dys);
	else
	{
		Kraw *p = Q;
		while (p->next != NULL && p->next->Dys>Dys)
			p = p->next;
		DodajDoKraw(p->next, Od, Do, Dys);
	}
}

void Critical_path_designation::DeleteKraw(Kraw *&Q)
{
	if (Q != NULL)
	{
		Kraw *p = Q;
		Q = Q->next;
		delete p;
	}
}

double* Critical_path_designation::AlgorytmDijkstry(nodeLS** LS, int size, int S, int *critical_path)
{
	double *odl = new double[size];
	int *pop = new int[size];

	for (int i = 0; i<size; i++)
	{
		odl[i] = -1;
		pop[i] = -1;
	}
	odl[S] = 0;
	pop[S] = -1;


	Kraw* Q = NULL;
	nodeLS* pom = LS[S];
	while (pom != NULL)
	{
		DodajKraw(Q, S, pom->Do, pom->Dys);
		pop[pom->Do] = S;
		odl[pom->Do] = odl[S] + pom->Dys;
		pom = pom->next;

	}
	int k;

	while (Q != NULL)
	{
		k = Q->Do;
		DeleteKraw(Q);
		pom = LS[k];
		while (pom != NULL)
		{
			if (odl[pom->Do] == -1 || odl[pom->Do]<odl[k] + pom->Dys)
			{
				DodajKraw(Q, k, pom->Do, pom->Dys);
				pop[pom->Do] = k;
				odl[pom->Do] = odl[k] + pom->Dys;
			}
			pom = pom->next;
		}
	}

	int b = size - 1;
	while (b != -1)
	{
		critical_path[b] = 1;
		b = pop[b];
	}

	return odl;
}

double **Critical_path_designation::StworzMacierzSasiedztwa(double **MS, int amount_of_processes, Process *processes)
{
	for (int i = 0; i < amount_of_processes; i++)
		for (int j = 0; j < amount_of_processes; j++)
			MS[i][j] = -1;

	int temp = 0;
	for (int i = 0; i < amount_of_processes; i++)
	{
		for (int k = 0; k < processes[i].amount_of_previous_proccesses; k++)
		{
			temp = processes[i].previous_processes_ids[k] - 1;
			MS[i][temp] = processes[i].expected_time;
		}
	}

	for (int i = 0; i < amount_of_processes; i++)
		for (int j = 0; j < amount_of_processes; j++)
			MS[i][j] = MS[j][i];

	int v = 1;
	for (int i = 1; i < amount_of_processes; i++)
	{
		for (int j = 0; j < v; j++)
			MS[i][j] = -1;

		if (v<amount_of_processes)
			v++;
	}
	return MS;
}

int * Critical_path_designation::Calculate_critical_path(int amount_of_processes, Process * processes)
{
	double **MS = new double *[amount_of_processes];
	for (int i = 0; i<amount_of_processes; i++)
		MS[i] = new double[amount_of_processes];

	MS = StworzMacierzSasiedztwa(MS, amount_of_processes, processes);

	critical_path = new int[amount_of_processes];
	for (int i = 0; i < amount_of_processes; i++)
		critical_path[i] = 0;

	nodeLS **Lista = StworzListeSasiedztwa(MS, amount_of_processes);
	WyswietlLS(Lista, amount_of_processes);
	cout << endl << endl;
	double *Tab = AlgorytmDijkstry(Lista, amount_of_processes, 0, critical_path);

	return critical_path;
}