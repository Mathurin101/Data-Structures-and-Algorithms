/*
File:			DSA_Main.cpp
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
Created:		11.21.2020
Last Modified:	08.03.2024
Purpose:		Main file for SDV2213 Labs
				Contains menu code and calls to all unit tests
Notes:			Property of Full Sail University

				DO NOT CHANGE ANY CODE IN THIS FILE BEYOND
				CHECKING FOR MEMORY LEAKS
*/

/************/
/* Includes */
/************/
#include <crtdbg.h>
#include "TestHarness.h"

// Entry point of the program
int main() {
	// Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function call will set a breakpoint at the location of a leaked block
	// Set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);

	TestHarness test;

	test.Init();
	test.Run();


	return 0;
}