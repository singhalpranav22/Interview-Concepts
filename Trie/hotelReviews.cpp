Problem Description

Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

You are expected to use Trie in an Interview for such problems



Problem Constraints
1 <= No.of reviews <= 200
1 <= No. of words in a review <= 1000
1 <= Length of an individual review <= 10,000
1 <= Number of Good Words <= 10,000
1 <= Length of an individual Good Word <= 4
All the alphabets are lower case (a - z)


Input Format
First argument is a string A containing "Good Words" separated by "_" character

Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.



Output Format
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.



Example Input
Input 1:

 A = "cool_ice_wifi"
 B = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]


Example Output
Output 1:

 [2, 0, 1]


Example Explanation
Explanation 1:

 sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]


struct Trie{
    bool b=false; 
    Trie *pt[26]={NULL};
};
bool comp(pair<int,int> &x,pair<int,int> &y){
    if(x.first!=y.first) return x.first>y.first;
    else{
        return x.second<y.second;
    }
}
vector<int> Solution::solve(string w, vector<string> &v) {
    Trie *root=new Trie();
     Trie* t=root;
    for(auto x : w){
        // cout<<x<<" "<<endl;
        if(x=='_'){
            t->b=true;
            t=root;continue;
        }
        if(t->pt[x-'a']==NULL){
                t->pt[x-'a']=new Trie();
            }
            t=t->pt[x-'a'];
        }
        t->b=true;
    vector<pair<int,int> > res;
    int it=0;
    for(auto s : v){
        int ct=0;
        t=root;
        for(auto x : s){
            if(x=='_'){
                if(t==NULL || t->b==false){ t=root;continue;}
                if(t->b==true){ ct++;}
                t=root; continue;
            }
            if(t==NULL) { continue;}
            t=t->pt[x-'a'];
        }
        if(t!=NULL) {
            if(t->b==true)ct++;}

        res.push_back({ct,it});
        it++;
    }
    sort(res.begin(),res.end(),comp);
    vector<int> ans;
    for(auto x : res) ans.push_back(x.second);
    return ans;
}
