pongpromax.exe: main.cpp game.cpp game.h graphics.cpp graphics.h config.h audio.h audio.cpp
	x86_64-w64-mingw32-g++ main.cpp game.cpp graphics.cpp audio.cpp -o pongpromax.exe \
                                                                   -O2 -Wall -mwindows -s \
                                                                   -Iraylib/src \
                                                                   raylib/src/libraylib.a \
                                                                   -lopengl32 -lgdi32 -lwinmm -lpthread
