#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_PATH 255
void banner()
{
	system("cls");
	printf(" /—————————————————————\\\r\n");
	printf("|             云窗缓存视频解码程序           |\r\n");
	printf(" \\—————————————————————/\r\n");
	printf("base code by wormfox\r\n\r\n");
	printf("blog:http://t.qq.com/wormfox\r\n\r\n");
	printf("rewritten by 879965984@qq.com\r\n\r\n");
	printf("eg: decoding.exe 1.mp4\r\n\r\n");
	printf("推荐把要解密的视频文件拖到程序上\r\n\r\n");

}
void Decoding_xor(const char *path)
{
	FILE *fp;
	unsigned char file_byte[MAX_PATH];
	int i;
	//printf("%s\n",argv[1]);
	if (path == NULL)
		return;
	fp = fopen(path,"rb+");//读写字符串
	if (fp == NULL)				
		return;	
// 	for(i = 0;i<=254;i++)
// 		ch[i] =fgetc(fp);
	fread( file_byte,sizeof(char),255,fp);	
	fseek(fp,-255,SEEK_CUR);	
	for(i = 0;i<255;i++)	
		fputc((unsigned int)file_byte[i]^0xFF,fp);		
	fclose(fp);
	printf("视频解密成功\r\n");
}


//这个有点问题
void Extension(const char *path,char *str_ext_out)
{
	int i,j;
	char ch[255];	
	char hz[10]={'\0'};	
	if (path != NULL&&strlen(path)<255)//防止空参数和溢出
		strcpy(ch,path);
	else
		return;
	for (i =0;ch[i]!='\0';i++)
	{
		if(ch[i] =='.')
		{

			for (j =0;j<=strlen(path)-i&&j<10;j++)//防止超长后缀溢出
			{
				hz[j] = ch[i+1];
				i++;
			}			
			break;
		}
	}
	strcpy(str_ext_out,hz);	
	//return ext;
}
int main(int argc,char *argv[])
{

	//char *ext = NULL;
	char *str_exp = NULL;	
	banner();
	str_exp = (char *)malloc(MAX_PATH);
	if( str_exp == NULL )
	{
		printf( "内存分配失败\n" );
		system("pause");
		return -1;
	}
	if(argv[1]==NULL)
	{
		system("pause");
		return -1;
	}
	Extension((argv[1]),str_exp);
	if (strcmp(str_exp,"mkv")==0||strcmp(str_exp,"mp4")==0)   
		Decoding_xor(argv[1]);	    
	else
		printf("文件不是音频文件\n");
	free(str_exp);//内存泄露
	str_exp=NULL;
	system("pause");	
	return 0;
}