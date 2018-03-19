|
	.macro BUGCALL x
	trap	#15
	.word	\x
	.endm
|
	.set	.INCHR,		0x0000
	.set	.INSTAT,	0x0001
	.set	.INLN,		0x0002
	.set	.READSTR,	0x0003
	.set	.READLN,	0x0004
	.set	.CHKBRK,	0x0005
|
	.set	.DSKRD,		0x0010
	.set	.DSKWR,		0x0011
	.set	.DSKCFIG,	0x0012
	.set	.DSKFMT,	0x0014
	.set	.DSKRD,		0x0015
|
	.set	.OUTCHR,	0x0020
	.set	.OUTSTR,	0x0021
	.set	.OUTLN,		0x0022
	.set	.WRITE,		0x0023
	.set	.WRITELN,	0x0024
	.set	.WRITDLN,	0x0025
	.set	.PCRLN,		0x0026
	.set	.ERASLN,	0x0027
	.set	.WRITD,		0x0028
	.set	.SNDBRK,	0x0029
|
	.set	.TM_INI,	0x0040
	.set	.DT_INI,	0x0041
	.set	.TM_DISP,	0x0042
	.set	.TM_RDI,	0x0043
|
	.set	.REDIR,		0x0060
	.set	.REDIR_I,	0x0061
	.set	.REDIR_O,	0x0062
	.set	.RETURN,	0x0063
	.set	.BINDEC,	0x0064
	.set	.CHANGEV,	0x0067
	.set	.STRCMP,	0x0068
	.set	.MULU32,	0x0069
	.set	.DIVU32,	0x006A
	.set	.CHK_SUM,	0x006B

