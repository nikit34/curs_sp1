;golden21
(define(NOT? x?)(= 0(cond (x? 1) (#t 0))))
(define a 2)(define b 6)
(define (fun x)
 (set! x (- x (/ 100 101)))
 (-(+(log(+ x 1))(exp(+(- x)7))(expt(- x 8)3)) (atan(- x 6)) 2)
)
(define (golden-section-search a b)
 (let(
      (xmin(cond((> b a)(golden-start a b))(#t (golden-start b a ))))
     )
     (newline)
     xmin
 )
)
(define (golden-start a b)
 (set! total-iterations 0)
 (let(
      (xa (+ a (* mphi(- b a))))
      (xb (+ b (-(* mphi(- b a)))))
     )
     (try a b xa (fun xa) xb (fun xb))
 )
)
(define mphi (* (- 3(sqrt 5))(* 1(/ 2))))
(define (try a b xa ya xb yb)
 (cond((close-enough? a b)
      (* (+ a b)(/ 2)))
      (#t(let() (display "+")
             (set! total-iterations (+ total-iterations 1))
             (cond((> yb ya)(let() (set! b xb)
                               (set! xb xa)
                               (set! yb ya)
                               (set! xa (+ a (* mphi(+ b (- a)))))
                               (try a b xa (fun xa) xb yb))
                             )
                  (#t    (let() (set! a xa)
                        (set! xa xb)
                        (set! ya yb)
                        (set! xb (+ b (-(* mphi(+ b (- a))))))
                        (try a b xa ya xb (fun xb)))

                   )
             );cond...
      ));let...
 );if...
)
(define (close-enough? x y)
  (> tolerance (abs (+ x (- y)))))
(define tolerance 0.00001e2)
(define total-iterations 0)
(define xmin 0)
(set! xmin(golden-section-search a b))
  (display"Interval=\t[")
  (display a)
  (display" , ")
  (display b)
  (display"]\n")
  (display"Total number of iteranions=")
total-iterations
  (display"xmin=\t\t")
xmin
  (display"f(xmin)=\t")
(fun xmin)