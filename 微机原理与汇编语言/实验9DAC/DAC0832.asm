ST EQU 0000H        
ND EQU 0020H
BOTH EQU 0040H
ORG 100H 
AA1:
    CALL DELAY 
    MOV AL,00H;�趨�����ѹֵ
	MOV DX,ST;���õ�һƬDAC0832��ַ 
	OUT DX,AL;���ݱ�������8λ����Ĵ���
	MOV AL,0CH;�����ѹ-2.0V��Ӧ����ֵ
	MOV DX,ND;���õڶ�ƬDAC0832��ַ
	OUT DX,AL;���ݱ�������8λ����Ĵ���
	MOV DX,BOTH;���ö�Ƭ0832���õ�ַ
	OUT DX,AL;������ƬDAC0832ͬʱת��
	CALL DELAY
	MOV AL,20H;�����ѹ-5V��Ӧ����ֵ
	MOV DX,ST;���õ�һƬDAC0832��ַ
	OUT DX,AL 
	MOV AL,1CH;�����ѹ+2.0V��Ӧ����ֵ
    MOV DX,ND;���õڶ�ƬDAC0832��ַ
    OUT DX,AL
    MOV DX,BOTH;���ö�ƬDAC0832���õ�ַ 
    OUT DX,AL;������ƬDAC0832ͬʱת��
    JMP AA1
DELAY PROC
    PUSH CX
    MOV CX,1
LP:
    LOOP LP
    POP CX
    RET 
DELAY ENDP    


