class Solution {
public:
    void dfs(int curr,int n,vector<int>& res)
    {
            if(curr > n) return;

            res.push_back(curr);

            for(int j=0;j<=9;j++)
            {
                int next = curr * 10 +j;
                if(next <=n)
                {
                    dfs(next,n,res);
                }
                else
                {
                    break;
                }
            }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int i=1;i<=9;i++)
        {
            if(i <=n)
            {
                dfs(i,n,res);
            }
        }
        return res;
    }
};