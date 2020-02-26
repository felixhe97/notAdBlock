#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include <vector>

class MedianFilter {

    MedianFilter(int &);

    std::vector<double> update(std::vector<double> &);
}

#endif
