//stack using two queue;
// class MyStack {
//     queue<int>q1,q2;
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         while(!q1.empty()){
//             int val=q1.front();
//             q1.pop();
//             q2.push(val);
//         }
//         q1.push(x);
//         while(!q2.empty()){
//             int val=q2.front();
//             q2.pop();
//             q1.push(val);
//         }

        
//     }
    
//     int pop() {
//         int val=q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
        
//     }
    
//     bool empty() {
        
//         return q1.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//  one queue
// class MyStack {
//     queue<int> q;
// public:
//     MyStack() {
//     }

//     void push(int x) {
//         q.push(x);
//         int sz = q.size();
//         // rotate all elements behind the new element
//         for (int i = 0; i < sz - 1; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         int topElem = q.front();
//         q.pop();
//         return topElem;
//     }

//     int top() {
//         return q.front();
//     }

//     bool empty() {
//         return q.empty();
//     }
// };
