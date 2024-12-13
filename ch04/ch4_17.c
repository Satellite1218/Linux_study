#include<stdlib.h>
#include<stdio.h>

int main(){
    FILE *fp;
    int n;
    long cur;
    char buf[BUFSIZ];

    fp = fopen("linux.txt", "r");
    if(fp == NULL){
        perror("fopen: linux.txt");
        exit(1);
    }

    cur = ftell(fp);
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 5, fp);
    buf[n]='\0';
    printf("--Read Str=%s\n", buf);

    fclose(fp);
    return 0;
}