class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n),temp;   //making ans and temp vector
        ans[0]=1;
        temp.push_back(obstacles[0]);
        for(int i=1;i<n;i++){          
            if(obstacles[i]>=temp.back()){temp.push_back(obstacles[i]) ; 
            ans[i]=temp.size();}
            else {
                int ind=upper_bound(temp.begin(),temp.end(),obstacles[i])-temp.begin();     //find the correct place to put the current element 
                temp[ind]=obstacles[i];  //for next calculation updating temp[ind]
                ans[i]=ind+1;  //store the index
            }
            
        }
return ans;
    }
};