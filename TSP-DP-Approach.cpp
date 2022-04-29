#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void tsp(int curr,int cost,vector<int> temp,int &ans)
{
	if(temp.size()==1)
	{
		cost+=dp[curr][temp[0]];
		cost+=dp[temp[0]][0];
		ans = min(cost,ans);
		return ;
	}
	for(int i = 0;i<temp.size();i++)
	{
		vector<int> t1;
		for(int j = 0 ;j<temp.size();j++)
		{
			if(i!=j)
			{
				t1.push_back(temp[j]);
			}
		}
		tsp(temp[i],cost+dp[curr][temp[i]],t1,ans);	
	}
}
int main()
{
	int nodes;
	cout<<"Enter the number of nodes -> ";
	cin>>nodes;
	memset(dp,0,sizeof(dp));
	for(int i = 0; i<nodes;i++)
	{
		for(int j = 0;j<nodes;j++)
		{
			if(i==j)
			{
				continue;
			}
			cout<<"Enter the distance between "<<i+1<<" to "<<j+1<<" -> ";
			cin>>dp[i][j];
		}
	}
	int ans = INT_MAX;
	vector<int> temp;
	for(int i = 1;i<nodes;i++)
	{
		temp.push_back(i);
	}
	tsp(0,0,temp,ans);
	cout<<"\n The Minimum cost is "<<ans;
}
