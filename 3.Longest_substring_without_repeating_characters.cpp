#include <string>

using namespace std;

#include <vector>

//using vector to set char dictionary (leetcode)
int lengthOfLongestSubstring(string s)
{
    int max_len = 0;
    int start = -1;
    vector<int> dict(256, -1);      //set the char index dict to "-1" (reason of using <int> instead <char>)
    for (int i = 0; i < s.length(); ++i)
    {
        if (dict[s[i]] > start)     //for repeating char, refresh the start index
            start = dict[s[i]];     //set start to front repeating char index
        dict[s[i]] = i;             //set the current char index
        if (i - start > max_len)    //if current substring length larger than max_len, refresh max_len
            max_len = i - start;    //max_len += 1 if start = -1
    }
    return max_len;
}

/*
#include <deque>
#include <algorithm>
//using queue (by https://clay-atlas.com/blog/2020/12/30/leetcode-cn-3-longest-substring-without-repeating-characters/)
int lengthOfLongestSubstring(string s)  
{
    deque<char> sub_str = {};
    int max_len = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        while (find(sub_str.begin(), sub_str.end(), s[i]) != sub_str.end())
            sub_str.pop_front();
        sub_str.push_back(s[i]);
        if (sub_str.size() > max_len)
            max_len = sub_str.size();
    }
    return max_len;
}
*/

int main()
{
    int answer = lengthOfLongestSubstring("pwwkew");
    return 0;
}

/*  using for() & find(): Time Limit Exceeded
int lengthOfLongestSubstring(string s)
{
    string sub_str;
    int find = -1;
    int left = -1;
    for (int i = s.length(); i > 0; --i)
    {
        for (int j = 0; j + i <= s.length(); ++j)
        {
            sub_str = s.substr(j, i);
            if (j <= left && j + i - 1 >= find)
                continue;

            for (int k = 0; k < sub_str.length(); ++k)
            {
                //std::cout << sub_str << " "<< sub_str.find(sub_str[k], k + 1);
                find = sub_str.find(sub_str[k], k + 1);
                if (find != -1)
                {
                    find += j;
                    left = j + k;
                    //std::cout << std::endl;
                    break;
                }
                else if (k == sub_str.length() - 1)
                    return i;
                //std::cout << std::endl;
            }
        }
    }
    return 0;
}
*/

/*worse than above
int lengthOfLongestSubstring(string s)
{
    string sub_str = s;
    string sub_str1, sub_str2;
    int breakpoint;
    int answer = sub_str.length();
    int answer1 = 0;
    int answer2 = 0;
    for (int i = 0; i < sub_str.length(); ++i)
    {
        breakpoint = sub_str.find(sub_str[i], i + 1);
        if (breakpoint != -1)
        {
            sub_str1 = sub_str.substr(0, breakpoint);
            answer1 = lengthOfLongestSubstring(sub_str1);
            sub_str2 = sub_str.substr(breakpoint);
            answer2 = lengthOfLongestSubstring(sub_str2);
            if (answer1 >= answer2)
                answer = answer1;
            else
                answer = answer2;
        }
        else if (sub_str.substr(i).length() >= answer)
            answer = sub_str.substr(i).length();
    }
    return answer;
}
*/