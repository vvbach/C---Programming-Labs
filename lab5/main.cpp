#include "lab5.h"

using namespace std;

void findMinTask(){
    int a, b; cin >> a >> b;
    cout << findMin(a, b) << endl;

    double c, d; cin >> c >> d;
    cout << findMin(c, d) << endl;

    string e, f; cin >> e >> f;
    cout << findMin(e, f) << endl;
}

void QueueTask(){
    Queue<1, int> q1;
    Queue<3, double> q2;
    double data;
    q1.Enqueue(3);
    q1.Enqueue(4);
    q2.Dequeue(data);
}

int main(){
    findMinTask();
    QueueTask();
}