org 100H
A EQU  4A0H     ;A端口地址
B EQU  4A2H     ;B端口地址
C EQU  4A4H     ;C端口地址
CON EQU  4A6H   ;控制字地址
 
START:   
MOV DX,CON
MOV AL,10000010B;A、B口方式0,A口输出，B口输入，C口输出
OUT DX,AL

KB1:
MOV AL,00H
MOV DX,A    ;行的地址
OUT DX,AL   ;向A口输出低电平      
MOV DX,B    ;列的地址 
IN AL,DX    ;读取列值    
CMP AL,0FFH;检查列是否有低电平
JZ  KB1    ;否，循环等待
MOV CX,100 ;是，延时抖动           
LOOP $        
MOV CX,8   ;行数
MOV AH,11111110B;扫描初值

KB2: 
MOV AL,AH
MOV DX,A
OUT DX,AL;输出行值
MOV DX,B
IN  AL,DX;读入列值
CMP AL,0FFH;检查是否有某列为低电平
JNZ KB3   ;是则进行进一步处理
ROL AH,1  ;否则循环左移扫描值以进行下一次扫描
LOOP KB2
JMP KB1   ;继续检测是否有键按下
 
KB3:
NOT AH;对行值取反
MOV BH,0
ROW:
;对行值计数
CMP AH,01H
JZ  KB4 
SHR AH,1      
INC BH
JMP ROW

KB4:
NOT AL;对列值取反
MOV BL,0        
COLUMN:
;对列值计数
CMP AL,01H
JZ  OUTPUT     
SHR AL,1         
INC BL
JMP COLUMN 

OUTPUT:
;输出按键信息
SHL BH,4
ADD BL,BH
MOV AL,BL
MOV DX,480H 
OUT DX,AL            
JMP KB1 
RET  
     
     