// Problem Description

// You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

// Your target is to go from top left corner to the bottom right corner of the matrix.

// But there are some restrictions while moving along the matrix:

// If you follow what is written in the cell then you can move freely.
// But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
// Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

// So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



// Problem Constraints
// 1 <= A,B <= 103
// C[i][j] can be either U,R,L or D.


// Input Format
// First Argument represents a integer A (number of rows).
// Second Argument represents a integer B (number of columns).
// Third Argument represents a string array C which contains A strings each of length B.


// Output Format
// Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



// Example Input
// Input:1

//  A = 3
//  B = 3
//  C = ["RRR","DDD","UUU"]
// Input:2

//  A = 1
//  B = 4
//  C = ["LLLL"]


// Example Output
// Output-1 :

//  1
// Output-2 :

//  3


// Example Explanation*
// Explanation for Input-1:

//  Matrix looks like: RRR
//                     DDD
//                     UUU
//  We go right two times and down two times.
//  So from top-right cell we are going down though right is given so this incurs a cost of 1.
// Explanation for Input-2:

//  Matrix looks like: LLLL
//  We go right three times.

Refer to this blog published on Codeforces for understanding this algorithm : https://codeforces.com/blog/entry/22276

// Created By : Pranav Singhal
// IIIT-Allahabad

// Using 0-1 BFS

char pos[4]={'R','D','L','U'};   // Positions that can be visited
int dx[4]={0,1,0,-1};   // where to go in x direction for ith position
int dy[4]={1,0,-1,0};   // where to go in y direction for ith position
bool check(int i,int j,int A,int B){
    return (i>=0 && j>=0 && i<A && j<B);
}
int Solution::solve(int A, int B, vector<string> &C) {
    int dis[A+1][B+1];  // to store the distances of node (i,j) from (0,0)
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            dis[i][j]=INT_MAX;   // initially every node is at infinite distance from (0,0)
        }
    }
    deque <pair<int,int> > q; // for 0-1 BFS
    q.push_front({0,0});
    dis[0][0]=0;  // initialisation
    while(!q.empty()){ // BFS starts here
        int i=q.front().first,j=q.front().second;
        q.pop_front();
        for(int k=0;k<4;k++){
            int x = dx[k]+i,y=dy[k]+j;
            if(check(x,y,A,B)){
                int d; // for storing whether the node x,y can be visited with 0 cost or 1 cost
                if(C[i][j]==pos[k]) d=0;
                else d=1;
                if(dis[x][y]>dis[i][j]+d){ // if x,y could be relaxed
                    dis[x][y]=dis[i][j]+d;
                    if(d==0) q.push_front({x,y});  // if at same level
                    else q.push_back({x,y});  // if one level ahead
                }
            }
        }
    }
    return dis[A-1][B-1];
}
