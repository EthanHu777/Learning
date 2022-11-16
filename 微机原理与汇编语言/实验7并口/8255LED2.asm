    ORG 100H
    A EQU 20H
    B EQU 22H
    C EQU 24H
    CON EQU 26H
    .DATA
    LEDtb DB 06H,5BH,4FH,66H,6DH,7DH,07H,7FH
    LEDdt db 8 dup('0')
    
     .CODE
     ;主程序
    mov  si,offset LEDdt
    call LEDdisp ;调用显示子程序
    
LEDdisp proc
    push ax
    push bx
    push dx
    mov  bx,offset LEDtb
    mov  ah,0feh    ;指向最左边数码管
LED1:  
    lodsb    ;取出要显示的数字
    MOV BX,OFFSET LEDdt
    xlat ;得到显示代码：AL←CS:[BX＋AL]
    mov dx,A	;segport为段控制端口
    out dx,al		;送出段码
    mov al,ah		;取出位显示代码
    mov dx,B	;bitport为位控制端口
    out dx,al		;送出位码
    call delay		;实现数码管延时显示
    rol ah,1		;指向下一个数码管
    cmp ah,0feh	;8个管显示一遍
    inc bx
    jnz LED1		;显示下一个数字
    pop dx
    pop bx
    pop ax
    ret	     		;8位数码管都显示
LEDdisp endp

Timer = 1    ;延时常量
Delay proc 
    push bx
    push cx
    mov  bx,timer ;外循环次数由timer确定
delay1: 
    xor  cx,cx
delay2:
    loop delay2 ;内循环：216次循环
    dec bx
    jnz delay1
    pop cx
    pop bx
    ret
delay endp

end start
