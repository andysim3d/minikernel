; load from 7c00
	org 07c00h
	mov ax, cs	
	mov ds, ax
	mov es, ax

	call DispStr
;	infinate loop
	jmp $

; DispStr sub module
DispStr:
	;load string into ax
	mov ax, BootMessage
	;ES:BP string address
	mov bp, ax
	; string length
	mov cx, 16
	; AH=13, AL=01
	mov ax, 01301h
	;page number is 0
	;BH 0, BL= 0ch (black backgrond, red char)
	mov bx, 000ch
	mov dl, 0
	; 10h interrupt
	int 10h
	ret

;	string
BootMessage:	db "Hello, OS world!"
	
	; keep the space length to 512
	times 510 - ($-$$)   db 0

	;stop symbol
	dw 0xaa55
	
