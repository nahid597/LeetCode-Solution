#include<iostream>

using namespace std;

void findMaxMin(int arr[], int n) {
   int mx = INT_MIN;
   int mn = INT_MAX;

   // [1,2,-3,4,6]

    for(int i = 0; i < n; i++) {
       if (arr[i] > mx)
       {
          mx = arr[i];
       }

       if (arr[i] < mn)
       {
          mn = arr[i];
       }
    }

    cout << "Max value " << mx << endl;
    cout << "Min value " << mn << endl;

    
}

int main() {

    int n;

    cout << "Enter the number of Elements" << endl;

    cin >> n;

    int x[n+1];

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    findMaxMin(x, n);
}