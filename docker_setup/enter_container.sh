#!/bin/bash

PWD=`pwd`

# Set the name of the container here
CONTAINER_NAME=dreamy_shannon


docker ps | grep $CONTAINER_NAME
if [ "$?" != "0" ] ; then

  # if 'dreamy_shannon' is not listed, then start it
  docker start $CONTAINER_NAME
  sleep 2
fi

# This command changes the title of your terminal window to "docker".
# This will make it easier to find when you have multiple terminal windows open

printf "\e]2;docker\a"

# Here are some helpful tmux commands
# tmux
# tmux Ctrl + b
# To switch between the panes use Ctrl+b arrow key
# join-pane -s 2 -t 1 
# break-pane
# Ctrl+b % to split the pane vertically
# To switch between the panes use Ctrl+b arrow key
# :resize-pane -D (Resizes the current pane down)
# :resize-pane -U (Resizes the current pane upward)
# :resize-pane -L (Resizes the current pane left)
# :resize-pane -R (Resizes the current pane right)
# :resize-pane -D 10 (Resizes the current pane down by 10 cells)
# :resize-pane -U 10 (Resizes the current pane upward by 10 cells)
# :resize-pane -L 10 (Resizes the current pane left by 10 cells)
# :resize-pane -R 10 (Resizes the current pane right by 10 cells)

# tmux cheat sheet: https://gist.github.com/MohamedAlaa/2961058

echo "============================================================="
echo "Helpful copy/paste commands"
echo "cd "$PWD" ; tmux"
echo ""
echo "source poky/oe-init-build-env"
echo "bitbake linux-renesas -c devshell"
echo "bitbake linux-renesas -c menuconfig"

# Enter our container
docker exec -it --user chris dreamy_shannon /bin/bash

#docker exec -t container_name /bin/bash -c "export COLUMNS=`tput cols`; export LINES=`tput lines`; exec bash"

#docker exec -it container_name sh -c "stty rows 50 && stty cols 150 && bash"
