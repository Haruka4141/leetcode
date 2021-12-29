#include <string>

using namespace std;
//Palindrome: reading it forwards or backwards is the same word

string longestPalindrome_v3(string s)      //Leetcode submission
{

    if (s.length() == 1)
        return s;

    int min_start = 0, max_len = 1;         //min_start: substr begin index

    for (int i = 0; i < s.size();) 
    {                             //  v because checking is extending from s[i]
        if (s.size() - i <= max_len / 2)        //if "", return "" / if remain substr is smaller than (max_len / 2), break
            break;                                

        int j = i, k = i;     //j=left, k=right
                              //and == &&
        while (k < s.size() - 1 and s[k + 1] == s[k])   //skip repeat char from the begin
            ++k;

        i = k + 1;  //set new i after repeated char(if has), or ++i
                                  //  v:avoid i = 0 runtime error
        while (k < s.size() - 1 and j > 0 and s[k + 1] == s[j - 1])     //set k = j as center, extend 1 and check same or not
        {
            ++k;
            --j;
        }

        int new_len = k - j + 1;                        //set repeated char length

        if (new_len > max_len) {                        //refresh max_len
            min_start = j;
            max_len = new_len;
        }
    }
    return s.substr(min_start, max_len);
    //substr(pos, len):
    //The substring is the portion of the object that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).
}



string longestPalindrome_v2(string s)       //runtime: 300~400ms
{
    for (int length = s.size(); length > 0; --length)
    {
        
        int begin = 0;

        while (begin + length <= s.size())
        {
            int tmp_b = begin;
            int tmp_e = begin + length - 1;

            while (s[tmp_b] == s[tmp_e])
            {
                if (tmp_b - tmp_e == 1 || tmp_b == tmp_e)
                    break;
                ++tmp_b;
                --tmp_e;
            }

            if (tmp_b - tmp_e == 1 || tmp_b == tmp_e)
                return s.substr(begin, length);
            else
                ++begin;
        }
    }
    return "";  //pass for MSVC, compile error on GNU

}


int main()
{

    string ans = longestPalindrome_v3("aacabdkacaa");
    //string ans = longestPalindrome_v2("cbbd");
    //string ans = longestPalindrome_v2("a");

    return 0;
}


string longestPalindrome(string s)  //"aacabdkacaa" fail
{
    int begin = 0;
    int end = 0;
    int max_len = 1;

    for (int i = 0; i < s.size() - 1; ++i)
    {
        int j = s.size() - 1;

        while (s[i] != s[j] && j != i)
            --j;

        int tmp_i = i + 1;
        int tmp_j = j - 1;

        while (s[tmp_i] == s[tmp_j])
        {
            if (tmp_i - tmp_j == 1 || tmp_i == tmp_j)
                break;
            ++tmp_i;
            --tmp_j;
        }

        if (tmp_i - tmp_j != 1 || tmp_i != tmp_j)
            continue;

        if (j != i && j - i + 1 > max_len)
        {

            begin = i;
            end = j;
            max_len = j - i + 1;
        }

    }
    return s.substr(begin, max_len);
}
