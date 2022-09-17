class Solution {

private:
	bool checkPalindrome(string& word, int l, int r) {
		while (l < r)
		{
			if (word[l] != word[r]) return false;
			l++; r--;
		}
		return true;
	}
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> um;
		vector<vector<int>> ans;
		int emptyindex = -1;
		vector<int> indexOfPalindromes;
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[i] == "")
			{
				emptyindex = i;
				continue;
			}
			if (checkPalindrome(words[i], 0, words[i].size() - 1))
				indexOfPalindromes.push_back(i);
			string str = words[i];
			
			reverse(begin(str), end(str));
			um[str] = i;
		}
		for (int i = 0; i < words.size(); ++i)
		{
			for (int cut = 0; cut < words[i].size(); ++cut)
			{
			
				if (checkPalindrome(words[i], cut, words[i].size() - 1))
				{
					string right = words[i].substr(0, cut);
					if (um.find(right) != end(um) && um[right] != i)
					{
						ans.push_back(vector<int> {i, um[right]});
					}
				}
				
				if (checkPalindrome(words[i], 0, cut - 1))
				{
					string left = words[i].substr(cut);
					if (um.find(left) != end(um) && um[left] != i)
					{
						ans.push_back(vector<int> {um[left], i});
					}
				}
			}
		}
		if (emptyindex != -1)
			for (int x : indexOfPalindromes)
			{
				ans.push_back(vector<int> {emptyindex, x});
				ans.push_back(vector<int> {x, emptyindex});
			}
		return ans;
	}
};