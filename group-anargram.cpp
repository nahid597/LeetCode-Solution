#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

vector<vector<string> > groupAnagrams(vector<string> &strs)
{
    
    vector<vector<string> > result;

    unordered_map<string, vector<string> > mp;
    unordered_map<string, vector<string> >::iterator itr;

    string temp;

    // eat tae
    // aet aet

    for (int i = 0; i < strs.size(); i++)
    {
       temp = strs[i];
       sort(strs[i].begin(), strs[i].end());
       mp[strs[i]].push_back(temp);
    }

    for ( itr = mp.begin(); itr != mp.end(); itr++)
    {
        result.push_back(itr->second);
    }
    

    return result;  
}
 
int main()
{

    vector<string> vec;

    string str[] = {"eat", "tea", "tan", "ate", "nat", "bat"};

    for (int i = 0; i < 6; i++)
    {
        vec.push_back(str[i]);
    }

    vector<vector<string> > res = groupAnagrams(vec);



      for (int i = 0; i < res.size(); i++)
      {
          for (int j = 0; j < res[i].size(); j++)
          {
             cout << res[i][j]<<" ";
          }

          cout << endl;

      }

    return 0;
}