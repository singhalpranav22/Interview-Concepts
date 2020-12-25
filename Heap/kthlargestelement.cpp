// Identification of heap problem:
// K and smallest/largest
// For kth largest make minheap
// For kth smalles make maxheap
// Complexity => O(nlogk)
class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue <int,vector<int> , greater<int> > mnheap;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            mnheap.push(a[i]);
            if(mnheap.size()>k) mnheap.pop();
        }
        return mnheap.top();
    }
};