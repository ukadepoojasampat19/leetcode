class MyCalendarTwo {
private:
        vector<pair<int,int>> doubleOverlapping;
        vector<pair<int,int>> overallOverlapping;
public:
    MyCalendarTwo() {
        
    }
    bool checkOverlap(int s1, int e1,int s2, int e2)
    {
        if(max(s1,s2) < min(e1,e2))
        {
            return true;
        }
        return false;
    }
    pair<int,int> findOverlappingRegion(int s1, int e1,int s2, int e2)
    {
            int first = max(s1,s2);
            int second = min(e1,e2);
            return {first,second};
    }
    bool book(int start, int end) {

        for(pair<int,int>& region :doubleOverlapping)
        {
            if(checkOverlap(region.first, region.second,start,end))
            {
                return false;
            }
        }
        //if double overlap exist then store it
        for(pair<int,int>& region : overallOverlapping )
        {
            if(checkOverlap(region.first, region.second,start,end))
            {
                doubleOverlapping.push_back(findOverlappingRegion(region.first, region.second,start,end));
            }
        }

        overallOverlapping.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */