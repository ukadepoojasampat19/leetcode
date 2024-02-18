class Solution {
public:
    string intToRoman(int num) {
        vector<int> num1={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> num2={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string result="";
        
        for(int i=0;i<num1.size();i++)
        {
            while(num >= num1[i])
            {
                result+=num2[i];
                num-=num1[i];
            }
        }
        return result;
        
    }
};