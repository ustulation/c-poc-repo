# make --just-print
# make --silent

# Note: assignment is `=` and not `:=` which would expand immediately (what we want in most cases).
# Here, however, we want the expansion only in relevant context - when var is actually used there.
# That is how `$(@D)` would get its value.
# dir_guard = mkdir -p $(@D)

# To override any var run as `make target_dir:=hello` or `make clean target_dir:=hello` etc.
target_dir := target
obj_dir := $(target_dir)/obj

objs := $(obj_dir)/main.o

# The order is important here - we 1st need to ensure that directory exists before we proceed.
$(target_dir)/pointers: create_dirs $(objs)
	cc -o $@ $(objs)

# This target specific var is just put here as an e.g. If moved to the parent target `pointers` it
# will be applicable for all children (pre-requisites of parent) and should be ideally put there.
$(obj_dir)/main.o: CFLAGS := -std=c99 -O2 -s
$(obj_dir)/main.o: main.c
	cc $(CFLAGS) -c $< -o $@

# To run this exclusively do `make create_dirs`. Simply `make` will execute the 1st target by
# default which in this case is `$(target_dir)/pointers` == `target/pointers`.
.PHONY: create_dirs
create_dirs:
# @ prefix suppress echo.
	@mkdir -p $(obj_dir)

.PHONY: clean
clean:
# @ prefix suppress echo.
# - prefix ignores errors if any and continues.
	-@rm -r $(target_dir)/*
