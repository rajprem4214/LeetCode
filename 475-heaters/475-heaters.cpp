class Solution {
public:
    int n;
    int findRadius(vector<int>& hs, vector<int>& ht) 
    {
      n=hs.size();
        sort(hs.begin(),hs.end());
        sort(ht.begin(),ht.end());
        int ans=0;
        for(int i=0; i<n; i++)
        {
            auto it=lower_bound(ht.begin(),ht.end(),hs[i])-ht.begin();
            
            if(it==ht.size())
            {
                ans=max(ans,abs(hs[i]-ht[ht.size()-1]));
            }
            else 
            {
              
              if(it>0)
              {
                  ans=max(ans,min(abs(hs[i]-ht[it]),abs(hs[i]-ht[it-1])));
              }
                else
                {
                  ans=max(ans,abs(hs[i]-ht[it]));  
                }
                
            }
        }
        return ans;
    }
};