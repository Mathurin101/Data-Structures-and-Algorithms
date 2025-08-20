/*
File:			TestHarness.cpp
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
Created:		10.20.2021
Last Modified:	08.03.2024
Purpose:
Notes:			Property of Full Sail University

				DO NOT CHANGE ANY CODE IN THIS FILE
*/

/************/
/* Includes */
/************/
#include "TestHarness.h"
#include "ResultsLib.h"
#include "UnitTests_Lab1.h"
#include <iostream>
#include <filesystem>

#ifdef _DEBUG
#pragma comment (lib, "ResultsLibD.lib")
#else
#pragma comment (lib, "ResultsLibR.lib")
#endif

bool TestHarness::verboseMode = false;

#define ROOT_FOLDER "..\\"

// Runs all the one-time only code
void TestHarness::Init() const {
	CleanUpFiles();
	
	if (sizeof(void*) != 8) {
		std::cout << "Make sure you are running your program in x64 mode\n\n";
		std::system("pause");
	}
}

void TestHarness::CleanUpFiles() const {
	std::string temp, extension;
	size_t index;
	for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {
		// Finding files to be removed
		temp = entry.path().filename().string();
		index = temp.find_last_of('.') + 1;
		extension = temp.substr(index);

		// Removing files
		if (extension == "bin" || extension == "check" || extension == "student" || extension == "txt" || extension == "compressed")
			std::filesystem::remove(entry);
	}
}

void TestHarness::Run() {
#if (LAB1_DEFAULT_CONSTRUCTOR_DEFAULTS)		|| \
	(LAB1_DEFAULT_CONSTRUCTOR_WITH_ARGS)	|| \
	(LAB1_BRACKET_OPERATOR)					|| \
	(LAB1_SIZE_ACCESSOR)					|| \
	(LAB1_CAPACITY_ACCESSOR)				|| \
	(LAB1_RESERVE_EMPTY)					|| \
	(LAB1_RESERVE_DOUBLE_CAPACITY)			|| \
	(LAB1_RESERVE_LARGER_CAPACITY)			|| \
	(LAB1_RESERVE_SMALLER_CAPACITY)			|| \
	(LAB1_APPEND_NO_RESIZE)					|| \
	(LAB1_APPEND_RESIZE)					|| \
	(LAB1_CLEAR)							|| \
	(LAB1_DESTRUCTOR)						|| \
	(LAB1_ASSIGNMENT_OPERATOR)				|| \
	(LAB1_COPY_CONSTRUCTOR)				
	UnitTests_Lab1::FullBattery();
#else
	std::cout << "No unit tests are turned on\n";
#endif
}

