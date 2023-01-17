#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(int ii, vector<int> &temp, vector<vector<int> > &ans, vector<int> &candidate, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    if (target < 0 || ii == candidate.size())
    {
        return;
    }

    for (int i = ii; i < candidate.size(); i++)
    {
        //helper(i+1, temp, ans, candidate,target);
        // 1 2 2 2 5  tar = 8
        if (i > ii && candidate[i] == candidate[i-1])
        {
           continue;
        }
        
        temp.push_back(candidate[i]);
        helper(i + 1, temp, ans, candidate, target - candidate[i]);
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int> > ans;
    vector<int> temp;

    sort(candidates.begin(), candidates.end());
    helper(0, temp, ans, candidates, target);

    return ans;
}

int main()
{

    int n, p, t;
    cout << "Enter the number of elements " << endl;
    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    cout << "Enter the target " << endl;
    cin >> t;

    vector<vector<int> > res = combinationSum(vec, t);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}