class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;

        sort(arr1.begin(),arr1.end());

        for(int i=0;i< arr2.size(); i++)
        {
            int num = arr2[i];
            for(int j=0; j< arr1.size(); j++)
            {
                if(num == arr1[j])
                {
                    arr1[j]=-1;
                    result.push_back(num);
                }
            }
        }
        for(int i=0;i<arr1.size();i++)
        {
            if(arr1[i] >= 0)
            {
                result.push_back(arr1[i]);
            }
        }

        return result;
    }
};