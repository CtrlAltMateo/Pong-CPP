pongpromax.exe: main.cpp menu.cpp menu.h game.cpp game.h graphics.cpp graphics.h config.h audio.h audio.cpp particles.cpp particles.h
	x86_64-w64-mingw32-g++ main.cpp menu.cpp game.cpp graphics.cpp audio.cpp particles.cpp -o pongpromax.exe \
                                                                   -O2 -Wall -s \
                                                                   -Iraylib/src \
                                                                   /mnt/c/bin/raylib/libraylib.a \
                                                                   -lopengl32 -lgdi32 -lwinmm -lpthread \
                                                                   -static -static-libgcc -static-libstdc++
