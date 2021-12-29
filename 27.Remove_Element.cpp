#include <vector>

int removeElement(std::vector<int>& nums, int val)  //solution
{
    if (nums.empty())
        return 0;

    int count = 0;
    for (int j = 0; j < nums.size(); ++j)
    {
        if (nums[j] != val)         //element not equal to val, copy the j to the front, ++count
        {                           //if equal, remain the index(count), next time the unequal element will copy to this index
            nums[count] = nums[j];
            ++count;
        }
    }
    return count;
}

int main()
{
    std::vector<int> vec = { 3,2,2,3 };
    int ans = removeElement(vec, 3);

    return 0;
}