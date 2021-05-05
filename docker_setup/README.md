# Using Docker to build the VLP64

The VLP64 uses Yocto 2.4 Rocko to build.
However, Yocto 2.4 only supports up to Ubuntu 16.04.
These instructions explain how to install and set up docker so that you can build the VLP64 inside a Ubuntu-16.04 docker container.

These instructions were created using Ubuntu 18.04.
More details here:
  https://docs.docker.com/install/linux/docker-ce/ubuntu/
  https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04

## 1. Inside vs Outside the container
When you operate inside a docker container, the entire container file system is isolated (contained) from the host system's file system. You can imagine from a security standpoint, this is very helpful. However, if your entire VLP64 is located inside this container, you **will not** be able to access it from your normal Ubuntu Desktop environment. That will make things more difficult for you!
Therefore, you should choose a location on your host machine that will be accessible from both inside and outside of your docker container. Like a 'shared directory'.

I suggest using the same path for both inside and outside. For example, if you make a directory called "yocto" off your home directory and then that directory will be accessible from inside the docker container.
Host PC:  /home/chris/yocto
docker container:  /home/chris/yocto


## 2. Docker Install

###  2.1 Set up the repository (Ubuntu 18.04 only)
Docker is not container in the standard Ubuntu download repositories,so you will have to download it directly from docker.
Copy/paste the following command to add the docker repository to the list of available download sources.
```
$ sudo apt update
$ sudo apt install apt-transport-https ca-certificates curl gnupg-agent software-properties-common
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
$ sudo apt-key fingerprint 0EBFCD88

	pub   rsa4096 2017-02-22 [SCEA]
	      9DC8 5822 9FC7 DD38 854A  E2D8 8D81 803C 0EBF CD88
	uid           [ unknown] Docker Release (CE deb) <docker@docker.com>
	sub   rsa4096 2017-02-22 [S

$ sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
```
###  2.2 Install the Docker Engine
Copy/paste the following commands to install the docker  (community edition).

Ubuntu 18.04:
```
$ sudo apt-get update
$ sudo apt-get install docker-ce docker-ce-cli containerd.io
```
Ubuntu 20.04:
```
$ sudo apt-get update
$ sudo apt-get install docker.io
```
(Optional, just to see if it installed)
```
$ sudo docker run hello-world
```

### 2.3 Check if docker is running (optional)
```
$ sudo systemctl status docker
```
**NOTE**: The command above puts you into vi...so you need to do this to exit:  [ESC]  +   [ : ]  + [  q  ]  + [ENTER]
Here is what you will see:
```
	chris$ sudo systemctl status docker
	\u25cf docker.service - Docker Application Container Engine
	   Loaded: loaded (/lib/systemd/system/docker.service; enabled; vendor preset: enabled)
	   Active: active (running) since Mon 2020-04-13 07:49:12 EDT; 4 days ago
		 Docs: https://docs.docker.com
	 Main PID: 2509 (dockerd)
		Tasks: 22
	   CGroup: /system.slice/docker.service
			   \u2514\u25002509 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock

	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.412197282-04:00" level=info msg="Loading containers: start."
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.436198563-04:00" level=warning msg="6129a9d87b19c0427ad4af0dc3fb9aba275ea05056705f7a6788ac435
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.641389384-04:00" level=info msg="Removing stale sandbox 3346937d1da7290f0f597bd7ad4afd9d59e0c
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.646117840-04:00" level=warning msg="Error (Unable to complete atomic operation, key modified)
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.701050867-04:00" level=info msg="Default bridge (docker0) is assigned with an IP address 172.
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.772810325-04:00" level=info msg="Loading containers: done."
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.842487009-04:00" level=info msg="Docker daemon" commit=633a0ea838 graphdriver(s)=overlay2 ver
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.842918272-04:00" level=info msg="Daemon has completed initialization"
	Apr 13 07:49:12 lenovo-p330 dockerd[2509]: time="2020-04-13T07:49:12.876262101-04:00" level=info msg="API listen on /var/run/docker.sock"
	Apr 13 07:49:12 lenovo-p330 systemd[1]: Started Docker Application Container Engine.
```

### 2.4 Add self to docker group  (so you do not have to 'sudo docker' every time)
This is not required, but it makes it easier to start docker each time :)
```
$ sudo usermod -a -G docker ${USER}
```
Then, completely **log out** of your account and log back in (or you could run "$ su - ${USER}"  to avoid having to logout/reboot just  this one time)

Check that you are part of the docker group now:
```
$ id -nG | grep docker
```
Docker install is basically done.

## 3. Create a Ubuntu 16.04 container
By creating a Ubuntu 16.04 container, all the system software running inside the container will be from the Ubuntu 16.04 release and completely compatible with Yocto 2.4 Rocko.

### 3.1 Download a pre-made Ubuntu 16.04 LTS "image"
Download a Ubuntu 16.04 LTS image from Docker Hub.
You have to specify the tag "xenial" to get the 16.04 version (xenial was the code name for Ubuntu 16.04)
```
$ docker pull ubuntu:xenial
```

### 3.2 Create a new "container" that is based on an "image"
You create 'containers' which are running instances of 'images'. They don't change the original image (it's like a clone).
But, if you want to save/transfer that container to another machine, or make another container using a current container as a starting point, you have to first 'commit' that container back to an 'image' file.
Note that many command line options/features are only available when you first create the container. If you missed something, you'll have to recreate the container from scratch again.

**3.2.1 Create a new container**
After you run the 'docker run' command, it will drop you off as user 'root' on the command line so you can set up your environment. At that point you will want to set up a user account (using the **same user name** that you use on your host machine) because you do not want to be doing everything inside your container as root.
Below use **your name** instead of "chris"
Also remember that we want to 'mount' a directory location outside our container to show up inside out container.
For this example, we will create a new directory called 'yocto' in your home directory.
Note that when we use the -v option, the directory inside the container will automatically be created.
The -it instructs Docker to allocate a pseudo-TTY connected to the container's stdin.
```
$ mkdir /home/$USER/yocto
$ docker run -it -v "/home/$USER/yocto":/home/$USER/yocto ubuntu:xenial

	[ inside the container ]
	## Set your user name to be the same as your host machine to match /home/$USER
	root@xxxxxxx:/#  MY_NAME=chris

	## Add yourself as a user
	root@xxxxxxx:/#  useradd -s /bin/bash $MY_NAME
	root@xxxxxxx:/#  passwd $MY_NAME
	Enter new UNIX password:
	Retype new UNIX password:
	passwd: password updated successfully

	## set up your home directory by copying default files
	root@xxxxxxx:/#  mkdir -p /home/$MY_NAME
	root@xxxxxxx:/#  cp -v /etc/skel/.bash* /home/$MY_NAME
	root@xxxxxxx:/#  cp -v /etc/skel/.profile /home/$MY_NAME
	root@xxxxxxx:/#  chown $MY_NAME:$MY_NAME /home/$MY_NAME/*

	## Add sudo, and then add yourself to it
	root@xxxxxxx:/#  apt-get update
	root@xxxxxxx:/#  apt-get install sudo
	root@xxxxxxx:/#  usermod -a -G sudo $MY_NAME

	# That's all we need to do as root since now we have sudo
	root@xxxxxxx:/#  exit
```
NOTE: The "xxxxxxx" will be your container ID. You can use that number to start up this specific container later.


**3.2.2 Start your container running (if it is stopped, doesn't show up in 'docker ps' )**
If you type
```
$ docker ps
```
and nothing shows up, that means no containers are running. If you add "-a" to that command you can see all the containers that you have created by have not started yet.
```
$ docker ps -a
```
NOTE: Docker will automatically make silly names for each container as well as container IDs.
You can either use the Container ID  value or silly name when referencing the container.
```
$ docker start distracted_bohr
```
or
```
$ docker start ff6d1973d9d9
```
Now you should see that your container is 'running'
```
$ docker ps   # this will show you the status of 'running' containers
```
**3.2.3 Enter back into your running "container" as a user**
Your container is running, but you need to enter back into by executing a shell terminal inside of it.
Remember to use your name instead of 'chris'.
You can use the container NAME  or CONTAINER ID
```
$ docker exec -it --user chris distracted_bohr /bin/bash
```

**3.2.4 Configure local for en_US.UTF-8**
By default for the Ubutnu images is that the local is not set,
so everything will be set to "POSIX". Yocto is not going to like that.
```
	[ inside the container ]
	$ locale     # notice that everything is "POSIX"

	# Set local as en_US.UTF-8
	$ sudo apt-get update
	$ sudo apt-get install locales
	$ sudo dpkg-reconfigure locales

		"149" will be "en_US.UTF-8 UTF-8", that's what we want to use.

		Locales to be generated: 149   <<<---- enter "149" -----

		  1. None  2. C.UTF-8  3. en_US.UTF-8
		Default locale for the system environment: 3  <<<--- enter "3"

	$ sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
	$ sudo update-locale LANG=en_US.UTF-8
	$ cat /etc/default/locale


	# NOTE: This this looks like it sets the default to en_US.UTF-8, but
	# in never really worked for me. Every time I ran 'locale', it always
	# kept saying "POSIX", and of course Yocto would not build.
	# So, after doing the steps above, I added a line to my ~/.bashrc
	# so it would automaticlly set LANG each time I logged in, and that
	# worked every time.

	$ echo '' >> ~/.bashrc
	$ echo '# Set locale manually' >> ~/.bashrc
	$ echo 'export LANG=en_US.UTF-8' >> ~/.bashrc
	$ source ~/.bashrc
	$ locale

	# you can leave the conainter at any time.
	$ exit
```
**3.2.5 Change time zone inside container**
The container will get the time and date from the host machine, but the time zone might be different. Therefor set the timezone inside the container to match your host machine using the tzdata.
```
	[ inside the container ]
	$ sudo apt-get install tzdata
	$ sudo dpkg-reconfigure tzdata
	$ ls -la /etc/localtime
	lrwxr-xr-x  1 root  wheel  36 Aug 24 13:17 /etc/localtime -> /usr/share/zoneinfo/America/New_York
```
**3.2.6 Add 'tumx' so things like menuconfig will display correctly**
When you inside a container, the "terminal" you are executing commands is not a standard terminal and some things will not display correctly. However, you can run 'tumx' which emulates a standard terminal and then things (like menuconfig) will all look correct inside your container.
```
	#Install tmux
	[ inside the container ]
	$ sudo apt-get install tmux
```
Run this each time you enter the container (before you start to do any Yocto work)
```
	$ tmux
```
You can do many things with tmux like divide your 1 container terminal into multiple terminals all running in the same container. The key stroke "Ctrl + b" is used to send command to tux.
 * Use "Ctrl-b", the "?" to see a list of commands
 * Example: Ctrl-b  + %  (will split the window in 2 and give you a new terminal)

### 3.3. Suggestions software packages to add inside your container
Here are some common packages that are useful inside your container even though you will only be using it for Yocto builds.
```
$ sudo apt-get update
$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm cpio python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping libssl-dev
```
For menuconfig, you need the ncurser package:
```
$ sudo apt-get install libncurses5-dev libncursesw5-dev
```

From the RZ/G2 VLP64 build instructions, these packages are required:
```
$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
build-essential chrpath socat cpio python python3 python3-pip python3-pexpect \
xz-utils debianutils iputils-ping libsdl1.2-dev xterm p7zip-full
```


**Your container is now set up.**

### 3.4 Generate the Ubuntu 16.04 image by using dockerfile
In order to generate the build environment with docker more easier, You can just use Dockerfile.ubuntu1604 file. The default image tag is "rzg", you can also replace to yours.
```
$ docker build --no-cache --build-arg "host_uid=$(id -u)" --build-arg "host_gid=$(id -g)" --build-arg "USERNAME=$USER" --tag rzg -f ./Dockerfile.ubuntu1604 .
$ docker images
REPOSITORY   TAG       IMAGE ID       CREATED       SIZE
rzg          latest    1234567890ab   5 hours ago   1.18GB
$ 
```

## 4. Using your Container

**4.1 Start your container running (if it is stopped, doesn't show up in 'docker ps' )**
After each system restart, you will need to start up your container again. You can use 'docker ps -a' if you've forgotten the name or ID of your container.
```
$ docker ps -a
$ docker start distracted_bohr
```

**4.2 Enter back into your running "container" as a user**
During the creation and setup of your container, you created a user account with the same name as your host machine. When entering into your container, use that user account (not root).
```
$ docker exec -it --user chris distracted_bohr /bin/bash
```

**4.3 Rename a container (in case you don't like the silly name)**
If you really don't like the name that was automatically generated, you can change it using the docker rename command.
```
$ docker rename CONTAINER NEW_NAME
```

**4.4 Run the container if you generate the image by the Dockerfile.ubuntu1604 file**
Make sure you put everything into your host workdir folder. Here is an example below.
```
$ cd $HOME/workdir
$ ls
build  extra  meta-gplv2  meta-openembedded  meta-rzg2  poky
$ docker run -it --rm -v $PWD:/workdir rzg /bin/bash
user@docker:/workdir $ source poky/oe-init-build-env
user@docker:/workdir/build $ bitbake core-image-minimal
user@docker:/workdir/build $ 
```


## 5. extra notes
```
$ docker images		# shows you your availible images
$ docker ps		# shows running containers
$ docker ps -a		# shows all containers (running and not running)
$ docker start -i <container>
$ docker rm <container>	# remove a container
$ docker rmi <image>	# remove a image
```
### 5.1 A script to make it easy to start up your container
In this directory there is a script file "enter_container.sh". You can copy it to your /home/$USER/yocto directory and edit the value of "CONTAINER_NAME" inside the script. Now you have an easy way to start your container.

### 5.2 Change your prompt inside your container
When you are **inside** your container, you can change the prompt in your terminal to make it easier to remember what window is your docker window.
When you are inside your container, simply add the following 2 lines to your contianer's  ~/.bashrc file.
```
PS1="\[\e[33m\]dir: \w\n\[\e[1;31m\](docker)$\[\e[00m\] "

printf "\e]2;docker\a"
```


## 6. Add a mount to a container that you've already created
 * These instructions are for if you used the docker run command without the -v option, but now you decide you want it.

A container has its own restricted file system space.
Any files you create in that container can only be accessed from within that container.
You might want the container just so you can do Yocto builds on files that reside outside of your container.
In that case, you'll want to 'mount' a directly inside your container.
Note, you can only add a mount when you first [create] the container.
That was done with the 'docker run' command.
So if you didn't do it, you'll have to save what you have as a new 'image' and then make a new container from that.

For example, I want to mount an OUTSIDE directory of /home/renesas/ to the location /home/renesas/ INSIDE my container. Basically so I can get to all my files from inside or outside my container environment.
First I had to make a directory " /home/renesas " inside my container:
```
	[ inside the container ]
	$ sudo mkdir /home/renesas
	$ sudo chown chris:chris /home/renesas
	$ exit
```
You can commit your existing 'container' (that is create a new 'image' from
container's changes) and then run it with your new mounts.
   'docker commit 5a8f89adeead newimagename'

$ docker commit distracted_bohr ubuntu_16.04_chris
$ docker images

Create a new container using that new image
$ docker run -ti -v "/home/renesas/yocto":/home/renesas/yocto ubuntu_16.04_chris /bin/bash

Now start that new container and enter it. Everything should be the same, but now you can see /home/renesas
```
$ docker start dreamy_shannon
$ docker exec -it --user chris dreamy_shannon /bin/bash
```

You can remove your old container now because it's not needed anymore
```
$ docker rm distracted_bohr
```


