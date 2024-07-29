CC ?= gcc
CFLAGS = $(if $(NODEBUG),,-g)

HEADERS = test.h

SYSTEM_INCLUDE_DIR=/usr/local/include/w/t35t

.PHONY: check install

check:
	$(CC) -fsyntax-only $(HEADERS) 

install:
	mkdir -p $(SYSTEM_INCLUDE_DIR)
	for header in $(HEADERS) ; do \
		cp $$header $(SYSTEM_INCLUDE_DIR) ; \
	done
