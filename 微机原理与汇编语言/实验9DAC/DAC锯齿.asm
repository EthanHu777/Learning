org 100h
START: 
MOV AL,0  ;��ѹ��ֵ 
AA1:		
OUT 0,AL  ;Ƭѡ1���  	
OUT 20H,AL;Ƭѡ2���   	
INC AL	  ;��ѹ+1���ӵ����ֵ��+1�Զ�����Ϊ0 		
JMP AA1
 