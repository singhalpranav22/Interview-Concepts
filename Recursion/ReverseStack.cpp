// Reverse stack with recursion similar to sort

#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s,int el)
{
    if(s.size()==0)
      s.push(el);
    else
    {
      int temp=s.top();
      s.pop();
      insert(s,el);
      s.push(temp);
    }
}
void reverse(stack<int> &s)
{
    if(s.size()==1)
     return;
    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s,temp); 
}
int main()
{
    int n;
    cin>>n;
    stack <int> s;
   
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        s.push(x);
    }
    
    reverse(s);
   
    // for(int i=1;i<n;i++)
    // {
    //  int x=s.top();
    // cout<<x<<" ";
    // s.pop();
    // }
    cout<<endl;

}