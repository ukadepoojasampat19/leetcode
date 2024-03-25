class DisjointSet    {
    vector<int> parent, size;
    int components;
public:
	// Create an empty union find data structure with N isolated sets.
    DisjointSet(int n)   {
        components = n;
        parent.resize(n);
        size.resize(n, 0);

        for(int i = 0; i < n ; i++)	{
            parent[i] = i;
            size[i] = 1;
        }
    }

	// Return the parent of component corresponding to object p.
    int find(int u)	{
        if (u == parent[u]) return u;

        return parent[u] = find(parent[u]);
    }

	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int root_of_x = find(x);
        int root_of_y = find(y);

        if (root_of_x == root_of_y) return;
		
		// make smaller root point to larger one
        if (size[root_of_x] < size[root_of_y])	{ 
            parent[root_of_x] = root_of_y; 
            size[root_of_y] += size[root_of_x]; 
        } else	{ 
            parent[root_of_y] = root_of_x; 
            size[root_of_x] += size[root_of_y]; 
        }
        components--;
    }

	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
    
	// Return the number of disjoint sets.
    int totalComponents() {
        return components;
    }

    // Is the graph connected?
    bool isConnected() {
        return size[find(0)] == size.size();
    }
};


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> factorIndex;
        DisjointSet ds(n);

        for(int i = 0 ; i < n ; i++) {
            int number = nums[i];
            for(int factor = 2 ; factor*factor <= number ; factor++) {
                if(number % factor != 0) continue;

                if(factorIndex.find(factor) == factorIndex.end()) {
                    factorIndex[factor] = i;
                } else {
                    ds.merge(factorIndex[factor], i);
                }

                while(number % factor == 0) number /= factor;
            }
            if(number > 1) {
                if(factorIndex.find(number) != factorIndex.end()) {
                    ds.merge(factorIndex[number], i);
                } else {
                    factorIndex[number] = i;
                }
            }
        }

        return (ds.totalComponents() == 1);
        // return ds.isConnected();
    }
};







// class Solution {
// public:
//     bool canTraverseAllPairs(vector<int>& nums) {
//         unordered_map<int, vector<int>> adjList;
//         int n = nums.size();

//         for(int i = 0 ; i < n ; i++) {
//             for(int j = i+1 ; j < n ; j++) {
//                 if(__gcd(nums[i], nums[j]) != 1) {
//                     adjList[i].push_back(j);
//                     adjList[j].push_back(i);
//                 }
//             }
//         }

//         // BFS
//         queue<int> q;
//         vector<bool> visited(n, false);
//         q.push(0);
//         visited[0] = true;

//         while(!q.empty()) {
//             int element = q.front();
//             q.pop();
//             // cout << element << ",";
//             for(int neighbourIndex : adjList[element]) {
//                 if(visited[neighbourIndex] == false) {
//                     visited[neighbourIndex] = true;
//                     q.push(neighbourIndex);
//                 }
//             }
//         }

//         for(auto item : visited) {
//             if(item == false) return false;
//         }
//         return true;
//     }
// };