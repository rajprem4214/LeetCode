class Solution {
public:
	// read this function after reading the main function
    unordered_map<string, vector<string>> adj;
    void dfs(string node, vector<vector<string>> &ans, vector<string> &curr, string beginWord)
    {
        if(node == beginWord)
        {
            ans.push_back(curr);
            return;
        }
        
        for(string &nbr : adj[node])
        {
            curr.push_back(nbr);
            dfs(nbr, ans, curr, beginWord);
            curr.pop_back();
        }
    }
	
	// main function
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;
        
        unordered_map<string, int> list;
		// shortest distance to reach the current word
        for(string &word : wordList) list[word] = INT_MAX;
        
        if(list.find(endWord) == list.end()) return ans;
        
        queue<string> q;
        
        q.push(beginWord);
        int level = 0;
        
		// straight forward BFS
        while(!q.empty())
        {
            int n = q.size();
			// distance to reach the current node (from beginWord)
            ++level;
            for(int i=0; i<n; ++i)
            {
                string front = q.front();
                q.pop();
                
				// generating all possible words that differ from the current word at a single position
                for(int j=0; j<front.size(); ++j)
                {
                    string newWord = front;
                    
                    for(char letter='a'; letter<='z'; ++letter)
                    {
                        newWord[j] = letter;
                        
						// if the newWord is not visited or is visited on this level then only proceed 
						// o/w there's no sense of proceeding because we have already reached 
						// the word in less no. of steps
						
                        if(newWord != front && list.find(newWord) != list.end() && list[newWord] >= level)
                        {
							// building the graph in reverse order (we will know the reason for this later)
							// i.e making a edge between [u, v] in u <-- v this order.
                            adj[newWord].push_back(front);
                            
							// the newWord has been discovered in this level only, 
							// since this has been happended the path from this newWord to endWord 
							// will be same for both the cases thus not proceeding any further
                            if(list[newWord] == level) continue;
                            
                            list[newWord] = level;
                            
                            if(newWord != endWord) q.push(newWord);
                        }
                    }
                }
            }
        }
        vector<string> curr({endWord});
        dfs(endWord, ans, curr, beginWord);
		// because all the paths generated from dfs are from endWord->beginWord
        for(int i=0; i<ans.size(); ++i) reverse(ans[i].begin(), ans[i].end());
        
        return ans;
    }
};