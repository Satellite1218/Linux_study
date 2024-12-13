#include<stdlib.h>
#include<stdio.h>

int main(){
    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int n;

    rfp = fopen("linux.txt", "r");
    if(rfp == NULL){
        perror("fopen: linux.txt");
        exit(1);
    }

    wfp = fopen("linux.txt", "a");
    if(wfp == NULL){
        perror("fopen: linux.out");
        exit(1);
    }

    while ((n=fread(buf, sizeof(char)*2, 4, rfp)) > 0){
        fwrite(buf, sizeof(char)*2, n, wfp);
    }

    fclose(rfp);
    fclose(wfp);
    return 0;
    
}