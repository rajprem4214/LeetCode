class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rs=0;
        unordered_map<int,int>m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto i:m){
            int x=i.second;
            if(x==1)
                return -1;
            if(x==2)
                rs++;
            if(x==3)
                rs++;
            if(x>=4){
                int s=x/3;
                int r=x-3*s;
                if(r==0) 
                    rs+=s;
                if(r==1) 
                    rs+=(s-1+2);
                if(r==2) 
                    rs+=(s+1);
            }
        }
        return rs;
    }
};