FROM fedora:latest

RUN dnf update -y
RUN dnf install -y openssl

RUN dnf -y groupinstall "Development Tools"
RUN dnf install -y cmake openssl-devel clang libcxx-devel libcxxabi-devel bzip2-devel which

