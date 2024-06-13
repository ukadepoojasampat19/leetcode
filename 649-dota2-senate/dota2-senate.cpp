class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> rad,dire;

        int n = senate.length();

        for(int i=0;i<n;i++)
        {
            if(senate[i] == 'R') rad.push(i);
            else dire.push(i);
        }
        while(!rad.empty() && !dire.empty())
        {
            if(rad.front() < dire.front())
            {
                rad.push(n++);
            }
            else
            {
                dire.push(n++);
            }
            rad.pop(),dire.pop();
        }
        return (rad.empty()) ? ("Dire") : ("Radiant");
    }
};