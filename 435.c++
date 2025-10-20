#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct CompareIntervals
{
    bool operator()(const std::vector<int> &a, const std::vector<int> &b) const
    {
        return a[1] < b[1];
    }
};

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), CompareIntervals());
    }
};