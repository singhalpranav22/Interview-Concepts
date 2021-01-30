// use of topological sort
// There are a total of n courses you have to take labelled from 0 to n - 1.

// Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

// Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

// If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

// using topological sort and finding the cycle using the ordering that whether a parent comes before the child in final topological order or not
#define pb push_back

class Solution {
public:
    vector<int> adj[2005];
    stack<int> s;
    bool vis[2005]={false};
    void dfs(int val)
    {
         vis[val]=true;
        for( auto x : adj[val])
        {
            if(vis[x]!=true)
            {
                dfs(x);
            }
        }
        s.push(val);
    }
    bool isCycle(stack<int> st,int num)
    {
     unordered_map<int,int> pos;
        int i=0;
        while(st.size()!=0)
        {
            pos[st.top()]=i;
            i++;
            st.pop();
        }
        for(int i=0;i<num;i++)
        {
            for(auto x : adj[i])
            {
                if(pos[i]>pos[x])
                    return true;
            }
        }
        return false;
    }
        
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        for(int i=0;i<=2000;i++) adj[i].clear();
        int n=pre.size();
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            adj[pre[i][1]].pb(pre[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]!=true)
            {
                dfs(i);
            }
        }
        if(isCycle(s,numCourses))
             return ans;
        else
        {
            while(s.size()!=0)
            {
                ans.pb(s.top());
                s.pop();
            }
            return ans;
        }
        
        
    }
};