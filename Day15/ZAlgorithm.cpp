// Time - O(N)
// Space - O(N+M+1)

vector<int> zFunc(string s, int n){
	vector<int> zf(n,0);
	int L=0,R=0;
	for(int i=1;i<n;i++){
		if(i<=R){
			zf[i]=min(R-i+1,zf[i-L]);
		}
		while(i+zf[i]<n and s[zf[i]]==s[i+zf[i]]){
			zf[i]++;
		}
		if(i+zf[i]-1>R){
			L=i;
			R=i+zf[i]-1;
		}
	}
	return zf;
}


int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	string cnctnt= p+"#"+s;
	int cnt=0;
	vector<int> z=zFunc(cnctnt,n+m+1);
	for(int i=1;i<cnctnt.length();i++){
		if(z[i]==m){
			// cout<<i<<" ";
			cnt += 1;
		}
	}
	return cnt;
}