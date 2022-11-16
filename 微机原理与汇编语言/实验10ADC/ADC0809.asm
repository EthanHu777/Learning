org 100h  
PORT EQU 00H
PRINT EQU 20H

START:	   
    CLI
	MOV DX,10H;设置ICW1
    MOV AL,13H;边沿触发
    OUT DX,AL	  
        
    MOV DX,12H;设置ICW2
	MOV AL,60H;中断类型号为60h
	OUT DX,AL 	  
		
	MOV AL,03H;ICW4，自动清除中断
	OUT DX,AL     
		
	MOV AL,00H;OCW1, 开放所有中断
	OUT DX,AL 
	                     
	MOV AX,0
	MOV ES,AX
	MOV SI,60H*4
	MOV AX,OFFSET INT0;取偏移地址
	MOV ES:[SI],AX
	MOV AX,800H
	MOV ES:[SI+2],AX;程序装入段地址
			
	STI
    MOV DX,PORT
    OUT DX,AL  ;循环读模拟电压值
    
LP:      
    JMP LP

INT0: 
    PUSH AX
	MOV	DX,PORT
	IN	AL,DX
	MOV	DX,PRINT
	OUT DX,AL 
	
	MOV DX,PORT
    OUT DX,AL  ;循环读模拟电压值 
	POP AX
	IRET
	RET
	   