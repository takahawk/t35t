CC ?= gcc
CFLAGS = $(if $(NODEBUG),,-g)

HEADERS = test.h
T35T=t35t

INSTALL_BIN_DIR=/usr/local/bin
INSTALL_INCLUDE_DIR=/usr/local/include/w/t35t

.PHONY: check install

check:
	$(CC) -fsyntax-only $(HEADERS) 

install:
	mkdir -p $(INSTALL_INCLUDE_DIR)
	for header in $(HEADERS) ; do \
		cp $$header $(INSTALL_INCLUDE_DIR) ; \
	done
	cp test.sh $(T35T)
	chmod +x $(T35T)
	mv $(T35T) $(INSTALL_BIN_DIR) 

