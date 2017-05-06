//============================================================================
// Name        : PERT.cpp
// Author      : Maria, Wojciech
// Description : Application to calculate probability of finishing process before directive time in C++
//============================================================================

#include "PERT.h"


using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	PERTGUI::PERT forma;
	Application::Run(%forma);
	return 0;
}