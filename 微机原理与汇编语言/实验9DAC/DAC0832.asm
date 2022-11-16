ST EQU 0000H        
ND EQU 0020H
BOTH EQU 0040H
ORG 100H 
AA1:
    CALL DELAY 
    MOV AL,00H;设定输出电压值
	MOV DX,ST;设置第一片DAC0832地址 
	OUT DX,AL;数据被锁存在8位输入寄存器
	MOV AL,0CH;输出电压-2.0V对应数字值
	MOV DX,ND;设置第二片DAC0832地址
	OUT DX,AL;数据被锁存在8位输入寄存器
	MOV DX,BOTH;设置二片0832共用地址
	OUT DX,AL;启动两片DAC0832同时转换
	CALL DELAY
	MOV AL,20H;输出电压-5V对应数字值
	MOV DX,ST;设置第一片DAC0832地址
	OUT DX,AL 
	MOV AL,1CH;输出电压+2.0V对应数字值
    MOV DX,ND;设置第二片DAC0832地址
    OUT DX,AL
    MOV DX,BOTH;设置二片DAC0832共用地址 
    OUT DX,AL;启动两片DAC0832同时转换
    JMP AA1
DELAY PROC
    PUSH CX
    MOV CX,1
LP:
    LOOP LP
    POP CX
    RET 
DELAY ENDP    


