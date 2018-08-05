#include <string.h>

/*
*** strncat(t, f, n)
*    copies at most n chars from f to the end of t
*/
__norts__ asm
char *strncat(char *t, char *f, size_t n)
{
	asm {
strncat EXPORT
strncat: pshs  y,u 
 ldu   8,s f
 ldx   6,s t
 ldy   10,s n
 beq   @strncat4 if null length
@strncat1 ldb   ,x+ find end of t
 bne   @strncat1 
 leax  -1,x back to null
@strncat2 ldb   ,u+ f char
 stb   ,x+ put in t
 leay  -1,y n-=1
 beq   @strncat3 if done
 tstb   
 bne   @strncat2 if not null on f
@strncat3 clr   ,x terminate
@strncat4 ldd   6,s * ldd 4,s t
 puls  y,u,pc 
	}
}
