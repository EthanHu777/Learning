org 100h
.model small
.data
MSG DB "The quick brown fox jumps over the lazy dog"
.code
START:
;���ô�������
MOV DX,40H
ADD DX,6  ;LCR
MOV AL,80h;ѡ������Ĵ���
OUT DX,AL 

MOV DX,40H
MOV AX,0CH;���������� 
OUT DX,AL
ADD DX,2
MOV AL,0
OUT DX,AL
  
;�������ݰ���ʽ
ADD DX,4 ;LCR 
MOV AL,7 ;��У��λ,8λ����λ, 2λֹͣλ
OUT DX,AL

;�����ж�
MOV DX,42H
MOV AL,0
OUT DX,AL 
MOV BX,OFFSET MSG 

SEND:
MOV AL,[BX] ;��ȡ��һ���ַ�
PUSH AX     ;��ջ������ȡ���ַ�
MOV DX,4AH  ;��·״̬�Ĵ���LSR

WAITING:
IN   AL,DX
TEST AL,20H ;�жϷ��ͱ��ּĴ����Ƿ�Ϊ��
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