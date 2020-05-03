FROM madmongo1/fedora-devel:latest

ARG toolchain

RUN cmake -Hsrc/dependencies -Bcmake-build-${toolchain}-debug/dependencies -DCMAKE_TOOLCHAIN_FILE=/src/polly/${toolchain}.cmake

