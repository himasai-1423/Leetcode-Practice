//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         int left_size = mid - l +1, right_size = r - mid;
         
         auto *leftArr= new int[left_size], *rightArr= new int[right_size];
         
         for(int i=0; i<left_size; i++)
             leftArr[i] = arr[l+i];
             
         for(int i=0; i<right_size; i++)
             rightArr[i] = arr[mid+i+1];
             
         int indexLeft =0, indexRight = 0, indexMain=l;
         
         while(indexLeft<left_size && indexRight<right_size){
             if(leftArr[indexLeft]<rightArr[indexRight]){
                 arr[indexMain] = leftArr[indexLeft];
                 indexLeft++;
             }
            
             else{
                 arr[indexMain] = rightArr[indexRight];
                 indexRight++;
             }
             indexMain++;
         }
         
         while(indexLeft<left_size){
             arr[indexMain] = leftArr[indexLeft];
             indexLeft++;
             indexMain++;
         }
         
         while(indexRight<right_size){
             arr[indexMain] = rightArr[indexRight];
             indexRight++;
             indexMain++;
         }
         
         delete[] leftArr;
         delete[] rightArr;
         
         return;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends