class Solution {
public:
    vector<string> letterCombinations(string d) {
       map<char, string> m;
    char c = 'a';
    vector<string> a;
    for (char i = '2'; i <= '9'; i++) //making the map
    {
        if (i == '9')
        {
            m[i] = "wxyz";
            continue;
        }
        if(i=='7')
        {
            m[i]="pqrs";
            c='t';
            continue;
        }
        string s = "";
        for (int j = 1; j <= 3; j++)
        {
            s += c;
            c++;
        }
        m[i] = s;
    }
    for (int i = 0; i < d.length(); i++)
    {
        if (i == 0)                                    //for first time, to initialize the array
        {
            string t = m[d[i]], k;
            if (d[i] != '9' && d[i]!='7')                //excluding special cases
            {
                for (int j = 0; j < 3; j++)
                {
                    k = t[j];
                    a.push_back(k);
                }
            }
            else                                                        //special case
            {
                for (int j = 0; j < 4; j++)                   
                {
                    k = t[j];
                    a.push_back(k);
                }
            }
        }
        else                                                  //for rest of times
        {
            vector<string> n;
            string t = m[d[i]], k;
            if (d[i] != '9' && d[i]!='7')            //excluding sppecial cases
            {
                for (int j = 0; j < 3; j++)          //all combinations are formed
                {
                    for (auto h : a)
                    {
                        k = h + t[j];
                        n.push_back(k);
                    }
                }
            }
            else                                                          //for special cases
            {
                for (int j = 0; j < 4; j++)
                {
                    for (auto h : a)
                    {
                        k = h + t[j];
                        n.push_back(k);
                    }
                }
            }
            a = n;
        }
    }
    
    return a;
    }
};