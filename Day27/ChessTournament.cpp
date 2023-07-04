// Time - O(N* Log(N))

#include <bits/stdc++.h> 
bool check(int dis,vector<int> &arr,int c,int n){
	int player=1;
	int pos = arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-pos>=dis)
		{
			pos=arr[i];
			player++;
		}
		if( player==c) return true;

	}
	return false; 
}
int chessTournament(vector<int> positions , int n ,  int c)
{
	sort(positions.begin(),positions.end());
	int i=0;
	int j=positions[n-1]-positions[0];
	int ans=-1;
	while(i<=j)
	{
		int mid=i+((j-i)>>1);
		if(check(mid,positions,c,n))
		{
			i=mid+1;
			ans=mid;
		}
		else j=mid-1;
	}
	return ans;
}