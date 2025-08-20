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
#include "UnitTests_Lab3.h"
#include <iostream>
#include <filesystem>

#ifdef _DEBUG
#pragma comment (lib, "ResultsLibD.lib")
#else
#pragma comment (lib, "ResultsLibR.lib")
#endif

bool TestHarness::verboseMode = false;

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
#if (LAB3_CTOR)					|| \
	(LAB3_NODE_CTOR_DEFAULT)	|| \
	(LAB3_NODE_CTOR)			|| \
	(LAB3_ADDHEAD_EMPTY)		|| \
	(LAB3_ADDHEAD)				|| \
	(LAB3_ADDTAIL_EMPTY)		|| \
	(LAB3_ADDTAIL)				|| \
	(LAB3_CLEAR)				|| \
	(LAB3_DTOR)					|| \
	(LAB3_ITER_BEGIN)			|| \
	(LAB3_ITER_END)				|| \
	(LAB3_ITER_INCREMENT_PRE)	|| \
	(LAB3_ITER_INCREMENT_POST)	|| \
	(LAB3_ITER_DECREMENT_PRE)	|| \
	(LAB3_ITER_DECREMENT_POST)	|| \
	(LAB3_ITER_DEREFERENCE)		|| \
	(LAB3_INSERT_EMPTY)			|| \
	(LAB3_INSERT_HEAD)			|| \
	(LAB3_INSERT_MIDDLE)		|| \
	(LAB3_ERASE_EMPTY)			|| \
	(LAB3_ERASE_HEAD)			|| \
	(LAB3_ERASE_TAIL)			|| \
	(LAB3_ERASE_MIDDLE)			|| \
	(LAB3_ASSIGNMENT_OP)		|| \
	(LAB3_COPY_CTOR)			
	UnitTests_Lab3::FullBattery();
#else
	std::cout << "No unit tests are turned on\n";
#endif
}

