all:
    cl mainprogramming.cpp implementation.cpp
    mainprogramming.exe

clean:
     del *.obj
     del *.exe