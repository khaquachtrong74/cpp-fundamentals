#include<stack>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<char> st;
    string input;
    getline(cin, input);
    for(const char &c : input){
        if(c == '[' || c == '(' || c == '{')
            st.push(c);
        else if(c == ']' || c == ')' || c == '}'){
            if(st.empty()) {
                cout<<"NO\n";
                return 0;
            }
            if( (c == ']' && st.top() == '[') || 
                (c == ')' && st.top() == '(')||
                (c == '}' && st.top() == '{'))
            {
                st.pop();
            }else{
                cout<<"NO\n";
                return 0;
            }
        }
    }
    printf((st.size()==0)?"YES\n":"NO\n");
    return 0;
}
