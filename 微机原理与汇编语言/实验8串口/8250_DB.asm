code segment 
assume cs:code
org 100h
port equ 400h
start: 
;���ô�������
mov bx,port
mov dx,bx
add dx,6 ;��·���ƼĴ���
mov ax,80h
out dx,ax
mov dx,bx
mov ax,0ch;����������
out dx,ax 
add dx,2
mov ax,0h
out dx,ax
;�������ݰ���ʽ
add dx,4 
mov ax,07;��У��λ��8����λ��1ֹͣλ
out dx,ax
;�����ж�����
mov dx,bx
add dx,2 
mov ax,0
out dx,ax
;�շ���Ϣ
randt: call recv
call send
jmp randt
recv:
mov bx,port
mov dx,bx
add dx,0ah
wait2r:
in al,dx
test al,01h
jnz recvok
jmp wait2r
recvok:
mov dx,bx
in al,dx
ret
send:
push ax
mov bx,port
mov dx,bx
add dx,0ah
wait2t:
in al,dx
test al,20h
jnz sendok
jmp wait2t
sendok:
pop ax
mov dx,bx
out dx,ax
ret
code ends 
end start 
