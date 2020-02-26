#include <iostream>
#include <vector>

#include "rangeFilter.hpp"

int main(){

    // TODO test range filter
    RangeFilter rf;
    std::vector<double> test1 = {
        0.03, 0.02, 0.0301, 0.0299, 0.3, 5, 49, 49.99, 50, 50.01, 50.0001,
        49.999, -234
    };
    for (double distance : rf.update(test1)) {
        std::cout << distance << " ";
    }
    std::cout << '\n';

    return 0;
}
