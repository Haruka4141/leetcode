#include <vector>
#include <algorithm>

using namespace std;

//reference: https://leetcode.com/problems/4sum/discuss/238725/ksum-java-solution-intuitive-and-clean
vector<vector<int>> kSum(vector<int>, int, int, int);

vector<vector<int>> fourSum_v2(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    auto ret = kSum(nums, target, 4, 0);
    return ret;
}


vector<vector<int>> kSum(vector<int> nums, int target, int k, int start)   //same logic to foursum_v1, using recursive function to break k sum into 2sum
{
    vector<vector<int>> ret;

    if (k == 2)
    {
        int low = start;
        int high = nums.size() - 1;
        while(low < high)
        {
            if (nums[low] + nums[high] < target)        
                ++low;
            else if (nums[low] + nums[high] > target)
                --high;
            else
            {
                vector<int> vec = { nums[low], nums[high] };
                ret.push_back(vec);
                while (low < high && nums[low] == vec[0])       //skip same value
                    ++low;
                while (low < high && nums[high] == vec[1])
                    --high;
                //while (low < high && nums[low] == nums[++low]);     //<-***   this will generate low = high
                //while (low < high && nums[high] == nums[--high]);   //<-***   useless?
            }
        }
        return ret;
    }
    else
    {
        for (int i = start; i < nums.size(); ++i)
        {
            auto temp = kSum(nums, target - nums[i], k - 1, i + 1);
            
            for (auto element : temp)
            {
                element.insert(element.begin(), nums[i]);
                ret.push_back(element);
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return ret;
    }
}

int main()
{
    //vector<int> nums = { 1,0,-1,0,-2,2 };
    //vector<int> nums = { 2,2,2,2 };
    //vector<int> nums = { -2,-1,-1,1,1,2,2 };
    vector<int> nums = { -3,-2,-1,0,0,1,2,3 };
    auto ans = fourSum_v2(nums, 0);

    return 0;
}

vector<vector<int>> fourSum_v1(vector<int>& nums, int target)      //extract i & j, break into twoSum
{
    vector<vector<int>> ret;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int sum = nums[i] + nums[j];

            int low = j + 1;
            int high = nums.size() - 1;

            while (low < high)
            {
                if (nums[low] + nums[high] < target - sum)
                {
                    ++low;
                }
                else if (nums[low] + nums[high] > target - sum)
                {
                    --high;
                }
                else
                {
                    vector<int> quadruplet = { nums[i], nums[j], nums[low], nums[high] };
                    ret.push_back(quadruplet);

                    //while (low + 1 < nums.size() && nums[low + 1] == nums[low])
                    while (low < high && nums[low] == quadruplet[2])
                        ++low;
                    while (low < high && nums[high] == quadruplet[3])
                        --high;
                }
            }

            while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                ++j;
        }

        while (i + 1 < nums.size() - 1 && nums[i + 1] == nums[i])
            ++i;
    }
    return ret;
}
