// https://www.hackerrank.com/contests/sda-hw-5-2023/challenges/bridge-battle-1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        bool hasLost = false;
        
        while(!st.empty() && st.top() > 0 && v[i] < 0)
        {
            if(st.top() < abs(v[i]))
            {
                st.pop();
            }
            
            else if(st.top() == abs(v[i]))
            {
                st.pop();
                hasLost = true;
                break;
            }
            
            else
            {
                hasLost = true;
                break;
            }
        }
        
        if(!hasLost)
        {
            st.push(v[i]);
        }
    }
    
    vector<int> res(st.size());
    for(int i = st.size() - 1; i >= 0; i--)
    {
        res[i] = st.top();
        st.pop();
    }
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}
