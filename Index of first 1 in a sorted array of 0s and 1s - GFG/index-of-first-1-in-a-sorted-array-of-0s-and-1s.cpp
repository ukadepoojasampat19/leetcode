//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int  binary_search(int arr[],int l,int u,int target)
     {
         int result=-1;
         while(l<=u)
         {
             int mid=(l+u)/2;
             if(target <= arr[mid])
             {
                 result=mid;
                 u=mid-1;
             }
             else 
             {
                 l=mid+1;
             }
         }
         return result;
     }
    int firstIndex(int a[], int n) 
    {
        return binary_search(a,0,n-1,1);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends