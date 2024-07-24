#include<bits/stdc++.h>
using namespace std;
void placeBottom(stack<int>&st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int t = st.top();
    st.pop();
    placeBottom(st,x);
    st.push(t);
}
void solve(stack<int>&st){
    if(st.empty())return;
    int t = st.top();
    st.pop();
    solve(st);
    placeBottom(st,t);

}
int main(){
    stack<int>st;
    for(int i=1; i <= 10; i++){
        st.push(i);
    }
    solve(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}