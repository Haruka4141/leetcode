#include <vector>
#include <bitset>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)    //leetcode submission
{
    vector<vector<int>> stack;
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0])
        stack.push_back(intervals[i++]);
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) 
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    stack.push_back(newInterval);
    while (i < intervals.size())
        stack.push_back(intervals[i++]);
    return stack;
}

int main()
{
    vector<vector<int>> interval = { {1,2}, {3,5}, {6,7}, {8,10}, {12,16} };
    vector<int> new_interval = { 4, 8 };

    auto ans = insert(interval, new_interval);

    return 0;
}

vector<vector<int>> insert_v1(vector<vector<int>>& intervals, vector<int>& newInterval)    //pass but stack memory exceed
{
    vector<vector<int>> ret;

    bitset<100001> num_set;
    bitset<100000> num_interval;
    int interval_min = 10001;
    int interval_max = 0;

    vector<vector<int>> temp = intervals;
    temp.push_back(newInterval);
    for (auto& element : temp)
    {
        interval_min = min(interval_min, element[0]);
        interval_max = max(interval_max, element[1]);
        for (int i = element[0]; i <= element[1]; ++i)
        {
            num_set[i] = 1;
            if (i > element[0])
                num_interval[i - 1] = 1;
        }
    }

    int begin = -1;
    for (int i = interval_min; i <= interval_max + 1; ++i)
    {
        if (i > 0 && num_interval[i - 1] == 0 && begin != -1)
        {
            ret.push_back({ begin, i - 1 });
            begin = -1;
        }
        if (num_set[i] == 1 && begin == -1)
        {
            begin = i;
        }
    }

    return ret;
}