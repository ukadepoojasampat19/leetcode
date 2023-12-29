//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isvalid(int arr[],int n,int k,int max)
    {
        int std=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum > max)
            {
                std++;
                sum=arr[i];
            }
            if(std > k)
            {
                return false;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(N < M)
        {
            return -1;
        }
        int start = *max_element(A, A + N);  
        int end =0;
        for(int i=0;i<N;i++)
        {
            end=end+A[i];
        }
        int result=0;
       
        while(start <= end)
        {
            int mid=start + (end - start)/2;
            if(isvalid(A,N,M,mid) == true )
            {
                result=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
       return result;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends