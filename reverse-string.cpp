#include<iostream>

using namespace std;

int reverse(int x) {

     long long st = x, p = 0;
     long long result = 0;

     if (st < 0)
     {
        st = st * -1;
     }
     

     while (st)
     {
        p = x % 10;
        result = result * 10 + p;
        st = st / 10;
     }

     if (x < 0)
     {
        result = result * -1;
     }

     if (result < INT_MIN || result > INT_MAX)
     {
        result = 0;
     }

     cout << INT_MAX << endl;
     
    return result;        

}


int main() {

    int x;

    cin >> x;

    int res = reverse(x);

    cout << res << endl;

    return 0;
}