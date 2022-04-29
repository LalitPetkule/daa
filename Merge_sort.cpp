#include<iostream>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1;
   nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

long int random()
{
	int num=rand()%10000000;
	return num;
}

int main()
{
   int n,rd;
   struct timespec start, end;
   srand(time(0));

   cout << "\nEnter the number of elements : ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   for(int i=0;i<n;i++)
   {
        rd=random();
        cout<<"\t "<<rd;
        arr[i] = rd;
   }
   cout << "\n\n\nArray before Sorting : ";
   display(arr, n);
   clock_gettime(CLOCK_MONOTONIC, &start);

   ios_base::sync_with_stdio(false);

   mergeSort(arr, 0, n-1);

   clock_gettime(CLOCK_MONOTONIC, &end);

   //(n-1) for last index
   cout << "\nArray after Sorting : ";
   display(arr, n);

   double time_taken;
   time_taken = (end.tv_sec - start.tv_sec) * 1e9;
   time_taken = 1000*(time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

   cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9);
   cout << " milliseconds" << endl;
   return 0;
}
