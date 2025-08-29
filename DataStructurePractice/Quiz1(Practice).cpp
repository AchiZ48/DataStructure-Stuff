#include<bits/stdc++.h>
using namespace std;

struct process{
    int PID;
    int arrival;
    int service;
};

int main(){
    int n;
    cin>>n;
    vector<process> processes(n);
    for(int i = 0; i<n; i++){
        cin>>processes[i].PID>>processes[i].arrival>>processes[i].service;
    }
    //sort
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1-i;j++){
            if(processes[j].arrival > processes[j+1].arrival){
                swap(processes[j], processes[j+1]);
            }
        }
    }
    queue<process> q;
    int time = 0;
    int idx = 0;
    while(!q.empty() || idx < n){
        if(idx < n && processes[idx].arrival <= time){
            q.push(processes[idx]);
            idx++;
        }

        if(!q.empty()){
            process p = q.front();
            q.pop();
            cout<<p.PID<<" : "<<p.service<<endl;
            p.service--;
            time++;
            if(p.service > 0){
                while(idx < n && processes[idx].arrival == time){
                    q.push(processes[idx]);
                    idx++;
                }
                q.push(p);
            } 
        }
        else time++;
    }
    return 0;
}