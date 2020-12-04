#include "NumWriter.h"

void NumWriter::writeTo(std::ostream& os, std::vector<int>& num) {
	bool is_num_started = false;
	for (int i = num.size() - 1; i >= 0; --i) {
		if (num[i] != 0) { is_num_started = true; }
		if (is_num_started) { os << num[i]; }
	}
	if (!is_num_started) { os << 0; }
	os << std::endl;
}
