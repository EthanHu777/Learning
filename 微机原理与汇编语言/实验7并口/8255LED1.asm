org 100H
A EQU  4A0H     ;A�˿ڵ�ַ
B EQU  4A2H     ;B�˿ڵ�ַ
C EQU  4A4H     ;C�˿ڵ�ַ
CON EQU  4A6H   ;�����ֵ�ַ
 
START:   
MOV DX,CON
MOV AL,10000010B;A��B�ڷ�ʽ0,A�������B�����룬C�����
OUT DX,AL

KB1:
MOV AL,00H
MOV DX,A    ;�еĵ�ַ
OUT DX,AL   ;��A������͵�ƽ      
MOV DX,B    ;�еĵ�ַ 
IN AL,DX    ;��ȡ��ֵ    
CMP AL,0FFH;������Ƿ��е͵�ƽ
JZ  KB1    ;��ѭ���ȴ�
MOV CX,100 ;�ǣ���ʱ����           
LOOP $        
MOV CX,8   ;����
MOV AH,11111110B;ɨ���ֵ

KB2: 
MOV AL,AH
MOV DX,A
OUT DX,AL;�����ֵ
MOV DX,B
IN  AL,DX;������ֵ
CMP AL,0FFH;����Ƿ���ĳ��Ϊ�͵�ƽ
JNZ KB3   ;������н�һ������
ROL AH,1  ;����ѭ������ɨ��ֵ�Խ�����һ��ɨ��
LOOP KB2
JMP KB1   ;��������Ƿ��м�����
 
KB3:
NOT AH;����ֵȡ��
MOV BH,0
ROW:
;����ֵ����
CMP AH,01H
JZ  KB4 
SHR AH,1      
INC BH
JMP ROW

KB4:
NOT AL;����ֵȡ��
MOV BL,0        
COLUMN:
;����ֵ����
CMP AL,01H
JZ  OUTPUT     
SHR AL,1         
INC BL
JMP COLUMN 

OUTPUT:
;���������Ϣ
SHL BH,4
ADD BL,BH
MOV AL,BL
MOV DX,480H 
OUT DX,AL            
JMP KB1 
RET  
     
     