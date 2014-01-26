: sign.test
   dup 0= if ." ZERO"      else
       0> if ." POSITIVE"  else 
             ." NEGATIVE"  then then ;
