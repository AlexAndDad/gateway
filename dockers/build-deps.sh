#!/usr/bin/env bash
set -e

echo "building dependencies for toolchain ${toolchain}"
mkdir /build
cmake -H/src/dependencies -B/build/cmake-build-${toolchain}-debug/dependencies -DCMAKE_TOOLCHAIN_FILE=/src/polly/${toolchain}.cmake
