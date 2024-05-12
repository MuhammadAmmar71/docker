FROM ubuntu:latest 
RUN apt-get -y update && apt-get install -y
RUN apt-get -y install clang
COPY . /usr/src/docker
WORKDIR /usr/src/docker
RUN clang++ -o CircleLinkedList CircularLinkedList.cpp
CMD ["./CircleLinkedList"]