#include "MultiplyMode.h"

void MultiplyMode::run(int argc, char* argv[]) {
	std::vector<int> fst = std::vector<int>();
	std::vector<int> sec = std::vector<int>();
	std::vector<int> product = std::vector<int>();
	std::string fst_str(argv[2]);
	std::string sec_str(argv[3]);

	bool is_fst_valid = NumParser::setNumber(fst_str, fst);
	if (!is_fst_valid) { 
		displayArgunetsError("first argument is not valid");
		return;
	}

	bool is_sec_valid = NumParser::setNumber(sec_str, sec);
	if (!is_sec_valid) {
		displayArgunetsError("second argument is not valid");
		return;
	}

	NumParser::align(fst, sec);
	FFT_Multiplyer::multiply(fst, sec, product);
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "Product:" << std::endl;
	NumWriter::writeTo(std::cout, product);
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void MultiplyMode::displayArgunetsError(std::string error_mes) {
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << error_mes << std::endl;
	std::cout << "Argument must be >= 0 and you can use only digits from 0 to 9" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	return;
}

