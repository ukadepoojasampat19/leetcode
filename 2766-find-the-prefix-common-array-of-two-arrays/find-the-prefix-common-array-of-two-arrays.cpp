class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> Af;
       set<int>Bf;
        vector<int> res;
        for(int i=0;i<A.size();i++)
        {
            Af.insert(A[i]);
            int ct=0;
            for(int j=0;j<=i;j++){
                    if(Af.count(B[j]))
                    {
                        ct++;
                    }
            }
            res.push_back(ct);

        }
        return res;
    }
};