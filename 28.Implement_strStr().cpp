#include <string>
#include <vector>

/*
Morris�VPratt Algorithm:
e.g.                  0 1 2 3 4 5 6
   needle          :[ A B C D A B D]
-> failure function:[-1 0 0 0 0 1 0]
                                ^ move to the needle prefix

haystack1:[ABCDABCEDDAA]
          [ABCDABD]
                 ^ move to index
                [ABCDABD]

haystack2:[ABCDACCDDDAA]
          [ABCDABD]
                ^ move to index
              [ABCABBD]
                ^ (same mismatch, need to move again)


=improve=
Knuth�VMorris-Pratt Algorithm:

modified failure function:
[ A B C D A B D]
[-1 0 0 0 0 1 0] (MP)
[-1 0 0 0-1 0 2] (KMP)

haystack2:[ABCDACCDDDAA]
          [ABCDABD]
                ^
               [ABCDABD](mismatch, index = -1)
              ->[ABCDABD]

*/

using namespace std;

vector<int> kmp(string needle)
{
    int n = needle.size();
    vector<int> next(n, 0);
    next[0] = -1;
    for (int pos = 1, cnd = 0; pos < n; ++pos, ++cnd)       //wiki persudocode https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
    {
        if (needle[pos] == needle[cnd])
            next[pos] = next[cnd];
        else
        {
            next[pos] = cnd;
            while (cnd >= 0 && needle[pos] != needle[cnd])  
                cnd = next[cnd];                            //if first char is not repeat, other chars will be all 0
        }                                                   //after appeared, following char will get cnd if it is not same, and cnd will refresh to -1 (next[0])
    }                                                       //ABACABA B C              
    return next;                                            //        ^ get cnd, cnd refresh to 1(C) 
}                                                           //          ^ not equal to A, get cnd(2), cnd refresh to -1
/*
                                                              
                                                              A  B  A  C  A  B  A  B  C
                                                             -1  0 -1  1 -1  0 -1  3  2
                                                                                   ^  ^
                                                                comp to   A  B  A  C  |   
                                                                comp to         A  B  A

*/
int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
        return 0;

    auto failure_function = kmp(needle);
    for (int i = 0, j = 0; i < haystack.size();)
    {
        if (haystack[i] == needle[j])
            ++i, ++j;
        else
        {
            j = failure_function[j];
            if (j < 0)
            {
                i-=j;
                ++j;
            }
        }
        if (j == needle.size())
            return i-j;
    }
    return -1;
}

int main()
{
    auto ff = kmp("aaaaaa");  
                             //PARTICIPATE IN PARACHUTE
                             //ABACABABC
                             //ABACD, ABACABABA 

    int ans = strStr("", "");

    return 0;
}

class Solution {                            //leetcode submission

    vector<int> kmp(string needle)
    {
        int n = needle.size();
        vector<int> next(n, 0);             //failure function
        for (int i = 1, len = 0; i < n;)
        {
            if (needle[i] == needle[len])
                next[i++] = ++len;
            else if (len)
                len = next[len - 1];
            else
                next[i++] = 0;
        }
        return next;
    }

public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();

        if (!n) return 0;

        vector<int> next = kmp(needle);

        for (int i = 0, j = 0; i < m;)
        {
            if (haystack[i] == needle[j])
                i++, j++;
            if (j == n)
                return i - j;
            if (i < m && haystack[i] != needle[j])
                j ? j = next[j - 1] : i++;
        }
        return -1;
    }
};

int strStr_v2(string haystack, string needle)   //Time limit
{
    //return haystack.find(needle);

    if (needle.length() == 0)
        return 0;

    int index = 0;
    while (index < haystack.size())
    {
        if (haystack[index] == needle[0])
        {
            int i;
            for (i = 0; i < needle.size(); ++i)
            {
                if (haystack[index + i] != needle[i])
                    break;
            }
            if (i == needle.size())
                return index;
        }
        ++index;
    }
    return -1;
}

int strStr_v1(string haystack, string needle)  //Time limit
{
    //return haystack.find(needle);

    char* p_haystack = (char*)&haystack[0];
    char* p_needle = (char*)&needle[0];

    int index = 0;
    if (needle.length() == 0)
        return 0;

    while (*p_haystack != '\0')
    {
        if (*p_haystack == *p_needle)
        {
            int i;
            for (i = 0; i < needle.size(); ++i)
            {
                if (*(p_haystack + i) != *(p_needle + i))
                    break;
            }
            if (i == needle.length())
                return index;
        }
        ++index;
        ++p_haystack;
    }

    return -1;
}

