    ORG 100H
    A EQU 20H
    B EQU 22H
    C EQU 24H
    CON EQU 26H
    .DATA
    LEDtb DB 06H,5BH,4FH,66H,6DH,7DH,07H,7FH
    LEDdt db 8 dup('0')
    
     .CODE
     ;������
    mov  si,offset LEDdt
    call LEDdisp ;������ʾ�ӳ���
    
LEDdisp proc
    push ax
    push bx
    push dx
    mov  bx,offset LEDtb
    mov  ah,0feh    ;ָ������������
LED1:  
    lodsb    ;ȡ��Ҫ��ʾ������
    MOV BX,OFFSET LEDdt
    xlat ;�õ���ʾ���룺AL��CS:[BX��AL]
    mov dx,A	;segportΪ�ο��ƶ˿�
    out dx,al		;�ͳ�����
    mov al,ah		;ȡ��λ��ʾ����
    mov dx,B	;bitportΪλ���ƶ˿�
    out dx,al		;�ͳ�λ��
    call delay		;ʵ���������ʱ��ʾ
    rol ah,1		;ָ����һ�������
    cmp ah,0feh	;8������ʾһ��
    inc bx
    jnz LED1		;��ʾ��һ������
    pop dx
    pop bx
    pop ax
    ret	     		;8λ����ܶ���ʾ
LEDdisp endp

Timer = 1    ;��ʱ����
Delay proc 
    push bx
    push cx
    mov  bx,timer ;��ѭ��������timerȷ��
delay1: 
    xor  cx,cx
delay2:
    loop delay2 ;��ѭ����216��ѭ��
    dec bx
    jnz delay1
    pop cx
    pop bx
    ret
delay endp

end start
