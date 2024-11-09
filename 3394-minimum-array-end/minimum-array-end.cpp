class Solution {
public:
    long long minEnd(int n, int x) {
        long result =x;
        long remaning =n-1;
        long position =1;


        while(remaning){
            if(!(x & position)){
                result |= (remaning & 1)* position;
                remaning >>=1;
            }
            position <<=1;
        }
        return result;
    }
};