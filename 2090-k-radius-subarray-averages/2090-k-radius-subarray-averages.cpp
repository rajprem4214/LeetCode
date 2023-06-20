class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int>arr(n+1) ;
        vector<long long >pf_sum(n+1 , 0) ;
        for( int i = 1 ; i <= n ; i++ ){
            long long ele = nums[i-1] ;
            arr[i] = ele ;
            pf_sum[i] = pf_sum[i-1] + (long long)ele ; 
        }
        vector<int>ans ;
        long long t = (2*k) + 1 ;
        for( int i = 1 ; i <= n ; i++ ){
            if( i - k >= 1 and i + k <= n ) {
                    long long sum = (pf_sum[i+k]-pf_sum[i-1]) ;
                    sum += (pf_sum[i-1]-pf_sum[i-k-1]) ;  
                    ans.push_back(sum/t) ; 
            }else ans.push_back(-1) ;
        }
       return ans ;
    }
};