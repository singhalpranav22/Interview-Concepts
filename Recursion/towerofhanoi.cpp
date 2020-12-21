// A poor old man works in a palace for a living. One day the old man's wife met with an accident. She needed an immediate operation but the old man's savings were not enough for the operation. He went running to the king to beg for money. The king told that he will not only pay the full amount for the operation but also double his salary. But for that the old man had to pass a test. The king showed him a pile of glass plates kept one above another, each one being smaller than the one beneath. The plates were kept in box 1. He had to transfer the plates to box 3 using box 2. However, there were some constraints. The old man could only take one plate at a time and he could only place a smaller plate on top of a larger plate. He could take a plate only from the top. Help the old man do so.

// Note:
// Given any number of plates, they can be transferred from box 1 to box 3 using box 2 using the following steps.
 

// Step 1: Transfer first N-1 plates from box 1 to box 2 using box 3.

// Step 2: Transfer the remaining plate from box 1 to box 3.

// Step 3: Transfer the first N-1 plates from box 2 to box 3 using box 1.
 

// Input:

// The first line of input takes the number of test cases T. Then T test cases follow .
// The next T lines take 2 space separated integers, the number of plates, N and the move no, n to be printed.
 

// Output:

// Print the n th move in the following format: i j which denotes  movement of  plate from i th box to j th box.
 

// Constraints:

// 1<=T<=100

// 1<=N<=1000

// 1<=n<=1000
 

// Example:

// Input:
// 3
// 2 2
// 3 4
// 4 5

// Output:
// 1 3
// 1 3
// 3 1
 

// Explanation:

// In the first test case, there are 2 plates. The plate on top of box 1 is first transferred to box 2. The second plate from box 1 is transferred to box 3 and finally the plate from box 2 is transferred to box 3. In each situation, all the constraints are satisfied. You are required to print the 2nd move which is "Move plate from box 1 to box 3", hence 1 3.

// The remaining test cases follow from the same logic.

#include <bits/stdc++.h>
using namespace std;
int ct=0;
void Hanoi(int n,int m,int src,int dest,int aux)
{
    if(n==1)
     {
         ct++;
         if(ct==m)
            cout<<src<<" "<<dest<<endl;
            return;
     }
    Hanoi(n-1,m,src,aux,dest);
       ct++;
       if(ct==m)
       {
           cout<<src<<" "<<dest<<endl;
        return;
       }
    Hanoi(n-1,m,aux,dest,src);
}
int main() {
	//code
	int t;cin>>t;
	while(t--){
	    ct=0;
	    int n;cin>>n;int m;cin>>m;
	    Hanoi(n,m,1,3,2);
	    
	}
}