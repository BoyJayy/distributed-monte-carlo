#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>
#include <string>
#define ld long double


int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_samples> <seed>" << std::endl;
        return 1;
    }
    constexpr ld a = 0.0;
    constexpr ld b = 2.0;
    size_t pos_n = 0;
    int N;
    int seed;
    try {
        N = std::stoi(argv[1], &pos_n);
        if (pos_n != std::string(argv[1]).length()) {
            throw std::invalid_argument("Invalid number of samples");
        }
        seed = std::stoi(argv[2], &pos_n);
        if (pos_n != std::string(argv[2]).length()) {
            throw std::invalid_argument("Invalid seed");
        }
        if (N < 1 || N > 1000000000) {
            throw std::out_of_range("Number of samples must be between 1 and 1,000,000,000");
        }
        if (seed < 0 || seed > 1000000000) {
            throw std::out_of_range("Seed must be between 0 and 1,000,000,000");
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Argument out of range: " << e.what() << std::endl;
        return 1;
    }    
    std::mt19937_64 rng(seed);
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