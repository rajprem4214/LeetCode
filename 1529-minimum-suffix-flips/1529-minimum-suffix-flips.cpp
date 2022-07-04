class Solution {
public:
    int minFlips(string target) {
      int c=0;
int ans=0;
for(auto x:target)
{
if(x!=c+'0')
{
ans++;
c=!c;
}
}
return ans;  
    }
};