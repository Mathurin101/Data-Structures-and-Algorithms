/*
File:			TestHarness.cpp
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
Created:		10.20.2021
Last Modified:	10.20.2021
Purpose:
Notes:			Property of Full Sail University

				DO NOT CHANGE ANY CODE IN THIS FILE
*/

/************/
/* Includes */
/************/
#include "TestHarness.h"
#include "ResultsLib.h"
#include "UnitTests_Lab2.h"
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
#if (LAB2_PALINDROME_NUMBER)	|| \
	(LAB2_FILL_FILE)			|| \
	(LAB2_FILL_ARRAY)			|| \
	(LAB2_CLEAR)				|| \
	(LAB2_SORT_ASCENDING)		|| \
	(LAB2_SORT_DESCENDING)		|| \
	(LAB2_BRACKETS)				|| \
	(LAB2_CONTAINS_TRUE)		|| \
	(LAB2_CONTAINS_FALSE)		|| \
	(LAB2_MOVE_PALINDROMES)
	UnitTests_Lab2::FullBattery();
#else
	std::cout << "No unit tests are turned on\n";
#endif
}