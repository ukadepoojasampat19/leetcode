//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int  binary_Search(int arr[],int l,int u,int k)
  {
      if(l<=u)
      {
        int mid=(l+u)/2;
        if(arr[mid] == k)
        {
            return mid;
        }
        else if(k < arr[mid])
        {
            return binary_Search(arr,l,mid -1,k);
            
        }
        else 
        {
             return binary_Search(arr,mid + 1,u,k);
           
        }
        
      }
      return -1;
     
  }
    int binarysearch(int arr[], int n, int k) {
        int l=0;
        int u=n-1;
        return binary_Search(arr,l,u,k);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends