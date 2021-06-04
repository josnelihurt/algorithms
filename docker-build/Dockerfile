FROM debian:bullseye

LABEL description="remote container to be used by Visual Studio as compiler and debugger target" 

# install build dependencies to build and debug 
RUN apt-get update \
    && apt-get install -y g++ build-essential make cmake gdb gdbserver \
       rsync zip openssh-server git 

# install application dependencies
RUN apt-get install -y libopenblas-dev liblapack-dev python3-dev \ 
    libncurses5-dev libncursesw5-dev libasio-dev libboost-all-dev

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'root:root' | chpasswd \
    && sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config \
    && sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd


RUN mkdir -p /source
WORKDIR /source

ENTRYPOINT ["/usr/sbin/sshd", "-D"]

EXPOSE 22