#include <vector>

int removeDuplicates_solution(std::vector<int>& nums)     //solution
{
    if (nums.empty())
        return 0;

    int index = 0;
        
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[index] != nums[i])
            nums[++index] = nums[i];
    }

    return index + 1;
}

int main()
{
    std::vector<int> vec = { 1, 1, 2, 3, 5, 5};
    removeDuplicates_solution(vec);

    return 0;
}

int removeDuplicates(std::vector<int>& nums)
{

    if (nums.size() == 0)
        return 0;

    int temp = nums.front();
    int position = 1;

    while (position < nums.size())
    {
        if (temp == nums[position])
            nums.erase(nums.begin() + position);        //vector::erase(): Iterators, pointers, and references pointing to position and beyond are invaildated.
        else
        {
            temp = nums[position];
            ++position;
        }
    }
    return nums.size();
}