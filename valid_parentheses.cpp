#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
  stack<char> st;
  int i = 0;
iterate:
  if (i <= s.length() - 1) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
      i++;
      goto iterate;
    } else {
      if (st.empty() or (s[i] == ')' && st.top() != '(') or
          (s[i] == '}' && st.top() != '{') or
          (s[i] == ']' && st.top() != '[')) {
        return false;
      } else {
        st.pop();
        i++;
        goto iterate;
      }
    }
  }
  return st.empty();
}
int main(void) {
  string s = "({[()]}";
  cout << isValid(s) << endl;
  return 0;
}
