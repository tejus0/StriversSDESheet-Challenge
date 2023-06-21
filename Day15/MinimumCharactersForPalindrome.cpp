
int minCharsforPalindrome(string s) {
	// Write your code here.
	int i = 0;
       int j = s.length()-1 , trim = j , res = 0;
       while(i < j)
       {
           if(s[i] == s[j]){  
               i++;
               j--;
           }
           else{
               res++;
               i = 0;
               j = --trim;
           }
       }
       return res;
}
