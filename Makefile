CC ?= gcc
CFLAGS = $(if $(NODEBUG),,-g)

.PHONY: check

check:
	$(CC) -fsyntax-only test_case.h
