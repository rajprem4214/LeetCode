class MyCalendar {
public:
    
    vector<pair<int,int>>vp;
    MyCalendar() {
      //  vp{};
    }
    
    bool book(int start, int end) {
        
        if(vp.size()==0)
        {
            vp.push_back({start,end});
            return true;
        }
        else{
            
            for(auto el:vp)
            {
                if(start<el.second&&el.first<end)
                {
                    return false;
                }
                
            }
            
            vp.push_back({start,end});
            return true;
        }
    }
};
