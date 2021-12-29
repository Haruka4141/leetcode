#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

/*
Hint1:
If we fix one of the numbers say x, we are left with the two-sum problem at hand

Hint2:
For the two-sum problem, if we fix one of the numbers, say x, we have to scan the entire array to find the next number y
which is value -x

Hint3:
The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?
*/
//brute-force sol: O(N^3)

//O(N^2) solution (slow than v2):
//https://stackoverflow.com/questions/62359366/leetcode-15-3sum-using-hash-maps
vector<vector<int>> threeSum_v3(vector<int>& nums)
{
    vector<vector<int>> res;
    set<pair<int, int>> found; // or define hash<pair<int, int>> and use unordered_set.
    unordered_set<int> dups;
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); ++i)                    // insert element or same key element  v         v insert successfully or not 
        if (dups.insert(nums[i]).second)    //unordered_set::insert(const val) will return pair< iterator , bool >
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int complement = -nums[i] - nums[j];
                auto it = seen.find(complement);
                //   v return end iterator
                if (it != end(seen) && it->second == i)     //Iterators to elements of unordered_map containers access to both the key and the mapped value. ( typedef pair<const Key, T> value_type ) 
                {
                    int v1 = min(nums[i], min(complement, nums[j]));    //min value in 3 values
                    int v2 = max(nums[i], max(complement, nums[j]));    //max

                    if (found.insert({ v1, v2 }).second)    //return a pair that pair::first set to an iterator pointing to either the newly inserted element or to the equivalent element already in the set. The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
                        res.push_back({ nums[i], complement, nums[j] });
                }                               //   ^  i + k + j  = 0, k = -i-j

                seen[nums[j]] = i;      //cannot find value, so save value num[j] and i , means nums[j] is checked by value num[i]
            }                           //using map can reduce 1 for loop that search from j = i + 1
    return res;
}


//O(N^2) solution:
//https://stackoverflow.com/questions/62359366/leetcode-15-3sum-using-hash-maps
vector<vector<int>> threeSum_v2(vector<int> &nums) 
{
    vector<vector<int>> triplets;

    std::sort(nums.begin(), nums.end());    //need sorting!  Time complexity: O(N * log(2,N))

    for (int index = 0; index < nums.size(); index++) {
        int target = -nums[index];
        int lo = -~index, hi = nums.size() - 1;     //tadpole operator, doesn't need paretheses
               // ^ == index + 1, ~- == index - 1
        if (target < 0)
            break;

        while (lo < hi) {
            int sum = nums[lo] + nums[hi];

            if (sum < target)
                lo++;

            else if (sum > target)
                hi--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[index];
                triplet[1] = nums[lo];
                triplet[2] = nums[hi];
                triplets.push_back(triplet);                //  index lo            hi
                                                            //      v v             v
                while (lo < hi && nums[lo] == triplet[1])   //e.g. -1 1 1 1 1 0 0 0 0 
                    lo++;                                   //                ^ lo will move to here, because ans is same
                                                            //
                while (lo < hi && nums[lo] == triplet[2])   //              ^ hi will move to here, break while(lo < hi)
                    hi--;
            }
        }

        while (-~index < nums.size() && nums[-~index] == nums[index])   //skip same value for index
            index++;
    }
    return triplets;
}

int main()
{
    vector<int> nums = { -1,0,1,2,-1,-4 };
    //vector<int> nums = {0};
    //vector<int> nums = { 0,0,0,0,0,0 };
    auto ans = threeSum_v3(nums);

    return 0;
}

//https://leetcode.com/problems/3sum/discuss/346895/java-on2-solution-using-hashmap-and-set
vector<vector<int>> threeSum_v4(vector<int>& nums)  //(c++) :Time Limits 
{                                                   //(Java):Much Slower & larger than v3
    vector<vector<int>> ret;
    unordered_map<int, int> map;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
        map[nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int complement = -nums[i] - nums[j];
            vector<int> triplet = { nums[i], nums[j], complement };
            auto iter = map.find(complement);
            if (iter != map.end() &&
                map[complement] > j &&
                find(ret.begin(), ret.end(), triplet) == ret.end())
                ret.push_back(triplet);
        }
    }
    return ret;
}

vector<vector<int>> threeSum(vector<int>& nums)     //{ 0,0,0,0,0,0 }  fail
{
    vector<vector<int>> ret;

    vector<int> first_index_set;
    int index1;
    for (index1 = 0; index1 < nums.size(); ++index1)
        first_index_set.push_back(index1);

    index1 = 0;
    while (index1 < first_index_set.size())
    {
        int sum = nums[index1];

        for (int second_index = 0; second_index < nums.size(); ++second_index)
        {
            if (second_index == index1)
                continue;
            sum += nums[second_index];
            for (int third_index = second_index + 1; third_index < nums.size(); ++third_index)
            {
                if (third_index == index1)
                    continue;

                if (sum + nums[third_index] == 0)
                    sum += nums[third_index];
                else
                    continue;

                if (sum == 0)
                {
                    vector<int> triplets = { nums[index1], nums[second_index], nums[third_index] };
                    ret.push_back(triplets);
                    first_index_set[index1] = -1;
                    first_index_set[second_index] = -1;
                    first_index_set[third_index] = -1;
                    break;
                }
            }
            if (sum == 0)
                break;
            else
                sum -= nums[second_index];

        }
        sum = 0;

        ++index1;
        while (index1 < first_index_set.size() && first_index_set[index1] == -1)
            ++index1;
    }
    return ret;
}