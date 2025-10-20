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
        if (intervals.empty())
        {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end(), CompareIntervals());

        // intervalos não sobrepostos
        int count = 0;

        // tempo de término do último intervalo adicionado
        long prev_end = numeric_limits<long>::min();

        for (const auto &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
        }
        return 0;
    }
};