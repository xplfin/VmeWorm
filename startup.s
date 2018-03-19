	.text
	.include "bugcall.i"
	.global _start
_start:
|
| Debug ROM on alustanut keskeytysvektorin ja pino-osoittimen
|
	jsr	Init
	jsr	main
|
	BUGCALL	.RETURN
|
| Pikku IO-kirjasto Debug ROMin kautta
|
        .globl  InChar
InChar:
	subq.l	#2,%sp
	BUGCALL	.INCHR
	move.b	(%sp)+,%d0
	rts
|
	.globl	InStat
InStat:
	clr.l	%d0
	BUGCAll	.INSTAT
	beq	1f
	move.l	#1,%d0
1:
	rts
|
	.globl	OutCh
OutCh:
	move.l	4(%sp),%d0
	move.b	%d0,-(%sp)
	BUGCALL	.OUTCHR
	rts
|
	.end

	
