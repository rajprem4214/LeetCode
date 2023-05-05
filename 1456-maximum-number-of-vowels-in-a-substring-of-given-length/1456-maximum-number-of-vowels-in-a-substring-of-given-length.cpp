class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int count=0;
        //we will make a sliding window of size k
        for(int i=0;i<k;i++){    
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
             count++; 
           }
        }
        //we will count the count of vowel in that window ans store in ans varilable
        ans=max(ans,count);
        
        int j=0;
        // start of the window is j
        for(int i=k;i<=s.length();i++){
         
            //end of the window is k 
            //if end is vowel we will increse the count 
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
             count++; 
            }
            //if start is vowel we will decrease the count 
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
             count--; 
            }
            //update start
            j++;
            //size of the window that is sliding i-j 
          ans=max(ans,count);
        
        }
      
        return ans;
    }
};