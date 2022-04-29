#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

	int n;
	cout<<"\nEnter no of coins : ";
	cin>>n;

	int a[n];
	cout<<"\nEnter the values of coin : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}



	int v;
	vector <int> ans;

	cout<<"\nEnter the Change You Want : ";
	cin>>v;

	int d=v;

	sort(a, a + n, greater<int>());
	int count=0;
	for(int i=0;i<n;i++){
		while(d>=a[i]){
			d-=a[i];
			ans.push_back(a[i]);
			count++;
		}
		if(d == 0)
            break;
	}

	cout<<"\nThe number of coins are : "<<count;
	cout<<"\nThe selected coins are : ";

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}
