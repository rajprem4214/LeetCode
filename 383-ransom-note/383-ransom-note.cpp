class Solution {
public:
    bool canConstruct(string ransomNote, string magazine){
        unordered_map<int,int> mp;
        
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            if( mp[ransomNote[i]]>0 && mp.find(ransomNote[i])!=mp.end()){
                mp[ransomNote[i]]--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};