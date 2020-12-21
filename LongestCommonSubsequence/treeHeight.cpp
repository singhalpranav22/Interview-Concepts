#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int el)
{
    if(v.size()==0 || v[v.size()-1]<=el)
    {
         v.push_back(el);
         return;
    }
    else
    {
        int temp=v[v.size()-1];
        v.pop_back();
        insert(v,el);
        v.push_back(temp);
        return;
    }
}
void sort(vector<int> &v)
{
  if(v.size()==1)
   return;
  int temp=v[v.size()-1];
  v.pop_back();
  sort(v);
  insert(v,temp);
}
int main()
{
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];
     sort(v);
    for(int i=0;i<n;i++)
     cout<<v[i]<<" ";
     cout<<endl;

}