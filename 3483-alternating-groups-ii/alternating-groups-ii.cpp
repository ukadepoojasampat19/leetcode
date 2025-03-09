class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int l=0;
        int r=1;
        int color_size = colors.size();
        int res=0;
        while(r < color_size){
            if(colors[r] == colors[r-1]){
                l =r;
                r++;
                continue;
            }
            r++;
            if(r - l < k) continue;
            res++;
            l++;
        }
        return res;
    }
};