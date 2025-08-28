#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Process {
    string pid;
    int arrival;
    int service;
};

int main() {
    int n;
    cin >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].service;
    }

    stack<Process> lifoStack;
    int time = 0, i = 0;
    bool running = false;
    Process current;

    while (i < n || running || !lifoStack.empty()) {
        // Push process if it arrives at this time
        if (i < n && processes[i].arrival == time) {
            lifoStack.push(processes[i]);
            i++;
        }

        // Start next process if nothing is running
        if (!running && !lifoStack.empty()) {
            current = lifoStack.top();
            lifoStack.pop();
            running = true;
        }

        // Run current process
        if (running) {
            cout << current.pid << " : " << current.service << endl;
            current.service--;
            if (current.service == 0) {
                running = false;
            }
        }

        time++;
    }

    return 0;
}
