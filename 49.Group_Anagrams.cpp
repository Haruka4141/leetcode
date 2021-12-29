#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> ret;
    unordered_map<string, int> map;

    int anagrams_count = 0;
    for (auto& element : strs)
    {
        string temp = element;
        sort(temp.begin(), temp.end());
        if (map.insert({ temp, anagrams_count }).second == true)
        {
            ret.push_back({ element });
            ++anagrams_count;
        }
        else
        {
            ret[map[temp]].push_back(element);
        }


    }

    for (auto& element : ret)
        sort(element.begin(), element.end());
    return ret;
}

int main()
{
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
    auto ans = groupAnagrams(strs);

    return 0;
}