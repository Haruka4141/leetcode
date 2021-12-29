#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> letterCombinations_v2(string digits)     //leetcode submission
{
    if (digits.size() == 0)
        return {};

    vector<string> ans;
    unordered_map<char, string> M;      //using char as keys is simpler

    M['2'] = "abc";
    M['3'] = "def";
    M['4'] = "ghi";
    M['5'] = "jkl";
    M['6'] = "mno";
    M['7'] = "pqrs";
    M['8'] = "tuv";
    M['9'] = "wxyz";

    ans.push_back(""); // "a" "b" "c"

    for (char& c : digits) 
    {
        // c = 3
        vector<string> temp;                    //extend ans for every digit
                                                //e.g. "23"
        for (auto& s : ans)                     //at '2', ans = "a", "b", "c"
        { // ""                                 //at '3', temp will extend ans to "ad", "ae", "af", ..... "cf" 
            for (char& d : M[c])                
            {
                temp.push_back(s + d);
            }
        }
        ans = temp;                             //refresh ans
    }

    return ans;
}

//Backtracking
//https://medium.com/trick-the-interviwer/letter-combinations-of-a-phone-number-511284412c8e (Modified)

void recursive(string&, int, string&, vector<string>&);

//O(3^n*4^m)
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};
    vector<string> ret;
    string sub_string = "";
    recursive(digits, 0, sub_string, ret);

    return ret;
}


static unordered_map<int, string> number_letter_map = { {2,"abc"}, {3, "def"}, {4, "ghi"},
                                                        {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                                        {8, "tuv"}, {9, "wxyz"} };

void recursive(string& digits, int start, string& sub_string, vector<string>& ret) 
{
    if (start == digits.size())
    {
        ret.push_back(sub_string);
        return;
    }

    for (int i = 0; i < number_letter_map[digits[start] - '0'].size(); ++i)
    {
        sub_string.push_back(number_letter_map[digits[start] - '0'][i]);
        recursive(digits, start + 1, sub_string, ret);
        sub_string.pop_back();
    }
}


int main()
{

    auto ans = letterCombinations_v2("23");
        
    return 0;
}