       #include <sys/types.h>
       #include <sys/statfs.h>
       #include <sys/stat.h>
       #include <time.h>  //ctime function
       #include <stdio.h>
       #include <stdlib.h>

       int
       main(int argc, char *argv[])
       {
           struct statfs sb;

           if (argc != 2) {
               //fprintf write to the specified fd output stream
               fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           if (statfs(argv[1], &sb) == -1) {
               perror("stat");
               exit(EXIT_FAILURE);
           }

           printf("fs_type:            %ld\n", sb.f_type);
           printf("f_bsize:                     %ld \n",sb.f_bsize);
           printf("total data blocks:               %ld\n", sb.f_blocks);
           printf("free blocks:                %ld\n",sb.f_bfree);
           printf("f_bavail: %ld bytes\n",sb.f_bavail);
           printf("total file inodes:                %ld\n",sb.f_files);
           printf("file inodes in fs:                %ld\n",sb.f_ffree);
           printf("maximum length of filenames %ld\n",sb.f_namelen);
           printf("fragment size (since Linux 2.6) %ld\n",sb.f_frsize);

           exit(EXIT_SUCCESS);
       }
