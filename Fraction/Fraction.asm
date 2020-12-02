; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2020-12-02
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

    push rcx;                          Save rcx (1st parameter);
    push rdx;                          Save rdx (2nd parameter);

    mov ecx, 8;                        ecx = 8

    sub rsp, 32+8;                     Allocate memory to call C function
    call malloc;                       Call malloc(ecx), rax = fr
    add rsp, 32+8;                     Deallocate memory

    pop rdx;                           Restore rdx (2nd parameter)
    pop rcx;                           Restore rcx (1st parameter)

    mov DWORD[rax + 0], ecx;           fr[0] = ecx
    mov DWORD[rax + 4], edx;           fr[1] = edx
	
    ret;                               RETURN

; PARAMATERS:
; - rcx = int* fr
global delete_fr
delete_fr:

    sub rsp, 32+8;                     Allocate memory to call C function
	
    call free;                         Call free(fr)
	
    add rsp, 32+8;                     Deallocate memory
    ret;                               RETURN

; PARAMATERS: 
; - rcx = int* fr
; - edx = int numer
global set_numer
set_numer:

    mov DWORD[rcx + 0], edx;           fr[0] = edx
    ret;                               RETURN

; PARAMATERS: 
; - rcx = int* fr
; - edx = int denom
global set_denom
set_denom:

    mov DWORD[rcx + 4], edx;           fr[1] = edx
    ret;                               RETURN

; PARAMETERS:
; - rcx = int* fr
; - edx = int numer
; - r8d = int denom
global set_fr
set_fr:

    mov DWORD[rcx + 0], edx;           fr[0] = numer
    mov DWORD[rcx + 4], r8d;           fr[1] = denom
     
    ret;                               RETURN

; PARAMETERS:
; - rcx = int* fr
; - edx = unsigned int n
global pow_fr
pow_fr:

    cmp edx, 0;                        n == 0 ?
    je N_IS_0;                         IF TRUE, JUMP TO LINE 110

    cmp edx, 1;                        n == 1 ?
    je END;                            IF TRUE, JUMP TO LINE 115

    mov r8d, DWORD[rcx + 0];           r8d = fr[0]
    mov r9d, r8d;                      r9d = r8d = fr[0]

    mov r10d, DWORD[rcx + 4];          r10d = fr[1]
    mov r11d, r10d;                    r11d = r10d = fr[2]

    LOOP:

        imul r8d, r9d;                 r8d *= r9d
        imul r10d, r11d;               r10d *= r11d

        sub edx, 1;                    --n
        cmp edx, 1;                    n > 1 ?
        jg LOOP;                       IF TRUE, JUMP TO LINE 97

    mov DWORD[rcx + 0], r8d;           fr[0] = r8d
    mov DWORD[rcx + 4], r10d;          fr[1] = r10d
    jmp END;                           JUMP TO LINE 115

    N_IS_0:

        mov DWORD[rcx + 0], 1;         fr[0] = 1
        mov DWORD[rcx + 4], 1;         fr[1] = 1
        
    END:
        ret;                           RETURN

; PARAMATERS:
; - rcx = numer
; - rdx = denom
global evaluate_fr
evaluate_fr:

	cvtsi2ss xmm0, rcx;                xmm0 = (float)rcx = (float)numer
    cvtsi2ss xmm1, rdx;                xmm1 = (float)rdx = (float)denom

	divss xmm0, xmm1;                  xmm0 = rcx / rdx
	ret;                               RETURN

; PARAMETERS:
; - rcx = int* fr
; - edx = int numer
; - r8d = int denom
global add_fr
add_fr:

    cmp DWORD[rcx + 4], r8d;           fr[1] != denom ?
    jne DENOM_NOT_EQUAL_01;            IF TRUE, JUMP TO LINE 143

    add DWORD[rcx + 0], edx;           fr[0] += numer
    ret;                               RETURN

    DENOM_NOT_EQUAL_01:

        mov r10d, DWORD[rcx + 0];      r10d = fr[0]
        mov r11d, DWORD[rcx + 4];      r11d = fr[1]

        push r10;                      Save r10                                Stack: { fr[0] }
        push r11;                      Save r11                                Stack: { fr[0], fr[1] }

        imul r10d, r8d;                r10d *= denom                           Stack: { fr[0], fr[1] }
        imul r11d, r8d;                r11d *= denom                           Stack: { fr[0], fr[1] }

        mov DWORD[rcx + 0], r10d;      fr[0] = r10d                            Stack: { fr[0], fr[1] }
        mov DWORD[rcx + 4], r11d;      fr[1] = r11d                            Stack: { fr[0], fr[1] }

        pop r11;                       Retrieve r11                            Stack: { fr[0] }
        pop r10;                       Retrieve r10                            Stack: {}

        imul edx, r11d;                numer *= fr[1]
        imul r8d, r11d;                denom *= fr[1]

        add DWORD[rcx + 0], edx;       fr[0] += edx

        ret;                           RETURN

; PARAMETERS:
; - rcx = int* fr
; - edx = int numer
; - r8d = int denom
global sub_fr
sub_fr:

    cmp DWORD[rcx + 4], r8d;           fr[1] != denom ?
    jne DENOM_NOT_EQUAL_02;            IF TRUE, JUMP TO LINE 180

    sub DWORD[rcx + 0], edx;           fr[0] -= numer
    ret;                               RETURN

    DENOM_NOT_EQUAL_02:

        mov r10d, DWORD[rcx + 0];      r10d = fr[0]
        mov r11d, DWORD[rcx + 4];      r11d = fr[1]

        push r10;                      Save r10                                Stack: { fr[0] }
        push r11;                      Save r11                                Stack: { fr[0], fr[1] }

        imul r10d, r8d;                r10d *= denom                           Stack: { fr[0], fr[1] }
        imul r11d, r8d;                r11d *= denom                           Stack: { fr[0], fr[1] }

        mov DWORD[rcx + 0], r10d;      fr[0] = r10d                            Stack: { fr[0], fr[1] }
        mov DWORD[rcx + 4], r11d;      fr[1] = r11d                            Stack: { fr[0], fr[1] }

        pop r11;                       Retrieve r11                            Stack: { fr[0] }
        pop r10;                       Retrieve r10                            Stack: {}

        imul edx, r11d;                numer *= fr[1]
        imul r8d, r11d;                denom *= fr[1]

        sub DWORD[rcx + 0], edx;       fr[0] -= edx

        ret;                           RETURN

; PARAMETERS:
; - rcx = int* fr
; - edx = int numer
; - r8d = int denom
global mul_fr
mul_fr:

    mov r10d, DWORD[rcx + 0];          r10d = fr[0]
    mov r11d, DWORD[rcx + 4];          r11d = fr[1]

    imul r10d, edx;                    r10d *= numer
    imul r11d, r8d;                    r11d *= denom

    mov DWORD[rcx + 0], r10d;          f1[0] = r10d
    mov DWORD[rcx + 4], r11d;          f1[1] = r911d

    ret;                               RETURN

; PARAMETERS:
; - rcx = int* fr
; - edx = int numer
; - r8d = int denom
global div_fr
div_fr:

    mov r10d, DWORD[rcx + 0];          r10d = fr[0]
    mov r11d, DWORD[rcx + 4];          r11d = fr[1]

    imul r10d, r8d;                    r10d *= denom
    imul r11d, edx;                    r11d *= numer

    mov DWORD[rcx + 0], r10d;          f1[0] = r10d
    mov DWORD[rcx + 4], r11d;          f1[1] = r911d

    ret;                               RETURN