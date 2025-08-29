#include <bits/stdc++.h>
using namespace std;

struct Process {
    int PID;
    int arrival;
    int service;
};

int main() {
    int n;
    cin >> n;
    vector<Process> processes(n);
    // รับค่า
    for (int i = 0; i < n; i++) {
        cin >> processes[i].PID >> processes[i].arrival >> processes[i].service;
    }
    // เรียงตาม arrival time
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (processes[j].arrival > processes[j+1].arrival) {
                swap(processes[j], processes[j+1]);
            }
        }
    }
    queue<Process> q;
    int time = 0;
    int idx = 0;
    
    while (!q.empty() || idx < n) { //ถ้าคิวยังไม่หมดหรือจำนวน process ยังไม่ครบ
        if (idx < n && processes[idx].arrival <= time) { //เช็คว่า process ครบ และ ถึงเวลาหรือยัง
            q.push(processes[idx]); //ถ้าถึงก็เพิ่มเข้าคิว
            idx++; //เพิ่มจำนวน process
        }
        if (!q.empty()) { //ถ้าคิวไม่ว่างก็มา execute
            Process p = q.front(); //ดึงตัวแรก
            q.pop(); //เอาออกจากคิว
            cout << p.PID << " : " << p.service << endl; //แสดงผล
            p.service -= 1; //ลด service time
            time += 1; //เพิ่ม time

            if (p.service > 0) { //ถ้ายังไม่เสร็จ (service time > 0)
                while (idx < n && processes[idx].arrival == time) {//ถ้าarrive timeคิวใหม่ตรงให้เข้ามาก่อน
                    q.push(processes[idx]);
                    idx++;
                }
                q.push(p); //ส่งกลับคิว
            }
        } else {
            time++; //เลื่อนไปเรื่อยๆ
        }
    }

    return 0;
}
