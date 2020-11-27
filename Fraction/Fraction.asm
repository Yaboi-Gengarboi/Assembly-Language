; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2020-11-23
; Assembly file for Fraction class.

section .text
bits 64

extern malloc
extern free

; PARAMETERS: 
; - ecx = numer
; - edx = denom
global make_fr
make_fr:

    push rcx;                                    Save rcx (1st parameter);
    push rdx;                                    Save rdx (2nd parameter);

    mov ecx, 8;                                  ecx = 8

    sub rsp, 32+8;                               Allocate memory to call C function
    call malloc;                                 Call malloc(ecx), rax = int* f
    add rsp, 32+8;                               Deallocate memory

    pop rdx;                                     Restore rdx (2nd parameter)
    pop rcx;                                     Restore rcx (1st parameter)

    mov DWORD[rax + 0], ecx;                     f[0] = ecx
    mov DWORD[rax + 4], edx;                     f[1] = edx
	
    ret;                                         RETURN

; PARAMATERS:
; - rcx = int* f
global delete_fr
delete_fr:

    sub rsp, 32+8;                               Allocate memory to call C function
	
    call free;                                   Call free(f)
	
    add rsp, 32+8;                               Deallocate memory
    ret;                                         RETURN

; PARAMATERS: 
; - rcx = int* f
; - edx = int numer
global set_numer
set_numer:

    mov DWORD[rcx + 0], edx;                     f[0] = edx
    ret;                                         RETURN

; PARAMATERS: 
; - rcx = int* f
; - edx = int denom
global set_denom
set_denom:

    mov DWORD[rcx + 4], edx;                     f[1] = edx
    ret;                                         RETURN

; PARAMETERS:
; - rcx = int* f
; - edx = int numer
; - r8d = int denom
global set_fr
set_fr:

    mov DWORD[rcx + 0], edx;                     f[0] = numer
    mov DWORD[rcx + 4], r8d;                     f[1] = denom
     
    ret;                                         RETURN

; PARAMETERS:
; - rcx = int* f
; - edx = unsigned int n
global pow_fr
pow_fr:

    cmp edx, 0;                                  n == 0 ?
    je N_IS_0;                                   IF TRUE, JUMP TO LINE 110

    cmp edx, 1;                                  n == 1 ?
    je END;                                      IF TRUE, JUMP TO LINE 115

    mov r8d, DWORD[rcx + 0];                     r8d = f[0]
    mov r9d, r8d;                                r9d = r8d = f[0]

    mov r10d, DWORD[rcx + 4];                    r10d = f[1]
    mov r11d, r10d;                              r11d = r10d = f[2]

    LOOP:

        imul r8d, r9d;                           r8d *= r9d
        imul r10d, r11d;                         r10d *= r11d

        sub edx, 1;                              --n
        cmp edx, 1;                              n > 1 ?
        jg LOOP;                                 IF TRUE, JUMP TO LINE 97

    mov DWORD[rcx + 0], r8d;                     f[0] = r8d
    mov DWORD[rcx + 4], r10d;                    f[1] = r10d
    jmp END;                                     JUMP TO LINE 115

    N_IS_0:

        mov DWORD[rcx + 0], 1;                   f[0] = 1
        mov DWORD[rcx + 4], 1;                   f[1] = 1
        
    END:
        ret;                                     RETURN

; PARAMATERS:
; - rcx = numer
; - rdx = denom
global evaluate_fr
evaluate_fr:

	cvtsi2ss xmm0, rcx
    cvtsi2ss xmm1, rdx

	divss xmm0, xmm1
	ret

; PARAMETERS:
; - rcx = int* f1
; - rdx = int* f2
global add_fr
add_fr:

    mov r8d, DWORD[rcx + 4];                     r8d = f1[1] 
    mov r9d, DWORD[rdx + 4];                     r9d = f2[1]

    cmp r8d, r9d;                                r8d != r9d ?
    jne DENOM_NOT_EQUAL_01;                      IF TRUE, JUMP TO LINE 148

    mov r8d, DWORD[rcx + 0];                     r8d = f1[0]
    add r8d, DWORD[rdx + 0];                     r8d += f2[0]

    mov DWORD[rcx + 0], r8d;                     f1[0] = r8d
    ret;                                         RETURN

    DENOM_NOT_EQUAL_01:
		
        mov r8d, DWORD[rcx + 0];                 r8d = f1[0]
        mov r9d, DWORD[rdx + 0];                 r9d = f2[0]

        mov r10d, DWORD[rcx + 4];                r10d = f1[1]
        mov r11d, DWORD[rdx + 4];                r11d = f2[1]

        imul r8d, r11d;                          r8d *= r11d
        imul r9d, r10d;                          r9d *= r10d

        add r8d, r9d;                            r8d += r9d
		imul r10d, r11d;                         r10d *= r11d

		mov DWORD[rcx + 0], r8d;                 f1[0] = r8d
		mov DWORD[rcx + 4], r10d;                f1[1] = r10d

        ret;                                     RETURN

; PARAMETERS:
; - rcx = int* f1
; - rdx = int* f2
global sub_fr
sub_fr:

    mov r8d, DWORD[rcx + 4];                     r8d = f1[1] 
    mov r9d, DWORD[rdx + 4];                     r9d = f2[1]

    cmp r8d, r9d;                                r8d != r9d ?
    jne DENOM_NOT_EQUAL_02;                      IF TRUE, JUMP TO LINE 185

    mov r8d, DWORD[rcx + 0];                     r8d = f1[0]
    sub r8d, DWORD[rdx + 0];                     r8d -= f2[0]

    mov DWORD[rcx + 0], r8d;                     f1[0] = r8d
    ret;                                         RETURN

    DENOM_NOT_EQUAL_02:
		
        mov r8d, DWORD[rcx + 0];                 r8d = f1[0]
        mov r9d, DWORD[rdx + 0];                 r9d = f2[0]

        mov r10d, DWORD[rcx + 4];                r10d = f1[1]
        mov r11d, DWORD[rdx + 4];                r11d = f2[1]

        imul r8d, r11d;                          r8d *= r11d
        imul r9d, r10d;                          r9d *= r10d

        sub r8d, r9d;                            r8d -= r9d
		imul r10d, r11d;                         r10d *= r11d

		mov DWORD[rcx + 0], r8d;                 f1[0] = r8d
		mov DWORD[rcx + 4], r10d;                f1[1] = r10d

        ret;                                     RETURN

; PARAMETERS:
; - rcx = int* f1
; - rdx = int* f2
global mul_fr
mul_fr:

    mov r8d, DWORD[rcx + 0];                     r8d = f1[0]
    mov r9d, DWORD[rcx + 4];                     r9d = f1[1]

    mov r10d, DWORD[rdx + 0];                    r10d = f2[0]
    mov r11d, DWORD[rdx + 4];                    r11d = f2[1]

    imul r8d, r10d;                              r8d *= r10d
    imul r9d, r11d;                              r9d *= r11d

    mov DWORD[rcx + 0], r8d;                     f1[0] = r8d
    mov DWORD[rcx + 4], r9d;                     f1[1] = r9d

    ret;                                         RETURN

; PARAMETERS:
; - rcx = int* f1
; - rdx = int* f2
global div_fr
div_fr:

    mov r8d, DWORD[rcx + 0];                     r8d = f1[0]
    mov r9d, DWORD[rcx + 4];                     r9d = f1[1]

    mov r10d, DWORD[rdx + 0];                    r10d = f2[0]
    mov r11d, DWORD[rdx + 4];                    r11d = f2[1]

    imul r8d, r11d;                              r8d *= r11d
    imul r9d, r10d;                              r9d *= r10d

    mov DWORD[rcx + 0], r8d;                     f1[0] = r8d
    mov DWORD[rcx + 4], r9d;                     f1[1] = r9d

    ret;                                         RETURN