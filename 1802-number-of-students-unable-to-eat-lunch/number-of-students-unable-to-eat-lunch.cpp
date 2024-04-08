class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        /*int ct=0;
        queue<int> myqueue;
        stack<int> temp;
        for(auto c: students)
        {
            myqueue.push(c);
        }
        for(auto c: sandwiches)
        {
            temp.push(c);
        }
        while(!myqueue.empty() && !sandwiches.empty())
        {
            if(myqueue.front() == temp.top())
            {
                myqueue.pop();
                temp.pop();
            }
            else
            {
                int num=myqueue.front();
                myqueue.pop();
                myqueue.push(num);

            }
            
        }
        int size_q= queue.size();
            return size_q;*/
             vector<int> counts(2, 0);
        for (int student : students)
            counts[student]++;

        int remaining = sandwiches.size();
        for (int sandwich : sandwiches) {
            if (counts[sandwich] == 0)
                break;
            if (remaining == 0)
                break;
            counts[sandwich]--;
            remaining--;
        }

        return remaining;
    }
};