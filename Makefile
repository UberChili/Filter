##
# Filter
#
# @file
# @version 0.1

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

# Object files (all go to build directory)
OBJS = $(BUILDDIR)/main.o $(BUILDDIR)/helpers.o $(BUILDDIR)/png.o $(BUILDDIR)/chunk.o

# Main target
$(BINDIR)/filter: $(OBJS) | $(BINDIR)
	$(CC) $(OBJS) -o $@

# Compile main.c
$(BUILDDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/filter.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile helpers.c
$(BUILDDIR)/helpers.o: $(SRCDIR)/helpers.c $(INCDIR)/filter.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile png.c
$(BUILDDIR)/png.o: $(SRCDIR)/png.c $(INCDIR)/filter.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile chunk.c
$(BUILDDIR)/chunk.o: $(SRCDIR)/chunk.c $(INCDIR)/filter.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: clean
