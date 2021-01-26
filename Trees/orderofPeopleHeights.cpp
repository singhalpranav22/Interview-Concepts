// Order of People Heights
// Asked in:  
// Google
// You are given the following :

// A positive number N
// Heights : A list of heights of N persons standing in a queue
// Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
// You need to return list of actual order of persons’s height

// Consider that heights will be unique

// Example

// Input : 
// Heights: 5 3 2 6 1 4
// InFronts: 0 1 2 0 3 2
// Output : 
// actual order is: 5 3 2 1 6 4 
// So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

// For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

// You can do similar inference for other people in the list.

// O(n^2) approach

// O(N^2) approach

// Sort people by heights. Then iterate from shortest to tallest. In each step you need an efficient way to put the next person to the correct position. Notice that people we’ve already placed are not taller that the current person. And the people we place after are taller than the current. So we have to find a place such that the number of empty positions in the front is equal to the inFronts value of this person.

// Lets take an example :

// For example after sorting,

// Height - 1, 2, 3, 4, 5, 6
// Infront - 3, 2, 1, 2, 0, 0.
// 1st element should go in position 3. Hence final array becomes:

// ---1--
// 2nd element shall go in position 2. Hence final array becomes:

// --21--
// 3rd element should go in position 1. Hence final array becomes:

// -321--
// 4th element shall go in position 2. This is the position among the empty ones. Hence final array becomes:

// -321-4
// 5th element shall go in position 0. Hence final array becomes:

// 5321-4
// 6th element should go in position 0. Hence final array becomes:

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int,int> >v;
     int n=A.size();
     for(int i=0;i<n;i++)
     {
         v.push_back(make_pair(A[i],B[i]));
     }
     sort(v.begin(),v.end());
     vector<int> ans(n,-1);
     for(auto x : v)
     {
         int i=0;
         int curr=0;
         for(int j=0;j<n;j++)
         {
             if(curr==x.second)
             {
                for(int k=j;k<n;k++)
                {
                    if(ans[k]==-1)
                      {
                          i=k;
                          break;
                      }
                }
                break;
             }
             if(ans[j]==-1)
              {
                  curr++;
              }
         }
         ans[i]=x.first;
     }
     return ans;
}

// 532164
// Hint towards an even better solution

// Can we make the process of finding the ith empty position even more efficient ? Think binary tree / segment tree ?
// Oh, by the way, this would be a nice time to read up on Segment Trees which are incredibly useful ( http://codeforces.com/blog/entry/3327 )
// What if you knew how many elements are there in first half of the array, and the second half of the array ?

