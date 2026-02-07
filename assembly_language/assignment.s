  .data 
 	value: .byte 5;
 
 .text
 start:
 	ldr r1,=value;
 	ldr r2, [r1]  ;	
 	
 
 	
 stop: b stop
