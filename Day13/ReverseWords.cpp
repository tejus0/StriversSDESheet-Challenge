// Time Complexity: O(N), Traversing the entire string

// Space Complexity: O(N), Stack and ans variable

#include <stack>

string reverseString(string &s){
	// Write your code here.
    stack<string> st;
       string temp = "";
       string ans  = "";
        
       for(int i =0; i <s.length(); i++){
          if(s[i] == ' '){ 
              if(temp.length() > 0)
               st.push(temp);             
              temp = "";
          }else
             temp = temp + s[i];
        }
        
        ans = ans + temp;
        while(!st.empty()){
            string word=st.top();
            // cout<<word<<" ";
            st.pop();
            ans += ans.length()==0 ? word : (" "+word);
        }
    return ans;
}

// Optimized Approach - Two Pointers 
// Time Complexity: O(N), N~length of string

// Space Complexity: O(1), Constant Space

string result(string s)
{
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    
}