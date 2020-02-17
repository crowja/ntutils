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
STAMPER = stamper

INDENT_FLAGS = -TFILE -Tsize_t -Tuint8_t

.PHONY: check check-examples vcheck scheck echeck indent stamp clean

TESTS = t/test-revcomp
EXAMPLES = ex/ex_1

check: test-revcomp test-tidy test-match test-align

test-revcomp:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c ntrevcomp.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

test-tidy:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c nttidy.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

test-match:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c ntmatch.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

test-align:
	( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
	  -o t/a.out-$@ t/$@.c ntalign.c ntmatch.c $(LDFLAGS) ) \
	  && ( $(VALGRIND) t/a.out-$@ );

indent:
	@indent $(INDENT_FLAGS) ntalign.c
	@indent $(INDENT_FLAGS) ntalign.h
	@indent $(INDENT_FLAGS) ntmatch.c
	@indent $(INDENT_FLAGS) ntmatch.h
	@indent $(INDENT_FLAGS) ntrevcomp.c
	@indent $(INDENT_FLAGS) ntrevcomp.h
	@indent $(INDENT_FLAGS) nttidy.c
	@indent $(INDENT_FLAGS) nttidy.h
	@indent $(INDENT_FLAGS) t/test-revcomp.c
	@indent $(INDENT_FLAGS) t/test-tidy.c

stamp:
	@$(STAMPER) ntalign.c
	@$(STAMPER) ntalign.h
	@$(STAMPER) ntmatch.c
	@$(STAMPER) ntmatch.h
	@$(STAMPER) ntrevcomp.c
	@$(STAMPER) ntrevcomp.h
	@$(STAMPER) nttidy.c
	@$(STAMPER) nttidy.h

clean:
	@/bin/rm -f *.o *~ *.BAK *.bak core.* a.out
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out*
	@/bin/rm -f ex/*.o ex/*~ ex/*.BAK ex/*.bak ex/core.* ex/a.out*

