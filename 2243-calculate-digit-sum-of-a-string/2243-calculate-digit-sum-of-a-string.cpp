class Solution {
public:
    string add(string a){
        int sum=0;
        
        for(int i=0;i<a.length();i++){
            sum = sum + (a[i]-'0');
        }
        return to_string(sum);
        
    }
    
    
    
    string digitSum(string s, int k) {
        string str="";
        string ans="";
        int sum=0;
    string res="";
        
        while(s.length()>k){
            for(int i=0;i<s.length();i+=k){
                
                str = s.substr(i,k);
                  
                ans+=add(str);
            }
                s=ans;
            ans="";
      
    }
            
              
       return s;
        
    }
};