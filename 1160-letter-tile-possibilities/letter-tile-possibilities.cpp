class Solution {
public:
    int arragemnt(string& s,int l,int r,set<string>& uniqueStr)
    {
        if(l == r){
            uniqueStr.insert(s);
            return 0;
        }
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            arragemnt(s,l+1,r,uniqueStr);
            swap(s[l],s[i]);

        }
        return 0;
    }
    int numTilePossibilities(string tiles) {
        //no of arragement
        int result =0;
        set<string> uniqueStr;
        set<string> final_str;
        arragemnt(tiles, 0, tiles.size()-1,uniqueStr);
        int uniw_size = uniqueStr.size();

        for(auto& str: uniqueStr)
        {
            string temp;
            for(char ch: str){
                temp += ch;
                final_str.insert(temp);
            }
        }
        for(auto& t:final_str ){
            result++;
        }
        return result;
    }
};