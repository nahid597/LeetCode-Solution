#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int calPoints(vector<string>& operations) {
    stack<int>st;
    int p,q,x, sum = 0;
    // [5,2,c,d,+]
    // [5,10]

    for (int i = 0; i < operations.size(); i++)
    {
        if(operations[i] == "C") {
            st.pop();
        } else if(operations[i] == "D") {
           p = st.top();
           st.push(p*2);
        } else if(operations[i] == "+") {
           p = st.top();
           st.pop();
           q = st.top();
           st.push(p);
           st.push(p + q);
        } else {
           x = stoi(operations[i]);
           st.push(x);
        }
        
    }

    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    

    return sum;
    
}

int main() {

    string s;
    vector<string> vec;
    int n;
    cout << "Enter number of string" << endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vec.push_back(s);
    }
    
   int res = calPoints(vec);
   cout << res << endl;



    return 0;
}