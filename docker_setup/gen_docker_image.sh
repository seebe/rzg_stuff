#!/bin/bash

# setup default docker image tag
IMAGE_TAG=rzg

# if user setup the tag name, just use it
if [ $1 ] ; then
	IMAGE_TAG=$1
fi

# start to build the docker image 
docker build --no-cache --build-arg "host_uid=$(id -u)" --build-arg "host_gid=$(id -g)" --build-arg "USERNAME=$USER" --build-arg "TZ=$(cat /etc/timezone)" --tag $IMAGE_TAG -f ./Dockerfile.ubuntu1804 .