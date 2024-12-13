#define _POSIX_C_SOURCE 199309L  // POSIX 기능 활성화

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signo) {
    psignal(signo, "Received Signal:");
}

int main() {
    sigset_t set, oldset;

    signal(SIGALRM, sig_handler);  // 시그널 핸들러 등록

    sigfillset(&set);
    sigdelset(&set, SIGALRM);      // SIGALRM만 집합에서 제거

    alarm(3);                      // 3초 후 SIGALRM 발생

    printf("Wait...\n");

    // 현재 시그널 마스크를 oldset에 저장
    sigprocmask(SIG_SETMASK, &set, &oldset);  

    // SIGALRM 시그널을 대기
    sigsuspend(&set);

    // 시그널 마스크 복원
    sigprocmask(SIG_SETMASK, &oldset, NULL);  

    return 0;
}
