: star    [char] * emit ;
: oldstars   0 ?do  star  loop ;
: stars   dup 0= invert if oldstars  then ;
