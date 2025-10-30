#include <iostream>
#include <vector>


using namespace std;

template<typename T>
class MaxHeap {
private:
    vector<T> heap;

    bool compare(const T &a, const T &b) {
        if constexpr (is_same_v<T, pair<int, int>>) {
            return a.second > b.second;
        } else {
            return a > b;
        }
    }

    int getParent(int i) {
        return (i - 1) / 2;
    }

    int getLeft(int i) {
        return 2 * i + 1;
    }

    int getRight(int i) {
        return 2 * i + 2;
    }

    void heapifyUp(int i) {
        while (i > 0 && compare(heap[i], heap[getParent(i)])) {
            swap(heap[i], heap[getParent(i)]);
            i = getParent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = getLeft(i);
        int right = getRight(i);

        if (left < heap.size() && compare(heap[left], heap[largest])) {
            largest = left;
        }
        if (right < heap.size() && compare(heap[right], heap[largest])) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {}

    void insert(T value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }

    T removeMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty!");
        }
        T maxx = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxx;
    }

    int getSize() {
        return heap.size();
    }

    void display() {
        for (auto &x: heap) {
            if constexpr (is_same_v<T, pair<int, int>>)
                cout << "[Value: " << x.first << ", Priority: " << x.second << "] ";
            else
                cout << x << " ";
        }
        cout << endl;
    }

    bool empty() const {
        return heap.empty();
    }

    vector<T> getHeap() const {
        return heap;
    }
};

class PriorityQueue {
private:
    MaxHeap<pair<int, int>> heap;

public:
    void insert(int value, int priority) {
        heap.insert({value, priority});
    }

    int extractHighestPriorityValue() {
        if (heap.empty()) {
            throw runtime_error("Priority Queue is empty!");
        }
        auto maxx = heap.removeMax();
        return maxx.first;
    }

    void display() {
        heap.display();
    }

    int getValueOfPriority(int priority) {
        for (auto &p: heap.getHeap()) {
            if (p.second == priority) {
                return p.first;
            }
        }
        throw runtime_error("Priority not found!");
    }
};

void heapSort(vector<int> &(newData)) {
    MaxHeap<int> heap;
    for (int val: newData) {
        heap.insert(val);
    }
    for (int i = newData.size() - 1; i >= 0; i--) {
        newData[i] = heap.removeMax();
    }
}

int main() {

//    cout << " 1. Enter data\n 2. Use initialized data" << endl;
    int choice =0;
//    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "Choose a valid choice (1-2):\n 1. Enter data\n 2. Use initialized data" << endl;
        cin >> choice;
    }
    MaxHeap<int> h;
    PriorityQueue pq;
    switch (choice) {
        case 1: {
            cout << "=== Normal Max Heap ===\n";
            int n;
            cout << "Enter number of elements for the heap: ";
            cin >> n;
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                h.insert(x);
            }
            cout << "Heap elements: ";
            h.display();

            cout << "Extracted Max: " << h.removeMax() << endl;
            cout << "Heap after extraction: ";
            h.display();

            // -------------------- PRIORITY QUEUE --------------------
            cout << "\n=== Priority Queue ===\n";
            int m;
            cout << "Enter number of (value, priority) pairs: ";
            cin >> m;
            for (int i = 0; i < m; i++) {
                int val, pr;
                cout << "Enter value and priority: ";
                cin >> val >> pr;
                pq.insert(val, pr);
            }

            cout << "Priority Queue content:\n";
            pq.display();

            cout << "Extracted Highest Priority Value: " << pq.extractHighestPriorityValue() << endl;
            cout << "Queue after extraction:\n";
            pq.display();

            cout << "Enter a priority to get its value: ";
            int pr;
            cin >> pr;
            try {
                cout << "Value with priority " << pr << " = " << pq.getValueOfPriority(pr) << endl;
            } catch (exception &e) {
                cout << e.what() << endl;
            }

            // -------------------- HEAP SORT --------------------
            cout << "\n=== Heap Sort ===\n";
            int s;
            cout << "Enter size of array: ";
            cin >> s;
            vector<int> arr(s);
            cout << "Enter " << s << " elements:\n";
            for (int i = 0; i < s; i++) cin >> arr[i];

            heapSort(arr);

            cout << "Sorted array (descending): ";
            for (int x: arr) cout << x << " ";
            cout << endl;
            break;
        }
        case 2: {
            cout << "=== Normal Heap ===\n";
            h.insert(10);
            h.insert(30);
            h.insert(20);
            h.display();
            cout << "Extract Max: " << h.removeMax() << endl;

            cout << "\n=== Priority Queue (using Heap) ===\n";
            pq.insert(100, 2);
            pq.insert(200, 5);
            pq.insert(300, 1);
            pq.display();

            cout << "Extract Highest Priority Value: " << pq.extractHighestPriorityValue() << endl;
            pq.display();

            cout << "Value of priority 2: " << pq.getValueOfPriority(2) << endl;

            cout << "\n=== Heap Sort ===\n";
            vector<int> arr1 = {4, 10, 3, 5, 1};
            heapSort(arr1);
            for (int x: arr1) cout << x << " ";
            cout << endl;
        }
    }


}

