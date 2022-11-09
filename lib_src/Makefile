CC = g++
ESIN = .
HPPS = $(ESIN)/incl/esin
AR = ar
src = error.cpp util.cpp gen_driver.cpp mem_din.cpp
hdrs = $(HPPS)/error $(HPPS)/util $(HPPS)/gen_driver $(HPPS)/mem_din
objs = error.o util.o gen_driver.o mem_din.o 
picobjs = error.pic.o util.pic.o \
          gen_driver.pic.o dummy.pic.o mem_din.pic.o
CPPFLAGS = -g -std=c++98 -ansi -Wall -I $(ESIN)/lib/incl $(DEBUG) 

all: dynamic

libesin.a: $(objs)
	$(AR) -r $@ $(objs) 

libesin-SunOS.so: $(src) dummy.cpp
	$(CC) $(CPPFLAGS) -G -fpic -o libps-Solaris.so $<

libesin.so: $(picobjs)
	 $(CC) -g -o $@ -fpic -shared -Ur  $(picobjs) 

dynamic: libesin.so

static: libesin.a

%.pic.o: %.cpp $(hdrs)
	$(CC) -c -fpic $(CPPFLAGS) $< -o $@

%.o:	%.cpp $(hdrs)
	$(CC) -c $(CPPFLAGS) $<

tgz:	
	tar cvzf libesin-includes.tgz incl/*

clean:	
	rm -rf *.o *.tex *.toc *.dvi *.log *.aux *.out *~

superclean: clean
	rm -f *.toc *.bbl *.e
	rm -f *.ps *.pdf
	rm -f *.so *.a core 

# 	echo -n 'g++ ' > version-info
# 	g++ --version >> version-info
# 	ld -v >> version-info
# 	head -1q $(src) >> version-info
# 	head -1q $(hdrs) >> version-info

