class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxl=0,maxr=0,sum=0;
        vector<int> templ(n,0),tempr(n,0);

        for(int i=0,j=n-1;i<n && j>=0;i++,j--)
        {
            maxl=max(maxl,height[i]);
            maxr=max(maxr,height[j]);
            templ[i]=maxl;
            tempr[j]=maxr;
        }
        for(int i=0;i<n;i++)
        {
            sum+=min(templ[i],tempr[i]) - height[i];
        }
        return sum;

    }
};