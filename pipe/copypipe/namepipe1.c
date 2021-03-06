#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char* argv)
{
	int outfd;
	outfd = open("abcd",O_WRONLY | O_CREAT | O_TRUNC,0644);
	if( outfd == -1){
		perror("open");
		exit(1);
	}
	
	int infd;
	infd = open("tp",O_RDONLY);
	if( infd == -1){
		perror("open");
		exit(1);
	}

	char buf[1024];
	int n;
	while((n = read(infd, buf, 1024)) > 0){
		write(outfd, buf, n);
	}
	close(infd);
	close(outfd);
	unlink("tp");
	return 0;
}

