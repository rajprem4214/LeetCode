class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
           int len=tasks.size();
    vector<int> H(26,0);
    for (int i=0;i<len;i++) H[tasks[i]-65]++;
    sort(H.begin(), H.end(), greater<int>());
    int time=0;
    while (true) {
        int pick=0, i=0, rem=0;
        while (pick<n+1 && i<26) {
            if (H[i] > 0) {
                pick++;
                H[i]--;
            }
            rem += H[i];
            i++;
        }
        while (i<26) rem += H[i++];
        if (rem==0) {
            time += pick;
            break;
        }
        time += n+1;
        sort(H.begin(), H.end(), greater<int>());
    }
    return time;
    }
};