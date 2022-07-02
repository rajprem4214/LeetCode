class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {   
        hC.push_back(h);
        sort(hC.begin(), hC.end());
		int maxh = hC[0];
        for(int i=1; i<hC.size(); i++){
            maxh = max(maxh, hC[i] - hC[i-1]);
        }
        
        vC.push_back(w);
        sort(vC.begin(), vC.end());
		int maxv = vC[0];
        for(int i=1; i<vC.size(); i++){
            maxv = max(maxv, vC[i] - vC[i-1]);
        }
		
        return (1LL*maxh*maxv) % 1000000007; //1LL used to make the product long long or integer sign overflow will occur.
    }
};