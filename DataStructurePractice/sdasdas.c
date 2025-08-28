#include<stdio.h>
#include<string.h>


int main(){
    int minute, second;
    scanf("%d.%d", &minute, &second);
    int n;
    scanf("%d", &n);
    char name[n][50];
    int dura[n];
    for(int i = 0 ; i<n; i++){
        getchar(); 
        int order,min,sec;
        char songname[50];
        scanf("Queue#%d <|> %[^<] <|> %d.%d", &order, songname, &min, &sec);
        strcpy(name[order - 1], songname);  
        sec += min*60;
        dura[order-1] = sec;
    }
    for(int i = 0; i<n; i++){
        int min = dura[i] / 60;
        int sec = dura[i] % 60;
        printf("Queue#%d <|> %s <|> %d.%d\n", i+1, name[i], min,sec);
    }
    int durafreqsum[n];
    durafreqsum[0] = dura[0];
    for(int i = 1; i<n;i++){
        durafreqsum[i] = dura[i]+durafreqsum[i-1];
    }
    printf("%d", durafreqsum[n-1]);
}
