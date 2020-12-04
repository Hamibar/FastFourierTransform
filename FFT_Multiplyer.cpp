#include "FFT_Multiplyer.h"

void FFT_Multiplyer::multiply(const std::vector<int>& fst_num, const std::vector<int>& sec_num, std::vector<int>& out) {
	out.resize(fst_num.size(), 0);
	auto complex_fst_num = std::vector<std::complex<double>>(fst_num.begin(), fst_num.end());
	auto complex_sec_num = std::vector<std::complex<double>>(sec_num.begin(), sec_num.end());
	std::vector<int> perm_order(complex_fst_num.size());
	getBitReversedOrder(perm_order);

	transformByOrder(complex_fst_num, perm_order);
	transformByOrder(complex_sec_num, perm_order);
	fft(complex_fst_num, false);
	fft(complex_sec_num, false);

	for (size_t i = 0; i < complex_fst_num.size(); ++i) {
		complex_fst_num[i] *= complex_sec_num[i];
	}
	transformByOrder(complex_fst_num, perm_order);
	fft(complex_fst_num, true);
	for (size_t i = 0; i < complex_fst_num.size(); i++) {
		out[i] = static_cast<int>(complex_fst_num[i].real() + 0.5);
	}
	normalizeBase10(out);
}

void FFT_Multiplyer::normalizeBase10(std::vector<int>& num) {
	int carry = 0;
	for (size_t i = 0; i < num.size(); ++i) {
		num[i] += carry;
		carry = num[i] / 10;
		num[i] %= 10;
	}
}

void FFT_Multiplyer::fft(std::vector<std::complex<double>>& num, bool invert) {
	auto w_pw = std::vector<std::complex<double>>(num.size(), 0);
	for (size_t len = 2; len <= num.size(); len <<= 1) {
		double ang = 2 * pi / len * (invert ? -1 : 1);
		auto wn = std::complex<double>(cos(ang), sin(ang));
		w_pw[0] = std::complex<double>(1, 0);
		for (size_t i = 1; i < len / 2; ++i) {
			w_pw[i] = w_pw[i - 1] * wn;
		}
		for (size_t i = 0; i < num.size(); i += len) {
			for (size_t j = 0; j < len / 2; ++j) {
				std::complex<double> butterfly_add = num[i + j + len / 2] * w_pw[j];
				num[i + j + len / 2] = num[i + j] - butterfly_add;
				num[i + j] += butterfly_add;
			}
		}
	}
	if (invert) {
		for (int i = 0; i < num.size(); ++i) {
			num[i] /= num.size();
		}
	}
}

void FFT_Multiplyer::transformByOrder(std::vector<std::complex<double>>& num, std::vector<int>& order) {
	for (size_t i = 0; i < num.size(); ++i) {
		if (i < order[i]) {
			std::swap(num[i], num[order[i]]);
		}
	}
}

void FFT_Multiplyer::getBitReversedOrder(std::vector<int>& order) {
	int lg_n = 0;
	while ((1 << lg_n) < order.size())  ++lg_n;

	for (size_t i = 0; i < order.size(); ++i) {
		order[i] = 0;
		for (int j = 0; j < lg_n; ++j) {
			if (i & (1 << j)) {
				order[i] |= 1 << (lg_n - 1 - j);
			}
		}
	}
}
