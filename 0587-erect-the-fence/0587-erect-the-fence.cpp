class Solution {
public:
    // monotonic chain solution
    int crossProduct(vector<int> &x ,vector<int> &y, vector<int> &z){
        // make two vector v1 = (x,y) and v2(y,z)
        // if their cross product is positive...then we are good..else we need to pop the top element from stack
        /*
                            P3

            P1----P2

            now v1 = (p1,p2) and v2(p2,p3).. their cross product is positive and from the graph it's visible that all three should be part of the hull


            p1---p2 

                        p3

            now v1 = (p1,p2) and v2(p2,p3).. their cross product is negative and from the graph it's visible that all p1 and p3 are part of hull but not p2.


            if cross product is zero..then all three points are collinear and hence part of hull..l.

        */


        int a= y[0] - x[0];
        int b= y[1] - x[1];
        int c= z[0] - y[0];
        int d= z[1] - y[1];
        return a*d - b*c;
    }

    vector<vector<int>> convexHULL(vector<vector<int>> & trees){
        int n= trees.size();
        vector<vector<int>>st;
        int k = 0;
        for(int i=0;i<n;i++){
            while(k>=2 and crossProduct(st[k-2], st[k-1], trees[i])<0){
                st.pop_back();
                k--;
            }
            st.push_back(trees[i]);
            k++;
        }
        return st;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        set<vector<int>>st;
        sort(trees.begin(),trees.end());

        vector<vector<int>> bottomHULL = convexHULL(trees);
        reverse(trees.begin(),trees.end());
        vector<vector<int>> topHULL = convexHULL(trees);

        for(auto &it: bottomHULL)st.insert(it);        
        for(auto &it: topHULL)st.insert(it);        

        vector<vector<int>>res(st.begin(),st.end());

        return res;
    }
};