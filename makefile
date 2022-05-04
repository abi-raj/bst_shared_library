name    := bst
version := 0.0.1

all: build

build:
	make -C bst/ 
	make link -C test/

gentar:
	tar --exclude-vcs --exclude-ignore=.gitignore -zcvf ${name}-${version}.tar.gz ./
	#cp ${name}-${version}.tar.gz ~/rpmbuild/SOURCES/