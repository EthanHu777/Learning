DATA SEGMENT
CODE SEGMENT
ASSUME CS:CODE
ORG 100H
start:
    MOV DX,66H
    MOV AL,00110100B
    OUT DX,AL
    MOV DX,60H
    MOV AX,4
    OUT DX,AL
    MOV AL,AH
    OUT DX,AL
    MOV DX,66H
    MOV AL,01110010B
    OUT DX,AL
    MOV DX,62H
    MOV AX,1
    OUT DX,AL
    MOV AL,AH
    OUT DX,AL
CODE ENDS
END start 