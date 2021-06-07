#!/bin/bash

# setup default docker image tag
IMAGE_TAG=rz_world
WORK_DIR_=workdir

# if user give workdir, set it as workdir
if [ $1 ] ; then
	WORK_DIR_=$1
	if [ ! -d $WORK_DIR_ ]; then
		WORK_DIR_=$PWD
	fi
	# go into RZ world
	docker run -it --rm -h "renesas" -v $WORK_DIR_:$WORK_DIR_ -w $WORK_DIR_ $IMAGE_TAG /bin/bash
else
	# go into default RZ world
	docker run -it --rm -h "renesas" -v $PWD:/home/renesas/$WORK_DIR_ $IMAGE_TAG /bin/bash
fi
