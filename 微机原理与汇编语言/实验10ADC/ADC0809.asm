org 100h  
PORT EQU 00H
PRINT EQU 20H

START:	   
    CLI
	MOV DX,10H;����ICW1
    MOV AL,13H;���ش���
    OUT DX,AL	  
        
    MOV DX,12H;����ICW2
	MOV AL,60H;�ж����ͺ�Ϊ60h
	OUT DX,AL 	  
		
	MOV AL,03H;ICW4���Զ�����ж�
	OUT DX,AL     
		
	MOV AL,00H;OCW1, ���������ж�
	OUT DX,AL 
	                     
	MOV AX,0
	MOV ES,AX
	MOV SI,60H*4
	MOV AX,OFFSET INT0;ȡƫ�Ƶ�ַ
	MOV ES:[SI],AX
	MOV AX,800H
	MOV ES:[SI+2],AX;����װ��ε�ַ
			
	STI
    MOV DX,PORT
    OUT DX,AL  ;ѭ����ģ���ѹֵ
    
LP:      
    JMP LP

INT0: 
    PUSH AX
	MOV	DX,PORT
	IN	AL,DX
	MOV	DX,PRINT
	OUT DX,AL 
	
	MOV DX,PORT
    OUT DX,AL  ;ѭ����ģ���ѹֵ 
	POP AX
	IRET
	RET
	   