#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 vector<int> plusOne(vector<int>& digits) {
    
    vector<int>result;
    int num = 0, d = 0;
    int n = digits.size();

    digits[n-1] += 1;

    for (int i = n-1; i >= 0; i--)
    {
       if(digits[i] > 9 && i != 0) {
            digits[i] %= 10;
            digits[i-1] += 1;
       }

       if(digits[i] > 9 && i == 0) {
            d = digits[i] / 10;
            digits[i] %= 10;
       }

       result.push_back(digits[i]);
    }

    if(d > 0) {
        result.push_back(d);
    }
   

     reverse(result.begin(),result.end());


    return result;
    
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


    vector<int> result = plusOne(vec);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
    
}