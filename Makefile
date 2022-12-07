SUBDIRS = $(wildcard Dia*/)

#Compile all the days
all:
	for i in $(SUBDIRS); do \
		$(MAKE) -C $$i; \
	done
