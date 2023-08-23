class Solution {
public:
    vector<string> gen_words(string &s)
    {
        int n=s.size();
        vector<string> res;
        int i=0;
        while (i<n)
        {
            string temp="";
            while(i<n && s[i]!=' ')
                  temp+=s[i++];
            i++;
            res.push_back(temp);
        }
        return res;

    }
    bool possible(vector<string> &st1,vector<string> &st2)
    {
        int n=st1.size();
        int m=st2.size();
        int i1=0,j1=n-1;
        int i2=0,j2=m-1;
        while (i1<=j1 && i2<=j2)
        {
            if (st1[i1]==st2[i2])
               i1++,i2++;
            else if (st1[j1]==st2[j2])
                j1--,j2--;
            else
              return false;
        }
        return (i1>j1)? true:false;

    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> st1=gen_words(sentence1);
        vector<string> st2=gen_words(sentence2);
        if (st1.size()==st2.size())
        {
            for (int i=0;i<st1.size();i++)
            {
                if (st1[i]!=st2[i])
                  return false;
            }
            return true;
        }
        else if (st1.size()<st2.size())
            return possible(st1,st2);
        else
           return possible(st2,st1);
    }
};