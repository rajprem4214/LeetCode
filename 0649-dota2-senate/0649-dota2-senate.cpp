class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.length();
        queue<int>q;
        int count=n;
        unordered_map<int,int>m;//Used for tracking the unbanned characters.

        int i=1;
        q.push(0);

        int flag=0;//Used for checking the count at the end of one iteration.

        while(count!=1){
            if(m[i]==0){//Checking alive
                if(!q.empty()){
                    int a=q.front();
                    if(senate[a]==senate[i]){
                        q.push(i);

                    }
                    else{
                        q.pop();
                        m[i]=1;
                        count--;//dead one element.
                        flag=1;//count is updated so flag is 1 for next iteration.
                    }
                }
                else{
                    q.push(i);
                }
            }
            if(i==n-1){
                if(count==n||flag==0){//if count not changed means all elements are equal so, no required to iterate further.
                    break;
                }
                i=0;
                flag=0;//after completion of each iteration flag is 0 and it changed only when one element is dead in that particular iteration.
                continue;
            }
            
            i++;
        }
        int j;
        for(j=0;j<n;j++){
            if(m[j]==0){
                break;
            }
        }
        return senate[j]=='D'?"Dire":"Radiant";
    }
};