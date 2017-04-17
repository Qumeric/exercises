(define (sqrt-iter guess old-guess x)
  (if (good-enough? guess old-guess)
      guess
      (sqrt-iter (improve guess x) guess x)))
    
(define (improve guess x)
  (/ (+ guess (/ x guess)) 2))

; Whether absolute or relative error is small enough
(define (good-enough? a b)
  (< (/ (abs (- a b)) (max 1 b)) 0.0001))

(define (sqrt x)
  (sqrt-iter 1.0 10.0 x))
