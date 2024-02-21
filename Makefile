exe:
	g++ ./src/*.cpp $$(root-config --glibs --cflags --libs) -o ./bin/main
pdf-only:
	cd ./tex; lualatex --shall-escape --output-dir=build main.tex
clean:
	rm -rf ./tex/build/*.aux ./tex/build/*.log
pdf: pdf-only clean