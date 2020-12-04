#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "NumParser.h"
#include "NumWriter.h"
#include "FFT_Multiplyer.h"

class MultiplyMode {
public:
	static void run(int argc, char* argv[]);
private:
	static void displayArgunetsError(std::string error_mes);
};

