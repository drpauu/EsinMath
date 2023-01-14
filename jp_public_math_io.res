###!----------------------------------------------------------
###!Tests per comprovar que es mostrin els ( ) imprescindibles
###!----------------------------------------------------------
#init L list<token>
#scan "x+(y-z)" L
#init E expressio L
#lotp
x + y - z
#L destroy
#E destroy
###!
#init L list<token>
#scan "x-(y+z)" L
#init E expressio L
#lotp
x - ( y + z )
#L destroy
#E destroy
###!
#init L list<token>
#scan "x-(y-z)" L
#init E expressio L
#lotp
x - ( y - z )
#L destroy
#E destroy
###!
#init L list<token>
#scan "x*(y/z)" L
#init E expressio L
#lotp
x * y / z
#L destroy
#E destroy
###!
#init L list<token>
#scan "x/(y*z)" L
#init E expressio L
#lotp
x / ( y * z )
#L destroy
#E destroy
###!
#init L list<token>
#scan "x/(y/z)" L
#init E expressio L
#lotp
x / ( y / z )
#L destroy
#E destroy
###!
###!------------------------------------------------------------------------
###!Tests per comprovar l'associativitat dreta a esquerra de l'exponenciació 
###!------------------------------------------------------------------------
#init L list<token>
#scan "variable_a^variable_b^variable_c" L
#init E expressio L
#lotp
variable_a ^ variable_b ^ variable_c
#sosp
variable_a ^ variable_b ^ variable_c
#L destroy
#E destroy
###!
#init L list<token>
#scan "(variable_a^variable_b)^variable_c" L
#init E expressio L
#lotp
( variable_a ^ variable_b ) ^ variable_c
#sosp
variable_a ^ ( variable_b * variable_c )
#L destroy
#E destroy
###!
###!----------------------------------------------------------
###!Tests per comprovar l'ordre en les simplificacions
###!----------------------------------------------------------
#init L list<token>
#scan "(3 * 2 + 3.141592 * sqrt (5))/(3*log(log(5)))" L
#init E expressio L
#lotp
( 3 * 2 + 3.141592 * sqrt ( 5 ) ) / ( 3 * log ( log ( 5 ) ) )
#sosp
( 6 + 3.141592 * sqrt ( 5 ) ) / ( 3 * log ( log ( 5 ) ) )
#sosp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * log ( log ( 5 ) ) )
#sosp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * log ( log ( 5 ) ) )
#simpp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * log ( log ( 5 ) ) )
#lotp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * log ( log ( 5 ) ) )
#L destroy
#E destroy
###!
#init L list<token>
#scan "(3 * 2 + 3.141592 * sqrt (5))/(3*log(log(5.0)))" L
#init E expressio L
#lotp
( 3 * 2 + 3.141592 * sqrt ( 5 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#sosp
( 6 + 3.141592 * sqrt ( 5 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#sosp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#sosp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * log ( 1.609438 ) )
#simpp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * 0.475885 )
#lotp
( 6 + 3.141592 * 5 ^ ( 1/2 ) ) / ( 3 * 0.475885 )
#L destroy
#E destroy
###!
#init L list<token>
#scan "(3/2 + 1/3 * sqrt (2/5))/(3*log(log(5.0)))" L
#init E expressio L
#lotp
( 3 / 2 + 1 / 3 * sqrt ( 2 / 5 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#sosp
( 3/2 + 1 / 3 * sqrt ( 2 / 5 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#sosp
( 3/2 + 1/3 * sqrt ( 2 / 5 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#sosp
( 3/2 + 1/3 * sqrt ( 2/5 ) ) / ( 3 * log ( log ( 5.000000 ) ) )
#simpp
( 3/2 + 1/3 * 2/5 ^ ( 1/2 ) ) / ( 3 * 0.475885 )
#lotp
( 3/2 + 1/3 * 2/5 ^ ( 1/2 ) ) / ( 3 * 0.475885 )
#L destroy
#E destroy
###!
###!-----------------------------------------------------------------
###!Tests per comprovar l'exponenciació amb exponents 0, 1 o negatius
###!-----------------------------------------------------------------
#init L list<token>
#scan "x^y^(z-z)" L
#init E expressio L
#lotp
x ^ y ^ ( z - z )
#sosp
x ^ y ^ 0
#sosp
x ^ 1
#simpp
x
#lotp
x
#L destroy
#E destroy
###!
#init L list<token>
#scan "x^y^(z/z)" L
#init E expressio L
#lotp
x ^ y ^ ( z / z )
#sosp
x ^ y ^ 1
#sosp
x ^ y
#simpp
x ^ y
#lotp
x ^ y
#L destroy
#E destroy
###!
#init L list<token>
#scan "3^2^-1" L
#init E expressio L
#lotp
3 ^ 2 ^ - 1
#sosp
3 ^ 2 ^ -1
#sosp
3 ^ ( 1/2 )
#simpp
3 ^ ( 1/2 )
#lotp
3 ^ ( 1/2 )
#L destroy
#E destroy
###!
#init L list<token>
#scan "(3^2)^-1" L
#init E expressio L
#lotp
( 3 ^ 2 ) ^ - 1
#sosp
9 ^ - 1
#sosp
9 ^ -1
#simpp
1/9
#lotp
1/9
#L destroy
#E destroy
###!
#init L list<token>
#scan "(1/3)^(1/2)^-1" L
#init E expressio L
#lotp
( 1 / 3 ) ^ ( 1 / 2 ) ^ - 1
#sosp
1/3 ^ ( 1 / 2 ) ^ - 1
#sosp
1/3 ^ ( 1/2 ) ^ - 1
#sosp
1/3 ^ ( 1/2 ) ^ -1
#simpp
1/9
#lotp
1/9
#L destroy
#E destroy
###!
#init L list<token>
#scan "3.0^2.0^-1" L
#init E expressio L
#lotp
3.000000 ^ 2.000000 ^ - 1
#sosp
3.000000 ^ 2.000000 ^ -1
#sosp
3.000000 ^ 0.500000
#simpp
1.732051
#lotp
1.732051
#L destroy
#E destroy
###!
#init L list<token>
#scan "(3.0^2.0)^-1" L
#init E expressio L
#lotp
( 3.000000 ^ 2.000000 ) ^ - 1
#sosp
9.000000 ^ - 1
#sosp
9.000000 ^ -1
#simpp
0.111111
#lotp
0.111111
#L destroy
#E destroy
###!
#init L list<token>
#scan "3.0^2.0^-1.0" L
#init E expressio L
#lotp
3.000000 ^ 2.000000 ^ - 1.000000
#sosp
3.000000 ^ 2.000000 ^ -1.000000
#sosp
3.000000 ^ 0.500000
#simpp
1.732051
#lotp
1.732051
#L destroy
#E destroy
###!
#init L list<token>
#scan "(3.0^2.0)^-1.0" L
#init E expressio L
#lotp
( 3.000000 ^ 2.000000 ) ^ - 1.000000
#sosp
9.000000 ^ - 1.000000
#sosp
9.000000 ^ -1.000000
#simpp
0.111111
#lotp
0.111111
#L destroy
#E destroy
