#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> mp;
    map<int, int>::iterator it;
    vector<int>st(2005);
    fill(st.begin(), st.end(), 1001);
    bool res = true;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (it = mp.begin(); it != mp.end(); it++)
    {
        if (st[it->second] == 1001)
        {
            st[it->second] = it->second;
        }
        else
        {
            res = false;
            break;
        }
    }

    return res;
}

int main()
{

    vector<int> vec;

    int n, m, p, val;

    cout << "Enter size of element of nums1" << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    bool res = uniqueOccurrences(vec);

    cout << res << endl;
}