#include "NumParser.h"

void NumParser::align(std::vector<int>& fst, std::vector<int>& sec) {
	size_t max_size = std::max(fst.size(), sec.size());
	fst.insert(fst.end(), max_size - fst.size(), 0);
	sec.insert(sec.end(), max_size - sec.size(), 0);
}

bool NumParser::setNumber(std::istream& is, std::vector<int>& out_num) {
	std::string num_str;
	is >> num_str;
	return setNumber(num_str, out_num);
}

bool NumParser::setNumber(std::string& num_str, std::vector<int>& out_num) {
	bool is_valid = writeToVector(num_str, out_num);
	if (!is_valid) { return false; }
	setNeededSize(out_num);
	return true;
}

bool NumParser::writeToVector(std::string& num_str, std::vector<int>& out_num) {
	if (num_str.size() == 0) { return false; }
	std::reverse(num_str.begin(), num_str.end());
	out_num.resize(num_str.size());
	for (int i = 0; i < num_str.size(); ++i) {
		if (!isdigit(num_str[i])) { return false; }
		out_num[i] = int{ num_str[i] - '0' };
	}
	return true;
}

void NumParser::setNeededSize(std::vector<int>& out_num) {
	int lg_n = 0;
	while ((1 << lg_n) < out_num.size()) { ++lg_n; };
	size_t size = pow(2, lg_n);
	out_num.insert(out_num.end(), size - out_num.size(), 0);
	out_num.insert(out_num.end(), size, 0);
}
