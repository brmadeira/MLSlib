DIRS = include demo lib src
TARFILE = mlssurf.tar

all:
	cd src; make install; cd ..;
	cd demo; make install; cd ..;

tar:
	make clean;
	tar cvf $(TARFILE) $(DIRS) $(DATA) Makefile
	gzip $(TARFILE)

back:
	make clean;
	tar cvf $(TARFILE) $(DIRS) Makefile
	gzip $(TARFILE)
 
clean:
	cd src; make clean; cd ..;
	cd demo; make clean; cd ..;
	cd lib; rm -f *; cd ..;
	cd include; rm -f *; cd ..;








