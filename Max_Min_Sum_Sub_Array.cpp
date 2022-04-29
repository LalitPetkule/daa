#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
	// k must be smaller than n
	if (n < k)
	{
        cout << "Invalid";
        return -1;
	}
	int res = 0;
	for (int i=0; i<k; i++)
	res += arr[i];
	int curr_sum = res;
	for (int i=k; i<n; i++)
	{
        curr_sum += arr[i] - arr[i-k];
        res = max(res, curr_sum);
	}

	return res;
}
// Returns minimum sum in a subarray of size k
int minSum(int arr[], int n, int k)
{
	// k must be smaller than n
	if (n < k)
	{
        cout << "Invalid";
        return -1;
	}
	int res = 0;
	for (int i=0; i<k; i++)
	res += arr[i];
	int curr_sum = res;
	for (int i=k; i<n; i++)
	{
        curr_sum += arr[i] - arr[i-k];
        res = min(res, curr_sum);
	}

	return res;
}

long int random()
{
	int num=rand()%10000000;
	return num;
}
// Driver code
int main()
{
	int n,k,a=1,rd,ch;
	struct timespec start, end;
	cout<<"\nEnter the number of elements in the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        rd=random();
        cout<<"\t "<<rd;
        arr[i] = rd;
    }
    cout<<"\nEnter the value K : ";
    cin>>k;
    while(a==1)
    {
        cout<<"\n\n\n1.Max Sum Sub-Array\n2.Min Sum Sub-Array";
        cout<<"\n\nEnter your choice : ";
        cin>>ch;
        //int n = sizeof(arr)/ sizeof(arr[0]);
        switch(ch)
        {
            case 1:
                {
                    clock_gettime(CLOCK_MONOTONIC, &start);

                    ios_base::sync_with_stdio(false);

                    cout << maxSum(arr, n, k)<<endl;

                    clock_gettime(CLOCK_MONOTONIC, &end);

                    // Calculating total time taken by the program.
                    double time_taken;
                    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
                    time_taken = 1000*(time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

                    cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9);
                    cout << " milliseconds" << endl;
                }
                break;

            case 2:
                {
                    clock_gettime(CLOCK_MONOTONIC, &start);

                    ios_base::sync_with_stdio(false);

                    cout << minSum(arr, n, k)<<endl;

                    clock_gettime(CLOCK_MONOTONIC, &end);

                    // Calculating total time taken by the program.
                    double time_taken;
                    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
                    time_taken = 1000*(time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

                    cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9);
                    cout << " milliseconds" << endl;
                }
                break;

            default: cout<<"\nWrong choice.";
        }
        cout<<"\nDo you want to continue(1/0) : ";
        cin>>a;
    }

	return 0;
}
