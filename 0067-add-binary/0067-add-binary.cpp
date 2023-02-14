class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
         reverse(a.begin(),a.end());
         reverse(b.begin(),b.end());
        string e = "";
        int g = a.size() - b.size();
        if(g<0) g = -g;
        for(int i=1;i<=g;i++)
            e+="0";
        if(a.size()>b.size())
        b+=e;
        else
        a+=e;
        int cr = 0;
        for(int i=0;i<a.size();i++){
            int t = 0;
            if(a[i]=='1')t++;
            if(b[i]=='1')t++;
            if(cr==1)t++;
            if(t>=2) cr = 1;
            else cr =0;
            if(t==2 or t==0) t =0;
            else t =1;
            string s = to_string(t);
            c+=s;
        }
        if(cr){
            c+= to_string(cr);
        }
        reverse(c.begin(),c.end());
        return c;

    }
};