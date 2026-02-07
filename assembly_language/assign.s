 .data 
 	value: .byte 8;
 
 .text
 start:
 	ldr r1,adr_value;
 	ldr r2, [r1]  ;	
 	
 
 adr_value: .word value;	
 stop: b stop
