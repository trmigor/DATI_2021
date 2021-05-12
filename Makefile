TARGETS = crackme

BIN_DIR = ./bin

.PHONY: all
all: $(TARGETS)

.PHONY: $(TARGETS)
$(TARGETS): %: $(BIN_DIR)
	make -C $@
	cp $@/bin/$@ $(BIN_DIR)

$(BIN_DIR):
	$(MKDIR_P) $(BIN_DIR)

.PHONY: install
install:
	$(foreach t,$(TARGETS),$(shell make -C $(t) install))

.PHONY: clean
clean:
	$(foreach t,$(TARGETS),$(shell make -C $(t) clean))
	$(RM) -r $(BIN_DIR)

MKDIR_P ?= mkdir -p
