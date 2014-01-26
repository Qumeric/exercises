: within ( n l h -- bool)
   rot dup -rot > rot 1 - rot < and ;

: 3dup ( a b c -- a b c a b c )
   dup 2over rot ;

: alleq ( a b c -- eq? )
   over = -rot = and ;

: trap ( a a b c -- a a )
   3dup alleq
   if ." YOU GOT IT!" drop drop else
      within if ." BETWEEN" else ." NOT BETWEEN" then dup
   then ;

: start dup ;
