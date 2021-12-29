#include <vector>
#include <algorithm>

using namespace std;

//Hint: https://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
void rotate(vector<vector<int>>& matrix) 
{
    //Transpose
    for (int i = 0; i < matrix.size() - 1; ++i)
        for (int j = i + 1; j < matrix.size(); ++j)
            swap(matrix[i][j], matrix[j][i]);

    //Reverse rows
    for (auto& rows : matrix)
        reverse(rows.begin(), rows.end());
}

int main() 
{
    vector<vector<int>> matrix = { {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };
    rotate(matrix);

    return 0;
}