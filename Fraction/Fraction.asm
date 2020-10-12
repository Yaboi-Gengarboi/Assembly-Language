; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2020-10-12
; Assembly file for Fraction class.

section .text
bits 64

extern malloc
extern free

global make_empty_fraction
make_empty_fraction:

    mov ecx, 8;                                  exc = 8

    sub rsp, 32+8;                               Allocate memory to call C function
    call malloc;                                 Call malloc(ecx), rax = _ptr
    add rsp, 32+8;                               Deallocate memory

    ret;                                         RETURN

global make_fraction
make_fraction:

    push rcx;                                    Save rcx (1st parameter);
    push rdx;                                    Save rdx (2nd parameter);

    mov ecx, 8;                                  exc = 8

    sub rsp, 32+8;                               Allocate memory to call C function
    call malloc;                                 Call malloc(ecx), rax = _ptr
    add rsp, 32+8;                               Deallocate memory

    pop rdx;                                     Restore rdx (2nd parameter)
    pop rcx;                                     Restore rcx (1st parameter)

    mov DWORD[rax + 0], ecx;                     _ptr[0] = ecx
    mov DWORD[rax + 4], edx;                     _ptr[1] = edx
	
    ret;                                         RETURN

global delete_fraction
delete_fraction:

    sub rsp, 32+8;                               Allocate memory to call C function
	
    call free;                                   Call free(rcx)
	
    add rsp, 32+8;                               Deallocate memory
    ret;                                         RETURN

global set_numer
set_numer:

    mov DWORD[rcx + 0], edx;                     _ptr[0] = edx
    ret;                                         RETURN

global set_denom
set_denom:

    mov DWORD[rcx + 4], edx;                     _ptr[1] = edx
    ret;                                         RETURN

global evaluate_fraction
evaluate_fraction:

	cvtsi2ss xmm0, rcx
    cvtsi2ss xmm1, rdx

	divss xmm0, xmm1
	ret

global add_fraction
add_fraction:

    mov r8d, DWORD[rcx + 4];                     r8d = f1._ptr[1] 
    mov r9d, DWORD[rdx + 4];                     r9d = f2._ptr[1]

    cmp r8d, r9d;                                r8d != r9d ?
    jne DENOM_NOT_EQUAL_01;                      IF TRUE, JUMP TO LINE 91

    mov r8d, DWORD[rcx + 0];                     r8d = f1._ptr[0]
    add r8d, DWORD[rdx + 0];                     r8d += f2._ptr[0]

    mov DWORD[rcx + 0], r8d;                     f1._ptr[0] = r8d
    ret;                                         RETURN

    DENOM_NOT_EQUAL_01:
		
        mov r8d, DWORD[rcx + 0];                 r8d = f1._ptr[0]
        mov r9d, DWORD[rdx + 0];                 r9d = f2._ptr[0]

        mov r10d, DWORD[rcx + 4];                r10d = f1._ptr[1]
        mov r11d, DWORD[rdx + 4];                r11d = f2._ptr[1]

        imul r8d, r11d;                          r8d *= r11d
        imul r9d, r10d;                          r9d *= r10d

        add r8d, r9d;                            r8d += r9d
		imul r10d, r11d;                         r10d *= r11d

		mov DWORD[rcx + 0], r8d;                 f1._ptr[0] = r8d
		mov DWORD[rcx + 4], r10d;                f1._ptr[1] = r10d

        ret;                                     RETURN

global sub_fraction
sub_fraction:

    mov r8d, DWORD[rcx + 4];                     r8d = f1._ptr[1] 
    mov r9d, DWORD[rdx + 4];                     r9d = f2._ptr[1]

    cmp r8d, r9d;                                r8d != r9d ?
    jne DENOM_NOT_EQUAL_02;                      IF TRUE, JUMP TO LINE 125

    mov r8d, DWORD[rcx + 0];                     r8d = f1._ptr[0]
    sub r8d, DWORD[rdx + 0];                     r8d -= f2._ptr[0]

    mov DWORD[rcx + 0], r8d;                     f1._ptr[0] = r8d
    ret;                                         RETURN

    DENOM_NOT_EQUAL_02:
		
        mov r8d, DWORD[rcx + 0];                 r8d = f1._ptr[0]
        mov r9d, DWORD[rdx + 0];                 r9d = f2._ptr[0]

        mov r10d, DWORD[rcx + 4];                r10d = f1._ptr[1]
        mov r11d, DWORD[rdx + 4];                r11d = f2._ptr[1]

        imul r8d, r11d;                          r8d *= r11d
        imul r9d, r10d;                          r9d *= r10d

        sub r8d, r9d;                            r8d -= r9d
		imul r10d, r11d;                         r10d *= r11d

		mov DWORD[rcx + 0], r8d;                 f1._ptr[0] = r8d
		mov DWORD[rcx + 4], r10d;                f1._ptr[1] = r10d

        ret;                                     RETURN