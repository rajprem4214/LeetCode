class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> ans;
        
		int x = 0; //POINTER X : To iterate over all the x parameter of the array
		
        int y =n;  //POINTER Y: To iterate over all the y parameter of the array
		
        while(x<n && y<2*n) {
		//pushing x and y parameters and increasing them to iterate over the next respective parameters
            ans.push_back(nums[x++]); 
            ans.push_back(nums[y++]);
        }
        
        return ans;
    }
};