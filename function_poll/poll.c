#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <poll.h>

#define MAX_BUFFER_SIZE  1024  //  the maximum of buffer size
#define IN_FILES   1    // the count of fds
#define TIME_DELAY   6000    //the time delay by millsecond


int main()
{
struct pollfd fds[1];
char buf[MAX_BUFFER_SIZE];
int i, res, real_read, maxfd;

// open two file with proper permissions
fds[0].fd =0; //open ("in1", O_RDONLY|O_NONBLOCK);

fds[0].events=POLLIN;

//if you don't add \n at the end of printf,it will not be printed on screen ,cause line buffer
printf("start while loop !!\n");
// wait for the event and do sthwhile(fds[0].events || fds[1].events ||
while(fds[0].events)
{
   printf("before poll from standered input !!\n");
   int k=-2;
   //if it is a nomoral file will return 0 ,but a fifo will block,such as fd 0,you can try
   if ((k=poll(fds, IN_FILES, TIME_DELAY)) <= 0)
   {
   printf("after poll error from standered input !!");
    printf("poll error,return value(0--timeout) is %d\n",k);
    return 1;
   }

   printf("after nomoral poll from standered input !!");

    if (fds[0].revents)
    {
     memset(buf, 0, MAX_BUFFER_SIZE);
     real_read = read(fds[0].fd, buf, MAX_BUFFER_SIZE);

     if (real_read < 0)
     {
      if (errno != EAGAIN)
      {
       //return 1;
       printf("the read will block,and fd index,is %d \n",i );
      }
     }
     else if (!real_read)
     {
       printf("read fail and return %d ,the fd %d is closed\n",real_read,i);
       fds[0].events = 0;
     close(fds[0].fd);
     }
     else
     {

       if ((buf[0] == 'q') || (buf[0] == 'Q'))
       {
       printf("read from fd 0 and the character is %c \n",buf[0]);
       exit(0);
        //return 1;
      }
      else
      {
       // make buff end with \0 ,so that we can output the string
       buf[real_read] = '\0';
       printf("read from fd %d and the content is %s\n",i, buf);
      }
     } /* end of if real_read*/
    } /* end of if revents */
} /*end of while */
return 0;
}
