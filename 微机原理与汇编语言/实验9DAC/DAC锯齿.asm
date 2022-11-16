org 100h
START: 
MOV AL,0  ;电压初值 
AA1:		
OUT 0,AL  ;片选1输出  	
OUT 20H,AL;片选2输出   	
INC AL	  ;电压+1，加到最大值再+1自动跳变为0 		
JMP AA1
 