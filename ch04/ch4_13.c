#include<stdlib.h>
#include<stdio.h>

int main(){
    FILE *rfp;
    char buf[BUFSIZ];
    int n;

    rfp = fopen("linux.txt", "r");
    if(rfp == NULL){
        perror("fopen: linux.txt");
        exit(1);
    }

    while ((n=fread(buf, sizeof(char)*2, 4, rfp)) > 0){
        buf[8] = '\0';
        printf("n=%d, buf=%s\n", n ,buf);
    }

    fclose(rfp);
    return 0;
    
}