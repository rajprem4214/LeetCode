class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> s;  //*** stack with first as value at index and second as minimum value encountered before current index
        
        int mini = INT_MAX;   // keeping track of minimum value encountered before our current index
        
        for(int i = 0;i<nums.size();i++){
            
            if(s.size()!=0)
            mini = min(mini,s.top().first);  // since we have to keep it for a value before current , we will check it here as the value of previous index will always be there at top
            
            
            while(s.size()!=0 && nums[i]>s.top().first){   //**  keeping the stack in decreasing order
                
                s.pop();
            }
            
            
            if(s.size()!=0){         // find if the value we got at the top is greater than our current and also the min with that value is smaller than current value
                
            if((s.top().first > nums[i]) && (nums[i] > s.top().second))return true;
            }
            
            s.push({nums[i],mini});  
           
        
        }
        
        
        
        return false;
        
        
    }
};