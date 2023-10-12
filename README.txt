2023-2 CAU CSE 객체지향프로그래밍 과제 프로젝트 1 학생 정보 관리 프로그램

# OOP_Project01_Prob2

very briefly explain how to compile and execute the source code.
(explain which OS and compiler (which version) you used, and how I can compile
and execute your code (e.g. “click run button in Visual Studio”, or execute ”make“)


### Compile with Makefile
```$ make```
or
```$ make all```


### Etc make command

```$ make clean```
rm -f $(OBJS)

```$ make fclean```
make clean
rm -f $(NAME)

```$ make re```
make fclean
make all

### Excute

```$ ./a.exe ```

or

```$ ./a.exe file1.txt```

or

```$ make test```

if file1.txt does not exist, file1.txt is automatically made by a.exe program


### Compiler
In Makefile, $(GC) is mapping g++, but actually, my compiler is clang

```
oop_prob2 git:(main) ✗ g++ --version
Apple clang version 14.0.3 (clang-1403.0.22.14.1)
Target: arm64-apple-darwin23.0.0
Thread model: posix
```

### OS
MacOS Sonoma version 14.0 | arm64 (M1 chip)
