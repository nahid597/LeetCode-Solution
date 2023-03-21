#include <iostream>
#include <vector>
#include<iterator>

using namespace std;


vector<int> majorityElement(vector<int>& nums) {

    vector<int>res;

    int candidate = INT_MIN;
    int life = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
       if (candidate == nums[i])
       {
           life++;
       } else if (life == 0)
       {
           candidate = nums[i];
           life = 1;
       } else {
        life--;
       }
       
    }

    cout << candidate << endl;
    
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

    vector<int> res = majorityElement(vec);

    for (int i = 0; i < res.size(); i++)
    {
       cout << res[i] << " ";
    }

    cout << endl;
    

    return 0;
}