// Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

// Example 1:

// Input:  N = 2
// Output: 11 10
// Explanation: 11 and 10 have more than 
// or equal 1's than 0's
// Example 2:

// Input:  N = 3
// Output: 111 110 101
// Explanation: 111, 110 and 101 have more 
// than or equal 1's than 0's
// User Task:
// Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any input or print anything.

// Expected Time Complexity: O(|2N|)
// Expected Auxiliary Space: O(2N)

// Constraints:
// 1 <= N <= 20

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:	
vector<string> ans;
void find(string s,int o,int z,int n)
{
    if(o+z==n){
        ans.push_back(s);
        return ;
    }
    if(z<o)
    {
        string a;
        a+=s+"1";
        o++;
        find(a,o,z,n);
        string b;
        b+=s+"0";
        z++;
        o--;
        find(b,o,z,n);
    }
    else
    {
        string a;
        a+=s+"1";
        o++;
        find(a,o,z,n);
    }
    return;
}
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    int o=0,z=0;
	    string s="";
	    find(s,o,z,N);
	    return ans;
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends