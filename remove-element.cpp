#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < n-1; j++)
            {
                nums[j] = nums[j+1];
            }

            n--;
            i--;
        }  
    }

    return n;
    
}


int main()
{

    vector<int> vec;

    int n, p, val;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    cout << "enter val " << endl;
    cin >> val;

    int result = removeElement(vec, val);

    cout << result << endl;
}