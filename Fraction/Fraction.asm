; Fraction
; Fraction.asm
; Justyn Durnford
; Created on 2020-10-05
; Last updated on 2021-02-27
; Assembly file for the Fraction class.

section .text
bits 64

extern malloc
extern free

; PARAMATERS: 
; - rcx = int64_t* fr
; - rdx = int64_t numer
global set_numer
set_numer:

    mov QWORD[rcx + 0], rdx;           fr[0] = rdx
    ret;                               RETURN

; PARAMATERS: 
; - rcx = int64_t* fr
; - rdx = int64_t denom
global set_denom
set_denom:

    mov QWORD[rcx + 8], rdx;           fr[1] = rdx
    ret;                               RETURN

; PARAMETERS:
; - rcx = int64_t* fr
; - rdx = int64_t numer
; - r8  = int64_t denom
global set_fr
set_fr:

    mov QWORD[rcx + 0], rdx;           fr[0] = numer
    mov QWORD[rcx + 8], r8;            fr[1] = denom
     
    ret;                               RETURN

; PARAMETERS:
; - rcx = int64_t* fr
; - rdx = uint64_t n
global pow_fr
pow_fr:

    cmp rdx, 0;                        n == 0 ?
    je N_IS_0;                         IF TRUE, JUMP TO LINE 75

    cmp rdx, 1;                        n == 1 ?
    je END;                            IF TRUE, JUMP TO LINE 80

    mov r8, QWORD[rcx + 0];            r8 = fr[0]
    mov r9, r8;                        r9 = r8 = fr[0]

    mov r10, QWORD[rcx + 8];           r10 = fr[1]
    mov r11, r10;                      r11 = r10 = fr[2]

    LOOP:

        imul r8d, r9d;                 r8d *= r9d
        imul r10d, r11d;               r10d *= r11d

        sub rdx, 1;                    --n
        cmp rdx, 1;                    n > 1 ?
        jg LOOP;                       IF TRUE, JUMP TO LINE 62

    mov QWORD[rcx + 0], r8;            fr[0] = r8
    mov QWORD[rcx + 8], r10;           fr[1] = r10
    jmp END;                           JUMP TO LINE 80

    N_IS_0:

        mov QWORD[rcx + 0], 1;         fr[0] = 1
        mov QWORD[rcx + 8], 1;         fr[1] = 1
        
    END:
        ret;                           RETURN

; PARAMATERS:
; - rcx = int64_t numer
; - rdx = int64_t denom
global evaluate_fr
evaluate_fr:

	cvtsi2sd xmm0, rcx;                xmm0 = (double)rcx = (double)numer
    cvtsi2sd xmm1, rdx;                xmm1 = (double)rdx = (double)denom

	divsd xmm0, xmm1;                  xmm0 = rcx / rdx
	ret;                               RETURN

; PARAMETERS:
; - rcx = int64_t* fr
; - rdx = int64_t numer
; - r8  = int64_t denom
global add_fr
add_fr:

    cmp QWORD[rcx + 8], r8;            fr[1] != denom ?
    jne DENOM_NOT_EQUAL_01;            IF TRUE, JUMP TO LINE 108

    add QWORD[rcx + 0], rdx;           fr[0] += numer
    ret;                               RETURN

    DENOM_NOT_EQUAL_01:

        mov r10, QWORD[rcx + 0];       r10 = fr[0]
        mov r11, QWORD[rcx + 8];       r11 = fr[1]

        push r10;                      Save r10                                Stack: { fr[0] }
        push r11;                      Save r11                                Stack: { fr[0], fr[1] }

        imul r10, r8;                  r10 *= denom                            Stack: { fr[0], fr[1] }
        imul r11, r8;                  r11 *= denom                            Stack: { fr[0], fr[1] }

        mov QWORD[rcx + 0], r10;       fr[0] = r10                             Stack: { fr[0], fr[1] }
        mov QWORD[rcx + 8], r11;       fr[1] = r11d                            Stack: { fr[0], fr[1] }

        pop r11;                       Retrieve r11                            Stack: { fr[0] }
        pop r10;                       Retrieve r10                            Stack: {}

        imul rdx, r11;                 numer *= fr[1]
        imul r8, r11;                  denom *= fr[1]

        add QWORD[rcx + 0], rdx;       fr[0] += rdx

        ret;                           RETURN

; PARAMETERS:
; - rcx = int64_t* fr
; - rdx = int64_t numer
; - r8  = int64_t denom
global sub_fr
sub_fr:

    cmp QWORD[rcx + 8], r8;            fr[1] != denom ?
    jne DENOM_NOT_EQUAL_02;            IF TRUE, JUMP TO LINE 145

    sub QWORD[rcx + 0], rdx;           fr[0] -= numer
    ret;                               RETURN

    DENOM_NOT_EQUAL_02:

        mov r10, QWORD[rcx + 0];       r10 = fr[0]
        mov r11, QWORD[rcx + 8];       r11 = fr[1]

        push r10;                      Save r10                                Stack: { fr[0] }
        push r11;                      Save r11                                Stack: { fr[0], fr[1] }

        imul r10, r8;                  r10 *= denom                            Stack: { fr[0], fr[1] }
        imul r11, r8;                  r11 *= denom                            Stack: { fr[0], fr[1] }

        mov QWORD[rcx + 0], r10;       fr[0] = r10                             Stack: { fr[0], fr[1] }
        mov QWORD[rcx + 8], r11;       fr[1] = r11                             Stack: { fr[0], fr[1] }

        pop r11;                       Retrieve r11                            Stack: { fr[0] }
        pop r10;                       Retrieve r10                            Stack: {}

        imul rdx, r11;                 numer *= fr[1]
        imul r8, r11;                  denom *= fr[1]

        sub QWORD[rcx + 0], rdx;       fr[0] -= rdx

        ret;                           RETURN

; PARAMETERS:
; - rcx = int64_t* fr
; - rdx = int64_t numer
; - r8  = int64_t denom
global mul_fr
mul_fr:

    mov r10, QWORD[rcx + 0];           r10 = fr[0]
    mov r11, QWORD[rcx + 8];           r11 = fr[1]

    imul r10, rdx;                     r10 *= numer
    imul r11, r8;                      r11 *= denom

    mov QWORD[rcx + 0], r10;           f1[0] = r10
    mov QWORD[rcx + 8], r11;           f1[1] = r911

    ret;                               RETURN

; PARAMETERS:
; - rcx = int64_t* fr
; - rdx = int64_t numer
; - r8 =  int64_t denom
global div_fr
div_fr:

    mov r10, QWORD[rcx + 0];           r10 = fr[0]
    mov r11, QWORD[rcx + 8];           r11 = fr[1]

    imul r10, r8;                      r10 *= denom
    imul r11, rdx;                     r11 *= numer

    mov QWORD[rcx + 0], r10;           f1[0] = r10
    mov QWORD[rcx + 8], r11;           f1[1] = r11

    ret;                               RETURN