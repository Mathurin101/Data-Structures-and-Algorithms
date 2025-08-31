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
#include "UnitTests_Lab8.h"
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
		if (extension == "bin" || extension == "check" || extension == "student" || extension == "txt" || extension == "compressed" || extension == "original")
			std::filesystem::remove(entry);
	}
}

void TestHarness::Run() {
#if (HUFFMAN_CTOR)					|| \
	(HUFFMAN_GENERATE_FREQUENCY)	|| \
	(HUFFMAN_GENERATE_LEAFLIST)		|| \
	(HUFFMAN_GENERATE_TREE)			|| \
	(HUFFMAN_CLEAR_TREE)			|| \
	(HUFFMAN_DTOR)					|| \
	(HUFFMAN_GENERATE_ENCODING)		|| \
	(HUFFMAN_COMPRESS)				|| \
	(HUFFMAN_DECOMPRESS)			|| \
	(HUFFMAN_DEBUG_COMPRESS)		|| \
	(HUFFMAN_DEBUG_DECOMPRESS)
	UnitTests_Lab8::FullBattery();
#else
	std::cout << "No unit tests are turned on\n";
#endif
}

