# User defined variables
BIN := testClient

# Directories
SRCDIR := src
INCDIR := include
OBJDIR := build
BINDIR := bin

# Variables
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# Programs
CC := gcc
RM := rm -f
MKDIR := mkdir -p
RMDIR := rm -rf

# Flags
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic #-Werror
CLIBS  := -I $(INCDIR)

# Phony targets
.PHONY: all
all: $(BINDIR)/$(BIN)

.PHONY: nothing
nothing:

# Rules
$(BINDIR)/$(BIN): $(OBJ) | $(BINDIR)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CLIBS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h | $(OBJDIR)
	$(CC) $(CFLAGS) $(CLIBS) -c $< -o $@

$(BINDIR) $(OBJDIR):
	$(MKDIR) $@

# Clean
.PHONY: clean
clean:
	$(RMDIR) $(OBJDIR)
	$(RMDIR) $(BINDIR)

.PHONY: debug
debug:
	@echo $(SRC)
	@echo $(OBJ)
