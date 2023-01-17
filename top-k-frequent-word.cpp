#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

static bool sortByValue(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second == b.second) {
        return (a.first < b.first);
    }
    
    return (a.second > b.second);
}

vector<string> topKFrequent(vector<string> &words, int k)
{

    map<string, int> mp;
    map<string, int>::iterator itr;
    vector<string> result;

    for (int i = 0; i < words.size(); i++)
    {
        mp[words[i]]++;
    }

    //  for (itr = mp.begin(); itr != mp.end(); itr++)
    // {
    //    cout << itr->first << " " << itr->second << endl;
    // }

    vector<pair<string, int> > vec;

    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        vec.push_back(make_pair(itr->first, itr->second));
    }

   // sort(vec.begin(),vec.end());
      sort(vec.begin(), vec.end(), sortByValue);

    for (int i = 0; i < k; i++)
    {
        result.push_back(vec[i].first);
    }

    for (int i = 0; i < k; i++)
    {
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    return result;
}

int main()
{

    vector<string> str;
    int n, k;
    string s;
    ifstream myFile("test.txt");

     while (getline (myFile, s)) {
    // Output the text from the file
   //  cout << s << endl;
  }

string word[500];
int kk= 0;

string che = "";

   for (int i = 0; i < s.length(); i++)
   {
      if (s[i] != ' ')
      {
          che += s[i];
      } else {
        word[kk++] = che;
        che = "";
      }
   }

   for (int i = 0; i < kk; i++)
   {
      str.push_back(word[i]);
   }
   
   

   // cout << "enter number of word " << endl;

    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> s;
    //     str.push_back(s);
    // }

    // cout << "enter number frequent" << endl;
    // cin >> k;

     vector<string> res = topKFrequent(str, 14);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}