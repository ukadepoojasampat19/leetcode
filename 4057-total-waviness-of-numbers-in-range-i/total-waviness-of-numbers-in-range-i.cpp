class Solution {
public:
     int calculate_waviness(int num){
       string s = to_string(num);
       int n = s.length();
       
       int ct =0;

       for(int i =1;i<n -1;i++){
                if(s[i] > s[i-1] && s[i] > s[i+1]) ct++;
                else if(s[i] < s[i-1] && s[i] < s[i+1]) ct++;
       }
       return ct;


     }
    int totalWaviness(int num1, int num2) {
      int ans = 0;

      for(int num=num1;num <= num2;num++){
        ans += calculate_waviness(num);
      }
       return ans;
    }
};