FROM debian:bullseye

LABEL description="remote container to be used by Visual Studio as compiler and debugger target" 

# install build dependencies to build and debug 
RUN apt-get update \
    && apt-get install -y g++ build-essential make cmake gdb gdbserver \
       rsync zip openssh-server git 

# install application dependencies
RUN apt-get install -y libopenblas-dev liblapack-dev python3-dev \ 
    libncurses5-dev libncursesw5-dev libasio-dev libboost-all-dev
RUN apt-get install -y wget curl npm openjdk-17-jdk

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'root:root' | chpasswd \
    && sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config \
    && sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd


WORKDIR /tmp
RUN wget https://golang.org/dl/go1.16.5.linux-amd64.tar.gz
# ADD dependencies/go1.16.5.linux-amd64.tar.gz /tmp/go1.16.5.linux-amd64.tar.gz
RUN tar -C /usr/local -xzf go1.16.5.linux-amd64.tar.gz
ENV PATH "$PATH:/usr/local/go/bin"
RUN go version
ADD https://sh.rustup.rs /tmp/rustup.sh
RUN chmod +x /tmp/rustup.sh && /tmp/rustup.sh -y
ENV PATH "$PATH:/root/.cargo/bin"

RUN apt-get -y install apt-transport-https 
RUN wget https://packages.microsoft.com/config/debian/10/packages-microsoft-prod.deb
#ADD dependencies/packages-microsoft-prod.deb packages-microsoft-prod.deb
RUN dpkg -i packages-microsoft-prod.deb && \
    apt-get update && \
    apt-get install -y dotnet-sdk-3.1 

RUN wget https://www-us.apache.org/dist/maven/maven-3/3.6.3/binaries/apache-maven-3.6.3-bin.tar.gz
#ADD dependencies/apache-maven-3.6.3-bin.tar.gz /tmp/apache-maven-3.6.3-bin.tar.gz
RUN tar xf /tmp/apache-maven-*.tar.gz -C /opt && ln -s /opt/apache-maven-3.6.3 /opt/maven

RUN apt-get install -y nodejs npm

RUN mkdir -p /source
WORKDIR /source

ENTRYPOINT ["/usr/sbin/sshd", "-D"]

EXPOSE 22