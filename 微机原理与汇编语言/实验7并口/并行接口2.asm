ORG 100H
A EQU 00H;8255�Ķ˿�A��ַ 
B EQU 02H;8255�Ķ˿�B��ַ 
C EQU 04H;8255�Ķ˿�C��ַ 
CON EQU 06H;8255�Ŀ��ƼĴ�����ַ 

START: 
    MOV DX,CON
    MOV AL,00001001B
    OUT DX,AL
    MOV DX,CON
    MOV AL,10111001B;A�ڷ�ʽ1����,B�ڷ�ʽ0��� 
    OUT DX,AL 

    cli
    ;�����ж�����
    mov ax,0
    mov es,ax
    mov si,60h*4
    mov ax,offset int0
    mov es:[si],ax
    mov ax,800h  ;8086����ģ���г���װ��ε�ַ
    mov es:[si+2],ax
  
    ;8259��ʼ��
    mov dx,20h  ;8259ż��ַ������ICW1
    mov al,13h  ;���ش�������Ƭ��ICW4 NEEDED
    out dx,al   
        
    mov dx,22h  ;8259���ַ������ICW2
    mov al,60h  ;�ж����ͺ�Ϊ60h
    out dx,al    
  
    mov al,03h  ;ICW4���Զ�����жϣ�8086CPU
    out dx,al     
  
    mov al,00h  ;OCW1, ���������ж�
    out dx,al     
  
    ;���ó�ʼ״̬     
    mov al,01h
    mov dx,40h
    out dx,al
    sti

lp:
    jmp lp
        
int0:
    MOV DX,A;A������ 
    IN  AL,DX
    MOV DX,B;B����� 
    OUT DX,AL  
    iret              ;���������� 
    ret
END START