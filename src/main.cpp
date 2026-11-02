#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>
#define ld long double

constexpr int N = 100000; 

int main(int argc, char** argv) {
    std::mt19937_64 rng(42);
    constexpr ld a = 0.0;
    constexpr ld b = 2.0;
    std::uniform_real_distribution<ld> dist(a, b);
    ld sum = 0.0;
    for (int i = 0; i < N; i++) {
        const ld x = dist(rng);
        sum += x*x;
    }
    const ld mean = sum / N;
    const ld integral = (b - a) * mean;
    // просчет дает 8/3 с ним мы сравниваем наш результат
    const ld exact = 8.0 / 3.0;
    const ld error = std::abs(integral - exact);
    std::cout << std::setprecision(10) << "Integral: " << integral << std::endl;
    std::cout << std::setprecision(10) << "Exact: " << exact << std::endl;
    std::cout << std::setprecision(10) << "Error: " << error << std::endl;
    return 0;
}