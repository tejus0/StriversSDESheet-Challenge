#include <bits/stdc++.h> 

string GetNextNum (string num){
 int ctr = 1;
    int lastNum = num[0];
    string nextNum;
    int i;
    for(i=1; i<num.size(); i++)
    {
        if(num[i] == lastNum)
        {
            ctr++;
        }
        else
        {
            nextNum += to_string(ctr) + num[i-1];
            ctr=1;
            lastNum = num[i];
        }
    }
    nextNum += to_string(ctr) + num[i-1];
    return nextNum;
}

string writeAsYouSpeak(int A) 
{
	// Write your code here.	
	string nextNum = "1";
    for(int i=0; i<A-1; i++)
    {
        string num = nextNum;
        nextNum = GetNextNum(num);
    }
    return nextNum;
}