-include packages

# packages/Makefile.  Generated from Makefile.in by configure.


CXX=g++
CXXFLAGS= -fno-omit-frame-pointer -D_GNU_SOURCE -march=native  -O3 -g -gdwarf-2 -std=c++11 -flto
YACC=bison -y
O=o
DRIVER_BIN=driver
INSTALL=/usr/bin/install -c
INSTALL_DIR=/mud/fluffos/bin
OPTIMIZE=-O3

.cc.$(O):
	$(CXX) -c -I.. $(CXXFLAGS) -x c++ -o $@ $<

all: $(OBJ)

# crypto
crypto.$(O): crypto.cc
	$(CXX) -c $(CXXFLAGS) -I..  -x c++ -o $@ $<

# special db stuff
async.$(O): async.cc
	$(CXX) -c $(CXXFLAGS) -I..    -x c++ -o $@ $<

db.$(O): db.cc
	$(CXX) -c $(CXXFLAGS) -I..    -x c++ -o $@ $<

# pcre
pcre.$(O): pcre.cc
	$(CXX) -c $(CXXFLAGS) -I..  -x c++ -o $@ $<

clean:
	-rm -f *.d
	-rm -f *.$(O)
