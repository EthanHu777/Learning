org 100h
start:     
    MOV DX, 66H
    MOV AL, 00110110B    
    OUT DX, AL
    MOV DX, 60H
    MOV AX, 2000        
    OUT DX, AL
    MOV AL, AH
    OUT DX, AL
    
    ;ÖÐ¶Ï³ÌÐò
    cli
    mov ax,0
    mov es,ax
    mov si,60h*4
    mov ax,offset int0
    mov es:[si],ax
    mov ax,800h   
    mov es:[si+2],ax
  
    mov dx,20h   
    mov al,13h     
    out  dx,al   
        
    mov dx,22h  
    mov al,60h  
    out dx,al
  
    mov al,03h   
    out dx,al
  
    mov al,00h 
    out dx,al
  
    mov bl,1
    mov al,bl 
    mov dx,40h
    out dx,al
  
    sti

lp:
   jmp lp
        
int0:  
    rol bl,1          ;cnt=cnt<<1
    mov al,bl
    mov dx,40h      ;led=cnt<<1 
    out dx,al
    iret           
    ret