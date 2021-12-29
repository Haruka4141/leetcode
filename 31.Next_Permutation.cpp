#include <vector>

using namespace std;

/*
lexicographical = aphabetical order

[1, 10, 2] is lexicographical

Q: Given a vector, find "next" permutation

*/

//https://programmerall.com/article/39401080776/
void nextPermutation(vector<int>& nums)
{
    int i;
    for (i = nums.size() - 2; i >= 0; --i)
    {
        if (nums[i] < nums[i + 1])
            break;
    }

    if (i >= 0)
    {
        int j;
        //int min_error = abs(nums[i] - nums[j]);
        //for (int k = j + 1; k < nums.size(); ++k)
        //{
        //    if (abs(nums[i] - nums[k]) < min_error)       //abs() will make -+value both are aceptable, but what we need is smaller one
        //        j = k;
        //}
        for (j = nums.size() - 1; j > i; --j)
        {
            if (nums[j] > nums[i])
                break;
        }

        int temp = nums[i];         //std::swap()
        nums[i] = nums[j];
        nums[j] = temp;

    }
    ++i;
    for (int k = nums.size() - 1; k > i; --k, ++i)      //std::reverse(iterator, iterator)
    {
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}


int main()
{
    vector<int> a = { 3,2,1 };
    nextPermutation(a);
    
    return 0;
}