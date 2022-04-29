#include<iostream>
using namespace std;

int DAC(int arr[],int size1,int n){
    int l=1;
    int h=size1;



    while(l<=h){
        int mid;
        mid=(l+h)/2;
        if(arr[mid]==n){
            return mid;
        }
        if(arr[mid]<n){
            l=mid+1;
        }
        else h=mid-1;

    }
    return -1;

}

int main(){
    int size1;
    cout<<"number of elements : ";
    cin>>size1;

    int arr[size1];

    for(int i=1;i<=size1;i++){
        cin>>arr[i];
    }
    int n;
    cout<<"enter number to find : ";
    cin>>n;

    cout<<DAC(arr,size1,n);

}
