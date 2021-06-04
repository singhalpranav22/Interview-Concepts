// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

// Example 1:

// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.
// Example 2:

// Input: nums = [0]
// Output: 0
// Example 3:

// Input: nums = [2,4]
// Output: 6
// Example 4:

// Input: nums = [8,10,2]
// Output: 10
// Example 5:

// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127
 

// Constraints:

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 231 - 1


class Solution {
public:
    struct Node{
        Node *pt[2]={NULL};
    };
    int findMaximumXOR(vector<int>& v) {
        int ans=0;
        Node *root=new Node();
        for(int j=0;j<v.size();j++){
            int n=v[j];
            Node *temp=root;
            for(int i=31;i>=0;i--){
                int bit = ((n>>i)&1);
                if(temp->pt[bit]!=NULL){
                    temp=temp->pt[bit];
                }
                else{
                    temp->pt[bit]=new Node();
                    temp=temp->pt[bit];
                }
            }
        }
        for(int j=0;j<v.size();j++){
            int n=v[j];
            Node *temp=root;
            int sum=0;
            for(int i=31;i>=0;i--){
                int bit = ((n>>i)&1);
                int to;
                if(bit==0) to=1;
                else to=0;
                if(temp->pt[to]!=NULL){
                        sum+=(1<<i);
                    temp=temp->pt[to];
                }
                else{
                    if(to==0)
                    temp=temp->pt[1];
                    else
                        temp=temp->pt[0];
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};