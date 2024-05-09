class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
      /*  sort(happiness.begin(),happiness.end());
        int no_child=k;
        int turn=k;
        long long sum=0;
        for(int i=happiness.size()-1;i>=0;i--)
        {
            if(turn >0)
            {
                 sum+=happiness[i];
                 turn--;
            }
            for(int j=i-1;j>=0;j--)
            {
                int a=happiness[j]-1;
                if(a >=0)
                {
                    happiness[j] =a;
                }
            }
            
            
           
        }
        return sum;*/
         sort(happiness.begin(),happiness.end(),greater<int>());
         int turn=0;
         long long happ_score=0;
         for(auto& a: happiness)
         {
            if(turn == k)
            {
                break;

            }
            happ_score+=max(0,a-turn);
            turn++;
         }
         return happ_score;
    }
};