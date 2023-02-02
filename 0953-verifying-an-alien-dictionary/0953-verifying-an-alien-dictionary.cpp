class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> a;
        for(int i=0;i<26;i++){a[order[i]]=i;}

        int n=words.size();
        for(int i=1;i<n;i++){
            string s1=words[i-1];
            string s2=words[i];
            int n1=s1.size();
            int n2=s2.size();
            bool match=false;
            
            for(int j=0;j<min({n1,n2});j++){
                
                if(a[s1[j]]>a[s2[j]]){match=false;return false;}
                else if(a[s1[j]]<a[s2[j]]){match=false;break;}
                else{match=true;}
            }
            if(match && n1>n2){
                
                return false;
            }
        }
        return true;
    }
};