// Credits - Prateek Mishra Sir (IIIT-Allahabad)
// Problem Description

// Given two equally sized 1-D arrays A, B containing N integers each.

// A sum combination is made by adding one element from array A and another element of array B.

// Return the maximum C valid sum combinations from all the possible sum combinations.



// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 103

// 1 <= C <= N



// Input Format
// First argument is an one-dimensional integer array A of size N.

// Second argument is an one-dimensional integer array B of size N.

// Third argument is an integer C.



// Output Format
// Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

// NOTE:

// The returned array must be sorted in non-increasing order.



// Example Input
// Input 1:

//  A = [3, 2]
//  B = [1, 4]
//  C = 2
// Input 2:

//  A = [1, 4, 2, 3]
//  B = [2, 5, 1, 6]
//  C = 4


// Example Output
// Output 1:

//  [7, 6]
// Output 1:

//  [10, 9, 9, 8]


// Example Explanation
// Explanation 1:

//  7     (A : 3) + (B : 4)
//  6     (A : 2) + (B : 4)
// Explanation 2:

//  10   (A : 4) + (B : 6)
//  9   (A : 4) + (B : 5)
//  9   (A : 3) + (B : 6)
//  8   (A : 3) + (B : 5)

// Code by Prateek Mishra IIT2018199, IIIT Allahabad.

//UNDERSTANDING THE APPROACH
/* We here use the concept of merging k - sorted linked lists.
Let the given vectors after sorting be
A : 16, 11, 7, 1
B : 15, 10, 9, 2

Now we know that 4 ^ 4 different sums are possible for this combination and we need to
find the largest C out of these. Let the pairs be:
(16,15), (16,10), (16,9), (16,2),
(11,15), (11,10), (11,9), (11,2),
(7,15), (7,10), (7,9), (7,2),
(1,15), (1,10), (1,9), (1,2),

Note that the numbers (pair of the sums) in every row are sorted in descending order. Now we
need to merge these sorted LinkedLists.
*/
// My soultion
#define mp make_pair
#define pb push_back
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
  priority_queue<pair<int,pair<int,int> > >  heap; // max heap to store the sum along with the indexes from which the sum came from
  sort(A.rbegin(),A.rend()); // sorting array A in descending order
  sort(B.rbegin(),B.rend()); // sorting array B in descending order
  map<pair<int,int>,bool > m; // map to be used as a vis array whether index (i,j)'s sum is already present int the heap or not
  heap.push(mp(A[0]+A[0],mp(0,0))); // Initially pushing the sum of the biggest elements from both the arrays (Ofcourse it would be the biggest sum combination for our solution)
  m[mp(0,0)]=true; // this represent that sum from (0,0) is already present in the heap
  vector<int> ans;
  while(ans.size()<C) // now find the top elements and keep pushing the (i+1,j) & (i,j+1)th sum cobinations in the heap (remeber that the top of the heap would only contain the maximum sum)
  {
      pair<int,pair<int,int> > temp = heap.top();
      heap.pop();
      int sum = temp.first;
      ans.pb(sum);
      int ind1 = temp.second.first;
      int ind2 = temp.second.second;
      if(m[mp(ind1+1,ind2)]!=true){
          heap.push(mp(A[ind1+1]+A[ind2],mp(ind1+1,ind2)));
          m[mp(ind1+1,ind2)] = true;
      }
      if(m[mp(ind1,ind2+1)]!=true){
          heap.push(mp(A[ind1]+A[ind2+1],mp(ind1,ind2+1)));
          m[mp(ind1,ind2+1)] = true;
      }
      
  }
  return ans;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend()); //sorting both the lists in descending order.
    priority_queue<pair<int, pair<int, int>>> maxh; //max heap for storing (sum, (i - index, j - index))

    for (int i = 0; i < C; i++) //pushing the heads of all the linked lists.
    {
        maxh.push(make_pair(B[0] + A[i], make_pair(0, i)));
    }

    std::vector<int> ans;
    while(ans.size() < C)
    {
        auto maxele = maxh.top(); maxh.pop(); 
        ans.emplace_back(maxele.first); //pushing the top to ans and inserting head -> next.
        maxh.push(make_pair(B[maxele.second.first + 1] + A[maxele.second.second], make_pair(maxele.second.first + 1, maxele.second.second)));
    }
    return ans;
}