#include <sys/time.h>
#include <sys/resource.h>

/**
The scheduling priority of the process, process group, or user, as indicated by which and who is obtained with the getpriority() call and set with the setprior‐
ity() call.

The value which is one of PRIO_PROCESS, PRIO_PGRP, or PRIO_USER, and who is interpreted relative to which (a process identifier for PRIO_PROCESS, process  group
identifier  for  PRIO_PGRP,  and  a  user  ID for PRIO_USER).  A zero value for who denotes (respectively) the calling process, the process group of the calling
process, or the real user ID of the calling process.  Prio is a value in the range -20 to 19 (but see the Notes below).  The default priority is 0; lower prior‐
ities cause more favorable scheduling.

The getpriority() call returns the highest priority (lowest numerical value) enjoyed by any of the specified processes.  The setpriority() call sets the priori‐
ties of all of the specified processes to the specified value.  Only the superuser may lower priorities.

**/

int main(){
  int priority=getpriority(PRIO_PROCESS,0);
  printf("my priority is %d\n",priority);
  return 0;
}
