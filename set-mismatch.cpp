#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> result;
    int n = nums.size();
    map<int, int> mp1;

    for (int i = 0; i < n; i++)
    {
        mp1[nums[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp1[i] > 1)
        {
            result.push_back(i);
        }
    }

     for (int i = 1; i <= n; i++)
    {

        if(mp1[i] == 0) {
            result.push_back(i);
        }
    }

    return result;

}

int main()
{

    vector<int> st;
    int n;

    cout << "Number of element" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        st.push_back(p);
    }

    vector<int> res = findErrorNums(st);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}