#ifndef FILTER_H
#define FILTER_H

#include <vector>

class Filter {
    public:
        /**
         * Abstract Function
         */
        virtual std::vector<double> update(std::vector<double> &) = 0;
};

#endif
