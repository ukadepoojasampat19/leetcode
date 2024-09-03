class Solution {
public:
    int getLucky(string s, int k) {
        string res="";
        for(auto& n: s)
        {
            int num = n - 'a';
            res+= to_string(num + 1);
        }
        //cout<<res<<"\n";
        while(k--)
        {
            int result=0;
            for(auto& n: res)
            {
                result += n -'0';
            }
            //cout<<result<<" ";
            res = to_string(result);
        }
        return stoi(res);
    }
};