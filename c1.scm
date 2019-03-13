(import chicken.format chicken.foreign)

#>
	extern void f1();
<#
(define ff1 (foreign-lambda void "f1"))


#>
	extern char * sf(int);
<#
(define fsf (foreign-lambda c-string "sf" int))

(ff1)
(printf "(fsf 3):~S\n" (fsf 3))
