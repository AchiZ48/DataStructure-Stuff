#include<iostream>
#include <cstdio>

using namespace std;


int main(){
    long int minute, sec;
    scanf("%ld.%d", &minute, &sec);
    int n;
    scanf("%d", &n);
    string name[n];
    int dura[n];
    for(int i = 0 ; i<n; i++){
        int order,min,sec;
        char songname[50];
        scanf("Queue#%d <|> %[^<] <|> %d.%d", &order, songname, &min, &sec);
        name[order-1] = songname;
        sec += min*60;
        dura[order-1] = sec;
    }
}
