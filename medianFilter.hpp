#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include <vector>
#include <queue>
#include <set>

#include "filter.hpp"

class MedianFilter : public Filter {
    private:
        std::size_t num_prev_scans;
        bool start_removing;
        std::vector<std::queue<double>> data;
        std::vector<std::multiset<double>> sorted_data;
        std::vector<std::multiset<double>::iterator> iterators;

    public:
        /**
         * Constructor
         * 
         * @param d number of most scans that update
         *          will use on top of update argument 
         *          to compute median values
         */
        MedianFilter(std::size_t);

        /**
         * Update
         * 
         * Returns an array of median values computed from
         * this argument and d previous arguments
         * 
         * @param arr array of doubles
         * @returns an array of median values
         */
        std::vector<double> update(std::vector<double> &);
};

#endif