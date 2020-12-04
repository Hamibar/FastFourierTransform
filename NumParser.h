#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

class NumParser {
public:
	static void align(std::vector<int>& fst, std::vector<int>& sec);
	static bool setNumber(std::istream& is ,std::vector<int>& out_num);
	static bool setNumber(std::string& str, std::vector<int>& out_num);
private:
	static bool writeToVector(std::string& num_str, std::vector<int>& out_num);
	static void setNeededSize(std::vector<int>& out_num);
};

