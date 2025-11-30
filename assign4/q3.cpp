#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    string s = "aabc";
    queue<char> q;
    map<char, int> count;

    for (char ch : s) {
        count[ch]++;
        q.push(ch);

        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

    
        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    return 0;
}
