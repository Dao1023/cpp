#include <iostream>
#include <queue>

using namespace std;

int main() {
    // for (int i = 1; i < 10; i++) {
    //     cout << i << endl;
    // }

    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;

    myQueue.pop();
    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;
}