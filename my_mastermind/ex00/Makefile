target     := my_mastermind
objs       := my_mastermind.o mastermind.o
CC         := gcc
CFLAGS     := -g3 -Wall -Wextra -Werror



all: $(target)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

my_mastermind: $(objs)
	$(CC) $(CFLAGS) -o $@ $^


%.o:   %.c  
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -r $(target) $(objs) $(deps)