class Solution {
public:
   
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue <pair<int,int>> maxhp;
        vector <int> arr1;
        for(int i=0;i<n;i++)
        {
            maxhp.push({abs(arr[i] - x), arr[i]});
            if(maxhp.size() > k)
            {
                maxhp.pop();
            }
        }
        while(maxhp.size() > 0)
        {
            int a=maxhp.top().second;
            arr1.push_back(a);
            maxhp.pop();
        }
        sort(arr1.begin(),arr1.end());
        return arr1;
        
    }
};