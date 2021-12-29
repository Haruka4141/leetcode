#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> generateParenthesis_v2(int n)
{
    vector<string> ret;
    
    if ( n > 1)
    {
        auto temp = generateParenthesis_v2(n - 1);
        unordered_set<string> map;
        for (auto sub_str : temp)
        {   
            string temp_str;
            for (int i = 0; i <= sub_str.size(); ++i)
            {
                temp_str = sub_str;                         
                temp_str.insert(i, "()");                   // insert: 0 ( 1 ) 2
                if (map.find(temp_str) == map.end())
                {
                    ret.push_back(temp_str);
                    map.insert(temp_str);
                }
            }
        }
    }
    else 
        ret.push_back("()");
    
    return ret;
}

int main()
{

    auto ans = generateParenthesis_v2(3);
    
    return 0;
}
                                                //                                                                    v                     v    duplicated, one should be "(())(())"
vector<string> generateParenthesis(int n)       //4 fail ["(((())))","()((()))","((()))()","(()(()))","()()(())","()(())()","((())())","()(())()","(())()()","((()()))","()(()())","(()())()","(()()())","()()()()"]
{                                                                                                              //()(()) + ()  ==  () + (())() 
    vector<string> ret;

    if (n > 1)
    {
        auto temp = generateParenthesis(n - 1);
        for (auto sub_str : temp)
        {
            string temp_str = sub_str;
            temp_str.insert(0, 1, '(');
            temp_str.append(1, ')');
            ret.push_back(temp_str);

            temp_str = sub_str;
            temp_str.insert(0, "()");

            string temp_str2 = sub_str;
            temp_str2 = sub_str;
            temp_str2.append("()");

            if (temp_str != temp_str2)
            {
                ret.push_back(temp_str);
                ret.push_back(temp_str2);
            }
            else
                ret.push_back(temp_str);
        }
    }
    else
        ret.push_back("()");

    return ret;
}

/*



"(())(())",















*/