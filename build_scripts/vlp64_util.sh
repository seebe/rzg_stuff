#!/bin/bash

START_DIR=`pwd`

if [ "$1" == "" ] ; then

	echo "
usage:
  $0 create	# create a new repository
  $0 update	# update an existing repo with a new VLP64 release
"
	exit
fi

function check_for_dir {
	# check if directory already exists
	if [ -e "$TARGET_DIR" ] ; then
		echo "ERROR: The directory \""$TARGET_DIR"\" already exists"
		echo "Please choose a different [base_directory], or a different [dir_name]"
		exit
	fi
}

vlp64_releases=(
	"BSP-1.0.4"
#	"BSP-1.0.4-update1"
#	"BSP-1.0.4-RT"
#	"BSP-1.0.4-RT-update1"
	"BSP-1.0.5"
	"BSP-1.0.5-RT"
	"BSP-1.0.5-RT-update1"
	"BSP-1.0.6-update1"
)
branch_names=(
	"vlp64_v104"
#	"vlp64_v104-update1"
#	"vlp64_v104rt"
#	"vlp64_v104rt-update1"
	"vlp64_v105"
	"vlp64_v105rt"
	"vlp64_v105rt-update1"
	"vlp64_v106-update1"
)

#DIR="vlp64_v105rt"

function select_vlp64 {
	echo "What VLP64 BSP version do you want?"
	for i in ${!vlp64_releases[@]}; do
		echo ${i}.  ${vlp64_releases[$i]}
	done
	echo -n "choice: "
	read ans
	VLP64_REL=${vlp64_releases[$ans]}
	BRANCH_NAME=${branch_names[$ans]}

	if [ "$VLP64_REL" == "" ] ; then
		echo -e "\nError reading choice"
		exit
	fi
}



if [ "$1" == "create" ] ; then

	if [ "$2" == "" ] || [ "$3" == "" ] ; then
		echo "$0 create:
	Creates a new repository based on a specific VLP64 release.
This will clone a public repository and then apply all the required patches to
reproduce what was contained in the VLP64 Yocto build.
At that point, you can then use the \"build.sh\" script to reproduce the
binaries outside to Yocto.

Uasge:
$0 create [package] [base_directory] (dir_name)

[package] choices:
 - \"flash_writer\" (or \"fw\")
 - \"arm-trusted-firmware\" (or \"atf\")
 - \"u-boot\" (or \"ub\")
 - \"kernel\" (or \"k\")

[base_directory]:
 - This is the base directory where a new repository directory will be created under.
   For example, if you pass:
       $0 create arm-trusted-firmware ~/my_vlp
   a new direcotry will be created: ~/my_vlp/arm-trusted-firmware

[dir_name] (Optional)
 - In case you do not want to use the default direcotry name, you can
   pass in yoru own name.
   For example, if you pass:
       $0 create  arm-trusted-firmware  ~/my_vlp  arm-trusted-firmware_myboard
   a new direcotry will be created: ~/my_vlp/arm-trusted-firmware_my_board"

		exit
	fi
	if [ "$2" == "arm-trusted-firmware" ] || [ "$2" == "atf" ] ; then
		REPO="ATF"
		PATCH_DIR_NAME="arm-trusted-firmware"
		BUILD_SCRIPT_DIR_NAME="arm-trusted-firmware"
		if [ "$4" == "" ] ; then
			TARGET_DIR="$3/arm-trusted-firmware"
		else
			TARGET_DIR="$3/$4"
		fi

	elif [ "$2" == "kernel" ] || [ "$2" == "k" ] ; then
		REPO="KERNEL"
		PATCH_DIR_NAME="kernel"
		BUILD_SCRIPT_DIR_NAME="linux-cip"
		if [ "$4" == "" ] ; then
			TARGET_DIR="$3/linux-cip"
		else
			TARGET_DIR="$3/$4"
		fi
	elif [ "$2" == "u-boot" ] || [ "$2" == "ub" ] ; then
		REPO="UBOOT"
		PATCH_DIR_NAME="u-boot"
		BUILD_SCRIPT_DIR_NAME="renesas-u-boot-cip"
		if [ "$4" == "" ] ; then
			TARGET_DIR="$3/renesas-u-boot-cip"
		else
			TARGET_DIR="$3/$4"
		fi
	elif [ "$2" == "flash_writer" ] || [ "$2" == "fw" ] ; then
		REPO="FLASH_WRITER"
		PATCH_DIR_NAME="rzg2_flash_writer"
		BUILD_SCRIPT_DIR_NAME="rzg2_flash_writer"
		if [ "$4" == "" ] ; then
			TARGET_DIR="$3/rzg2_flash_writer"
		else
			TARGET_DIR="$3/$4"
		fi
	else
		echo -e "\nERROR: Unrecognized pacakge name \"$2\"\n"
		exit
	fi


	check_for_dir

	select_vlp64

	echo ""

	# Read in the values for that version
	source vlp64_patches/$VLP64_REL/info.txt

	echo "mkdir -p $TARGET_DIR"
	mkdir -p "$TARGET_DIR"
	echo "cd $TARGET_DIR"
	cd "$TARGET_DIR"

	SRC_REPO=${REPO}_REPO
	echo "git clone $(eval echo ${!SRC_REPO}) ."
	git clone $(eval echo ${!SRC_REPO}) .

	HASH=${REPO}_COMMIT
	echo "git checkout -b $BRANCH_NAME $(eval echo ${!HASH})"
	git checkout -b $BRANCH_NAME $(eval echo ${!HASH})

	# Is there patches to apply?
	if [  -e "$START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/patches" ] ; then

		# apply patches
		# --whitespace=nowarn
		# --whitespace=fix
		# --reject
		echo "git am --whitespace=nowarn $START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/patches/*"
		git am --whitespace=nowarn $START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/patches/*

		if [ "$?" != "0" ] ; then
			# the git am failed
			echo -e "\n\nERROR: Failed to apply patches\n\n"
			exit
		fi
	fi

	# Copy config files
	if [  -e "$START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/configs" ] ; then
		echo -e "\nCopying config files...\n"
		mkdir -p .config_options
		cp -v $START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/configs/* .config_options
	fi

	# Create a tag at his point
	git tag $VLP64_REL

	# mbed code is needed for arm-trusted-firmware VLP1.0.5+
	if [ "$REPO" == "ATF" ] && [ "$MBEDTLS_REPO" != "" ] ; then
		if [ -e mbedtls ] ; then
			cd mbedtls
			git fetch
		else
			git clone $MBEDTLS_REPO mbedtls
			cd mbedtls
		fi
		git checkout $MBEDTLS_BRANCH
		git checkout $MBEDTLS_COMMIT
		cd ..
	fi

	echo -e "\n----------------------------------------------------"
	echo -e "  Repository created at: $TARGET_DIR"
	echo -e "  Branch created: $BRANCH_NAME"
	echo -e "  Tag created: $VLP64_REL"
	echo -e "----------------------------------------------------\n"

	# Create a symlink to build.sh
	echo "A script build.sh exists for making it easier to compile the $PATCH_DIR_NAME code."
	echo "How would you like to install the build.sh script?"
	echo ""
	echo "1. Place a COPY of build.sh into the repository directory?"
	echo "   If the build.sh script gets update, youwill have to manually"
	echo "   copy in the new version"
	echo ""
	echo "2. Place a SYMLINK to build.sh into the repository directory?"
	echo "   This means if the rzg_stuff repo gets updated, the build.sh"
	echo "   script automatically gets updated"
	echo ""
	echo "3. Do nothing"
	echo "   (I do not want the build.sh script)"
	echo ""
	echo -n "  Enter Choice: "
	read ans
	if [ "$ans" == "1" ] ; then
		cp -v $START_DIR/$BUILD_SCRIPT_DIR_NAME/build.sh $TARGET_DIR
	fi
	if [ "$ans" == "2" ] ; then
		ln -s $START_DIR/$BUILD_SCRIPT_DIR_NAME/build.sh $TARGET_DIR
	fi
	exit

fi


if [ "$1" == "update" ] ; then

	if [ "$2" == "" ] ; then
		echo "$0 update:
	Updates a repository based on a specific VLP64 release.
This will add a new branch to your repository that will contain the
patches for that release.
You can then use the \"build.sh\" script to reproduce the
binaries outside to Yocto.

Uasge:
$0 update [repo_directory]

[repo_directory]:
 - This is the directory where a repository directory is located.
   For example, if you pass:
       $0 update ~/rzg/arm-trusted-firmware
"
		exit
	fi

	# Check for the directory
	if [ ! -e "$2" ] ; then
		echo -e "\nERROR: Directory does not exist \"$2\"\n"
		exit
	fi

	# what repos is it?
	if [ -e "$2/bl1" ] ; then
		REPO="ATF"
		PATCH_DIR_NAME="arm-trusted-firmware"
	elif  [ -e "$2/cmd" ] ; then
		REPO="UBOOT"
		PATCH_DIR_NAME="u-boot"
	elif  [ -e "$2/AArch64_boot" ] ; then
		REPO="FLASH_WRITER"
		PATCH_DIR_NAME="flash_writer"
	elif  [ -e "$2/kernel" ] ; then
		REPO="KERNEL"
		PATCH_DIR_NAME="kernel"
	else
		echo -e "\nERROR: Cannot detect what repo is located there: \"$2\"\n"
		exit
	fi

	echo "Detected $PATCH_DIR_NAME"

	cd $2

	# make sure we do not have any modified files
	MODIFIED_FILES=`git status --untracked-files=no --porcelain`
	if [ "$MODIFIED_FILES" != "" ] ; then

		echo -e "\nERROR: You cannot leave any files modifed files not checked in.\n"
		echo "$MODIFIED_FILES"
		echo -e "\nPlease either:"
		echo "Discard your changes:"
		echo "    $ git checkout {file}"
		echo "Commit your changed to all modified files to the repo:"
		echo "    $ git add -u ;  git commit --message=\"my saved files\""
		echo "Temporary 'stash' your files. You can use use \"git stash pop\" to restore them later"
		echo "    $ git stash"
		exit
	fi

	# Find out what branches alread exist
	git branch > /tmp/branch_names.txt

	echo -e "\n These branches already exits in your repo:"
	for i in ${branch_names[@]} ; do
		while read line ; do
			if [ "$i" == "$line" ] || [ "* $i" == "$line" ] ; then
				echo " - $i"
			fi
		done < /tmp/branch_names.txt
	done
	echo ""

	select_vlp64

	# make sure that branch does not alrady exits
	#git branch --list $BRANCH_NAME 2>&1 >/dev/null
	git branch --list $BRANCH_NAME | grep $BRANCH_NAME
	if [ "$?" == "0" ] ; then
		echo -e "\nERROR: That version already exists in your repo\n"
		exit
	fi

	# Read in the values for that version
	source ${START_DIR}/vlp64_patches/$VLP64_REL/info.txt

	# Check if we can use an existing branch/tag
	SAME=${REPO}_SAME
	SAME_RELEASE="$(eval echo ${!SAME})"
	if [ "$SAME_RELEASE" != "" ] ; then
		git tag --list $SAME_RELEASE | grep $SAME_RELEASE
		if [ "$?" == "0" ] ; then
			echo -e "\nThe release \"$VLP64_REL\" is the same as release \"$SAME_RELEASE\"."
			echo -e "Therefore we will just create a branch and tag at same point\n"

			git checkout -b $BRANCH_NAME $SAME_RELEASE
			git tag  $VLP64_REL

			echo -e "\n----------------------------------------------------"
			echo -e "  Branch created: $BRANCH_NAME"
			echo -e "  Tag created: $VLP64_REL"
			echo -e "----------------------------------------------------\n"

			exit
		fi
	fi

	# fetch updates from the repo
	git fetch

	# Try to check out the commit hash
	HASH=${REPO}_COMMIT
	git checkout -b $BRANCH_NAME $(eval echo ${!HASH})
	if [ "$?" != "0" ] ; then
		echo -e "\nERROR: Cannot find correct repo commit.\n"
		exit
	fi

	# Is there patches to apply?
	if [  -e "$START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/patches" ] ; then
		# apply patches
		# --whitespace=nowarn
		# --whitespace=fix
		# --reject
		echo "git am --whitespace=nowarn $START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/patches/*"
		git am --whitespace=nowarn $START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/patches/*

		if [ "$?" != "0" ] ; then
			# the git am failed
			echo -e "\n\nERROR: Failed to apply patches\n\n"
			exit
		fi
	fi

	# Copy config files
	if [  -e "$START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/configs" ] ; then
		echo -e "\nCopying config files...\n"
		mkdir -p .config_options
		cp -a "$START_DIR/vlp64_patches/$VLP64_REL/$PATCH_DIR_NAME/configs/*" .config_options
	fi

	# Create a tag at his point
	git tag $VLP64_REL

	echo -e "\n----------------------------------------------------"
	echo -e "  Branch created: $BRANCH_NAME"
	echo -e "  Tag created: $VLP64_REL"
	echo -e "----------------------------------------------------\n"

	exit
fi

echo "ERROR: Unknown command \"$1\""
echo "
usage:
  $0 create	# create a new repository
  $0 update	# update an existing repo with a new VLP64 release
"

