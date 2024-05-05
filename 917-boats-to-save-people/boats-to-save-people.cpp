class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(),people.end());
       int st=0,ed=people.size()-1;
       int num_botas=0;
       while(st <= ed)
       {
           if(people[st] + people[ed] <= limit)
           {
                num_botas++;
                st++;
                ed--;
           }
           else
           {
               ed--;
               num_botas++;

           }
       }
       return num_botas;
    }
};


