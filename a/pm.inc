
DA_32	EQU 4000h	;32 BIT 
DA_DPL0	EQU 00h;
DA_DPL1	EQU 20h;
DA_DPL2	EQU 40h;
DA_DPL3	EQU 60h;

DA_DR	EQU 90h;
DA_DRW	EQU	92h;
DA_DRWA	EQU 93h;

DA_C	EQU 98h;
DA_CR	EQU	9Ah;
DA_CCO	EQU	9Ch;
DA_CCOR	EQU	9Eh;




;usage : Descriptor Base, Limit, Attr,
;Base: dd
;Limit: dd (low 20 bits available)
;Attr: dw (lower 4 bits of higher byte are always 0)
%macro Descriptor 3
	;base1
	dw %1 & 0FFFFh
	;Limit1
	dw %2 & 0FFFFh
	;Base 2
	db (%1 >> 16) &0FFh
	;Attr1 + Limit2 + Attr2
	dw ((%2 >> 8) & 0F00h ) | (%3 & 0F0FFh)
	;Base 3
	db (%1 >> 24) & 0FFh
%endmacro
