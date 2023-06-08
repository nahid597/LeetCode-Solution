#include<iostream>
#include<map>
#include<set>

using namespace std;

int countPoints(string rings) {
    int r = 0, g = 0, b = 0;
    int ans = 0;

    for (int i = 0; i < 10; i++)
    {
        r = g = b = 0;

        for (int j = 1; j < rings.size(); j = j + 2)
        {
            if (i == (int)rings[j] -48)
            {
                if (rings[j-1] == 'R')
                {
                    r++;
                }
                else if (rings[j-1] == 'G')
                {
                    g++;
                }
                else if (rings[j-1] == 'B')
                {
                    b++;
                }
                
            }
        }

        if (r > 0 && g > 0 && b > 0)
        {
            ans++;
        }
    }
    
      return ans;  
}

int countPoints2(string rings) {
    int cnt = 0;

    map<int, set<char> > mp;
    map<int, set<char > > ::iterator itr;

    // R3G2B7

    for (int i = 0; i < rings.size() - 1; i += 2)
    {
       set<char> s;
       s.insert(rings[i]);
       mp[(int) rings[i+1]].insert(rings[i]);
    }

    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->first << " " << itr->second.size() << endl;
    }
    
    

    return 0;
}

int main() {
    string s;

    cout << "Enter the string " << endl;
    cin >> s;

    int res = countPoints2(s);

    cout << res << endl;
}