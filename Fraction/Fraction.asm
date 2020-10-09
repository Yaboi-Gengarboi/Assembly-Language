; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2020-10-08
; Assembly file for Fraction class.

section .text
bits 64

extern malloc
extern free

global make_empty_fraction
make_empty_fraction:

	mov ecx, 8;

	sub rsp, 32+8; Realign stack to make Windows happy
	call malloc; moves a pointer to a 16-byte array into rax
	add rsp, 32+8;

	ret;

global make_fraction
make_fraction:

	push rcx; Save rcx (1st parameter);
	push rdx; Save rdx (2nd parameter);

	mov ecx, 8;

	sub rsp, 32+8; Realign stack to make Windows happy
	call malloc; moves a pointer to a 16-byte array into rax
	add rsp, 32+8;

	pop rdx; Restore rdx (2nd parameter)
	pop rcx; Restore rcx (1st parameter)

	mov DWORD[rax + 0], ecx;
	mov DWORD[rax + 4], edx; 
	
	ret;

global delete_fraction
delete_fraction:

	sub rsp, 32+8
	
	call free
	
	add rsp, 32+8
	ret

global set_numer
set_numer:

	mov DWORD[rcx + 0], edx
	ret

global set_denom
set_denom:

	mov DWORD[rcx + 4], edx
	ret

global evaluate_fraction
evaluate_fraction:


	ret