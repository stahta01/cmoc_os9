#include <string.h>

/*** strcmp(s1,s2)
*    compare s2 to s1 thru null on s2
*    return null if s2 matches s1
*      else s1(i) - s2(i) where i is index at miss
*     stack   s2
*             s1
*            ret
*         ->  u
*/
__norts__ asm
int   strcmp(char *s1, char *s2)
{
	asm {
 pshs  u 
 ldx   4,s *s1
 ldu   6,s *s2
 bra   strcmp2 

strcmp1 ldb   ,u+ check null & bump *s2
 beq   strcmp3 if EOS
strcmp2 ldb   ,u s2 char
 subb  ,x+ check same & bump pnt
 beq   strcmp1 if same
 negb reverse sign of result 
strcmp3 sex    
 puls  u,pc 

	}
}
