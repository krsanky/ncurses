CFLAGS=		-W -Wall -O2 -std=c99 -g
LDFLAGS=	-lncurses

all: fun

triangle: triangle.c 
	$(CC) $(CFLAGS) triangle.c $(LDFLAGS) -o triangle

diag: $@.c 
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@

fun: $@.c statw.h statw.c
	$(CC) $(CFLAGS) $@.c statw.c $(LDFLAGS) -o $@

indent:
	@echo "indenting all code..."
	./indent-all.sh

.PHONY: clean indent all
clean:
	rm -f a.out $(PRG) triangle curs diag main fun simple_init_main
	rm -f *.BAK


