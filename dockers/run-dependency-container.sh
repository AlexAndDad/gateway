#!/usr/bin/env bash
set -e

toolchain=$1
context=$2
container_name=gateway_${toolchain}


if docker ps -q -f name=${container_name}
then
  docker stop ${container_name}
fi

if docker ps -a -q -f name=${container_name}
then
  docker rm ${container_name}
fi

docker run -d -t -e toolchain=${toolchain} --name ${container_name} -v "${context}:/src:ro,Z" gateway/fedora-devel:latest

