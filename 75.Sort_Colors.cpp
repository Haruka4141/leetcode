#include <vector>

using namespace std;

//(Hint)
//https://en.wikipedia.org/wiki/Counting_sort, O(N+K)

void sortColors(vector<int>& nums)  //submission, 
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0: swap(nums[mid], nums[low]);
            mid++; low++;
            break;

        case 1: mid++;
            break;

        case 2: swap(nums[mid], nums[high]);
            high--;
            break;
        }
    }
}

//Insertion sort(Best O(N), worst O(N^2)), but in-place
void sortColors_insertion(vector<int>& nums) 
{
    for (int i = 1; i < nums.size(); ++i)
    {
        int temp = nums[i];
        int j = i;
        while (j > 0 && nums[j-1] >= temp)
        {
            nums[j] = nums[j - 1];
            --j;
        }
        nums[j] = temp;
    }
}

int main()
{
    vector<int> nums = { 2, 0, 2, 1, 1, 0 };
    sortColors(nums);

    return 0;
}
