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
#include "UnitTests_Lab7.h"
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
#if (BST_CTOR)						|| \
	(BST_NODE_CTOR)					|| \
	(BST_PUSH_EMPTY)				|| \
	(BST_PUSH_LEFT)					|| \
	(BST_PUSH_RIGHT)				|| \
	(BST_CLEAR)						|| \
	(BST_DTOR)						|| \
	(BST_CONTAINS_FOUND)			|| \
	(BST_CONTAINS_NOTFOUND)			|| \
	(BST_REMOVE_CASE0_ROOT)			|| \
	(BST_REMOVE_CASE0_LEFT)			|| \
	(BST_REMOVE_CASE0_RIGHT)		|| \
	(BST_REMOVE_CASE1_ROOT_LEFT)	|| \
	(BST_REMOVE_CASE1_ROOT_RIGHT)	|| \
	(BST_REMOVE_CASE1_LEFT_LEFT)	|| \
	(BST_REMOVE_CASE1_LEFT_RIGHT)	|| \
	(BST_REMOVE_CASE1_RIGHT_LEFT)	|| \
	(BST_REMOVE_CASE1_RIGHT_RIGHT)	|| \
	(BST_REMOVE_CASE2_CASE0)		|| \
	(BST_REMOVE_CASE2_CASE1)		|| \
	(BST_REMOVE_CASE0)				|| \
	(BST_REMOVE_CASE1)				|| \
	(BST_REMOVE_CASE2)				|| \
	(BST_REMOVE_NOT_FOUND)			|| \
	(BST_IN_ORDER_TRAVERSAL)		|| \
	(BST_ASSIGNMENT_OP)				|| \
	(BST_COPY_CTOR)
	UnitTests_Lab7::FullBattery();
#else
	std::cout << "No unit tests are turned on\n";
#endif
}

