#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
int main(){
    printf("%d about to create 2 child processes\n", getpid());
    int st, et;
    st = time(NULL);
    int timeW;
    pid_t p1;
    p1 = fork();
    if (p1 < 0){ //fork failed
        perror("fork fail\n");
        exit(1);
    }else if (p1 == 0){ //child one code
        srand(getpid());
        timeW = rand() % (5 - 1 + 1) + 1;
        printf("%d %dsec\n", getpid(), timeW);
        sleep(timeW);
        printf("%d finished after %dsec\n", getpid(), timeW);
    }else{ //create child two on parent
        p1 = fork();
        if (p1 < 0){ //fork failed
            perror("fork fail\n");
            exit(1);
        }else if (p1 == 0){ //child two code
            srand(getpid());
            timeW = rand() % (5 - 1 + 1) + 1;
            printf("%d %dsec\n", getpid(), timeW);
            sleep(timeW);
            printf("%d finished after %dsec\n", getpid(), timeW);
        }else{
            //parent
            int status;
            pid_t p = wait(&status);
            et = time(NULL);
            printf("Main Process %d is done. Child %d slept for %dsec\n", getpid(), p, et - st);
        }
    }
    return 0;
}
