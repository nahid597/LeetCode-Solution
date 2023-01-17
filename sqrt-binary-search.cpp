#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

int mySqrt(int x) {

    long long mid = 0;
    int l = 1;
    int r = x;

    // 1 2 3 4 5

    while (l <= r)
    {
       mid = l + (r-l)/2;

       if (mid*mid == x)
       {
         return mid;
       } else if (mid*mid > x)
       {
          r = mid -1;
       } else {
          l = mid + 1;
       }
       
    }

    return r; 
        
}

int main() {

    int n;

    cout << "enter number" << endl;
    cin >> n;

    int r = mySqrt(n);

    cout << r << endl;


    return 0;
}