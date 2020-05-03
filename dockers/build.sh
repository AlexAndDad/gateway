#!/usr/bin/env bash

if ! docker image exists madmongo1/fedora-devel:latest
then
  echo building image
  docker build -t madmongo1/fedora-devel:latest dockers/fedora-devel
fi

toolchain=clang-cxx20-libcxx

if ! docker image exists madmongo1/gateway-dependencies:latest
then
  echo building dependencies
  if docker ps -q -f name=gateway_dependencies
  then
    docker rm gateway_dependencies
  fi
  docker run -e toolchain=${toolchain} --name gateway_dependencies -v "${PWD}:/src:ro,Z" madmongo1/fedora-devel:latest /bin/bash /src/dockers/build-deps.sh
fi
