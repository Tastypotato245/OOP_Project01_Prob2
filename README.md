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


if file1.txt does not exist, file1.txt is automatically made by a.exe program
