# Minesweeper Game in C++ #

This code implements a minesweeper game in either shell or by using a graphical user interface ***wxWidgets***.

## Prerequisites ##

Before running this code, ensure you have the following :

- ***g++** compiler installed on your system.
- ***wxWidgets*** installed on your system.

Sur ***Ubuntu*** :
```bash
sudo apt-get install libwxgtk3.0-dev
```

## Usage ##

1. Navigate to the **Code** directory containing the source code and the ***Makefile*** file.
```bash
cd Code
```
2. Compile the minesweeper game on both shell and graphical user interface by running ***make all***. Run ***make shellGame*** to just compile the minesweeper on shell. Run ***make wxGame*** to just compile the minesweeper on graphical user interface. 
```bash
make all
```
```bash
make shellGame
```
```bash
make wxGame
```
3. The compiled program(s) ***shellGame*** or/and ***wxGame*** is/are now located in the parent repository.
```bash
cd ..
```
4. Execute the compiled game on shell by running ***./shellGame***. Execute the compiled game on graphical user interface by running ***./wxGame***.
```bash
./shellGame
```
```{bash}
./wxGame
```

*(Optional)* 5. Clean the repository by running ***make clean*** in the **Code** directory.

```{bash}
cd Code
make clean
```

### ShellGame ###

### wxGame ###

## To do list ##

- [ ] Test the well functioning of the two programs.
- [ ] Add a IA tool to iteratively solve the minesweepper. More especially for the graphical user interface version.
