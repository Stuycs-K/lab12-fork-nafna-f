#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
int main(){
    printf("%d about to create 2 child processes.\n", getpid());
    int timeW;
    pid_t p1;
    p1 = fork();
    if (p1 < 0){ //fork failed
        perror("fork fail\n");
        exit(1);
    }else if (p1 == 0){ //child one
        srand(getpid());
        timeW = rand() % (5 - 1 + 1) + 1;
        printf("%d %dsec\n", getpid(), timeW);
    }else{ //create child two on parent
        p1 = fork();
        if (p1 < 0){ //fork failed
            perror("fork fail\n");
            exit(1);
        }else if (p1 == 0){ //child two
            srand(getpid());
            timeW = rand() % (5 - 1 + 1) + 1;
            printf("%d %dsec\n", getpid(), timeW);
        }else{
            //parent
            printf("parent speaking\n");
        }
    }
    return 0;
}
