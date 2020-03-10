#ifndef FILTER_H
#define FILTER_H

#include <vector>

class Filter {
    public:
        /**
         * Abstract Function
         *
         * Returns filtered array, given input array of doubles
         *
         * @param arr values to filter
         * @returns filtered array
         */
        virtual std::vector<double> update(std::vector<double> &) = 0;
};

#endif