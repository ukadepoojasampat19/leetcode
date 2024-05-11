class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
           double result=DBL_MAX;

           //calulate all worker ratio
           vector<pair<double,int>> worker_ratio(n);

           for(int worker=0;worker < n;worker++)
           {
             worker_ratio[worker]= make_pair((double)wage[worker]/quality[worker],quality[worker]);
           }

           sort(begin(worker_ratio),end(worker_ratio)); //o(logn)
           priority_queue<int,vector<int>> pq;

           int sum_quality=0;

           for(int i=0;i<k;i++)
           {
              pq.push(worker_ratio[i].second);
              sum_quality+=worker_ratio[i].second;
           }

           double manager_ratio= worker_ratio[k-1].first;
           result=manager_ratio*sum_quality;


           for(int manager=k;manager<n;manager++)
           {
               /* double manager_wage= (double)wage[i]/quality[i];
                double sum_wages=0;
                vector<double> store;

                for(int j=0;j<quality.size();j++)
                {
                    sum_wages= (double) manager_wage * quality[j];
                    if( sum_wages >= wage[j])
                    {
                        store.push_back(sum_wages);
                    }
                    

                }
                if(store.size() < k)
                {
                    continue;
                }
                priority_queue<double,vector<double>> pq;
                double sum=0;
                for(auto& wages:store)
                {
                    sum+=wages;
                    pq.push(wages);

                    if(pq.size() > k)
                    {
                        sum-=pq.top();
                        pq.pop();
                    }
                }*/

                double manager_ratio = worker_ratio[manager].first;
                pq.push(worker_ratio[manager].second);
                sum_quality+=worker_ratio[manager].second;
                if(pq.size() > k)
                {
                    sum_quality-=pq.top();
                    pq.pop();
                }
                result=min(result,manager_ratio*sum_quality);

           }
           
        return result;
    }
};