//
// IPC--共享内存(写数据)
// Created by 卢鹏 on 2017/8/31.
//
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
 
// 共享内存大小
#define BUFFSIZE 1024
 
int main(int argc, char *argv[]) {
    // 共享内存的shmid
    int shmid;
    // 共享内存的key
    key_t key;
    char *shmadd;
    char *msg;
 
    // 创建共享内存的key
    if ((key = ftok("./", 2015)) == -1) {
        perror("ftok error");
    }
 
    // 创建共享内存
    if ((shmid = shmget(key, BUFFSIZE, IPC_CREAT|0666)) < 0) {
        perror("shmget error.");
        exit(-1);
    }
    printf("Create shared-memory success, with shmid: %d\n", shmid);
 
    // 映射
    if ((shmadd = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat error.");
        exit(-1);
    }
 
    // 拷贝共享数据到共享内存
    printf("copy data to shared-memory\n");
    bzero(shmadd, BUFFSIZE);
    msg = "hello, yj.";
    strcpy(shmadd, msg);
    printf("copy data to shared-memory success, with msg: %s\n", msg);
}