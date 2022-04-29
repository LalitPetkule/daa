#include<iostream>
#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

int findCab(float start_time[], float finish_time[], int n)
{
	int cab_cnt = 1, result = 1;
    int i = 1, j = 0;
    /*
    for (int i = 0; i < n; i++)
    {
        cab_cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((start_time[i] >= start_time[j] && start_time[i] <= finish_time[j]) || (start_time[j] >= start_time[i] && start_time[j] <= finish_time[i]))
            {
                cab_cnt++;
            }
        }
        result = max(result, cab_cnt);
    }*/
    sort(start_time, start_time + n);
    sort(finish_time, finish_time + n);
    while (i < n && j < n) {
        if (start_time[i] <= finish_time[j]) {
            cab_cnt++;
            i++;
        }

        else if (start_time[i] > finish_time[j]) {
            cab_cnt--;
            j++;
        }
        result = max(result, cab_cnt);
    }
    return result;
}

int main()
{
	int n;
	struct timespec start, end;
    srand(time(0));

	cout<<"\nEnter the number of time intervals : ";
	cin>>n;
	float start_time[n];
	float finish_time[n];
	cout<<"\nEnter the time intervals : ";
	for(int i=0;i<n;i++)
    {
        float s1,s2,e1,e2;
        cin>>s1>>s2>>e1>>e2;
        s1 += s2/60;
        e1 += e2/60;
        start_time[i]=s1;
        finish_time[i]=e1;
    }
    clock_gettime(CLOCK_MONOTONIC, &start);

    ios_base::sync_with_stdio(false);

    int count = findCab(start_time, finish_time, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

	cout<<"\nTotal number of minimum Cabs require are : "<<count;
	double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = 1000*(time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " milliseconds" << endl;
	return 0;
}
/*
6
1 0 2 0
9 30 13 0
12 0 12 30
16 0 21 30
20 30 21 00
21 30 22 30
*/
