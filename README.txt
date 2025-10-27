How to compile main.cpp:

g++ main.cpp -IC:/SDL2/include -LC:/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -o main.exe

Paste this into MSYS2 UCRT64.

64 bit SDL2.dll should be in the same folder as main.cpp
64 bit libwinpthread-1.dll should be in the same folder as main.cpp
64 bit libstdc++-6.dll should be in the same folder as main.cpp
64 bit libgcc_s_seh-1.dll should be in the same folder as main.cpp
