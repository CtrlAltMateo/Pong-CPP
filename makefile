pongpromax.exe: main.cpp menu.cpp menu.h game.cpp game.h graphics.cpp graphics.h config.h audio.h audio.cpp particles.cpp particles.h
	x86_64-w64-mingw32-g++ main.cpp menu.cpp game.cpp graphics.cpp audio.cpp particles.cpp -o pongpromax.exe \
                                                                   -O2 -Wall -s \
                                                                   -Iraylib/src \
                                                                   raylib/src/libraylib.a \
                                                                   -lopengl32 -lgdi32 -lwinmm -lpthread \
                                                                   -static -static-libgcc -static-libstdc++
                                                                   
web: main.cpp menu.cpp menu.h game.cpp game.h graphics.cpp graphics.h config.h audio.h audio.cpp particles.cpp particles.h
	em++ main.cpp menu.cpp game.cpp graphics.cpp audio.cpp particles.cpp -o index.html -O2 -Wall -Iraylib/src raylib/src/libraylib.web.a -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB --shell-file shell.html
