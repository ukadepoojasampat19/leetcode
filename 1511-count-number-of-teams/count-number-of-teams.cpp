class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();
        int ct =0;

        //ascending
        for(int i=0;i<n;i++)
        {
            int a = rating[i];
            for(int j=i+1;j<n;j++)
            {
                int b = rating[j];
               
                if(b > a)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        int c = rating[k];
                        if(c > b)
                        {
                           
                            ct++;
                           
                        }

                    }
                    
                }
               
            }
        }
        //decending
        for(int i=0;i<n;i++)
        {
            int a = rating[i];
            for(int j=i+1;j<n;j++)
            {
                int b = rating[j];
                bool check = false;
                if(b < a)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        int c = rating[k];
                        if(c < b)
                        {
                            ct++;
                        }

                    }
                    
                }
               
            }
        }
        return ct;
        
    }
};