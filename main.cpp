#include <iostream>
#include <vector>

#include "rangeFilter.hpp"
#include "medianFilter.hpp"

int main(){

    RangeFilter rf;
    std::vector<double> test1 = {
        0.03, 0.02, 0.0301, 0.0299, 0.3, 5, 49, 49.99, 50, 50.01, 50.0001,
        49.999, -234
    };
    for (double distance : rf.update(test1)) {
        std::cout << distance << " ";
    }
    std::cout << '\n';

    MedianFilter mf(3);
    std::vector<std::vector<double>> testMedian = {
        {0, 1, 2, 1, 3},
        {1, 5, 7, 1, 3},
        {2, 3, 4, 1, 0},
        {3, 3, 3, 1, 3},
        {10, 2, 4, 0, 0}
    };
    for (std::vector<double> &values : testMedian) {
        for (double distance : mf.update(values)) {
            std::cout << distance << " ";
        }
        std::cout << '\n';
    }

    return 0;
}