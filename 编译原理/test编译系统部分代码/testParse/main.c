//������
#include <stdio.h>
#include <ctype.h>
extern int TESTparse();
char Scanout[30], Errorfile[30], Codeout[30]; //���ڽ�����������Լ������ļ���
void main()
{
 int es=0;
 es = TESTparse();	//���﷨��������������ɴ���
 if(es == 0) 	printf("�﷨��������������ɴ���ɹ�!\n");
 else	printf("�﷨��������������ɴ������!\n");
}
