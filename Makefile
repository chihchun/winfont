winfont.exe: winfont.cpp
	i586-mingw32msvc-g++ -o winfont.exe winfont.cpp -mwindows

run: winfont.exe
	wine winfont.exe
