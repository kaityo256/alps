include /opt/alps/share/alps/include.mk

all: a.out

a.out: test.cc
	g++ test.cc $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBS)

run:
	/opt/alps/bin/parameter2xml params
	export HDF5_DISABLE_VERSION_CHECK=1;export OMP_NUM_THREADS=1;./a.out params.in.xml
	open params.out.xml

clean:
	rm -f a.out

clear:
	rm -f *.h5 *xml *.lck *.xsl
