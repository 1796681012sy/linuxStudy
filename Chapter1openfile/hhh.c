#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int fd1,fd2;
	int rpos = 0, wpos = 0,pos = 0;//读取位置，写入位置，当前位置
	char str[2];                   //临时数组
	int row = 0;                   //行数判断
	int trun_num =0 ;              //需要截断的位置
	//如果传入参数不够，给出提示
	if(argc < 1) {
		printf("Usage...\n");
		exit(1);
	}
	//只读方式打开
	//fd1 = open(argv[1],O_RDONLY);
	fd1 = open("tmp",O_RDONLY);
	
	if(-1 == fd1){
		perror("open()");
		exit(1);
	}
	//以读写方式打开
	//fd2 = open(argv[1],O_RDWR);
	fd2 = open("tmp",O_RDONLY);
	if(-1 == fd2){
		perror("open()");
		exit(1);
	}
	//找到读取位置
	while(1){
		if(row == 3) {
			rpos = pos;
			break;
		}
		if(read(fd1,str,1) <= 0) break;
		//printf("%s\n",str);
		if(str[0] == '\n') row = row+1;//判断是否到了一行的截止
		pos = pos + 1;
	}
	pos = 0;
	row = 0;
	//找到写入位置
	while(1){
        if(row == 2) {
            wpos = pos;
            break;
        }
        if(read(fd2,str,1) <= 0) break;
        if(str[0] == '\n') row = row+1;//判断是否到了一行的截止
        pos = pos + 1;
	}
	//读取数据写入文件
	while(1){
		if(read(fd1,str,1)<= 0) break;
		write(fd2,str,1);

	}
	//从写入位置开始截断
	trun_num = lseek(fd2,0,SEEK_CUR);
	ftruncate(fd2,trun_num);	
	close(fd1);//关闭文件
	close(fd2);
	exit(0);
}
