class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      /*  map<vector<int>, int>  sorted_arr;
        vector<int> temp;
        vector<int> result;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int num1=arr[i];
            for(int j=i+1;j<n;j++)
            {
                int num2=arr[j];
                sorted_arr[{num1,num2}]= floor(num1/num2);
            }
        }
        for(auto& n: sorted_arr)
        {
            temp.push_back(n);
        }
        sort(temp.begin(),temp.end());
        int var= temp[k-1];
        
       // int count=0;
        for(auto it = sorted_arr.begin();it != sorted_arr.end(); ++it)
        {
            //count++;
            if(var == it)
            {
                result.push_back(it->first[0]);
                result.push_back(it->first[1]);
                break;

            }
        }
        return result;*/
        priority_queue<vector<double>> pq; //{fraction,arr[i],arr[j]}
        int n= arr.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double div=(double)arr[i]/arr[j];
                pq.push(vector<double>{div, (double)arr[i],(double)arr[j]});
                if(pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        auto vc = pq.top();
        vector<int> result(2);
        result[0]=vc[1];
        result[1]=vc[2];

        return result;
        
        
               
        
    }
};