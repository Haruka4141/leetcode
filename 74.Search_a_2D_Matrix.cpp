#include <vector>

using namespace std;

bool searchMatrix_v1(vector<vector<int>>& matrix, int target)   //submisson!
{ 
    int r = matrix.size();
    int c = matrix[0].size();
    int i = 0, j = c - 1;
    while (i < r && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) 
            j--;
        else
            i++;
    }
    return false;

}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int left = 0;
    int right = matrix.size() - 1;
    int mid = ( left + right ) / 2;

    while (left < mid)
    {
        if (target > matrix[mid][0])
            left = mid;
        else if (target < matrix[mid][0])
            right = mid - 1;
        else
            return true;
        mid = (left + right) / 2;
    }

    int row;
    if (target >= matrix[right][0])
        row = right;
    else
        row = left;
    
    left = 0;
    right = matrix[row].size() - 1;
    mid = (left + right) / 2;

    while (left < right)
    {
        if (target > matrix[row][mid])
            left = mid + 1;
        else if (target < matrix[row][mid])
            right = mid - 1;
        else
            return true;
        mid = (left + right) / 2;
    }

    if (right >= 0 && matrix[row][right] == target)
        return true;
    else
        return false;
}

int main()
{
    vector<vector<int>> matrix = { {1}, {3} };
    //vector<vector<int>> matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, { 23, 30, 34, 60} };
    auto ans = searchMatrix(matrix, 3);

    return 0;
}