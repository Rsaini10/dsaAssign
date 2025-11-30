// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// void interleaveQueue(queue<int>& q) {
//     if (q.size() % 2 != 0) {
//         cout << "Queue must have even number of elements\n";
//         return;
//     }

//     stack<int> s;
//     int halfSize = q.size() / 2;

//     // Step 1: Push first half into stack
//     for (int i = 0; i < halfSize; i++) {
//         s.push(q.front());
//         q.pop();
//     }

//     // Step 2: Enqueue back stack elements
//     while (!s.empty()) {
//         q.push(s.top());
//         s.pop();
//     }

//     // Step 3: Move first half to the back of the queue
//     for (int i = 0; i < halfSize; i++) {
//         q.push(q.front());
//         q.pop();
//     }

//     // Step 4: Push first half into stack again
//     for (int i = 0; i < halfSize; i++) {
//         s.push(q.front());
//         q.pop();
//     }

//     // Step 5: Interleave stack and queue
//     while (!s.empty()) {
//         q.push(s.top());
//         s.pop();
//         q.push(q.front());
//         q.pop();
//     }
// }

// int main() {
//     queue<int> q;
//     for (int i = 1; i <= 6; i++) {
//         q.push(i);
//     }

//     interleaveQueue(q);

//     cout << "Interleaved Queue: ";
//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;

//     return 0;
// }
