#include <bits/stdc++.h> 

int pattern(char c){
    if(c=='I')
        return 1;
    else if (c=='V')
        return 5;
    else if (c=='X')
        return 10;
    else if (c=='L')
        return 50;
    else if (c=='C')
        return 100;
    else if (c=='D')
        return 500;
    else 
        return 1000;
}

int romanToInt(string s) {
    // Write your code here
    int ans=0;
    int n=s.length();
    for(int i=0;i<n-1;i++){
        int diff=pattern(s[i])- pattern(s[i+1]);
        if(diff<0){
            ans -= pattern(s[i]);
        }
        else
            ans+= pattern(s[i]);
    }
    ans += pattern(s[n-1]);
    return ans;
}
