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
MOV AX, WORD PTR NUM[0];NUM�ĵ�16λ����AX
MOV DX, WORD PTR NUM[2];NUM�ĸ�16λ����DX
MOV BX, OFFSET OBUF+10
MOV BYTE PTR [BX],'$'  

AGAIN: 
MOV CX,10;Ϊ��������(DX):(AX)/10 ���ȴ������      
CALL DIVDW        
ADD CX,30H;��CX�е�ʮ������ת��ΪASCII��
DEC BX
MOV [BX],CL
CMP AX,0
JNZ AGAIN;�̲�Ϊ0���ٴν��г�������

DSTRING INF2   
MOV DX,BX
MOV AH,09H
INT 21H  
MOV AH,4CH
INT 21H

;����32λ�������㣨��ֹ�����    
DIVDW PROC
    
;�ȶԸ�16λ���г������� 
PUSH BX;����BX�洢������
PUSH AX;��16λ��ջ    
MOV AX,DX   
MOV DX,0
DIV CX;����AX,������DX
MOV BX,AX;BX�����16λ��
POP AX;��16λ����AX
    
;�Ե�16λ���г�������
PUSH BX;��16λ��ջ
DIV CX 
MOV CX,DX;DX�б����������CX
POP DX;��ʱDX�洢���ĸ�16λ
POP BX
RET
ENDP DIVDW

END start