## Ubuntu base image
FROM ubuntu:latest
ENV DEBIAN_FRONTEND=noninteractive

## Install basic + ncurses
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    make \
    cmake \
    valgrind \
    gdb \
    git \
    wget \
    curl \
    unzip \
    tar \
    pkg-config \
    ncurses-dev \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

## Install GTEST
RUN git clone -q https://github.com/google/googletest.git /googletest \
    && mkdir -p /googletest/build \
    && cd /googletest/build \
    && cmake .. && make -j$(nproc) && make install \
    && ldconfig \
    && rm -rf /googletest

## SETWD
WORKDIR /src/

## Bash
CMD ["/bin/bash"]
