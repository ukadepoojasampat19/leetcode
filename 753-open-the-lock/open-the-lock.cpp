class Solution {
public:
    
    int openLock(vector<string>& deadends, string target) {

          unordered_set<string> dead(deadends.begin(),deadends.end());
          unordered_set<string> visit;
          queue<string> q;
          q.push("0000");
          visit.insert("0000");
          int level=0;
          while(!q.empty())
          {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string curr = q.front();
                q.pop();

                if(dead.count(curr)) continue;
                if(curr == target)  return level;

                for(int j=0;j<4;j++)
                {
                    string up=curr;
                    string down=curr;

                    up[j]= (up[j] == '9') ? '0': up[j]+1;
                    down[j]=(down[j] == '0') ? '9': down[j] -1;

                    if( !visit.count(up) && !dead.count(up))
                    {
                        q.push(up);
                        visit.insert(up);
                    
                    }
                    if(!visit.count(down) && !dead.count(down))
                    {
                         q.push(down);
                         visit.insert(down);
                    }
                }


            }
            level++;
          }


        return -1;
       
    }
};