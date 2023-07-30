CC=gcc
main: c_head.o c_display.o c_vend_func.o c_owner.o c_print_bill.o c_payment.o
	gcc c_head.o c_display.o c_vend_func.o c_owner.o c_print_bill.o c_payment.o -o cproj
c_head.o: c_head.o
	gcc -c c_head.c
c_display.o: c_display.o
	gcc -c c_display.c
c_vend_func.o: c_vend_func.o
	gcc -c c_vend_func.c
c_owner.o: c_owner.o
	gcc -c c_owner.c
c_print_bill.o: c_print_bill.o
	gcc -c c_print_bill.c
c_payment.o: c_payment.o
	gcc -c c_payment.c



