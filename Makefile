SHELL = /bin/sh

GCC_STRICT_FLAGS = -pedantic -ansi -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2
GCC_SANITIZE_FLAGS = -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
OTHER_SOURCE = -I./t
OTHER_INCLUDE =
CPPFLAGS = -g -I. $(OTHER_INCLUDE)
CFLAGS = $(GCC_STRICT_FLAGS) 
LDFLAGS =
LDFLAGS_EFENCE = -L/usr/lib -lefence $(LDFLAGS)
##VALGRIND_FLAGS = --verbose --leak-check=full --undef-value-errors=yes --track-origins=yes
VALGRIND_FLAGS = --leak-check=full --undef-value-errors=yes
##VALGRIND = 
VALGRIND = valgrind $(VALGRIND_FLAGS)

INDENT_FLAGS = -TFILE -Tsize_t -Tuint8_t

.PHONY: check check-examples vcheck scheck echeck indent stamp clean

TESTS = t/test-revcomp
EXAMPLES = ex/ex_1

check: test-revcomp test-tidy test-score

test-revcomp:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c ntrevcomp.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

test-tidy:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c nttidy.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

test-score:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c ntscore.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

vcheck:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c ntutils.c $(LDFLAGS) ) \
	  && ( valgrind $(VALGRIND_FLAGS) t/a.out ); \
	done 

scheck:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(GCC_SANITIZE_FLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c ntutils.c $(LDFLAGS) ) \
	  && ( t/a.out ); \
	done 

echeck:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c ntutils.c $(LDFLAGS_EFENCE) ) \
	  && ( LD_PRELOAD=libefence.so t/a.out ) ; \
	done 

indent:
	@indent $(INDENT_FLAGS) ntrevcomp.c
	@indent $(INDENT_FLAGS) ntrevcomp.h
	@indent $(INDENT_FLAGS) nttidy.c
	@indent $(INDENT_FLAGS) nttidy.h
	@indent $(INDENT_FLAGS) t/test-revcomp.c
	@indent $(INDENT_FLAGS) t/test-tidy.c

stamp:
	@stamper.bash ntrevcomp.c
	@stamper.bash ntrevcomp.h

clean:
	@/bin/rm -f *.o *~ *.BAK *.bak core.* a.out
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out*
	@/bin/rm -f ex/*.o ex/*~ ex/*.BAK ex/*.bak ex/core.* ex/a.out*

