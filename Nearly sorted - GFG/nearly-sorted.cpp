//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
   
    vector <int> nearlySorted(int arr[], int num, int K){
      
        vector<int> arr2;
      
    priority_queue <int, vector<int>, greater<int> > minhp;
    
    for(int i=0;i<num;i++)
    {
        minhp.push(arr[i]);
        if(minhp.size() > K)
        {
            
            arr2.push_back(minhp.top());
            minhp.pop();
        }
    }
    while(minhp.size() > 0)
    {
        int a=minhp.top();
        arr2.push_back(a);
        minhp.pop();
    }
    return arr2;
}
    
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends