class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int steps=0;
        queue<int>q;
        q.push(0);
        vector<bool>visited(n,0);
        visited[0]=1;
        while(!q.empty()){
            for(int size=q.size();size>0;size--){
                int i=q.front();q.pop();
                if(i==n-1)return steps;
                vector<int>next=mp[arr[i]];
                next.push_back(i-1);next.push_back(i+1);
                for(int j:next){
                    if(j>0&&j<n&&!visited[j]){
                        visited[j]=true;
                        q.push(j);
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return steps;
    }

};