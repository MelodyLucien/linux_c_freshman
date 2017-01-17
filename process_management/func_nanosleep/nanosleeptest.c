/**nanosleep() suspends the execution of the calling thread until either at least the time specified in *req has elapsed, or the delivery of a signal that triggers
       the invocation of a handler in the calling thread or that terminates the process.

       If the call is interrupted by a signal handler, nanosleep() returns -1, sets errno to EINTR, and writes the remaining time into the structure pointed to by  rem
       unless rem is NULL.  The value of *rem can then be used to call nanosleep() again and complete the specified pause (but see NOTES).

       The structure timespec is used to specify intervals of time with nanosecond precision.  It is defined as follows:

           struct timespec {
               time_t tv_sec;
               long   tv_nsec;
           };

       The value of the nanoseconds field must be in the range 0 to 999999999.

       Compared to sleep(3) and usleep(3), nanosleep() has the following advantages: it provides a higher resolution for specifying the sleep interval; POSIX.1 explic‐
       itly specifies that it does not interact with signals; and it makes the task of resuming a sleep that has been interrupted by a signal handler easier.

**/

#include<time.h>
#include<stdio.h>
int main(){
    struct timespec s;
    struct timespec rem;
    s.tv_sec=12;
    s.tv_nsec=33333;

    printf("start sleep!\n");
    nanosleep(&s,&rem);

    printf("i am done!!\n");
    printf("remaining time is %d\n",rem.tv_sec);
   return 0;
}
