.data
x: 	.word 0x01020304
msg:    .asciz "Truong cong nghe thong tin va truyen thong"
.text
la a0, msg	
li a7, 4	
ecall
addi t1,zero,2
addi t2,zero,3
add t0,t1,t2