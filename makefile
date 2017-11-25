# Tomer Grady 205660863
# Raz Shenkman 311130777

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: src/*.h src/*.cpp
	g++ -c src/*.cpp
