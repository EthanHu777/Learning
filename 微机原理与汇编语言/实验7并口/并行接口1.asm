  ORG 100H
A EQU 20H;8255�Ķ˿�A��ַ 
B EQU 22H;8255�Ķ˿�B��ַ 
C EQU 24H;8255�Ķ˿�C��ַ 
CON EQU 26H;8255�Ŀ��ƼĴ�����ַ 

START: 
    MOV DX,CON
    MOV AL,10011001B;A��B�ڹ�����ʽ0��A������,B����� 
    OUT DX,AL 
MAIN:
    MOV DX,A;A������ 
    IN  AL,DX
    MOV DX,B;B����� 
    OUT DX,AL 
    JMP MAIN
END START