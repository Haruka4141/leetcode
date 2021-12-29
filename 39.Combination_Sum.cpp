#include <vector>
#include <algorithm>

using namespace std;

//leetcode submission
void helper(vector<int>& c, int t, int i, vector<int>& v, vector<vector<int>>& ans) //pass reference v to reduce copy operate and memory
{
    if (t == 0) 
    {
        ans.push_back(v);               //if satisfied, save outcome to ans
        return;
    }
    if (t < 0 || i == c.size())
    { 
        return;
    }
    v.push_back(c[i]);                  
    helper(c, t - c[i], i, v, ans);
    v.pop_back();                       
    helper(c, t, i + 1, v, ans);
}

vector<vector<int>> combinationSum_v3(vector<int>& c, int t)                        //separate answer function and recursive function
{
    sort(c.begin(), c.end());           //sort previously to aviod duplicate
    vector<int> v;
    vector<vector<int>> ans;
    helper(c, t, 0, v, ans);
    return ans;
}

vector<vector<int>> combinationSum_v2(vector<int>& candidates, int target)      //pass, but confined by function body, recursive is very slow and fat
{
    vector<vector<int>> ret;

    for (int i = 0; i < candidates.size(); ++i)
    {
        if (target > candidates[i])
        {
            auto sub_ret = combinationSum_v2(candidates, target - candidates[i]);
            if (!sub_ret.empty())
            {
                for (auto sub_ret_element : sub_ret)
                {
                    sub_ret_element.insert(sub_ret_element.begin(), 1, candidates[i]);
                    sort(sub_ret_element.begin(), sub_ret_element.end());
                    if (find(ret.begin(), ret.end(), sub_ret_element) == ret.end())
                        ret.push_back(sub_ret_element);
                }
            }
        }
        else if (candidates[i] == target)
        {
            ret.push_back({ candidates[i] });   // == return  { {candidate[i]} };
        }
    }

    return ret;
}

int main()
{
    vector<int> cand = { 2, 3, 6, 7 };
    //vector<int> cand = { 1 ,2 };
    auto ans = combinationSum_v3(cand, 7);

    return 0;
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target)     //{2,3,6,7} fail
{
    vector<vector<int>> ret;

    for (int i = 0; i < candidates.size(); ++i)
    {
        vector<int> combination(target / candidates[i], candidates[i]);

        if (target % candidates[i] == 0 || candidates[i] == 1)
        {
            ret.push_back(combination);
        }
        else if (find(candidates.begin(), candidates.end(), target % candidates[i]) != candidates.end())
        {
            combination.insert(combination.begin(), target % candidates[i]);
            ret.push_back(combination);
        }
    }
    return ret;
}
