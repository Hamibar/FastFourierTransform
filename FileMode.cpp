#include "FileMode.h"

void FileMode::run(int argc, char* argv[]) {
	std::string in_file(argv[2]);
	std::string out_file(argv[3]);
	bool is_names_invalid = fileNamesErrorHandler(in_file, out_file);
	if (is_names_invalid) {  return; }

	std::fstream is(in_file, std::istream::in);
	bool is_input_not_open = openFileErrorHandler(is, in_file);
	if (is_input_not_open) { return; }

	std::fstream os(out_file, std::istream::out);
	bool is_out_not_open = openFileErrorHandler(os, out_file);
	if ( is_out_not_open) {  return; }

	performMultiplication(is, os);
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

bool FileMode::fileNamesErrorHandler(std::string& in_file, std::string& out_file) {
	if (in_file == out_file) {
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "Intput and output must be different files." << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		return true;
	}
	return false;
}

bool FileMode::openFileErrorHandler(std::fstream& fs, std::string& file_name) {
	if (!fs.is_open()) {
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "Error. " << file_name << " cannot be opened." << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		fs.close();
		return true;
	}
	return false;
}

void FileMode::performMultiplication(std::istream& is, std::ostream& os) {
	std::vector<int> fst = std::vector<int>();
	std::vector<int> sec = std::vector<int>();
	std::vector<int> product = std::vector<int>();
	int k = 1;
	int line = 0;
	while (!is.eof()) {
		++line;
		k = (k + 1) % 2;
		bool is_valid_num = true;
		if (k % 2 == 0) { is_valid_num = NumParser::setNumber(is, fst); }
		else { is_valid_num = NumParser::setNumber(is, sec); }

		if (!is_valid_num) {
			displayArgumetsError("Argument number " + std::to_string(line) + " is not valid.");
			printMultReport(line - 1, true);
			return;
		}

		if (line % 2 == 0) {
			NumParser::align(fst, sec);
			FFT_Multiplyer::multiply(fst, sec, product);
			NumWriter::writeTo(os, product);
		}		
	}
	printMultReport(line, false);
}

void FileMode::printMultReport(int line, bool is_terminated) {
	if (line % 2 == 1 && !is_terminated) {
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "Problem detected." << std::endl;
		std::cout << "File have odd number of multipler." << std::endl;
		std::cout << "Last line was ignored." << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << (is_terminated ? "Work terminated." : "Work completed.") << std::endl;
	std::cout << "Total multiplication: " << std::to_string(line / 2) << std::endl;
}

void FileMode::displayArgumetsError(std::string error_mes) {
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << error_mes << std::endl;
	std::cout << "Argument must be >= 0 and you can use only digits from 0 to 9" << std::endl;
	return;
}