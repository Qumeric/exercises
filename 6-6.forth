include 6-1.forth
: triangle ( step to from -- )
    2dup max 1 - >r 
    rot dup -1 = if -rot 1 - else -rot then
    do cr j i - spaces i 2 * 1 - stars j i - spaces dup +loop
    r> drop ;

: diamond 
    1 10 1 triangle
   -1 1 10 triangle ;

: diamonds 0 do diamond loop ;
