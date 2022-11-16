code segment 
assume cs:code
org 100h
port equ 400h
start: 
;设置传输速率
mov bx,port
mov dx,bx
add dx,6 ;线路控制寄存器
mov ax,80h
out dx,ax
mov dx,bx
mov ax,0ch;波特率因子
out dx,ax 
add dx,2
mov ax,0h
out dx,ax
;设置数据包格式
add dx,4 
mov ax,07;无校验位，8数据位，1停止位
out dx,ax
;设置中断允许
mov dx,bx
add dx,2 
mov ax,0
out dx,ax
;收发信息
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
