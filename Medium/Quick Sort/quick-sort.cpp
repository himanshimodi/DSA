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
    //Function to sort an array using quick sort algorithm WITH PIVOT AS LAST ELEMENT
    void quickSort(int arr[], int start, int end)
    {
        //base case
        if(start >= end) return;
        
        int pivot = end;
        int i = start-1;
        int j = start;
        
        //main logic
        while(j <= pivot){
            if(arr[j] < arr[pivot]){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        //after 'j' is out of the loop that is out of bound then do
        i++;
        swap(arr[i], arr[pivot]); //now arr[i] element is in its correct position
        
        //Recursion
        quickSort(arr, start, i-1);
        quickSort(arr, i+1, end);
    }   
    
    public:
    int partition (int arr[], int start, int end)
    {
        //WE ARE NOT GOING TO USE THIS AS WE ARE DOING QUICKSORT WITH PIVOT AS LAST ELEMENT
       // Your code here
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends