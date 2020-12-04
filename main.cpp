#include <complex>
#include <vector>
#include <iostream>
#include <cstring>
#include "FileMode.h"
#include "MultiplyMode.h"

void printHelp() {
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "command list:" << std::endl;
	std::cout << "--multiply (-m) first_number second_number" << std::endl;
	std::cout << "	multiplies 2 numbers. Product will print in standart out stream." << std::endl;
	std::cout << "--file (-f) infile outfile" << std::endl;
	std::cout << "	consistently multiplies 2 numbers from infile. Products will be write to outfile(if outfile doesn`t exist, program creates it)" << std::endl;
	std::cout << "--help (-h) " << std::endl;
	std::cout << "	print information about aviable command" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	return;
}

void printArgumentCountError() {
	std::cout << std::endl;
	std::cout << "invalid number of arguments" << std::endl;
	std::cout << "please use --help to see valid commands" << std::endl;
	return;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printArgumentCountError();
		return 0;
	}
	if (std::strcmp(argv[1], "-m") == 0 || std::strcmp(argv[1],"--multiply") == 0) {
		if (argc != 4) { printArgumentCountError(); return 0; }
		MultiplyMode::run(argc, argv);
	}
	else if (std::strcmp(argv[1], "-f") == 0 || std::strcmp(argv[1], "--file") == 0) {
		if (argc != 4) { printArgumentCountError(); return 0; }
		FileMode::run(argc, argv);
	}
	else if (std::strcmp(argv[1], "-h") == 0 || std::strcmp(argv[1], "--help") == 0) {
		printHelp();
	}
	else {
		printArgumentCountError();
		return 0;
	}
	return 0;
}