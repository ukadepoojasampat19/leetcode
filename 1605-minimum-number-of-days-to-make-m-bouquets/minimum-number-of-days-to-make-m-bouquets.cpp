class Solution {
public:
    int canmakebouquet(vector<int>& bloomDay,int mid,int k)
    {
        int bou_count =0;
        int consecutive_ct =0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= mid)
            {
                consecutive_ct++;
            }
            else
            {
                consecutive_ct=0;
            }
            if(consecutive_ct == k)
            {
                bou_count++;
                consecutive_ct =0;
            }
        }
        return bou_count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int start=0;
        int back = *max_element(bloomDay.begin(),bloomDay.end());
        int min_days=-1;
        while(start <= back)
        {
            int mid = start +(back-start)/2;  //l+(r-1)/2
            if(canmakebouquet(bloomDay,mid,k) >= m)
            {
                min_days = mid;
                back = mid-1;
            }
            else
            {
                start = mid +1;
            }
            
        }
        return min_days;
        }
};
