ORG 100H
A EQU 00H;8255的端口A地址 
B EQU 02H;8255的端口B地址 
C EQU 04H;8255的端口C地址 
CON EQU 06H;8255的控制寄存器地址 

START: 
    MOV DX,CON
    MOV AL,00001001B
    OUT DX,AL
    MOV DX,CON
    MOV AL,10111001B;A口方式1输入,B口方式0输出 
    OUT DX,AL 

    cli
    ;设置中断向量
    mov ax,0
    mov es,ax
    mov si,60h*4
    mov ax,offset int0
    mov es:[si],ax
    mov ax,800h  ;8086仿真模型中程序装入段地址
    mov es:[si+2],ax
  
    ;8259初始化
    mov dx,20h  ;8259偶地址，设置ICW1
    mov al,13h  ;边沿触发，单片，ICW4 NEEDED
    out dx,al   
        
    mov dx,22h  ;8259奇地址，设置ICW2
    mov al,60h  ;中断类型号为60h
    out dx,al    
  
    mov al,03h  ;ICW4，自动清除中断，8086CPU
    out dx,al     
  
    mov al,00h  ;OCW1, 开放所有中断
    out dx,al     
  
    ;设置初始状态     
    mov al,01h
    mov dx,40h
    out dx,al
    sti

lp:
    jmp lp
        
int0:
    MOV DX,A;A口输入 
    IN  AL,DX
    MOV DX,B;B口输出 
    OUT DX,AL  
    iret              ;返回主程序 
    ret
END START