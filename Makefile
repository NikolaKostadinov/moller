make:
	g++ ./src/*.cpp $$(root-config --glibs --cflags --libs) -o ./bin/main