###!----------------------------------------------------
###! CLASSE EXPRESSIO
###!----------------------------------------------------
###!
###!-----------------------
###1 Constructora con token
###!-----------------------
###!
#init T token SUMA
#init E expressio T
Error::expressio:31:Error sintactic.
##Error::expressio:31:Error sintactic.
#T destroy
###!
#init T token 3
#init E expressio T
#T destroy
#E destroy
###!
#init R racional 3 5
#init T token R
#init E expressio T
#R destroy
#T destroy
#E destroy
###!
#init T token 3.5
#init E expressio T
#T destroy
#E destroy
###!
#init T token CT_E
#init E expressio T
#T destroy
#E destroy
###!
#init T token X
#init E expressio T
#T destroy
#E destroy
###!
#init T token VAR_PORCENTAJE
#init E expressio T
#T destroy
#E destroy
###!
###!
###!
###!------------------------------
###2 Constructora con lista tokens
###!------------------------------
###!
#init L list<token>
#init E expressio L
Error::expressio:31:Error sintactic.
##Error::expressio:31:Error sintactic.
#L destroy
###!
#init T token OBRIR_PAR
#init L list<token>
#il T
#init E expressio L
Error::expressio:31:Error sintactic.
##Error::expressio:31:Error sintactic.
#T destroy
#L destroy
###!
#init T1 token "1"
#init T2 token "1"
#init T3 token SUMA
#init T4 token "2"
#init L list<token>
#il T1
#il T2
#il T3
#il T4
#init E expressio L
Error::expressio:31:Error sintactic.
##Error::expressio:31:Error sintactic.
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
###!
#init T1 token OBRIR_PAR
#init T2 token "1"
#init T3 token SUMA
#init T4 token "2"
#init L list<token>
#il T1
#il T2
#il T3
#il T4
#init E expressio L
Error::expressio:31:Error sintactic.
##Error::expressio:31:Error sintactic.
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
###!
#init R racional 3 5
#init T1 token "5"
#init T2 token EXPONENCIACIO
#init T3 token R
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#R destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
###!
###!
###!------------
###3 bool
###!------------
###!
###!------------
###3.1 buida
###!------------
###!
#init T token
#init E expressio T
#enula
true
##true
#T destroy
#E destroy
###!
#init E expressio
#enula
true
##true
#E destroy
###!
###!
###!------------
###3.2 no buida
###!------------
###!
#init T token 2
#init E expressio T
#E enula
false
##false
#T destroy
#E destroy
###!
#init T token "v"
#init E expressio T
#enula
false
##false
#T destroy
#E destroy
###!
#init T token "v"
#init L list<token>
#il T
#init E expressio L
#enula
false
##false
#T destroy
#L destroy
#E destroy
###!
###!
###!
###!------------
###4 ==
###!------------
###!
###!------------
###4.1 cert
###!------------
###!
#init E1 expressio
#init E2 expressio
#E1 == E2
true
##true
#E1 destroy
#E2 destroy
###!
#init T token "v"
#init E1 expressio T
#init E2 expressio T
#E1 == E2
true
##true
#T destroy
#E1 destroy
#E2 destroy
###!
#init T token "v"
#init L list<token>
#il T
#init E1 expressio L
#init E2 expressio T
#E1 == E2
true
##true
#T destroy
#L destroy
#E1 destroy
#E2 destroy
###!
#init R racional 3 5
#init T token R
#init L list<token>
#il T
#init E1 expressio L
#init E2 expressio L
#E1 == E2
true
##true
#R destroy
#T destroy
#L destroy
#E1 destroy
#E2 destroy
###!
#init R1 racional 3 5
#init R2 racional 3 5
#init T1 token R1
#init T2 token R2
#init L1 list<token>
#il T1
#init E1 expressio L1
#init E2 expressio T2
#E1 == E2
true
##true
#R1 destroy
#R2 destroy
#T1 destroy
#T2 destroy
#L1 destroy
#E1 destroy
#E2 destroy
###!
#init R1 racional 3 5
#init R2 racional 3 5
#init T1 token R1
#init T2 token R2
#init T3 token SUMA
#init L1 list<token>
#il T1
#il T3
#il T2
#init L2 list<token>
#il T1
#il T3
#il T2
#init E1 expressio L1
#init E2 expressio L2
#E1 == E2
true
##true
#R1 destroy
#R2 destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
#init T1 token SUMA
#init T2 token MULTIPLICACIO
#init T3 token 2
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token 3
#init L1 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#init E1 expressio L1
#init L2 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#init E2 expressio L2
#E1 == E2
true
##true
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
###!
###!------------
###4.2 fals
###!------------
###!
#init T token "v"
#init E1 expressio 
#init E2 expressio T
#E1 == E2
false
##false
#T destroy
#E1 destroy
#E2 destroy
###!
#init T token "v"
#init L list<token>
#il T
#init E1 expressio 
#init E2 expressio L
#E1 == E2
false
##false
#T destroy
#L destroy
#E1 destroy
#E2 destroy
###!
#init T1 token "v"
#init T2 token 3
#init E1 expressio T1
#init E2 expressio T2
#E1 == E2
false
##false
#T1 destroy
#T2 destroy
#E1 destroy
#E2 destroy
###!
#init R1 racional 3 5
#init R2 racional 3 5
#init T1 token R1
#init T2 token R2
#init T3 token SUMA
#init L1 list<token>
#il T1
#il T3
#il T2
#init L2 list<token>
#il T2
#il T3
#il T1
#init E1 expressio L1
#init E2 expressio L2
#E1 == E2
true
##true
#R1 destroy
#R2 destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
#init T1 token SUMA
#init T2 token MULTIPLICACIO
#init T3 token 2
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token 3
#init L1 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#init E1 expressio L1
#init L2 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T6
#il T5
#il T5
#init E2 expressio L2
#E1 == E2
false
##false
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
###!
###!
###!------------
###5 !=
###!------------
###!
###!------------
###5.1 cert
###!------------
###!
#init T token "b"
#init E1 expressio 
#init E2 expressio T
#E1 != E2
true
##true
#T destroy
#E1 destroy
#E2 destroy
###!
#init T token "v"
#init L list<token>
#il T
#init E1 expressio 
#init E2 expressio L
#E1 != E2
true
##true
#T destroy
#L destroy
#E1 destroy
#E2 destroy
###!
#init T1 token "v"
#init T2 token 3
#init E1 expressio T1
#init E2 expressio T2
#E1 != E2
true
##true
#T1 destroy
#T2 destroy
#E1 destroy
#E2 destroy
###!
#init R1 racional 3 5
#init R2 racional 3 5
#init T1 token R1
#init T2 token R2
#init T3 token SUMA
#init L1 list<token>
#il T1
#il T3
#il T2
#init L2 list<token>
#il T2
#il T3
#il T1
#init E1 expressio L1
#init E2 expressio L2
#E1 != E2
false
##false
#R1 destroy
#R2 destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
#init T1 token SUMA
#init T2 token MULTIPLICACIO
#init T3 token 2
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token 3
#init L1 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#init E1 expressio L1
#init L2 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T6
#il T5
#il T5
#init E2 expressio L2
#E1 != E2
true
##true
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
###!
###!------------
###5.2 fals
###!------------
###!
###!init E1 expressio
###!init E2 expressio
###!E1 != E2
###!#false
###!E1 destroy
###!E2 destroy
###!
###!init L list<token>
###!init E1 expressio L
###!init E2 expressio
###!E1 != E2
###!#false
###!L destroy
###!E1 destroy
###!E2 destroy
###!
#init T token "v"
#init E1 expressio T
#init E2 expressio T
#E1 != E2
false
##false
#T destroy
#E1 destroy
#E2 destroy
###!
#init T token "v"
#init L list<token>
#il T
#init E1 expressio L
#init E2 expressio T
#E1 != E2
false
##false
#T destroy
#L destroy
#E1 destroy
#E2 destroy
###!
#init R racional 3 5
#init T token R
#init L list<token>
#il T
#init E1 expressio L
#init E2 expressio L
#E1 != E2
false
##false
#R destroy
#T destroy
#L destroy
#E1 destroy
#E2 destroy
###!
#init R1 racional 3 5
#init R2 racional 3 5
#init T1 token R1
#init T2 token R2
#init L1 list<token>
#il T1
#init E1 expressio L1
#init E2 expressio T2
#E1 != E2
false
##false
#R1 destroy
#R2 destroy
#T1 destroy
#T2 destroy
#L1 destroy
#E1 destroy
#E2 destroy
###!
#init R1 racional 3 5
#init R2 racional 3 5
#init T1 token R1
#init T2 token R2
#init T3 token SUMA
#init L1 list<token>
#il T1
#il T3
#il T2
#init L2 list<token>
#il T1
#il T3
#il T2
#init E1 expressio L1
#init E2 expressio L2
#E1 != E2
false
##false
#R1 destroy
#R2 destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
#init T1 token SUMA
#init T2 token MULTIPLICACIO
#init T3 token 2
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token 3
#init L1 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#init E1 expressio L1
#init L2 list<token>
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#il T1
#il T4
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T1
#il T4
#il T3
#il T1
#il T3
#il T5
#il T2
#il T4
#il T3
#il T1
#il T3
#il T5
#il T5
#init E2 expressio L2
#E1 != E2
false
##false
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L1 destroy
#L2 destroy
#E1 destroy
#E2 destroy
###!
###!
###!
###!------------
###6 vars
###!------------
###!
###!---------------------
###6.1 buida
###!---------------------
###!
#init E expressio
#E varsp

##
#E destroy
###!
###!
###!---------------------
###6.2 una variable
###!---------------------
###!
#init T token "x"
#init E expressio T
#E varsp
x
##x
#T destroy
#E destroy
###!
#init T token "x"
#init L list<token>
#il T
#init E expressio L
#E varsp
x
##x
#T destroy
#L destroy
#E destroy
###!
#init T1 token "x"
#init T2 token SUMA
#init L list<token>
#il T1
#il T2
#il T1
#init E expressio L
#E varsp
x
##x
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###6.3 dues variables
###!---------------------
###!
#init T1 token "x"
#init T2 token SUMA
#init T3 token "y"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E varsp
x y
##x y
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "x"
#init T2 token SUMA
#init T3 token "y"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E varsp
x y
##x y
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "x"
#init T2 token SUMA
#init T3 token "y"
#init L list<token>
#il T1
#il T2
#il T1
#il T2
#il T1
#il T2
#il T1
#il T2
#il T1
#il T2
#il T3
#init E expressio L
#E varsp
x y
##x y
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###6.4 tres variables
###!---------------------
###!
#init T1 token "x"
#init T2 token SUMA
#init T3 token "y"
#init T4 token "z"
#init L list<token>
#il T1
#il T2
#il T3
#il T2
#il T4
#init E expressio L
#E varsp
x y z
##x y z
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token "x"
#init T2 token SUMA
#init T3 token "y"
#init T4 token "z"
#init L list<token>
#il T4
#il T2
#il T3
#il T2
#il T1
#init E expressio L
#E varsp
x y z
##x y z
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token "x"
#init T2 token SUMA
#init T3 token "y"
#init T4 token "z"
#init L list<token>
#il T3
#il T2
#il T1
#il T2
#il T4
#init E expressio L
#E varsp
x y z
##x y z
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
###!
###!
###!---------------------
###7 apply_substitution
###!---------------------
###!
###!---------------------
###7.1 no variable
###!---------------------
###!
###!init E1 expressio
###!init T token 5
###!init E2 expressio T
###!E1 asubsp "v" E2
###!#
###!T destroy
###!E1 destroy
###!E2 destroy
###!
###!init E1 expressio
###!init T token 5
###!init E2 expressio T
###!E2 asubsp "v" E1
###!#5
###!T destroy
###!E1 destroy
###!E2 destroy
###!
###! si variable
###!
###!init E1 expressio
###!init T token "v"
###!init E2 expressio T
###!E2 asubsp "v" E1
###!#
###!T destroy
###!E1 destroy
###!E2 destroy
###!
#init T token 5
#init E1 expressio T
#init T1 token "v"
#init E2 expressio T1
#E2 asubsp "v" E1
5
##5
#T destroy
#T1 destroy
#E1 destroy
#E2 destroy
###!
#init T token 5
#init E1 expressio T
#init T1 token "v"
#init E2 expressio T1
#E2 asubsp "v" E1
5
##5
#T destroy
#T1 destroy
#E1 destroy
#E2 destroy
###!
#init T token "v"
#init E2 expressio T
#E2 asubsp "v" E2
v
##v
#T destroy
#E2 destroy
###!
#init T1 token SUMA
#init T2 token "xa"
#init T3 token "ya"
#init T4 token "za"
#init T5 token "ta"
#init T6 token "ua"
#init T7 token "va"
#init T8 token "wa"
#init T9 token "xb"
#init T10 token "yb"
#init T11 token "zb"
#init T12 token "tb"
#init T13 token "ub"
#init T14 token "vb"
#init T15 token "wb"
#init T16 token "xc"
#init T17 token "wc"
#init L list<token>
#il T17
#il T1
#il T2
#il T1
#il T16
#il T1
#il T3
#il T1
#il T15
#il T1
#il T4
#il T1
#il T14
#il T1
#il T5
#il T1
#il T13
#il T1
#il T6
#il T1
#il T12
#il T1
#il T7
#il T1
#il T11
#il T1
#il T8
#il T1
#il T10
#il T1
#il T9
#il T1
#il T9
#il T1
#il T4
#il T1
#il T11
#il T1
#il T2
#init E1 expressio L
#E1 asubsp "w3" E1
wc + xa + xc + ya + wb + za + vb + ta + ub + ua + tb + va + zb + wa + yb + xb + xb + za + zb + xa
##wc + xa + xc + ya + wb + za + vb + ta + ub + ua + tb + va + zb + wa + yb + xb + xb + za + zb + xa
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#T10 destroy
#T11 destroy
#T12 destroy
#T13 destroy
#T14 destroy
#T15 destroy
#T16 destroy
#T17 destroy
#L destroy
#E1 destroy
###!
#init T3 token "y"
#init T6 token "r"
#init T7 token SUMA
#init L list<token>
#il T6
#il T7
#il T6
#init L1 list<token>
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#il T7
#il T3
#init E1 expressio L
#init E2 expressio L1
#E2 asubsp "y" E1
r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r
##r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r + r
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#L1 destroy
#E1 destroy
#E2 destroy
###!
###!
###!---------------------
###8 simplify_one_step
###!---------------------
###!
#init E expressio
#E sosp
NULLTOK
##NULLTOK
#E destroy
###!
#init T token "v"
#init E expressio T
#E sosp
v
##v
#T destroy
#E destroy
###!
###!
###!---------------------
###8.1 suma
###!---------------------
###!
#init T1 token "0"
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E sosp
2 * v
##2 * v
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token SUMA
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#E sosp
v - v
##v - v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token SUMA
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T4
#il T1
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#E sosp
v - v
##v - v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E sosp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E sosp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E sosp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E sosp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E sosp
( w + x ) / v
##( w + x ) / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.2 resta
###!---------------------
###!
#init T1 token "0"
#init T2 token RESTA
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
- v
##- v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token RESTA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token RESTA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E sosp
0
##0
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token RESTA
#init T2 token CANVI_DE_SIGNE
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T1
#il T4
#il T2
#il T3
#il T5
#init E expressio L
#E sosp
v + v
##v + v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
###!
#init T1 token RESTA
#init T2 token CANVI_DE_SIGNE
#init T3 token "v"
#init L list<token>
#il T3
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
v + v
##v + v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E sosp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E sosp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E sosp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E sosp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E sosp
( w - x ) / v
##( w - x ) / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.3 canvi de signe
###!---------------------
###!
#init T1 token "w"
#init T2 token CANVI_DE_SIGNE
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init L list<token>
#il T2
#il T6
#il T2
#il T1
#il T7
#init E expressio L
#E sosp
w
##w
#T1 destroy
#T2 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SIGNE_POSITIU
#init L list<token>
#il T2
#il T1
#init E expressio L
#E sosp
w
##w
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token CANVI_DE_SIGNE
#init L list<token>
#il T2
#il T1
#init E expressio L
#E sosp
-5
##-5
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 4.56
#init T2 token CANVI_DE_SIGNE
#init L list<token>
#il T2
#il T1
#init E expressio L
#E sosp
-4.560000
##-4.560000
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token CANVI_DE_SIGNE
#init T3 token SQRT
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T4
#il T2
#il T1
#il T5
#init E expressio L
#E sosp
sqrt ( -5 )
##sqrt ( -5 )
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.4 multiplicacion
###!---------------------
###!
#init T1 token "0"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E sosp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E sosp
v ^ 2
##v ^ 2
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T5
#init E expressio L
#E sosp
- ( v * w )
##- ( v * w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#E sosp
- ( v * v )
##- ( v * v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T4
#il T1
#il T6
#il T5
#il T2
#il T3
#init E expressio L
#E sosp
- ( w * v )
##- ( w * v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T4
#il T1
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#E sosp
- ( v * v )
##- ( v * v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init T7 token "w"
#init L list<token>
#il T7
#il T2
#il T4
#il T1
#il T6
#il T3
#il T5
#init E expressio L
#E sosp
w / v
##w / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T3
#il T5
#init E expressio L
#E sosp
v / v
##v / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init T7 token "w"
#init L list<token>
#il T4
#il T1
#il T6
#il T3
#il T5
#il T2
#il T7
#init E expressio L
#E sosp
w / v
##w / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init L list<token>
#il T4
#il T1
#il T6
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#E sosp
v / v
##v / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T6 token EXPONENCIACIO
#init T7 token "w"
#init L list<token>
#il T3
#il T6
#il T7
#il T2
#il T7
#il T6
#il T7
#init E expressio L
#E sosp
( v * w ) ^ w
##( v * w ) ^ w
#T2 destroy
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T6 token EXPONENCIACIO
#init T7 token "w"
#init L list<token>
#il T3
#il T6
#il T7
#il T2
#il T3
#il T6
#il T3
#init E expressio L
#E sosp
v ^ ( w + v )
##v ^ ( w + v )
#T2 destroy
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.5 division
###!---------------------
###!
#init T1 token "0"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E sosp
Error::expressio:33:Divisio per zero.
##Error::expressio:33:Divisio per zero.
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E sosp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#E sosp
- ( v / v )
##- ( v / v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T5
#init E expressio L
#E sosp
- ( v / w )
##- ( v / w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T2
#il T6
#il T5
#init E expressio L
#E sosp
v * w
##v * w
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T2
#il T3
#il T5
#init E expressio L
#E sosp
v * v
##v * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token EXPONENCIACIO
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T1
#il T6
#il T2
#il T6
#il T1
#il T6
#init E expressio L
#E sosp
( v / w ) ^ w
##( v / w ) ^ w
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token EXPONENCIACIO
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T1
#il T6
#il T2
#il T3
#il T1
#il T3
#init E expressio L
#E sosp
v ^ ( w - v )
##v ^ ( w - v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.6 exponenciacio
###!---------------------
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 0.5
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
Error::expressio:32:Negatiu elevat a no enter.
##Error::expressio:32:Negatiu elevat a no enter.
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token -4
#init T2 token EXPONENCIACIO
#init T3 token 1.34
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
Error::expressio:32:Negatiu elevat a no enter.
##Error::expressio:32:Negatiu elevat a no enter.
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 0
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 2
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
9
##9
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token 1
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E sosp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token CANVI_DE_SIGNE
#init T4 token "w"
#init L list<token>
#il T1
#il T2
#il T3
#il T4
#init E expressio L
#E sosp
1 / v ^ w
##1 / v ^ w
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token "z"
#init T4 token "w"
#init T5 token OBRIR_PAR
#init T6 token TANCAR_PAR
#init L list<token>
#il T5
#il T1
#il T2
#il T3
#il T6
#il T2
#il T4
#init E expressio L
#E sosp
v ^ ( z * w )
##v ^ ( z * w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.7 radicacion
###!---------------------
###!
#init T1 token SQRT
#init T2 token -0.5
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E sosp
Error::expressio:35:Arrel quadrada de negatiu.
##Error::expressio:35:Arrel quadrada de negatiu.
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token -5
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E sosp
Error::expressio:35:Arrel quadrada de negatiu.
##Error::expressio:35:Arrel quadrada de negatiu.
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token 0
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E sosp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token "v"
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E sosp
v ^ ( 1/2 )
##v ^ ( 1/2 )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token 25
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E sosp
25 ^ ( 1/2 )
##25 ^ ( 1/2 )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###8.8 regla 1
###!---------------------
###!
#init T1 token 5
#init T2 token 0
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
Error::expressio:33:Divisio per zero.
##Error::expressio:33:Divisio per zero.
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init R racional 0 4
#init T1 token 5
#init T2 token R
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
5 / 0
##5 / 0
#R destroy
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token 2
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
5/2
##5/2
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 10
#init T2 token 5
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
2
##2
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 10
#init T2 token 5.0
#init T4 token SUMA
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
10 + 5.000000
##10 + 5.000000
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 2
#init T2 token 1
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
2
##2
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 10
#init T2 token 5.0
#init T4 token RESTA
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E sosp
10 - 5.000000
##10 - 5.000000
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T9
#il T1
#il T7
#init E expressio L
#E sosp
w ^ ( 2 * v + v + v - w )
##w ^ ( 2 * v + v + v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token 2
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T5
#il T4
#il T3
#il T2
#il T3
#il T2
#il T3
#il T9
#il T1
#il T7
#init E expressio L
#E sosp
w ^ ( 2 * v + v + v - w )
##w ^ ( 2 * v + v + v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token 2
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T6
#il T5
#il T4
#il T3
#il T7
#il T2
#il T6
#il T5
#il T4
#il T3
#il T7
#il T9
#il T1
#il T7
#init E expressio L
#E sosp
w ^ ( 2 * 2 * v - w )
##w ^ ( 2 * 2 * v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init L list<token>
#il T1
#il T8
#il T6
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T1
#il T7
#init E expressio L
#E sosp
w ^ ( 0 - v - v - w )
##w ^ ( 0 - v - v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token 0
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init L list<token>
#il T1
#il T8
#il T6
#il T5
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T7
#init E expressio L
#E sosp
w ^ ( - v - v - v )
##w ^ ( - v - v - v )
#E sosp
w ^ ( - v - v - v )
##w ^ ( - v - v - v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token CANVI_DE_SIGNE
#init L list<token>
#il T1
#il T4
#il T6
#il T9
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T1
#il T7
#init E expressio L
#E sosp
w * ( - v - v - v - v - w )
##w * ( - v - v - v - v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T6
#il T3
#il T4
#il T3
#il T2
#il T3
#il T4
#il T3
#il T7
#il T9
#il T1
#il T7
#init E expressio L
#E sosp
w ^ ( v ^ 2 + v * v - w )
##w ^ ( v ^ 2 + v * v - w )
#E sosp
w ^ ( v ^ 2 + v ^ 2 - w )
##w ^ ( v ^ 2 + v ^ 2 - w )
#E sosp
w ^ ( 2 * v ^ 2 - w )
##w ^ ( 2 * v ^ 2 - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T2 token OBRIR_PAR
#init T3 token "x"
#init T4 token TANCAR_PAR
#init T5 token 2
#init T7 token DIVISIO
#init T8 token 2.0
#init T9 token "y"
#init T10 token MULTIPLICACIO
#init L list<token>
#il T9
#il T10
#il T3
#il T7
#il T2
#il T9
#il T10
#il T3
#il T4
#il T10
#il T8
#init E expressio L
#E sosp
1 * 2.000000
##1 * 2.000000
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#T10 destroy
#L destroy
#E destroy
###!
#init T2 token OBRIR_PAR
#init T3 token "x"
#init T4 token TANCAR_PAR
#init T5 token 2
#init T7 token DIVISIO
#init T8 token 2.0
#init T9 token "y"
#init T10 token MULTIPLICACIO
#init L list<token>
#il T9
#il T10
#il T3
#il T7
#il T2
#il T9
#il T10
#il T3
#il T4
#il T7
#il T3
#il T10
#il T8
#init E expressio L
#E sosp
1 / x * 2.000000
##1 / x * 2.000000
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#T10 destroy
#L destroy
#E destroy
###!
###!
###!
###!---------------------
###9 simplify
###!---------------------
###!
#init E expressio
#E simpp
NULLTOK
##NULLTOK
#E destroy
###!
#init T token "v"
#init E expressio T
#E simpp
v
##v
#T destroy
#E destroy
###!
###!
###!---------------------
###9.1 suma
###!---------------------
###!
#init T1 token 0
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token 0
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E simpp
2 * v
##2 * v
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token SUMA
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token SUMA
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T4
#il T1
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E simpp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E simpp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E simpp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E simpp
( w + x ) * v
##( w + x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T3
#il T2
#il T3
#il T4
#il T3
#init E expressio L
#E simpp
2 * v ^ 2
##2 * v ^ 2
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E simpp
( w + x ) / v
##( w + x ) / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T3
#il T2
#il T3
#il T4
#il T3
#init E expressio L
#E simpp
2
##2
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.2 resta
###!---------------------
###!
#init T1 token "0"
#init T2 token RESTA
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
- v
##- v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token RESTA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token RESTA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E simpp
0
##0
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token RESTA
#init T2 token CANVI_DE_SIGNE
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T1
#il T4
#il T2
#il T3
#il T5
#init E expressio L
#E simpp
2 * v
##2 * v
#T1 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E simpp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E simpp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E simpp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T1
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#E simpp
( w - x ) * v
##( w - x ) * v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T3
#il T4
#il T3
#il T2
#il T3
#il T4
#il T3
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#E simpp
( w - x ) / v
##( w - x ) / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T1
#il T4
#il T3
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.3 canvi de signe
###!---------------------
###!
#init T1 token "w"
#init T2 token CANVI_DE_SIGNE
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init L list<token>
#il T2
#il T6
#il T2
#il T1
#il T7
#init E expressio L
#E simpp
w
##w
#T1 destroy
#T2 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SIGNE_POSITIU
#init L list<token>
#il T2
#il T1
#init E expressio L
#E simpp
w
##w
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token CANVI_DE_SIGNE
#init L list<token>
#il T2
#il T1
#init E expressio L
#E simpp
-5
##-5
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 4.56
#init T2 token CANVI_DE_SIGNE
#init L list<token>
#il T2
#il T1
#init E expressio L
#E simpp
-4.560000
##-4.560000
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token CANVI_DE_SIGNE
#init T3 token SQRT
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T4
#il T2
#il T1
#il T5
#init E expressio L
#E simpp
Error::expressio:35:Arrel quadrada de negatiu.
##Error::expressio:35:Arrel quadrada de negatiu.
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.4 multiplicacion
###!---------------------
###!
#init T1 token "0"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E simpp
v ^ 2
##v ^ 2
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T5
#init E expressio L
#E simpp
- ( v * w )
##- ( v * w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#E simpp
- v ^ 2
##- v ^ 2
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T4
#il T1
#il T6
#il T5
#il T2
#il T3
#init E expressio L
#E simpp
- ( w * v )
##- ( w * v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T4
#il T1
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#E simpp
- v ^ 2
##- v ^ 2
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init T7 token "w"
#init L list<token>
#il T7
#il T2
#il T4
#il T1
#il T6
#il T3
#il T5
#init E expressio L
#E simpp
w / v
##w / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T3
#il T5
#init E expressio L
#E simpp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init T7 token "w"
#init L list<token>
#il T4
#il T1
#il T6
#il T3
#il T5
#il T2
#il T7
#init E expressio L
#E simpp
w / v
##w / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init L list<token>
#il T4
#il T1
#il T6
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#E simpp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T6 token EXPONENCIACIO
#init T7 token "w"
#init L list<token>
#il T3
#il T6
#il T7
#il T2
#il T7
#il T6
#il T7
#init E expressio L
#E simpp
( v * w ) ^ w
##( v * w ) ^ w
#T2 destroy
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T6 token EXPONENCIACIO
#init T7 token "w"
#init L list<token>
#il T3
#il T6
#il T7
#il T2
#il T3
#il T6
#il T3
#init E expressio L
#E simpp
v ^ ( w + v )
##v ^ ( w + v )
#T2 destroy
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T6 token EXPONENCIACIO
#init T7 token "w"
#init L list<token>
#il T3
#il T6
#il T3
#il T2
#il T3
#il T6
#il T3
#init E expressio L
#E simpp
v ^ ( v * 2 )
##v ^ ( v * 2 )
#T2 destroy
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.5 division
###!---------------------
###!
#init T1 token "0"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "0"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E simpp
Error::expressio:33:Divisio per zero.
##Error::expressio:33:Divisio per zero.
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T1
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#E simpp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#E simpp
-1
##-1
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T5
#init E expressio L
#E simpp
- ( v / w )
##- ( v / w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T2
#il T6
#il T5
#init E expressio L
#E simpp
v * w
##v * w
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T2
#il T3
#il T5
#init E expressio L
#E simpp
v ^ 2
##v ^ 2
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token EXPONENCIACIO
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T1
#il T6
#il T2
#il T6
#il T1
#il T6
#init E expressio L
#E simpp
( v / w ) ^ w
##( v / w ) ^ w
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token EXPONENCIACIO
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T1
#il T6
#il T2
#il T3
#il T1
#il T3
#init E expressio L
#E simpp
v ^ ( w - v )
##v ^ ( w - v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token EXPONENCIACIO
#init T2 token DIVISIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T1
#il T3
#il T2
#il T3
#il T1
#il T3
#init E expressio L
#E simpp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.6 exponenciacio
###!---------------------
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 0.5
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
Error::expressio:32:Negatiu elevat a no enter.
##Error::expressio:32:Negatiu elevat a no enter.
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token -4
#init T2 token EXPONENCIACIO
#init T3 token 1.34
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
Error::expressio:32:Negatiu elevat a no enter.
##Error::expressio:32:Negatiu elevat a no enter.
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 0
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
1
##1
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 2
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
9
##9
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token 1
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E simpp
v
##v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token CANVI_DE_SIGNE
#init T4 token "w"
#init L list<token>
#il T1
#il T2
#il T3
#il T4
#init E expressio L
#E simpp
1 / v ^ w
##1 / v ^ w
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token "z"
#init T4 token "w"
#init T5 token OBRIR_PAR
#init T6 token TANCAR_PAR
#init L list<token>
#il T5
#il T1
#il T2
#il T3
#il T6
#il T2
#il T4
#init E expressio L
#E simpp
v ^ ( z * w )
##v ^ ( z * w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.7 radicacio
###!---------------------
###!
#init T1 token SQRT
#init T2 token -0.5
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E simpp
Error::expressio:35:Arrel quadrada de negatiu.
##Error::expressio:35:Arrel quadrada de negatiu.
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token -5
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E simpp
Error::expressio:35:Arrel quadrada de negatiu.
##Error::expressio:35:Arrel quadrada de negatiu.
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token 0
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E simpp
0
##0
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token "v"
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E simpp
v ^ ( 1/2 )
##v ^ ( 1/2 )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token SQRT
#init T2 token 25
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E simpp
25 ^ ( 1/2 )
##25 ^ ( 1/2 )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#L destroy
#E destroy
###!
###!
###!---------------------
###9.8 regla 1
###!---------------------
###!
#init T1 token 5
#init T2 token 0
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
Error::expressio:33:Divisio per zero.
##Error::expressio:33:Divisio per zero.
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init R racional 0 4
#init T1 token 5
#init T2 token R
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
Error::expressio:33:Divisio per zero.
##Error::expressio:33:Divisio per zero.
#R destroy
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token 2
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
5/2
##5/2
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 10
#init T2 token 5
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
2
##2
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 10
#init T2 token 5.0
#init T4 token SUMA
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
10 + 5.000000
##10 + 5.000000
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 2
#init T2 token 1
#init T4 token DIVISIO
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
2
##2
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token 10
#init T2 token 5.0
#init T4 token RESTA
#init L list<token>
#il T1
#il T4
#il T2
#init E expressio L
#E simpp
10 - 5.000000
##10 - 5.000000
#T1 destroy
#T2 destroy
#T4 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T9
#il T1
#il T7
#init E expressio L
#E simpp
w ^ ( 2 * v + v + v - w )
##w ^ ( 2 * v + v + v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T7
#init E expressio L
#E simpp
w ^ ( 2 * v + v + v + v )
##w ^ ( 2 * v + v + v + v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T6
#il T3
#il T2
#il T3
#il T7
#il T2
#il T3
#il T2
#il T6
#il T3
#il T2
#il T3
#il T7
#il T7
#init E expressio L
#E simpp
w ^ ( 2 * v + v + 2 * v )
##w ^ ( 2 * v + v + 2 * v )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init L list<token>
#il T1
#il T8
#il T6
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T1
#il T7
#init E expressio L
#E simpp
w ^ ( - v - v - w )
##w ^ ( - v - v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token CANVI_DE_SIGNE
#init L list<token>
#il T1
#il T4
#il T6
#il T9
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T3
#il T2
#il T1
#il T7
#init E expressio L
#E simpp
w * ( - v - v - v - v - w )
##w * ( - v - v - v - v - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token SUMA
#init L list<token>
#il T1
#il T8
#il T6
#il T3
#il T9
#il T3
#il T2
#il T6
#il T3
#il T9
#il T3
#il T7
#il T2
#il T3
#il T7
#init E expressio L
#E simpp
1 / w ^ v
##1 / w ^ v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init T6 token OBRIR_PAR
#init T7 token TANCAR_PAR
#init T8 token EXPONENCIACIO
#init T9 token RESTA
#init L list<token>
#il T1
#il T8
#il T6
#il T6
#il T3
#il T4
#il T3
#il T2
#il T3
#il T4
#il T3
#il T7
#il T9
#il T1
#il T7
#init E expressio L
#E simpp
w ^ ( 2 * v ^ 2 - w )
##w ^ ( 2 * v ^ 2 - w )
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#T8 destroy
#T9 destroy
#L destroy
#E destroy
###!
###!
###!
###!------------------------------
###10 list of tokens
###!------------------------------
###!
#init T token 3
#init E expressio T
#E lotp
3
##3
#T destroy
#E destroy
###!
#init R racional 3 5
#init T token R
#init E expressio T
#E lotp
3/5
##3/5
#R destroy
#T destroy
#E destroy
###!
#init T token 3.5
#init E expressio T
#E lotp
3.500000
##3.500000
#T destroy
#E destroy
###!
#init T token CT_E
#init E expressio T
#E lotp
e
##e
#T destroy
#E destroy
###!
#init T token "X"
#init E expressio T
#E lotp
X
##X
#T destroy
#E destroy
###!
#init R racional 3 5
#init T1 token "5"
#init T2 token EXPONENCIACIO
#init T3 token R
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#E lotp
5 ^ ( 3/5 )
##5 ^ ( 3/5 )
#R destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init R racional 3 5
#init T1 token SQRT
#init T2 token R
#init T3 token OBRIR_PAR
#init T4 token TANCAR_PAR
#init L list<token>
#il T1
#il T3
#il T2
#il T4
#init E expressio L
#E lotp
sqrt ( 3/5 )
##sqrt ( 3/5 )
#R destroy
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "u"
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#lotp
u + v
##u + v
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T2 token SUMA
#init T3 token "v"
#init L list<token>
#il T3
#il T2
#il T3
#init E expressio L
#lotp
v + v
##v + v
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token SUMA
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T3
#il T5
#init E expressio L
#lotp
v + - v
##v + - v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token SUMA
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T4
#il T1
#il T3
#il T5
#il T2
#il T3
#init E expressio L
#lotp
- v + v
##- v + v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#lotp
w * v + v * x
##w * v + v * x
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token SUMA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#lotp
w / v + x / v
##w / v + x / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token RESTA
#init T2 token CANVI_DE_SIGNE
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T1
#il T4
#il T2
#il T3
#il T5
#init E expressio L
#lotp
v - - v
##v - - v
#T1 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token MULTIPLICACIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T3
#il T4
#il T5
#init E expressio L
#lotp
w * v - v * x
##w * v - v * x
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token "w"
#init T2 token RESTA
#init T3 token "v"
#init T4 token DIVISIO
#init T5 token "x"
#init L list<token>
#il T1
#il T4
#il T3
#il T2
#il T5
#il T4
#il T3
#init E expressio L
#lotp
w / v - x / v
##w / v - x / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token CANVI_DE_SIGNE
#init L list<token>
#il T2
#il T1
#init E expressio L
#lotp
- 5
##- 5
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 4.56
#init T2 token CANVI_DE_SIGNE
#init L list<token>
#il T2
#il T1
#init E expressio L
#lotp
- 4.560000
##- 4.560000
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token 5
#init T2 token CANVI_DE_SIGNE
#init T3 token SQRT
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init L list<token>
#il T3
#il T4
#il T2
#il T1
#il T5
#init E expressio L
#lotp
sqrt ( - 5 )
##sqrt ( - 5 )
#T1 destroy
#T2 destroy
#L destroy
#E destroy
###!
#init T1 token CANVI_DE_SIGNE
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token "w"
#init L list<token>
#il T3
#il T2
#il T4
#il T1
#il T6
#il T5
#init E expressio L
#lotp
v * - w
##v * - w
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
#init T1 token "1"
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T4 token OBRIR_PAR
#init T5 token TANCAR_PAR
#init T6 token DIVISIO
#init T7 token "w"
#init L list<token>
#il T7
#il T2
#il T4
#il T1
#il T6
#il T3
#il T5
#init E expressio L
#lotp
w * 1 / v
##w * 1 / v
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T2 token MULTIPLICACIO
#init T3 token "v"
#init T6 token EXPONENCIACIO
#init T7 token "w"
#init L list<token>
#il T3
#il T6
#il T7
#il T2
#il T7
#il T2
#il T7
#init E expressio L
#lotp
v ^ w * w * w
##v ^ w * w * w
#T2 destroy
#T3 destroy
#T6 destroy
#T7 destroy
#L destroy
#E destroy
###!
#init T1 token -3
#init T2 token EXPONENCIACIO
#init T3 token 0.5
#init L list<token>
#il T1
#il T2
#il T3
#init E expressio L
#lotp
-3 ^ 0.500000
##-3 ^ 0.500000
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token CANVI_DE_SIGNE
#init T4 token "w"
#init L list<token>
#il T1
#il T2
#il T3
#il T4
#init E expressio L
#lotp
v ^ - w
##v ^ - w
#T1 destroy
#T2 destroy
#T3 destroy
#L destroy
#E destroy
###!
#init T1 token "v"
#init T2 token EXPONENCIACIO
#init T3 token "z"
#init T4 token "w"
#init T5 token OBRIR_PAR
#init T6 token TANCAR_PAR
#init L list<token>
#il T5
#il T1
#il T2
#il T3
#il T6
#il T2
#il T4
#init E expressio L
#lotp
( v ^ z ) ^ w
##( v ^ z ) ^ w
#T1 destroy
#T2 destroy
#T3 destroy
#T4 destroy
#T5 destroy
#T6 destroy
#L destroy
#E destroy
###!
