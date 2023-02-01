class Solution {
public:
    string concatinate(string s ,int times){
        string str = "";
        while(times--){
            str+=s;
        }
        return str;
    }
    string gcdOfStrings(string str1, string str2) {
        
        string ans = "", s="";
        int n=str1.size(),m=str2.size();
        
        for(int i=0;i<min(str1.size(),str2.size());i++){
            s+=str1[i];
            if(n % s.size() ==0 && m % s.size() ==0){
                string x = concatinate(s,n/s.size());
                string y = concatinate(s,m/s.size());
                if(x == str1 && y == str2)
                    ans = s;
            }
        }
        return ans;
    }
};