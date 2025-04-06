
CC = clang
CFLAGS = -Wall -Wextra

GDB = gdb


# - -- - -- - -- - -- - -- - -- - -- - -- - --

DEFAULT_TARGET = main.exe

WD = .

src = src

bin = $(WD)/bin
build = $(WD)/build

release = $(WD)/release
debug = $(WD)/debug

DEP_DIR = $(WD)/.dep

TAGGED_FILE_TAG = d

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.$(TAGGED_FILE_TAG)

BUILD_DIRECTORIES = $(bin) $(build) $(release) $(debug) $(DEP_DIR)

DIRECTORIES = $(BUILD_DIRECTORIES) $(release)/bin $(release)/build $(debug)/bin $(debug)/build


# - -- - -- - -- - -- - -- - -- - -- - -- - --

srcs = $(wildcard $(src)/*.c)
deps = $(srcs:$(src)/%.c=$(build)/%.o)


default:$(basename $(DEFAULT_TARGET)).run


# - -- - -- - -- - -- - -- - -- - -- - -- - --

$(build)/%.o: $(src)/%.c $(src)/%.h $(src)/%.h | $(build) $(DEP_DIR)
	$(CC) -c $(CFLAGS) $(DEP_FLAGS) $< -o $@

$(build)/%.o: %.c | $(build) $(DEP_DIR)
	$(CC) -c $(CFLAGS) $(DEP_FLAGS) $< -o $@

$(bin)/%.exe: $(build)/%.o $(deps) | $(bin) $(DEP_DIR)
	$(CC) $(DYNAMIC_LIBRARIES) $^ -o $@

%.exe: $(build)/%.o $(deps) | $(build) $(DEP_DIR)
	$(CC) $(DYNAMIC_LIBRARIES) $^ -o $@
	@echo "Created $@ ..."
ifdef target
	mv $@ $(target)
endif


%.demo: $(bin)/%.exe
	@echo - -- - -- - -- - -- - -- -
	$< $(args)
	@echo
	@echo - -- - -- - -- - -- - -- -

%.run: $(bin)/%.exe
	@$< $(args)


# - -- - -- - -- - -- - -- - -- - -- - -- - --

$(release)/build/%.o: $(src)/%.c $(src)/%.h $(src)/%.h | $(release)/build $(DEP_DIR)
	$(CC) -c $(CFLAGS) $(DEP_FLAGS) $< -o $@

$(release)/build/%.o: %.c | $(release)/build $(DEP_DIR)
	$(CC) -c $(CFLAGS) $(DEP_FLAGS) $< -o $@

$(release)/bin/%.exe: $(release)/build/%.o $(srcs:$(src)/%.c=$(release)/build/%.o) | $(release)/bin $(DEP_DIR)
	$(CC) $(DYNAMIC_LIBRARIES) $^ -o $@

%.release: CFLAGS += -O2
%.release: TAGGED_FILE_TAG = release.d

%.release: $(release)/bin/%.exe
	@echo "Creating $< ..."
ifdef target
	mv $< $(target)
endif


# - -- - -- - -- - -- - -- - -- - -- - -- - --

$(debug)/build/%.o: $(src)/%.c $(src)/%.h $(src)/%.h | $(debug)/build $(DEP_DIR)
	$(CC) -c $(CFLAGS) $(DEP_FLAGS) $< -o $@

$(debug)/build/%.o: %.c | $(debug)/build $(DEP_DIR)
	$(CC) -c $(CFLAGS) $(DEP_FLAGS) $< -o $@

$(debug)/bin/%.exe: $(debug)/build/%.o $(srcs:$(src)/%.c=$(debug)/build/%.o) | $(debug)/bin $(DEP_DIR)
	$(CC) $(DYNAMIC_LIBRARIES) $^ -o $@

%.debug: CFLAGS += -g -Og
%.debug: TAGGED_FILE_TAG = debug.d

%.debug: $(debug)/bin/%.exe
	$(GDB) $<


# - -- - -- - -- - -- - -- - -- - -- - -- - --

.PHONY: compare

compare: args = 1000
compare: SHELL = /bin/bash
compare: $(bin)/$(DEFAULT_TARGET)
	diff <($< $(args)) <(./sieved.py $(args))


# - -- - -- - -- - -- - -- - -- - -- - -- - --

.PHONY: default clean purge %.release %.debug %.run %.demo

$(DIRECTORIES):
	mkdir -p $@

.PRECIOUS: $(bin)/%.exe $(build)/%.o $(release)/bin/%.exe $(release)/build/%.o $(debug)/bin/%.exe $(debug)/build/%.o

clean: $(shell find -type f -name "*.o" -o -name "*.exe" -o -name "*.d")
	rm -rf $^

purge:
	rm -rf $(BUILD_DIRECTORIES)

$(DEPFILES):

include $(wildcard $(DEPFILES))