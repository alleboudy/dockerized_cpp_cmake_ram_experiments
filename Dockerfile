FROM ubuntu:18.04
# Prepare build environment
RUN apt-get update && \
    apt-get -qq -y install gcc g++ \
    cmake curl wget pkg-config \
    libtool python3 python3-pip \
    daemontools

RUN g++ -v
RUN cmake -version


RUN mkdir code

COPY CMakeLists.txt code
COPY TestingMemoryLimits.h code
COPY TestingMemoryLimits.cpp code
COPY LRU.h code

RUN cd code && mkdir build && cd build && cmake .. && cmake --build . --config Release 

WORKDIR /code/build/

CMD ./TestingMemoryLimits



