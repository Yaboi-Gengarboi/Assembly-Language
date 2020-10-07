; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2020-10-07

section .text
bits 64

extern malloc
extern free

global make_empty_fraction
make_empty_fraction:

	mov rcx, 8*2;

	sub rsp, 32+8; Realign stack to make Windows happy
	call malloc; moves a pointer to a 16-byte array into rax
	add rsp, 32+8;

	ret;

global make_fraction
make_fraction:

	push rcx; Save rcx (1st parameter);
	push rdx; Save rdx (2nd parameter);

	mov rcx, 8*2;

	sub rsp, 32+8; Realign stack to make Windows happy
	call malloc; moves a pointer to a 16-byte array into rax
	add rsp, 32+8;

	pop rdx; Restore rdx (2nd parameter)
	pop rcx; Restore rcx (1st parameter)

	mov QWORD[rax + 0], rcx;
	mov QWORD[rax + 4], rdx; 
	
	ret;

global delete_fraction
delete_fraction:

	sub rsp, 32+8
	
	call free
	
	add rsp, 32+8
	ret

global set_numer
set_numer:

	mov QWORD[rcx + 0], rdx
	ret

global set_denom
set_denom:

	mov QWORD[rcx + 4], rdx
	ret