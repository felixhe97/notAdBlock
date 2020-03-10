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
         * 
         * @param range_min 
         * @param range_max
         */
        RangeFilter(double range_min = 0.03, double range_max = 50);

        /**
         * Set the minimum range
         * 
         * @param new_range_min
         * @returns true if floor was set, false otherwise
         */
        bool setMinRange(double);

        /**
         * Set the maximum range
         * 
         * @param new_range_max
         * @returns true if ceiling was set, false otherwise
         */
        bool setMaxRange(double);

        /**
         * Update
         * 
         * Returns an array of cropped values where every
         * value smaller than a minimum range is modified to be
         * the minimum range, and every value larger than a maximum
         * range is modified to be the maximum range
         * 
         * @param arr array of doubles
         * @returns array of cropped doubles
         */
        std::vector<double> update(std::vector<double> &);
};

#endif
