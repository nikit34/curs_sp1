/*  MIP   */
#include "mlisp.h"
extern double VARIANT/*1*/;
	 extern double LAST__DIGIT__OF__GROUP__NUMBER/*2*/;
	 extern double kinds__of__coins/*3*/;
	 bool NOT_Q/*4*/ (double x_Q);
	 double first__denomination/*7*/ (double kinds__of__coins) ;
	 double count__change/*17*/ (double amount, double kinds__of__coins) ;
	 bool pier_Q/*33*/ (double x_Q, double y_Q);
	 double cc/*37*/ (double amount, double kinds__of__coins) ;
	 double denomination__list/*48*/ (double kinds__of__coins) ;
	 double GR__AMOUNT/*56*/ () ;
	 //________________ 
double VARIANT/*1*/ = 24.;
	 double LAST__DIGIT__OF__GROUP__NUMBER/*2*/ = 8.;
	 double kinds__of__coins/*3*/ = 6.;
	 bool NOT_Q/*4*/ (double x_Q){
 return
 (0. == (x_Q
	? 1.
	: true
	? 0.
	: _infinity));
	 }
double first__denomination/*7*/ (double kinds__of__coins) {
 return
 ((kinds__of__coins == 1.)
	? 1.
	: true
	? ((kinds__of__coins == 2.)
	? 2.
	: true
	? ((kinds__of__coins == 3.)
	? 15.
	: true
	? ((kinds__of__coins == 4.)
	? 20.
	: true
	? ((kinds__of__coins == 5.)
	? 25.
	: true
	? ((kinds__of__coins == 6.)
	? 50.
	: true
	? 0.
	: _infinity)
	: _infinity)
	: _infinity)
	: _infinity)
	: _infinity)
	: _infinity);
	 }
double count__change/*17*/ (double amount, double kinds__of__coins) {
 display("______\namount: ");
	 display(amount);
	 newline();
	 display("KINDS-OF-COINS: ");
	 display(kinds__of__coins);
	 newline();
	 return
 ((amount > 0.)
	? ((kinds__of__coins > 0.)
	? ((first__denomination(kinds__of__coins) > 0.)
	? cc(amount
	 , kinds__of__coins)
	 
	: true
	? display("(improper parameter value) ")
	, 0.
	: _infinity)
	: true
	? display("(improper parameter value) ")
	, 0.
	: _infinity)
	: true
	? display("(improper parameter value) ")
	, 0.
	: _infinity);
	 }
bool pier_Q/*33*/ (double x_Q, double y_Q){
 return
 (NOT_Q(x_Q) && NOT_Q(y_Q));
	 }
double cc/*37*/ (double amount, double kinds__of__coins) {
 return
 ((amount == 0.)
	? 1.
	: true
	? (pier_Q((0. > amount), (kinds__of__coins == 0.))
	 
	? (cc(amount
	 , (kinds__of__coins - 1.))
	  + cc((amount - first__denomination(kinds__of__coins))
	 , kinds__of__coins)
	 )
	: true
	? 0.
	: _infinity)
	: _infinity);
	 }
double denomination__list/*48*/ (double kinds__of__coins) {
 return
 ((kinds__of__coins == 0.)
	? 0.
	: true
	? denomination__list((kinds__of__coins - 1.))
	: _infinity);
	 }
double GR__AMOUNT/*56*/ () {
 return
 remainder(((100. * LAST__DIGIT__OF__GROUP__NUMBER) + VARIANT)
	 , 231.)
	 ;
	 }
int main(){
 display("Variant ");
	 display(VARIANT);
	 newline();
	 newline();
	 display(count__change(100.
	 , kinds__of__coins)
	 );
	 newline();
	 display(count__change(GR__AMOUNT()
	 , kinds__of__coins)
	 );
	 newline();
	 display(count__change(100.
	 , kinds__of__coins)
	 );
	 newline();
	 display("(c) Permyakov N.A. 2021\n");
	 std::cin.get();
	 return
 0;
	 }

