class Solution {
public:
    int maximumSwap(int num) {
        int max_num=INT_MIN;
        string result = to_string(num);

        string temp = result;
        for(int i=0;i<temp.size();i++)
        {
            
            for(int j=0;j<temp.size();j++)
            {
                swap(temp[i],temp[j]);
                int n = stoi(temp);
                max_num = max(max_num,n);
                temp=result;
            }
        }
        return max_num;
    }
};