#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool area(int a, int b, int c)
{
    bool result = false;

    if (a + b > c && a + c > b && b + c > a)
    {
        result = true;
    }

    return result;
}

int largestPerimeter(vector<int> &nums)
{
    int a, b, c;
    bool rArea;
    int peri = 0;
    int mxPeri = INT_MIN;

    sort(nums.begin(), nums.end());

     for (int i = 0; i < nums.size() - 2; i++)
     {
        a = nums[i];
        b = nums[i+1];
        c = nums[i+2];

        rArea = area(a, b, c);

        if (rArea)
        {
            peri = a + b + c;
        }

        mxPeri = max(mxPeri, peri);
    }

    return mxPeri;
}

int main()
{

    vector<int> vec;

    int n, p;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    int result = largestPerimeter(vec);

    cout << result << endl;
}