//主程序
#include <stdio.h>
#include <ctype.h>
extern int TESTparse();
char Scanout[30], Errorfile[30], Codeout[30]; //用于接收输入输出以及错误文件名
void main()
{
 int es=0;
 es = TESTparse();	//调语法、语义分析并生成代码
 if(es == 0) 	printf("语法、语义分析并生成代码成功!\n");
 else	printf("语法、语义分析并生成代码错误!\n");
}
