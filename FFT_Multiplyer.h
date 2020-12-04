#pragma once
#include <vector>
#include <complex>
constexpr double pi = 3.14159265358979323846;

class FFT_Multiplyer {
public:
	static void multiply(const std::vector<int>& num_fst, const std::vector<int>& num_sec, std::vector<int>& out);
private:
	static void normalizeBase10(std::vector<int>& num);
	static void fft(std::vector<std::complex<double>>& num, bool invert); // num in bit reversed order
	static void transformByOrder(std::vector<std::complex<double>>& num, std::vector<int>& order);
	static void getBitReversedOrder(std::vector<int>& order);
};

