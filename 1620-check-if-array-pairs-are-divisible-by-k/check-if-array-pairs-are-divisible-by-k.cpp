class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> storeCount(k,0);


        for(auto& n: arr)
        {
            int num = ((n % k) + k ) % k;
            storeCount[num]++;
        }
        

        if(storeCount[0] % 2 != 0) return false;

        for(int i=1;i<k;i++)
        {
            if(storeCount[i] != storeCount[k-i])
            {
                return false;
            }
        }
        return true;
    }
};