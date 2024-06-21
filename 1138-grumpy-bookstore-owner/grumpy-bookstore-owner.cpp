class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

    int n = grumpy.size();
    
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(grumpy[i] == 0)
        {
            result += customers[i];
        }
    }
    int max_value =0;
    int add_statified =0;
    int max_satified =0;
    for(int i=0;i<minutes;i++)
    {
        if(grumpy[i] == 1)
        {
            add_statified += customers[i];
        }
    }
    max_satified = add_statified;
    for(int i=minutes;i<n;i++)
    {
        if(grumpy[i] == 1)
        {
            add_statified += customers[i];
        }
        if(grumpy[i-minutes] == 1)
        {
            add_statified -= customers[i-minutes];
        }
        max_satified =max(max_satified,add_statified);
    }
    

    return result + max_satified;
    }
};