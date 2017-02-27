all:
	mkdir -p build && cd build && cmake .. && make --no-print-directory

%:
	cd build && make --no-print-directory $@
