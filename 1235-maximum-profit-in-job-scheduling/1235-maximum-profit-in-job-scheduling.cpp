struct JOB
{
	int s, e, p;
};


bool cmpr(JOB &A, JOB &B)
{
	if(A.s == B.s)
		return A.e < B.e;
	return A.s < B.s;
}


class Solution {
public:
	int dp[50001];
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		memset(dp, -1, sizeof(dp));
		vector<JOB>jobTime;
		for(int i=0;i<startTime.size();i++)
		{
			jobTime.push_back({startTime[i], endTime[i], profit[i]});
		}

		sort(jobTime.begin(), jobTime.end(), cmpr);
		// for(int i=0;i<jobTime.size();i++)
		// {
		// 	cout<<jobTime[i].s<<" "<<jobTime[i].e<<" "<<jobTime[i].p<<endl;
		// }
		return getMaxProfit(0, jobTime);
    }

	int getMaxProfit(int idx, vector<JOB>&jobTime)
	{
		if(idx == jobTime.size())
			return 0;
		if(dp[idx] != -1)
			return dp[idx];
		int take1 = 0, take2 = 0;
		int nxt = binarySearchNextJob(idx, jobTime);
		// cout<<idx<<" "<<nxt<<endl;
		if(nxt >=0)
			take1 = jobTime[idx].p + getMaxProfit(nxt, jobTime);
		else
			take1 = jobTime[idx].p;
		
		take2 = getMaxProfit(idx+1, jobTime);

		return dp[idx] = max(take1,take2);
	}

	int binarySearchNextJob(int idx, vector<JOB>&jobTime)
	{
		int L = idx+1, R = jobTime.size()-1;
		int ans = -1;
		while(L<=R)
		{
			int M =  L + (R-L)/2;

			if(jobTime[M].s >= jobTime[idx].e)
			{
				ans = M;
				R = M - 1;
			}
			else
				L = M + 1;
		}

		return ans;
	}

};

