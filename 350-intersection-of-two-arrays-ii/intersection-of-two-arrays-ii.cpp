class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> arr1;
        unordered_map<int,int> arr2;
        vector<int> result;

        for(auto  &n: nums1)
        {
            arr1[n]++;
        }
        for(auto  &n: nums2)
        {
            arr2[n]++;
        }

        for( auto&n: arr1)
        {
            int a = n.first;
            int b = n.second;
           
            if( arr2.find(a) != arr2.end())
            {
                int c = arr2[a];
                int min_val = min(b,c);
                for(int i=0;i<min_val;i++)
                {
                    result.push_back(a);

                }
            }
        }
        return result;
    }
};