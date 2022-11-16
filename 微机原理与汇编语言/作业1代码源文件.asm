.model small
.stack
.data
NUM DD FFFFFFFFH
INF1 DB "The 32-bit unsigned integer is:"
     DB "11111111111111111111111111111111",0AH,0DH,'$'
INF2 DB "The result after conversion to decimal is:$"
OBUF DB 11 DUP(0) 

.code                
DSTRING MACRO STRING 
PUSH DX
PUSH AX
MOV DX, OFFSET STRING   
MOV AH, 09H
INT 21H
POP AX                                      
POP DX
ENDM 

start: 
MOV AX, data
MOV DS, AX 
DSTRING INF1
MOV AX, WORD PTR NUM[0];NUM的低16位送入AX
MOV DX, WORD PTR NUM[2];NUM的高16位送入DX
MOV BX, OFFSET OBUF+10
MOV BYTE PTR [BX],'$'  

AGAIN: 
MOV CX,10;为除法运算(DX):(AX)/10 事先存入除数      
CALL DIVDW        
ADD CX,30H;将CX中的十进制数转换为ASCII码
DEC BX
MOV [BX],CL
CMP AX,0
JNZ AGAIN;商不为0则再次进行除法运算

DSTRING INF2   
MOV DX,BX
MOV AH,09H
INT 21H  
MOV AH,4CH
INT 21H

;进行32位除法运算（防止溢出）    
DIVDW PROC
    
;先对高16位进行除法运算 
PUSH BX;保护BX存储的内容
PUSH AX;低16位入栈    
MOV AX,DX   
MOV DX,0
DIV CX;商在AX,余数在DX
MOV BX,AX;BX保存高16位商
POP AX;低16位送入AX
    
;对低16位进行除法运算
PUSH BX;高16位入栈
DIV CX 
MOV CX,DX;DX中保存的余数送CX
POP DX;此时DX存储数的高16位
POP BX
RET
ENDP DIVDW

END start