class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area=abs(ax2-ax1)*abs(ay2-ay1)+abs(bx2-bx1)*abs(by2-by1);

    //calculate comman  
    int x=min(ax2,bx2)-max(ax1,bx1);
    int y=min(ay2,by2)-max(ay1,by1);

    if(x>0&&y>0)
    {
        //subrating comman area
        area-=x*y;
    }
    return area;   
    }
    
};