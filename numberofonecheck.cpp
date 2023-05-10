#include<iostream>

using namespace std;

bool checkNum(int arr[], int n) {
    bool st = false;

    for(int i = 0; i < n; i++) {
       if (arr[i] > 2)
       {
          return false;
       }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2)
        {
            st = true;
            break;
        }
    }

    if (!st)
    {
        return false;
    }

    if (arr[0] != 1 || arr[n-1] != 1)
    {
        return false;
    }
    

    int cnt1 = 0, cnt2 = 0;
    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++)
    {
         if (arr[l] == 1)
         {
            cnt1++;
         }

         if (arr[r] == 1)
         {
            cnt2++;
         }

         if (arr[l] != 1 || arr[r] != 1)
         {
            break;
         }

        l++;
        r--;
    }

    if (cnt1 == cnt2 && cnt1 > 0 && cnt2 > 0)
    {
        return true;
    }

    return false;
    
}

int main() {

    int n;

    cout << "Enter the number of Elements" << endl;

    cin >> n;

    int x[n+1];

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    bool res = checkNum(x, n);

    cout << res << endl;

    return 0;
}