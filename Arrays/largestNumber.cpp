// Use of comparator function
// Given a list of non-negative integers nums, arrange them such that they form the largest number.

// Note: The result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
// Example 3:

// Input: nums = [1]
// Output: "1"
// Example 4:

// Input: nums = [10]
// Output: "10"
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

 bool com(int a,int b){
        string p=to_string(a),q=to_string(b);
        return (p+q)>(q+p);
    }
class Solution {
public:
   
    string largestNumber(vector<int>& v) {
        if(v.size()==1) return to_string(v[0]);
        bool f=true;
        for(int i=0;i<v.size();i++){
            if(v[i]!=0)
            {
                f=false;break;
            }
        }
        if(f) return "0";
        sort(v.begin(),v.end(),com);
        if(v[0]==0) return 0;
        string ans="";
        for(int i=0;i<v.size();i++){
            ans+=to_string(v[i]);
        }
        return ans;
    }
};