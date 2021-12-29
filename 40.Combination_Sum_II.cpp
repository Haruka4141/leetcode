#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ans_element, int index)
{
    if (target == 0)
    {   
        ans.push_back(ans_element);
        return;
    }
    else if (target < 0 || index >= candidates.size())
        return;

    ans_element.push_back(candidates[index]);
    helper(candidates, target - candidates[index], ans, ans_element, index + 1);
    ans_element.pop_back();
    //solution hint:
    while (index < candidates.size() - 1 && candidates[index] == candidates[index + 1])    //pass next element if same
        ++index;
    helper(candidates, target, ans, ans_element, index + 1);
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> ret;
    vector<int> ret_element;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, ret, ret_element, 0);

    return ret;

}


int main()
{
    //vector<int> cand = { 10,1,2,7,6,1,5 };
    //vector<int> cand = { 2,5,2,1,2 };

    vector<int> cand = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    auto ans = combinationSum2(cand, 30);

    return 0;
}