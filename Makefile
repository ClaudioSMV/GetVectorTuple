.DELETE_ON_ERROR:

MKDIR_P := mkdir -p

BINDIR := ./bin
SRCDIR := ./src

ROOTCONFIG := root-config
ROOTCFLAGS := $(shell $(ROOTCONFIG) --cflags)
ROOTLDFLAGS := $(shell $(ROOTCONFIG) --ldflags)
ROOTGLIBS := $(shell $(ROOTCONFIG) --glibs)

CXX := g++

CXXFLAGS := -g -O2 -Wall -fPIC $(ROOTCFLAGS)
LDFLAGS := -g -O2 $(ROOTLDFLAGS)

INCLUDES := -I./include
LIBS := $(ROOTGLIBS)

# Source and object files
SRCS = $(SRCDIR)/GetVectorTuple.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

.PHONY: all clean

all: $(BINDIR)/GetVectorTuple

$(BINDIR)/GetVectorTuple: $(OBJS)
	@echo "Doing application" $@ 
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@$(MKDIR_P) $(BINDIR)
	@$(MKDIR_P) ./output
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BINDIR)
