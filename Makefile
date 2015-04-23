CC ?= gcc
ALL_CFLAGS = -Wall $(CFLAGS)
ALL_LDFLAGS = $(LDFLAGS)
BUILDDIR = build

all : $(BUILDDIR)/static-analysis-test

clean:
	rm -rf $(BUILDDIR)

SRCS+=main.c
SRCS+=memleak.c
#SRCS+=floattests.c
#SRCS+=deadcode.c
#SRCS+=pointers.c

OBJS:=$(SRCS:%.c=$(BUILDDIR)/%.o)

$(BUILDDIR)/%.o : %.c
	@[ -d $(@D) ]  || mkdir -p $(@D)
	$(CC) -c $(^) -o $(@) $(ALL_CFLAGS)

$(BUILDDIR)/static-analysis-test : $(OBJS)
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(CC) $(^) -o $(@) $(ALL_LDFLAGS)
