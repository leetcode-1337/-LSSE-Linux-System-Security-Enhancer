#!/bin/bash

if [ ! -f ./bin/lsse ]; then
    # if [ ! -f /usr/include/sys/inotify.h ]; then
    #     echo "inotify library is not installed"
    #     echo "installing inotify-tools"
    #     sudo apt-get install inotify-tools
    # fi
    make
fi
cp ./bin/lsse /usr/local/bin
mkdir -p $HOME/.lsse
cp ./config/lsse.conf $HOME/.lsse/
