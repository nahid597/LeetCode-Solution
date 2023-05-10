#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct job
{
    int st;
    int et;
    int pt;
};

// 20 30 
bool compare(struct job s1, struct job s2) {
    if (s1.et == s2.et)
    {
        return s1.pt > s2.pt;
    }
    
    return s1.et < s2.et;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

    int n = startTime.size();

    struct job allJob[n+1];

    for (int i = 0; i < n; i++)
    {
        allJob[i].st = startTime[i];
        allJob[i].et = endTime[i];
        allJob[i].pt = profit[i];
    }

    sort(allJob, allJob + n, compare);

    vector<int>dp(n+1, 0);
    dp[1] = allJob[0].pt;

    for (int i = 2; i <= n; i++)
    {
      int l = 0, r = i - 2, j = 0;

      while (l <= r)
      {
         int mid = l + (r-l) / 2;

         if (allJob[mid].et <= allJob[i-1].st)
         {
             l = mid + 1;
             j = mid + 1;
         } else {
            r = mid - 1;
         }
      }
      
      dp[i] = max(dp[i - 1], allJob[i - 1].pt + dp[j]);
       
    }

    return dp[n];
    
}


int main() {

    int s,e,p,n;

    vector<int>vs;
    vector<int>ve;
    vector<int>vp;

    cout << "Enter the number of job"<< endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vs.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> e;
        ve.push_back(e);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vp.push_back(p);
    }

    int res = jobScheduling(vs, ve, vp);
    
   
    cout << res << endl;

    return 0;
}