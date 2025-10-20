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
        int count = 1;

        // tempo de término do último intervalo adicionado
        long prev_end = numeric_limits<long>::min();

        for (size_t i = 1; i < intervals.size(); ++i)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Adiciona o intervalo se não houver sobreposição
            if (start >= prev_end)
            {
                count++;
                prev_end = end;
            }
        }

        return intervals.size() - count;
    }
};