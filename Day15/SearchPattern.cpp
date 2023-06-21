
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

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
    string cctn=pattern+"#"+text;
    vector<int> ans;
    vector<int> zf=zFunc(cctn, cctn.length());
    for(int i=0;i<cctn.length();i++){
        if(zf[i]==pattern.length()){
            int ind=i-pattern.length();
            ans.push_back(ind);
        }
    }
    return ans;
}
