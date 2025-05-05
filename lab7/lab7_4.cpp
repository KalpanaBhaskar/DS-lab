#include <iostream>
#include <stack>
using namespace std;

void processString(const string &s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '+') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(ch);
        }
    }

    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    cout << result << endl;
}

int main() {
    string input;
    cin >> input;
    processString(input);
    return 0;
}
