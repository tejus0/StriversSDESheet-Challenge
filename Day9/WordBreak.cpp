#include <bits/stdc++.h> 

int dp[10001];
    bool solve (int s_index, string& s, vector<string>& dict){
        
         if (s_index >= s.size())
             return true;
        
         if (dp[s_index] != -1)
          return dp[s_index];
          
        string str;
        
          for (int i= s_index; i< s.size(); i++){
              
              str+= s[i];
              
        if (find(dict.begin(), dict.end(), str) != dict.end()){
            
                 bool check = solve (i+1, s, dict);
                  
                    if (check == true)
                   return dp[s_index]= true;
              }
        
          }
        
          return dp[s_index]= false; 
         
        
    }

bool wordBreak(vector < string > & wordDict, int n, string & s) {
    // Write your code here.
    dp[n];
        memset (dp, -1, sizeof (dp));
        return solve (0, s, wordDict);
}