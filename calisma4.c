#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE          (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("bir dosya ismi ve bir harf veriniz.\n");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY, FILE_MODE);
	if(fd<0)
	{
		printf("dosya okuma hatası.\n");
		exit(-2);
	}
	int n = 1;
	int sayac = 0;
	char buf[1];
	int word = 0;
	char harf = argv[2][0];
	while(n = read(fd,buf,sizeof(buf))>0)
	{
		if (buf[0] == harf)
			sayac = 1;
		if(sayac == 1 && (buf[0] == ' ' || buf[0] == '.'))
		{
			word++;
			sayac = 0;
		}
	}

	printf("Dosyada %c harfinden %d tane vardır.", harf,word);
	close(fd);
	return 0;
}
