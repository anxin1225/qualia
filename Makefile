EXAMPLES=$(wildcard tests/*)
MODE = debug
SCONS = /usr/local/bin/scons
SCONS += mode=$(MODE)

.PHONY: all clean install $(EXAMPLES)

default: all

all:
	@echo "== Building Qualia in mode $(MODE) =="
	$(SCONS)
	
clean:
	@echo "== Cleaning Qualia mode $(MODE) =="
	$(SCONS) --clean

install:
	@echo "== Installing Qualia in mode $(MODE) =="
	$(SCONS) install

examples: $(EXAMPLES)

$(EXAMPLES): all
	@echo "== Building example $@ in mode $(MODE) =="
	@cd $@ && $(SCONS)