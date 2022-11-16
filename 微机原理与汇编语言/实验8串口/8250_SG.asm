org 100h
.model small
.data
MSG DB "The quick brown fox jumps over the lazy dog"
.code
START:
;设置传输速率
MOV DX,40H
ADD DX,6  ;LCR
MOV AL,80h;选择除数寄存器
OUT DX,AL 

MOV DX,40H
MOV AX,0CH;波特率因子 
OUT DX,AL
ADD DX,2
MOV AL,0
OUT DX,AL
  
;设置数据包格式
ADD DX,4 ;LCR 
MOV AL,7 ;无校验位,8位数据位, 2位停止位
OUT DX,AL

;设置中断
MOV DX,42H
MOV AL,0
OUT DX,AL 
MOV BX,OFFSET MSG 

SEND:
MOV AL,[BX] ;读取第一个字符
PUSH AX     ;入栈保护读取的字符
MOV DX,4AH  ;线路状态寄存器LSR

WAITING:
IN   AL,DX
TEST AL,20H ;判断发送保持寄存器是否为空
JNZ RECEIVE 
JMP WAITING  

RECEIVE:
POP AX
MOV DX,40H
OUT DX,AL
INC BX 
CMP [BX],0BAH
JNZ SEND  
END START