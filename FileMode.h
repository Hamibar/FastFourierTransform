#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "NumParser.h"
#include "NumWriter.h"
#include "FFT_Multiplyer.h"

class FileMode {
public:
	static void run(int argc, char* argv[]);
private:
	static void displayArgumetsError(std::string error_mes);
	static bool fileNamesErrorHandler(std::string& in_file, std::string& out_file);
	static bool openFileErrorHandler(std::fstream& fs, std::string& file_name);
	static void performMultiplication(std::istream& is, std::ostream& os);
	static void printMultReport(int line, bool is_terminated);
};

