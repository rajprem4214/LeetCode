class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        int i,diff=0;
         sort(arr.begin(),arr.end());
         diff=arr[1]-arr[0];
         for(i=1; i<arr.size()-1;i++)
         {
             if(arr[i+1]-arr[i]!=diff)
             {
                 return false;
             }
         }
         return true;
    }
};