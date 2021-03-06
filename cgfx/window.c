#include <cgfx.h>

/***************************************
 * Standard Windowing Functions (MW C) *
 * Copyright (c) 1989 by Mike Sweet    *
 ***************************************/

asm error_code
_cgfx_dwset(path_id path, int sty, int cpx, int cpy, int szx, int szy, int fprn, int bprn, int bdprn)
{
	asm
	{
_Flush EXTERNAL
        pshs y
        lbsr _Flush
        leas -10,s
        ldy #10
        ldd #$1b20
        std ,s
        lda 17,s
        bne d0
        leay -1,y
d0      ldb 19,s
        std 2,s
        lda 21,s
        ldb 23,s
        std 4,s
        lda 25,s
        ldb 27,s
        std 6,s
        lda 29,s
        ldb 31,s
        std 8,s
        lda 15,s
        leax ,s
        os9 I$Write
        leas 10,s
        bra os9err0
    }
}

asm error_code
_cgfx_dwend(path_id path)
{
	asm
	{
        lbsr _Flush
        pshs y
        ldd #$1b24
        pshs d
        leax ,s
        ldy #2
        lda 7,s
        os9 I$Write
        leas 2,s
        bra os9err0
    }
}

asm error_code
_cgfx_dwprotsw(path_id path, int bsw)
{
	asm
	{
_sysret	EXTERNAL
        pshs y
        lbsr _Flush
        lda 7,s
        pshs a
        ldd #$1b36
        pshs d
        lda 8,s
        ldy #3
        leax ,s
        os9 I$Write
        leas 3,s
os9err0 puls y
		lbra	_sysret
    }
}

asm error_code
_cgfx_owset(path_id path, int svs, int cpx, int cpy, int szx, int szy, int fprn, int bprn)
{
	asm
	{
        pshs y
        lbsr _Flush
        leas -9,s
        lda 16,s
        ldb 18,s
        std 2,s
        lda 20,s
        ldb 22,s
        std 4,s
        lda 24,s
        ldb 26,s
        std 6,s
        lda 28,s
        sta 8,s
        ldd #$1b22
        std ,s
        ldy #9
        leax ,s
        lda 14,s
        os9 I$Write
        leas 9,s
        lbra os9err0
    }
}

asm error_code
_cgfx_mvowend(path_id path)
{
	asm
	{
        pshs y
        lbsr _Flush
        lda 5,s
        ldb #$86 first _ss_wset the overlay to no box...
        ldy #0
        os9 I$SetStt
        bra o0 then do OWEnd....
     }
}

asm error_code
_cgfx_owend(path_id path)
{
	asm
	{
        pshs y
        lbsr _Flush
o0      ldd #$1b23
        pshs d
        lda 7,s
        ldy #2
        leax ,s
        os9 I$Write
        leas 2,s
        lbra os9err0
    }
}

asm error_code
_cgfx_select(path_id path)
{
	asm
	{
        pshs y
        lbsr _Flush
        ldd #$1b21
        pshs d
        leax ,s
        lda 7,s
        ldy #2
        os9 I$Write
        leas 2,s
        lbra os9err0
    }
}        

asm error_code
_cgfx_cwarea(path_id path, int cpx, int cpy, int szx, int szy)
{
	asm
	{
        pshs y
        lbsr _Flush
        leas -6,s
        lda 13,s
        ldb 15,s
        std 2,s
        lda 17,s
        ldb 19,s
        std 4,s
        ldd #$1b25
        std ,s
        lda 11,s
        ldy #6
        leax ,s
        os9 I$Write
        leas 6,s
        lbra os9err0
    }
}
