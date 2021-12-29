#include <vector>

using namespace std;

/*
Hint2:
Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line. 
This way we are compromising on the width but we are looking forward to a longer length container
*/

int maxArea_v3(vector<int>& height)     //leetcode submission (same logic to v2, but simpler and cleaner)
{
    int max = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i != j) 
    {
        int area = min(height[i], height[j]) * (j - i);
        if (area > max) 
        {
            max = area;
        }
        if (height[i] > height[j])  //right is short_side
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
    return max;
}

int maxArea_v2(vector<int>& height)     //by hint2
{
    int long_length;
    int short_length;
    int right;
    int left;

    int right_short = 0;
    if (height.front() <= height.back())
    {
        long_length = height.back();
        short_length = height.front();        
    }
    else
    {
        long_length = height.front();
        short_length = height.back();
        right_short = 1;
    }

    right = height.size() - 1;
    left = 0;
    int max_area = abs(right - left) * short_length;

    while (right > left)
    {
        if (right_short == 0)
        {
            ++left;
            if (height[left] > short_length)
            {
                short_length = height[left];
            }
            if (height[left] > long_length)
            {
                short_length = long_length;
                long_length = height[left];
                right_short = 1;
            }

        }
        else if (right_short == 1)
        {
            --right;
            if (height[right] > short_length)
            {
                short_length = height[right];
            }
            if (height[right] > long_length)
            {
                short_length = long_length;
                long_length = height[right];
                right_short = 0;
            }
        }

        if (abs(right - left) * short_length > max_area)
            max_area = abs(right - left) * short_length;
    }
    
    return max_area;
}


int main()
{
    //vector<int> height = { 1,8,6,2,5,4,8,3,7 };
    vector<int> height = { 4,3,2,1,4};
    //vector<int> height = { 10,9,8,7,6,5,4,3,2,1 };
    
    int ans = maxArea_v2(height);

    return 0;
}

int maxArea(vector<int>& height)    //Time Limit
{
    int max_area = 0;
    for (int x = 1; x < height.size(); ++x)
    {
        for (int j = 0; j + x < height.size(); ++j)
        {
            int curr_area = min(height[j], height[j + x]) * x;
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}