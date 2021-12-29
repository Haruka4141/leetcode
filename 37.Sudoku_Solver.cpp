#include <vector>
#include <unordered_set>
#include <bitset>

using namespace std;

vector<bitset<9>> rows;
vector<bitset<9>> cols;
vector<vector<bitset<9>>> cells;

bitset<9> getPossibleStatus(int x, int y)
{
    return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);  // OR three bit set, NOT to return possible number
}

vector<int> getNext(vector<vector<char>>& board)        //search board, return the least branch element index
{
    vector<int> ret;                                    //ret = {row_index, col_index}
    int minCnt = 10;
    for (int i = 0; i < board.size(); i++)              //row (board.size() ==  9)
    {
        for (int j = 0; j < board[i].size(); j++)       //col (board[i].size() == 9)
        {
            if (board[i][j] != '.') continue;
            auto cur = getPossibleStatus(i, j);
            if (cur.count() >= minCnt) continue;        //std::bitset::count() count set bit, if possible bitset is all set, continue
            ret = { i, j };                             
            minCnt = cur.count();                       //min_Cnt will approach to 0, ret will be the least branch index
        }
    }
    return ret;
}

void fillNum(int x, int y, int n, bool fillFlag)        //set rows, cols, cells bitsets bit. fillflag : set or reset switch
{
    rows[x][n] = (fillFlag) ? 1 : 0;
    cols[y][n] = (fillFlag) ? 1 : 0;
    cells[x / 3][y / 3][n] = (fillFlag) ? 1 : 0;
}

bool dfs(vector<vector<char>>& board, int cnt)          //depth first search, return search is complete or not
{
    if (cnt == 0) return true;                          //depth reach end

    auto next = getNext(board);                         //next is the index which has least branch (possible numbers)       <-***
    auto bits = getPossibleStatus(next[0], next[1]);
    for (int n = 0; n < bits.size(); n++)               //bits.size() == 9
    {
        if (!bits.test(n)) continue;                    //bitset::test(pos) : test whether bit at pos is set
        fillNum(next[0], next[1], n, true);             //set 3 bitset's bit
        board[next[0]][next[1]] = n + '1';              //fill board
        if (dfs(board, cnt - 1))                        //'.' count - 1, search board in depth + 1
            return true;                                
        board[next[0]][next[1]] = '.';                  //if bit is all set (branch is invaild), reset board and 3 bitsets
        fillNum(next[0], next[1], n, false);            //                          ^
    }                                                   //                          |
    return false;                                       //---------------------------
}

void solveSudoku_v2(vector<vector<char>>& board)
{
    rows = vector<bitset<9>> (9, bitset<9>());   //initialize a 9 bit set with all 0, representing 1~9 is appeared or not
    cols = vector<bitset<9>> (9, bitset<9>());
    cells = vector<vector<bitset<9>>> (3, vector<bitset<9>>(3, bitset<9>()));   //3x3 vector, which element = bitset<9>

    //Initialize bitset existing
    int cnt = 0;        //'.' count
    for (int i = 0; i < board.size(); i++)          //row
    {
        for (int j = 0; j < board[i].size(); j++)   //col
        {
            cnt += (board[i][j] == '.');
            if (board[i][j] == '.') continue;
            int n = board[i][j] - '1';
            rows[i] |= (1 << n);        //set bit to 1
            cols[j] |= (1 << n);
            cells[i / 3][j / 3] |= (1 << n);
        }
    }
    dfs(board, cnt);
}

int main()
{
    vector<vector<char>> board
    { 
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku_v2(board);

    return 0;
}

//using backtracking
void solve_element(vector<vector<char>>& board,
    int& index, vector<unordered_set<int>>& rows,
    vector<unordered_set<int>>& cols,
    vector<unordered_set<int>>& blocks,
    bool& complete)
{
    if (index > 80)
    {
        complete = true;
        return;
    }

    if (board[index / 9][index % 9] != '.')
    {
        solve_element(board, ++index, rows, cols, blocks, complete);
        --index;
    }
    else
    {
        for (int num = 1; num <= 9; ++num)
        {
            if (rows[index / 9].count(num) || cols[index % 9].count(num) || blocks[(index / 27) * 3 + (index % 9) / 3].count(num))
                continue;
            else
            {
                rows[index / 9].insert(num);
                cols[index % 9].insert(num);
                blocks[(index / 27) * 3 + (index % 9) / 3].insert(num);
                board[index / 9][index % 9] = num + '0';
                solve_element(board, ++index, rows, cols, blocks, complete);
                if (!complete)
                {
                    --index;
                    rows[index / 9].erase(num);
                    cols[index % 9].erase(num);
                    blocks[(index / 27) * 3 + (index % 9 / 3)].erase(num);
                    board[index / 9][index % 9] = '.';
                }
                else
                    return;
            }
        }
    }

}

void solveSudoku(vector<vector<char>>& board)
{
    vector<unordered_set<int>> rows(9), cols(9), blocks(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                rows[i].insert(board[i][j] - '0');
                cols[j].insert(board[i][j] - '0');
                blocks[(i / 3) * 3 + j / 3].insert(board[i][j] - '0');
            }
        }
    }

    int index = 0;
    bool complete = false;
    solve_element(board, index, rows, cols, blocks, complete);
}