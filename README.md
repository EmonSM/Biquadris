# Biquadris
Biquadris is a non-real time variant of the classic game of Tetris, expanded for two player competition. This is a C++ version of Biquadris, that was built from scratch by a team of 3 developers: Abhishek Patel, Rav Kundi, and myself (Emon Sen Majumder) over the course of two weeks. The architecture of this application is based OOP principles, and utilizes both the Model View Controller (MVC) design pattern for its overall design and also the Factory Method pattern for block generation since blocks are level-dependant.

Text-based Display Examples:

![image](https://user-images.githubusercontent.com/55682406/134313295-47677310-cc9c-40d7-97a7-40854c8c7b82.png)

![image](https://user-images.githubusercontent.com/55682406/134313910-b999e264-55af-465c-b0e2-9cb39ecdad25.png)

Graphical Display Examples (please ignore the glitched font, it is a recent bug introduced to XQuartz due to the macOS Big Sur update):

![image](https://user-images.githubusercontent.com/55682406/134314245-f145754b-3f01-437e-8c60-7eb4223554ef.png)

![image](https://user-images.githubusercontent.com/55682406/134314075-df44656b-3d67-4dd6-bc93-22320cd40400.png)

Build Instructions (MacOS only):
1. Install XQuartz - https://www.xquartz.org/. This is a version of the X Window System that runs on macOS, and is necessary to run the graphics portion of this application.
2. Restart your computer (mandatory).
3. Attempt running the terminal command "make" from within the local repository.
4. If this command fails due to an "X11/Xlib.h not found" error, then you will need to modify the Makefile. This is because the Makefile needs to explicitly tell g++ where X11 is located, and your computer has installed X11 in a different location than what is currently in the Makefile. Look for a directory named "X11" that contains the directories "lib" and "include" by browsing your Mac's file system.
5. Once you have found these folders, edit the Makefile. Change "-L/usr/X11/lib" to "-L...", where ... is the pathname for X11's "lib" directory on your computer. Change "-I/usr/X11/include" to "-I...", where ... is the pathname for X11's "include" directory on your computer.
6. Run the terminal command "make" from within the local repository.
7. Run the compiled application from the command line. i.e. "./biquadris" or ./biquadris -text" (runs the program in text-only mode).

Rules:

A game of Biquadris consists of two boards, each 11 columns wide and 15 rows high. Blocks consisting of four cells (tetrominoes) appear at the top of each board, and you must drop them onto their respective boards so as not to leave any gaps. Once an entire row has been filled, it disappears, and the blocks above move down by one unit. Biquadris differs from Tetris in one significant way: it is not real-time. You have as much time as you want to decide where to place a block. Players will take turns rotating, moving, and dropping blocks, one at a time. A player’s turn ends when he/she has dropped a block onto the board. During a player’s turn, the block that the opponent will have to play next is already at the top board (and if it doesn’t fit, the opponent has lost). 
There are seven types of blocks:

![image](https://user-images.githubusercontent.com/55682406/134312264-a17eefcb-537c-4231-bef1-b91d71e524ef.png)

Controls:

You interact with the game by issuing text-based commands. The following commands are supported:

• left moves the current block one cell to the left. If this is not possible (left edge of the board, or block in the way), the command has no effect.

• right as above, but one cell to right.

• down as above, but one cell downward.

• clockwise rotates the block 90 degrees clockwise. If the rotation cannot be accomplished without coming into contact with existing blocks, the command has no effect.

• counterclockwise as above, but counterclockwise.

• drop drops the current block. It is (in one step) moved downward as far as possible until it comes into contact with either the bottom of the board or a block. This command also triggers the next block to appear. Even if a block is already as far down as it can go (as a result of executing the down command), it still needs to be dropped in order to get the next block.

In addition, commands can take a multiplier prefix, indicating that that command should be executed some number of times. For example 3right means move to the right by three cells.

Scoring:

The game is scored as follows: when a line (or multiple lines) is cleared, you score points equal to (your current level, plus number of lines) squared. (For example, clearing a line in level 2 is worth 9 points.) In addition, when a block is completely removed from the screen (i.e., when all of its cells have disappeared) you score points equal to the level you were in when the block was generated, plus one, squared. (For example if you got an O-block while on level 0, and cleared the O-block in level 3, you get 1 point.)
