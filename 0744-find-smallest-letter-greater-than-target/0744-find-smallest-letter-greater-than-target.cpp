class Solution {
public:
     char binary_search(vector<char>& arr,int l,int u,char target)
    {
        char ch=arr[0];
        while(l<=u)
        {
            int mid=(l+u)/2;
           
            if(target < arr[mid])
            {
                 ch=arr[mid];
                u=mid-1;
            }
            else
            {
               
                l=mid+1;
            }
        }
        return ch;
        
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
     
        int n=letters.size();
        return binary_search(letters,0,n-1,target);
    }
};