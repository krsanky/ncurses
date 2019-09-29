PRG=		curs
CFLAGS=		-W -Wall -O2 -std=c99 -g
LDFLAGS=	-lncurses

all: $(BINS)

triangle: triangle.c 
	$(CC) $(CFLAGS) triangle.c $(LDFLAGS) -o triangle

diag: $@.c 
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@

all: curs

indent:
	@echo "indenting all code..."
	./indent-all.sh

.PHONY: clean indent all
clean:
	rm -f a.out $(PRG) triangle curs diag main


