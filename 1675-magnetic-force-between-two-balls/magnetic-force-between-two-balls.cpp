class Solution {
public:
    bool ispossible(int midforce,vector<int>& position,int m)
    {
        int prev_ball = position[0];
        int count_ball =1;
        for(int i=1;i<position.size();i++)
        {
            int curr = position[i];
            if((curr - prev_ball) >= midforce)
            {
                count_ball++;
                prev_ball= curr;
            }

            if(count_ball == m) break;
        }
        return count_ball == m;
    }
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();
        sort(position.begin(),position.end());
        int minforce = 1;
        int maxforce = position[n-1] -position[0];
        int result =0;
        while(minforce <= maxforce)    
        {
            int midforce = minforce + (maxforce - minforce)/2;

            if(ispossible(midforce,position,m))
            {
                result = midforce;
                minforce = midforce +1;
            }
            else
            {
                maxforce = midforce -1;
            }
        }  
        return result;  
    }
};