#include <iterator>

#include "medianFilter.hpp"

MedianFilter::MedianFilter(std::size_t num_prev_scans)
{
    this->num_prev_scans = num_prev_scans;
    this->start_removing = false;
}

// init the private member variables
void inline initialize(std::vector<std::queue<double>> &q, std::vector<std::multiset<double>> &m,
    std::vector<std::multiset<double>::iterator> &i, double val) 
{
    std::queue<double> tempData;
    std::multiset<double> tempSortedData;
    tempData.push(val);
    tempSortedData.insert(val);
    q.push_back(tempData);
    m.push_back(tempSortedData);
    i.push_back(m.back().begin());
}

// computer the median of window
double inline findMedian(std::queue<double> &q, std::multiset<double>::iterator &it, double val) 
{
    if (q.size() % 2) { // odd length
        if (*it <= val) {
            it = std::next(it);
        }
        return *it;
    } else { // even length
        if (*it > val) {
            it = std::prev(it);
        }
        return *it + (*std::next(it) - *it) * 0.5;
    }
}

// remove oldest value from multiset, modify pointer
void inline balanceSortedData(std::queue<double> &q, std::multiset<double> &m,
    std::multiset<double>::iterator &it)
{
    std::multiset<double>::iterator toRemove = m.lower_bound(q.front());
    if (q.size() % 2) { // odd length
        if (*toRemove >= *it) {
            it = std::prev(it);
        }
    } else { // even length
        if (*toRemove <= *it) {
            it = std::next(it);
        }
    }
    m.erase(toRemove);
    q.pop();
}

std::vector<double> MedianFilter::update(std::vector<double> &scans)
{
    if (!this->start_removing) {
        if (this->num_prev_scans) {
            --this->num_prev_scans;
        } else {
            this->start_removing = true;
        }
    }

    std::vector<double> ans;
    if (this->data.empty()){
        for (std::size_t i = 0; i < scans.size(); ++i) {
            initialize(this->data, this->sorted_data, this->iterators, scans[i]);
        }
        ans = scans;
    } else {
        for (std::size_t i = 0; i < scans.size(); ++i) {
            this->data[i].push(scans[i]);
            this->sorted_data[i].insert(scans[i]);

            ans.push_back(findMedian(this->data[i], this->iterators[i], scans[i]));
            if (this->start_removing) {
                balanceSortedData(this->data[i], this->sorted_data[i], this->iterators[i]);
            }
        }
    }
    return ans;
}