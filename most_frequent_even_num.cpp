#include <iostream>
#include <vector>
#include <iterator>
#include<map>

using namespace std;

int mostFrequentEven(vector<int> &nums)
{
    map<int, int> mp;
    map<int,int>::iterator itr;

    int res = -1, cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] % 2) == 0)
            mp[nums[i]]++;
    }


    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (cnt < itr->second)
        {
            res = itr->first;
            cnt = itr->second;
        }
        
       // cout << itr->first << " " << itr->second << endl;
    }
    
    return res;

}

int main()
{
    vector<int> vec;
    int n, p;

    cout << "Enter the Number of element" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    int res = mostFrequentEven(vec);

    cout << res << endl;

    cout << endl;

    return 0;
}