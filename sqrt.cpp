#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

int mySqrt(int x) {

    int cnt = 0;
    int sub = 1;

    while (x >=0)
    {
        x = x - sub;
        sub += 2;
        cnt++;
    }

    if (x < 0)
    {
        cnt = cnt - 1;
    }
    

    return cnt; 
        
}

int main() {

    int n;

    cout << "enter number" << endl;
    cin >> n;

    int r = mySqrt(n);

    cout << r << endl;
    cout << INT_MAX << endl;


    return 0;
}