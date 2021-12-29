#include <vector>
#include <algorithm>
//#include <unordered_set>
#include <bitset>

using namespace std;

/*
Lambda expression: (anonymous function)
   1   2     3       4        5  
[&, =] () mutable throw() -> int
{
    lambda body
}
1. Capture clause(lambda introducer) : []->access no variable in scope, [&]->access by reference, [=]->access by value ([&var1, var2] is avaliable)
2. Parameter list(lambda declarator) : same as function parameter list
3. Mutable specification             : enables the body of a lambda expression to modify variables that are captured by value 
   (mutable key word: permits modification of the mutable class member declared even if containing object is declared const
    e.g. mutable const int* p)

4. Exception specification           : you can use the "noexcept" to indicate that the expression doesn't throw any expception
5. Return type                       : The return type of a lambda expression is automatically deduced (follow the parameter list).

   e.g.
        int main ()
        {
            int m = 0, n = 0;              v: mutable allows n to be modified within the lambda 
   ---------[&, n] (int a) mutable { m = ++n + a} (4);
   |        //m = 5, n = 0                         
   |    }
   |                                          v:a
   -------->trasform likes a function: void f(4) { m = ++n + a}
*/

vector<vector<int>> merge_v2(vector<vector<int>>& intervals)    //leetcode submission
{
    vector<vector<int>> ans;
    //sort(RandomIt, RandomIt, compare), compare: if second argument is larger than first argument, return true
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > ans.back()[1]) 
        {
            ans.push_back(intervals[i]);        //<-***
        }
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]); //<-***
        }
    }

    return ans;
}


/*
0 <= starti <= endi <= 10^4

intervals       0   1   2   3   4
num_set         0   1   2   3   4   ...
num_interval      0   1   2   3     ...


*/

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> ret;

    bitset<10001> num_set;
    bitset<10000> num_interval;
    int interval_min = 10001;                               //set range, reduce useless loops
    int interval_max = 0;

    for (auto& element : intervals)
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
        {                                        //caution:
            ret.push_back({ begin, i - 1});      //num_set           1     1
            begin = -1;                          //interval      ... 4     5 ....
                                                 //                     0  ^ need to set new begin   
        }
        if (num_set[i] == 1 && begin == -1)
        {
            begin = i;
        }
    }

    return ret;
}

int main()
{
    //vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    //vector<vector<int>> intervals = { {1,4}, {5,6} };
    vector<vector<int>> intervals = { {2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10} };
    
    auto ans = merge(intervals);

    return 0;
}

vector<vector<int>> merge_v2(vector<vector<int>>& intervals)   //  [[2, 3], [5, 5], [2, 2], [3, 4], [3, 4]] fail
{
    vector<vector<int>> ret;

    ret.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i)
    {
        int begin = intervals[i].front();
        int end = intervals[i].back();
        for (auto& vec : ret)
        {
            if (vec.front() <= begin && begin <= vec.back() && vec.back() <= end)
            {
                vec.back() = end;
            }
            else if (vec.front() <= end && end <= vec.back() && begin <= vec.front())
            {
                vec.front() = begin;
            }
            else if (begin <= vec.front() && vec.back() <= end)
            {
                vec.front() = begin;
                vec.back() = end;
            }
            else if (vec.front() < begin && end < vec.back())
            {
                continue;
            }
            else
            {
                ret.push_back({ begin, end });
                break;
            }
        }
    }

    //unordered_set<vector<int>> set( ret.begin(), ret.end() );     //compiling fail
    sort(ret.begin(), ret.end());
    auto iter = unique(ret.begin(), ret.end());                     //The removal is done by replacing the duplicate elements by the next element that is not a duplicate
    ret.erase(iter, ret.end());

    return ret;
}