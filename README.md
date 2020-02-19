# Game 2048

This is Game 2048 which I wrote in C. In this repository there are 2 versions according to the interface used, which are standard input/output and ncurses. 

In the development, I separate the functions and procedures into several files:
* Functions : Manages the logic of the game.
* Interface : Manages the inputs and renders the game. There are 2 version of this file : `interface_2048.c`and `interface_2048_curse.c`.
* Main file (`jeu_2048.c`and `jeu_2048_curse.c`)
As you can see both versions use the same function file but different interface file and main file.

## Dependencies for Running Locally
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* Library ncurses
  * Linux: ncurses is installed by default on most Linux distros
  * Mac: ncurses is installed by default on Mac OSX
  * The ncurses library source code can be found [here](ftp://ftp.gnu.org/gnu/ncurses/)

## Basic Build Instructions
### 2048 basic 
1. Clone this repo.
3. Compile: `make jeu_2048`
4. Run it: `./jeu_2048`

### 2048 with library ncurses
1. Clone this repo.
3. Compile: `make jeu_2048_curse`
4. Run it: `./jeu_2048_curse`
