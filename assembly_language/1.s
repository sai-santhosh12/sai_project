AREA program,CODE,READONLY
ENTRY

Main
	LDRB R1, value
	STR  R1,result

value DCB &1F
      ALIGN
result DCW 0
       END
