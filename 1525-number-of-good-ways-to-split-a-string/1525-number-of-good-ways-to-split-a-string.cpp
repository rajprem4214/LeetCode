class Solution {
public:
    int numSplits(string s) {
        int ans=0;
		unordered_map<char,int> mp1;
		unordered_map<char,int> mp2;
		for(auto c:s)
			mp1[c]++;
		if(mp1.size()==1) return s.size()-1;

		for(int i=0;i<s.size();i++)
		{
			mp2[s[i]]++;
			mp1[s[i]]--;

			if(mp1[s[i]]==0) mp1.erase(s[i]);
			if(mp1.size()==mp2.size())  ans++;
		}
		return ans;
    }
};