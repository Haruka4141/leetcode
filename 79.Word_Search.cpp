#include <string>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> dirs = { {-1,0},{0,1},{1,0},{0,-1} };
vector<vector<bool>> visited;

bool check(vector<vector<char>>& board, string& word, int start, int row, int col) 
{
    if (visited[row][col]) 
        return false;
    if (start == word.size() - 1) 
        return true;
    visited[row][col] = true;
    bool match = false;
    for (auto dir : dirs) 
    {
        int px = row + dir[0];
        int py = col + dir[1];
        if (px >= 0 && px < m && py >= 0 && py < n && board[px][py] == word[start + 1]) 
        {
            match |= check(board, word, start + 1, px, py);     //match = match | check()
        }
        if (match) 
            return match;
    }
    visited[row][col] = false;
    return match;
}
void reverseString(string& word) 
{
    int prefix_count = 0, postfix_count = 0;
    char prev = word[0];
    for (int i = 0; i < word.size() && word[i] == prev; ++i) 
    {
        prev = word[i];
        ++prefix_count;
    }
    prev = word.back();
    for (int i = word.size() - 1; i >= 0 && word[i] == prev; --i) 
    {
        prev = word[i];
        ++postfix_count;
    }
    if (prefix_count > postfix_count)
        reverse(word.begin(), word.end());
}
bool exist(vector<vector<char>>& board, string word) 
{
    m = board.size(), n = board[0].size();
    visited.resize(m, vector<bool>(n));
    reverseString(word);
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (word[0] == board[i][j] && check(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}

//pass, but slow
void exist_recursive(vector<vector<char>>& board, string word, int row, int col, int word_index, bool& ret, vector<vector<bool>>& flag)
{
    if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0)
        return;

    if (!flag[row][col] || ret)
        return;

    if (board[row][col] != word[word_index]) 
        return;
    
    if (word_index == word.size() - 1)
    {
        ret = true;
        return;
    }
 
    flag[row][col] = false;

    exist_recursive(board, word, row - 1, col, word_index + 1, ret, flag);
    exist_recursive(board, word, row + 1, col, word_index + 1, ret, flag);
    exist_recursive(board, word, row, col - 1, word_index + 1, ret, flag);
    exist_recursive(board, word, row, col + 1, word_index + 1, ret, flag);

    flag[row][col] = true;
}

bool exist_v1(vector<vector<char>>& board, string word) 
{
    bool ret = false;
    vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), true));

    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            exist_recursive(board, word, i, j, 0, ret, flag);

    return ret;
}

int main()
{
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    auto ans = exist(board, "AAAB");

    return 0;
}