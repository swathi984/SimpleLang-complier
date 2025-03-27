section.data
a: DW 0
MOV AX, 10
MOV [a], AX
b: DW 0
section.text
global_start
start:
   MOV eax,1
   int 0x80
