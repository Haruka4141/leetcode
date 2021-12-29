#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) 
{
    vector<vector<int>> ret(n, vector<int>(n, 0));

    int row_start = 0, col_start = 0;
    int row_end = n - 1, col_end = n - 1;    

    int index = 0;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; ++i)
        {
            ++index;
            ret[row_start][i] = index;
        }
        ++row_start;

        for (int i = row_start; i <= row_end; ++i)
        {
            ++index;
            ret[i][col_end] = index;
        }
        --col_end;

        if (row_start <= row_end)
            for (int i = col_end; i >= col_start; --i)
            {
                ++index;
                ret[row_end][i] = index;
            }
        --row_end;

        if (col_start <= col_end)
            for (int i = row_end; i >= row_start; --i)
            {
                ++index;
                ret[i][col_start] = index;
            }
        ++col_start;
    }
    
    return ret;
}

int main()
{
    auto ans = generateMatrix(2);


    return 0;
}