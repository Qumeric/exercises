: speller       dup -4 = if ." negative four"   else
                dup -3 = if ." negative three"  else
                dup -2 = if ." negative two"    else
                dup -1 = if ." negative one"    else
                dup 0  = if ." zero"            else
                dup 1  = if ." one"             else
                dup 2  = if ." two"             else
                dup 3  = if ." three"           else
                dup 4  = if ." four"            else
                            ." out of range" 
                then then then then then then then then then drop ;
