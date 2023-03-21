#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <utility>
#include<map>
#include<iterator>
#include<string>

using namespace std;

 vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size();
        int k = p.size();
        int cnt = 0;
        map<char,int>mp1;
        map<char,int>mp2;
        map<char,int>::iterator itr;
        

        for (int i = 0; i < k; i++)
        {
            mp1[p[i]]++; 
        }

        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                for ( itr = mp1.begin(); itr != mp1.end(); itr++)
                {
                    if (mp2[s[i-k]] <= itr->second && s[i-k] == itr->first)
                    {
                        cnt--;
                    }
                    
                }

                mp2[s[i-k]]--;
                
            }

            mp2[s[i]]++;

            if (mp2[s[i]] == mp1[s[i]] || (mp2[s[i]] < mp1[s[i]]))
            {
                cnt++;
            }

            if(cnt == k) {
               res.push_back(i-k+1);
            }
            
        }

    return res;
        
}


int main() {

    cout << "Enter the number of row and column" << endl;
    string s, p;

    cin >> s;
    cin >> p;


    //  for(int i = 0 ; i < vec.size(); i++) {
    //     for (int j = 0; j < vec[i].size(); j++) {
    
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }

   vector<int> res = findAnagrams(s,p);
   
    for (int  i = 0; i < res.size(); i++)
    {
       cout << res[i] << " ";
    }

    cout << endl;
    
}