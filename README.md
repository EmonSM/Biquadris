# Biquadris
Biquadris is a variant of the classic game Tetris, expanded for two player competition. This is a C++ version of Biquadris, that was built from scratch by a team of 3 developers: Abhishek Patel, Rav Kundi, and myself (Emon Sen Majumder). This project utilizes the Model View Controller (MVC) design pattern for its overall design and also uses the Factory Method pattern for block generation since blocks are level-dependant. 

Build Instructions (MacOS only):
1. Install XQuartz - https://www.xquartz.org/. This is a version of the X Window System that runs on macOS, and is necessary to run the graphics portion of this application.
2. Restart your computer (mandatory).
3. Attempt running the terminal command "make" from within the local repository.
4. If this command fails due to an "X11/Xlib.h not found" error, then you will need to modify the Makefile. This is because the Makefile needs to explicitly tell g++ where X11 is located, and your computer has installed X11 in a different location than what is currently in the Makefile. Look for a directory named "X11" that contains the directories "lib" and "include" by browsing your Mac's file system.
5. Once you have found these folders, edit the Makefile. Change "-L/usr/X11/lib" to "-L...", where ... is the pathname for X11's "lib" directory on your computer. Change "-I/usr/X11/include" to "-I...", where ... is the pathname for X11's "include" directory on your computer.
6. Run the terminal command "make" from within the local repository.
7. Run the compiled application from the command line. i.e. "./biquadris" or ./biquadris -text" (runs the program in text-only mode).

Controls:
You interact with the system by issuing text-based commands. The following commands are to be
supported:
• left moves the current block one cell to the left. If this is not possible (left edge of the board,
or block in the way), the command has no effect.
• right as above, but one cell to right.
• down as above, but one cell downward.
• clockwise rotates the block 90 degrees clockwise. If the rotation cannot
be accomplished without coming into contact with existing blocks, the command has no effect.
• counterclockwise as above, but counterclockwise.
• drop drops the current block. It is (in one step) moved downward as far as possible until
it comes into contact with either the bottom of the board or a block. This command also
triggers the next block to appear. Even if a block is already as far down as it can go (as a
result of executing the down command), it still needs to be dropped in order to get the next
block.
In addition, commands can take a multiplier prefix, indicating that that command should be
executed some number of times. For example 3right means move to the right by three cells.

Scoring
The game is scored as follows: when a line (or multiple lines) is cleared, you score points equal to
(your current level, plus number of lines) squared. (For example, clearing a line in level 2 is worth 9
points.) In addition, when a block is completely removed from the screen (i.e., when all of its cells
have disappeared) you score points equal to the level you were in when the block was generated,
plus one, squared. (For example if you got an O-block while on level 0, and cleared the O-block in
level 3, you get 1 point.)
