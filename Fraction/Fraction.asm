; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2020-10-05

section .text
bits 64

extern malloc
extern free

;global make_fraction
;make_fraction:
	;sub rsp, 32+8
	;
	;mov rdi, 8*2
	;call malloc
	;
	;mov QWORD [rax + 0*8], rcx
	;mov QWORD [rax + 1*8], rdx
	;
	;add rsp, 32+8
	;ret

;global delete_fraction
;delete_fraction:
	;sub rsp, 32+8
	;
	;mov rdi, rcx
	;call free
	;
	;add rsp, 32+8
	;mov rax, 0
	;ret

global test
test:
	sub rsp, 32+8

	mov rcx, 8*2
	call malloc

	mov QWORD [rax + 8*0], 1
	mov QWORD [rax + 8*1], 2

	mov rcx, rax
	call free

	add rsp, 32+8
	mov rax, 0
	ret