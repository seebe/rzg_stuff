
# BASH Profile

When you log into your board, the default command line shell (/bin/bash) will look for and execute the file .profile in your home directory (/home/root/).

But default in a standard Yocto build, it will not exists.

However, it's nice to have it with some customizations to make life easier for you.

This is basically what I use.

## Allias
Basicaly, these are macros that instead of typing in a long command line, you can make a 'shortcut' so to speak.
For example, you can just type "ll" and get a nice listing of the files in pretty colors.


## Install

### Manually copy to the SD Card
Simply copy the file profile.txt and rename it to /home/root/.profile.

### Using SCP over Ethernet
If you have a network connection to your board, you can just do the following:
(on host)$ scp profile.txt root@<BOARD-IP-ADDRESS>:/home/root/.profile

Now on your board in the serial terminal, type "exit" to log out, then log back in. Now you should be able to type the command "ll /bin" to see a colorful display of all executable files and links.

### Use the Copy/Paste clip board.
If you don't have a network connection on the board, and you don't feel like pulling out your SD Card, you can just use copy the test to your Linux/Windows clipboard and paste it into a file on your board.
Here is the procedure:
1. On your RZ/G board in the serial terminal, enter this command:
`$ vi ~/.profile`

2. Then on your host system, select all the text in the profile.txt file 'copy' it to the system clipboard.

3. Back in your serial terminal (where vi is running), press the "i" key on your keyboard to put you into 'text input' mode.

4. Now in your serial terminal, PASTE your text into the terminal. You will see all your text fill up the file.

5. To close and save this file, type the following keyboard sequence:
`  [ESC]  :   w   q  [ENTER]`

6. You should now be back to the command prompt. Type "exit" to log out of your shell.
7. Now log back in. Now you should be able to type the command "ll /bin" to see a colorful display of all executable files and links.

