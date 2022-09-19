class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& p) {
		map<string,vector<string>>m;
		for(int i=0;i<p.size();i++)
		{
			string s,t;
			int d=-1;
			for(int j=0;j<p[i].size();j++)
			{
				if(p[i][j]==' ')
				{
					d=j;
					break;
				}
				s+=p[i][j];
			}
			s+='/';
			int j=d+1;
			while(j<p[i].size())
			{
				if(p[i][j]=='(')
				{
					int c=j+1;
					string a;
					while(p[i][c]!=')')
					{
						a+=p[i][c];
						c++;
					}
					m[a].push_back(s+t);
					j=c+1;
					t.erase();
				}
				else
				{
					t+=p[i][j];
				}
				j++;
			}
		}
		vector<vector<string>>f;
		for(auto it:m)
		{
			if(it.second.size()>1)
			{
				f.push_back(it.second);
			}
		}
		return f;
	}
};