#include <vector>

using namespace std;

void merge(vector<int>& v1, int m, vector<int>& v2, int n)      //submission
{
    int p1 = m - 1;
    int p2 = n - 1;
    int i = m + n - 1;
    while (p2 >= 0)
    {
        if (p1 >= 0 && v1[p1] > v2[p2])
        {
            v1[i] = v1[p1];
            i--;
            p1--;
        }
        else
        {
            v1[i] = v2[p2];
            i--;
            p2--;
        }
    }
}

//pass, O(M+N), but slightly costs memory
void merge_v1(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int curr_index1 = 0;
    int curr_index2 = 0;

    while (curr_index2 < n)
    {
        while (nums1[curr_index1] < nums2[curr_index2] && curr_index1 < m)
        {
            ++curr_index1;
        }
        nums1.insert(nums1.begin() + curr_index1, nums2[curr_index2]);      //I think insert is costing memory
        nums1.pop_back();
        ++m;
        ++curr_index1;
        ++curr_index2;
    }
}

int main()
{
    //vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };    
    //vector<int> nums2 = { 2, 5, 6 };
    
    vector<int> nums1 = { 1};
    vector<int> nums2 = {};
    //merge(nums1, 3, nums2, 3);
    merge(nums1, 1, nums2, 0);

    return 0;
}