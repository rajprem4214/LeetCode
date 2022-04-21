class Solution {
public:
    vector<vector<int>> ans;
    vector<int> stack;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(0, k, n);
        return ans;
    }
private:
    void backtrack(int index, int k, int remaining) {
        if (stack.size() == k || remaining <= 0) {
            if (remaining == 0 && stack.size() == k) ans.push_back(stack);
            return;
        }
        
        for (int i = index+1; i <= 9; ++i) {   
            stack.push_back(i);
            backtrack(i, k, remaining-i);
            stack.pop_back();
        }
    }
};