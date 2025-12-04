#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    bool isEmpty() {
        return heap.empty();
    }

    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    
    pq.insert(10);
    pq.insert(40);
    pq.insert(25);
    pq.insert(100);
    pq.insert(60);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Maximum element: " << pq.getMax() << endl;
    cout << "Extracted max: " << pq.extractMax() << endl;

    cout << "Priority Queue after deletion: ";
    pq.display();

    return 0;
}
