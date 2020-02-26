#ifndef RANGE_FILTER_H
#define RANGE_FILTER_H

#include <vector>

#include "filter.hpp"

class RangeFilter : public Filter {
    private:
        double min_range;
        double max_range;

    public:
        /**
         * Constructor
         */
        RangeFilter(double = 0.03, double = 50);

        /**
         * Destructor
         */
        ~RangeFilter(void);

        /**
         * Set the minimum range
         */
        bool setMinRange(double);

        /**
         * Set the maximum range
         */
        bool setMaxRange(double);

        /**
         * Update
         */
        std::vector<double> update(std::vector<double> &);
};

#endif
