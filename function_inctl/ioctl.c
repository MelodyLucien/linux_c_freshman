/// @file main.cpp
/// @brief
/// @author EastonWoo
/// 0.01
/// @date 2012-12-19

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <sys/ioctl.h> //ioctl

#include <sys/mount.h>  //BLKSSZGET  //BLKGETSIZE
#include <linux/fd.h>  //struct floppy_struct //FDGETPRM
#include <linux/hdreg.h> //struct hd_geometry //HDIO_GETGEO


int main(int argc, const char *argv[])
{
	printf("hello  world\n");
    int dev = 0;
    if((dev = open("/dev/sda", O_EXCL | O_RDWR)) == 0)
        // if((dev = open("/dev/sdc", O_EXCL | O_RDWR)) == 0)
    {
        printf("open error!\n");
        return -1;
    }

    int min_sector_size = 0;
    if (ioctl(dev, BLKSSZGET, &min_sector_size) >= 0)
        printf("successful : min_sector_size = %d\n",min_sector_size);

    long loop_size = 0;
    if(ioctl(dev, BLKGETSIZE, &loop_size) >= 0)
        printf("successful : loop_size = %ld\n",loop_size);


    //#define BLKRRPART  _IO(0x12, 95) /* Re-read partition table.  */
    int retVal = 0;
    if(ioctl(dev,BLKRRPART,&retVal) >= 0) //重读分区表
    printf("successful : retVal = %d\n",retVal);

    struct floppy_struct param;
    memset(&param,0,sizeof(param));
    if(ioctl(dev, FDGETPRM, &param) >= 0)
        printf("\tsize = %u\n\
                \tsect = %u\n", \
                param.size, \
                param.sect \
              );

    struct hd_geometry geometry;
    if(ioctl(dev, HDIO_GETGEO, &geometry) >=0)
        printf("\theads = %u\n \
                \tsectors = %u\n \
                \tcylinders = %u\n \
                \tstart = %lu\n", \
                geometry.heads, \
                geometry.sectors, \
                geometry.cylinders, \
                geometry.start \
              );


    if(dev != 0)
    {
        close(dev);
    }

    printf("over!\n");
    return 0;
}
