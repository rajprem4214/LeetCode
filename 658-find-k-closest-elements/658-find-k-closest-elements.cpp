class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>ans;//answer vector to store the result
        sort(arr.begin(),arr.end(),[&](const int &a, const int &b){
            if(abs(a-x)==abs(b-x)){
                return a<b;
            }
            return abs(a-x) < abs(b-x);
        }); 
        //first k elements are our closest elements
        for(int i=0;i<k;i++){
            ans.push_back(arr[i]);
        }
        sort(ans.begin(),ans.end()); //given :"The result should also be in sorted order"
        return ans;
        
    }
};