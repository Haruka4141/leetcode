#include <string>

using namespace std;

/*
(3)

0   4   8   +4, +0
1 3 5 7 9   +2, +2
2   6   10  +0, +4

(4)
0     6     +6, +0
1   5 7     +4, +2
2 4   8     +2, +4
3     9     +0, +6

*/


string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
        
    string ret;

    for (int i = 1; i <= numRows; ++i)
    {
        int k = 2 * ( i - 1 );
        int j = (2 * numRows - 2) - k;
       
        int index = i - 1;
        int last_index = -1;
        int jk_switch = 0;
        while (index < s.size())
        {               
            if (index != last_index)
                ret.append(1, s[index]);

            last_index = index;

            if (jk_switch == 0)
            {
                index += j;
                jk_switch = 1;

            }
            else if (jk_switch == 1)
            {
                index += k;
                jk_switch = 0;
            }
        }
    }
    return ret;
}

int main()
{
    //string ans = convert("PAYPALISHIRING", 3);      //PAHNAPLSIIGYIR
    //string ans = convert("PAYPALISHIRING", 4);      //PINALSIGYAHRPI
    string ans = convert("A", 1);
    return 0;
}
