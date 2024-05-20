class Solution {
public:
    /*int subset(string op,string ip,int sum)
    {
        if(ip.empty())
        {
           
            int temp_sum=0;
            int num=0;
            for(auto& n:op)
            {
                num= n-'0';
                temp_sum^=num;
                num=0;
            }
            
            return sum + temp_sum;
        }
        int exclude_num =subset(op,ip.substr(1),sum);
        int include_num =subset(op+ip[0],ip.substr(1),sum);
        return exclude_num + include_num;

    }*/
    int subsetXORSum(vector<int>& nums) {
       /* string op="";
        string ip;
        int sum=0;
        for(auto& n: nums)
        {
            ip+=to_string(n);
        }
        return subset(op,ip,sum);*/
        int sum=0;
        for(int n: nums)
        {
            sum |= n;
        }
        return sum << (nums.size() -1);
        
    }
};