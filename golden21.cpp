/*  MIP   */
#include "mlisp.h"
bool NOT_Q/*2*/ (double x_Q);
	 extern double a/*3*/;
	 extern double b/*3*/;
	 double fun/*4*/ (double x) ;
	 double golden__section__search/*8*/ (double a, double b) ;
	 double golden__start/*16*/ (double a, double b) ;
	 extern double mphi/*25*/;
	 double __MIP__try/*26*/ (double a, double b
	 , double xa, double ya
	 , double xb, double yb) ;
	 bool close__enough_Q/*48*/ (double x, double y);
	 extern double tolerance/*50*/;
	 extern double total__iterations/*51*/;
	 extern double xmin/*52*/;
	 //________________ 
bool NOT_Q/*2*/ (double x_Q){
 return
 (0. == (x_Q
	? 1.
	: true
	? 0.
	: _infinity));
	 }
double a/*3*/ = 2.;
	 double b/*3*/ = 6.;
	 double fun/*4*/ (double x) {
 x = (x - (100. / 101.));
	 return
 ((log((x + 1.)) + exp(((- x) + 7.)) + expt((x - 8.)
	 , 3.)
	 ) - atan((x - 6.)) - 2.);
	 }
double golden__section__search/*8*/ (double a, double b) {
 {
 double xmin( ((b > a)
	? golden__start(a
	 , b)
	 
	: true
	? golden__start(b
	 , a)
	 
	: _infinity) );
	 newline();
	 return xmin;
	 }
}
double golden__start/*16*/ (double a, double b) {
 total__iterations = 0.;
	 {
 double xa( (a + (mphi * (b - a))) ),
	 xb( (b + (- (mphi * (b - a)))) );
	 return __MIP__try(a
	 , b
	 , xa
	 , fun(xa)
	 , xb
	 , fun(xb))
	 ;
	 }
}
double mphi/*25*/ = ((3. - sqrt(5.)) * (1. * (1. / 2.)));
	 double __MIP__try/*26*/ (double a, double b
	 , double xa, double ya
	 , double xb, double yb) {
 return
 (close__enough_Q(a, b)
	 
	? ((a + b) * (1. / 2.))
	: true
	? display("+")
	, total__iterations = (total__iterations + 1.)
	, ((yb > ya)
	? b = xb
	, xb = xa
	, yb = ya
	, xa = (a + (mphi * (b + (- a))))
	, __MIP__try(a
	 , b
	 , xa
	 , fun(xa)
	 , xb
	 , yb)
	 
	: true
	? a = xa
	, xa = xb
	, ya = yb
	, xb = (b + (- (mphi * (b + (- a)))))
	, __MIP__try(a
	 , b
	 , xa
	 , ya
	 , xb
	 , fun(xb))
	 
	: _infinity)
	: _infinity);
	 }
bool close__enough_Q/*48*/ (double x, double y){
 return
 (tolerance > abs((x + (- y))));
	 }
double tolerance/*50*/ = 0.00001e2;
	 double total__iterations/*51*/ = 0.;
	 double xmin/*52*/ = 0.;
	 int main(){
 xmin = golden__section__search(a
	 , b)
	 ;
	 display("Interval=\t[");
	 display(a);
	 display(" , ");
	 display(b);
	 display("]\n");
	 display("Total number of iteranions=");
	 display(total__iterations);
	 newline();
	 display("xmin=\t\t");
	 display(xmin);
	 newline();
	 display("f(xmin)=\t");
	 display(fun(xmin));
	 newline();
	 std::cin.get();
	 return
 0;
	 }

