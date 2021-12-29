#include <vector>
//#include <iostream>
#include <algorithm>

using namespace std;


//& means reference. Any change applied to the reference applied to the return variable
//e.g. int& func(): return int by reference
//     int  func(): return int by value

vector<int> twoSum(vector<int>& nums, int target)       //doesn't need to sort nums
{
    vector<int> output;
    vector<int>::iterator curr = nums.begin();
    int curr_index = 0;
    int next_index;
    for (int sum = 0; curr != nums.end(); ++curr)
    {
        sum += *curr;
        next_index = curr_index + 1;
        for (vector<int>::iterator next = curr + 1; next != nums.end(); ++next)
        { 
            sum += *next;
            if (sum == target)
            {
                output.push_back(curr_index);
                output.push_back(next_index);
                return output;
            }
            ++next_index;
            sum -= *next;
        }
        ++curr_index;
        sum = 0;
    }
    return {};
}

int main()
{
    vector<int> nums_arr = {3,2,4};
    int target = 6;

    
    auto output = twoSum(nums, target);
    // cout << "[ ";
    // for (vector<int>::iterator curr = output.begin(); curr != output.end(); ++curr)
    //     cout << *curr << " ";
    // cout << "]\n" ;
    return 0;

}