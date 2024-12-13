#include<stdlib.h>
#include<stdio.h>

int main(){
    FILE *rfp, *wfp;
    int c;

    rfp = fopen("linux.txt", "r");
    if(rfp = NULL){
        perror("fopen linux.txt");
        exit(1);
    }

    wfp = fopen("linux.out", "w");
    if(wfp = NULL){
        perror("fopen linux.txt");
        exit(1);
    }

    while ((c=fgetc(rfp)) != EOF)
    {
        fputc(c, wfp);
    }
    

    fclose(rfp);
    fclose(wfp);
}