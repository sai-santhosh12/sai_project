
_start:
	mov r1,#5;
	mov r2,#6;
	mul r3,r1,r2;
	swi &11;
	
stop:	LDR pc,=stop;
