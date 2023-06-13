string kthPermutation(int n, int k) {
    // Write your code here.
    int fact=1;
        vector<int> numbers;
        for(int i=1;i<=n;i++)
        {
            numbers.push_back(i);
            if(i!=n)
            fact*=i;
        }
        k-=1;
        string s;
        for(int i=0;i<n;i++)
        {
            int j=k/fact;
            k%=fact;
            if(n-i-1)
            fact/=(n-i-1);
            s+=('0'+numbers[j]);
            numbers.erase(numbers.begin()+j);
        }
        return s;
}
