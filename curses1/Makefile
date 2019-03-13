PRG=		curs
CFLAGS=		-W -Wall -O2 -std=c99 -g
SOURCES=	main.c
OBJS=		
LDLIBS=		-lncurses
HDRS=		wiki.h myhtml.h params.h forms.h util.h
TESTBINS=	test_forms params_test anchortest mdtest.cgi writef

#PRG=reduce
#OBJS=simplify.o io.o
#$(PRG): $(OBJS)
# $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(PRG) 


all: $(BINS)

curs: $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(SOURCES) $(LDLIBS) -o $(PRG) 

triangle: triangle.c 
	$(CC) $(CFLAGS) triangle.c $(LDLIBS) -o triangle


all: curs
#nanologger: ${.TARGET}.c
#	$(CC) $(CFLAGS) -o ${.TARGET} \
#		${.TARGET}.c \
#		myhtml.c util.c \
#		-L/usr/local/lib -I/usr/local/include \
#		-lnanomsg -lmarkdown 

indent:
	@echo "indenting all code..."
	./indent-all.sh

.PHONY: clean indent
clean:
	rm -f a.out $(PRG) triangle


