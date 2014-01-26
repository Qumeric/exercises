57 page
: guess   2dup = if ." correct" else
          2dup < if ." too big" else
          2dup > if ." too low"
          then then then drop ;
