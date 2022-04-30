class Solution {
public:
    void func(int &res,vector<bool>&visit,int &visitCount,int &n,int i)
    {
        if(i == n+1)
        {
            if(visitCount == n)
            {
                res++;
                return;
            }
            return;
        }
        for(int j=1;j<=n;j++)
        {
            if(visit[j] == false)
            {
                if(i%j == 0 || j%i == 0)
                {
                    visit[j]=true;
                    visitCount++;
                    func(res,visit,visitCount,n,i+1);
                    visitCount--;
                    visit[j]=false;
                    
                }
            }
        }
        
    }
    int countArrangement(int n) {
        int res=0;
        
        vector<bool>visit(n,false);
        int visitCount=0;
        int i=1;
        func(res,visit,visitCount,n,i);
        return res;
    }
};