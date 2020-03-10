#include "rangeFilter.hpp"

RangeFilter::RangeFilter(double range_min, double range_max)
{
    this->min_range = range_min;
    this->max_range = range_max;
}

bool RangeFilter::setMinRange(double range)
{
    if (range < 0 || range > this->max_range) {
        return false;
    } else {
        this->min_range = range;
        return true;
    }
}

bool RangeFilter::setMaxRange(double range)
{
    if (range < this->min_range) {
        return false;
    } else {
        this->max_range = range;
        return true;
    }
}

std::vector<double> RangeFilter::update(std::vector<double> &ranges)
{
    std::vector<double> ans;
    for (int i = 0; i < ranges.size(); ++i) {
        if (ranges[i] < this->min_range) {
            ans.push_back(this->min_range);
        } else if (ranges[i] > this->max_range) {
            ans.push_back(this->max_range);
        } else {
            ans.push_back(ranges[i]);
        }
    }
    return ans;
}