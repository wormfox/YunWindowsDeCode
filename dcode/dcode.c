#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_PATH 255
void banner()
{
	system("cls");
	printf(" /������������������������������������������\\\r\n");
	printf("|             �ƴ�������Ƶ�������           |\r\n");
	printf(" \\������������������������������������������/\r\n");
	printf("base code by wormfox\r\n\r\n");
	printf("blog:http://t.qq.com/wormfox\r\n\r\n");
	printf("rewritten by 879965984@qq.com\r\n\r\n");
	printf("eg: decoding.exe 1.mp4\r\n\r\n");
	printf("�Ƽ���Ҫ���ܵ���Ƶ�ļ��ϵ�������\r\n\r\n");

}
void Decoding_xor(const char *path)
{
	FILE *fp;
	unsigned char file_byte[MAX_PATH];
	int i;
	//printf("%s\n",argv[1]);
	if (path == NULL)
		return;
	fp = fopen(path,"rb+");//��д�ַ���
	if (fp == NULL)				
		return;	
// 	for(i = 0;i<=254;i++)
// 		ch[i] =fgetc(fp);
	fread( file_byte,sizeof(char),255,fp);	
	fseek(fp,-255,SEEK_CUR);	
	for(i = 0;i<255;i++)	
		fputc((unsigned int)file_byte[i]^0xFF,fp);		
	fclose(fp);
	printf("��Ƶ���ܳɹ�\r\n");
}


//����е�����
void Extension(const char *path,char *str_ext_out)
{
	int i,j;
	char ch[255];	
	char hz[10]={'\0'};	
	if (path != NULL&&strlen(path)<255)//��ֹ�ղ��������
		strcpy(ch,path);
	else
		return;
	for (i =0;ch[i]!='\0';i++)
	{
		if(ch[i] =='.')
		{

			for (j =0;j<=strlen(path)-i&&j<10;j++)//��ֹ������׺���
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
		printf( "�ڴ����ʧ��\n" );
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
		printf("�ļ�������Ƶ�ļ�\n");
	free(str_exp);//�ڴ�й¶
	str_exp=NULL;
	system("pause");	
	return 0;
}