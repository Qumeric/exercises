Fundamental Forth
=================

Words
-----
<x> emit                    type a symbol with charcode x
<x> spaces                  type x spaces
space                       1 spaces
: <name>   <command> ;      assign command to name
CR                          '\n'
<number> do <command> loop  ?
[char] <char>               return keycode
." <string>"                print string, last mark called "delimiter"
<stack> .[S]                [!]remove number from stack and print it


Internals
---------
INTERPRET finds words and pass them to EXECUTE if the word was found in dictionary or to NUMBER in other case.
: writes down word into dictionary and stops when ; occur.

Other
-----
Words can contain all symbols expect space, backspace and return.
Words shouldn't be longer than 30 symbols.
Glossary - list of words.

### Stack notation
It's kinda comments of Forth
Syntax:     <command> ( <before> -- <after> )
Example:    24 emit   (n -- )

Rightmost item located on the top of the stack.
n means number, c mean character, d means double, f means boolean.


How To Get Results
==================

Integer Arithmetic
------------------
+ - * / > = < (a b -- result)
[/]mod  (a b -- rem [quot])

Stack manipulations
-------------------
[2]swap (a b -- b a)
[2]dup  (n -- n n)
[2]over (a b -- a b a)
rot     (a b c -- b c a)
[2]drop (n --)
"2" versions work with pairs of numbers.

The Editor (And Staff)
======================

Words
-----
forget <word>       remove _last_ meaning of the word.
marker <-word>      return to the system state on the marker's line.
include<filename>  import a file
type                ???


### Forth as OS ???
use <block>
<n> list            show what block <n> contains.
<n> loas            run block <n>.
<n> block           save file as block
update              update modified blocks in buffer
flush               write updates at buffer
empty-buffers       rollback updates


Decisions
=========

Conditions
----------
if <cmd>    if true execute cmd.
else        self-descriptive.
then        return to normal flow (use in if).
invert      logical NOT

Boolean Type
------------
true        all bits are 1. (-1 and ALL others)
false       all bits are 0. (0)

### Logic
and or

Other
-----
: ?dup   =0 invert if dup then ;

abort" <error>" exit with error if true.
?stack          check for stack underflow ???
page            clear terminal screen


The Philosopy of Fixed Point
============================

Operators
---------
abs     ( n -- |n|   )
negate  ( n -- -n    )
min     ( a b -- min )
max     ( a b -- max )
*/      ( a b c -- a*b/c )
*/MOD   ( a b c -- rem a*b/c )

Return Stack
---------------
>R  ( n --   )      move from parameter stack to return stack
R>  (   -- n )      move from return stack to parameter stack
I   (   -- n )      copy from return stack
R@  (   -- n )      I???
J   (   -- n )      copy third item from return stack

Throw it for a Loop
===================

<limit> <index> [?]do ... loop
values of loop (limit, index) contained in return stack (get it with i).

begin xxx f until               when f is true loop ends
begin xxx f while yyy repeat    ???

u.r (u width -- )               . for tables
leave                           end loop
quit exit
