//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int binary_search(vector<long long> v,int l,int u,int x,int result)
    {
        
        while(l<=u)
        {
            int mid=(l+u)/2;
            if(v[mid] == x )
            {
                    
                return mid;
                
            }
          
            if(v[mid] < x)
            {
              result=mid;
                l=mid+1;
                
            }
            else if(v[mid] > x )
            {
                  
                u=mid-1;
               
            }
        }
       
        return result;
        
       
    }
    int findFloor(vector<long long> v, long long n, long long x){
        int result=-1;
        return binary_search(v,0,n-1,x,result);
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends