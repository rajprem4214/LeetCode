class Solution {
public:
    int fun(vector<vector<int>>& matrix,int m){
        int count=0;
        for(int i=0;i<matrix.size();i++){
            vector<int>::iterator upper;
            upper=upper_bound(matrix[i].begin(),matrix[i].end(),m);
            count+=upper-matrix[i].begin();
        }
        return count;
    }
	
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int low=matrix[0][0];
        int high=matrix[m-1][m-1];
        
        while(low<=high){
            int mid=low+((high-low)/2);
            int count=fun(matrix,mid);
            if(count<k)
                low=mid+1;
            else{
                int count1=fun(matrix,mid-1);
                if(count1<k)
                    return mid;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};