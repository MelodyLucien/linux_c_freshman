//
// IPC--共享内存(读数据)
// Created by 卢鹏 on 2017/8/31.
//
 
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUFFSIZE 1024
 
int main(int args, char *argv[]) {
    int shmid;
    int ret;
    key_t key;
    char *shmadd;
 
    // 创建key值
    if ((key = ftok("./", 2015)) == -1) {
        perror("ftok error.");
    }
 
    // 查看系统共享内存
    printf("start-ipcs------------------------------------------\n");
    system("ipcs -m");
    printf("end-ipcs--------------------------------------------\n");
 
    // 打开共享内存
    if ((shmid = shmget(key, BUFFSIZE, IPC_CREAT|0666)) < 0) {
        perror("shmget error.");
        exit(-1);
    }
    printf("Open shared-memory success, with shmid: %d\n", shmid);
 
    // 映射
    if ((shmadd = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat error.");
        exit(-1);
    }
 
    // 读取共享内存中的数据
    printf("read data from shared-memory\n");
    printf("%s\n", shmadd);
 
    // 分离共享内存和当前进程
    if ((ret = shmdt(shmadd)) < 0) {
        perror("shmdt error.");
        exit(1);
    } else {
        printf("Delete shared-memory\n");
    }
 
    // 删除共享内存
    shmctl(shmid, IPC_RMID, NULL);
 
    // 查看系统共享内存
    printf("start-ipcs------------------------------------------\n");
    system("ipcs -m");
    printf("end-ipcs--------------------------------------------\n");
 
    return 0;
}