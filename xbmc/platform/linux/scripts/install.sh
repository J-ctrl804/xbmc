#!/bin/bash

# Install Kodi on Linux

# Check if user is root
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

# Update package list
apt-get update

# Install dependencies
apt-get install -y \
  build-essential \
  cmake \
  git \
  libasound2-dev \
  libass-dev \
  libavcodec-dev \
  libavformat-dev \
  libavutil-dev \
  libbluray-dev \
  libcdio-dev \
  libcurl4-openssl-dev \
  libdvdnav-dev \
  libdvdread-dev \
  libegl1-mesa-dev \
  libfontconfig1-dev \
  libfreetype6-dev \
  libfribidi-dev \
  libgl1-mesa-dev \
  libgles2-mesa-dev \
  libglu1-mesa-dev \
  libgnutls28-dev \
  libiso9660-dev \
  libjpeg-dev \
  liblzo2-dev \
  libmad0-dev \
  libmicrohttpd-dev \
  libmodplug-dev \
  libmpeg2-4-dev \
  libogg-dev \
  libopenal-dev \
  libopus-dev \
  libpcre3-dev \
  libplist-dev \
  libpng-dev \
  libpulse-dev \
  libsmbclient-dev \
  libsqlite3-dev \
  libssh-dev \
  libssl-dev \
  libswscale-dev \
  libtag1-dev \
  libtiff-dev \
  libtinyxml-dev \
  libtool \
  libudev-dev \
  libvorbis-dev \
  libx11-dev \
  libxext-dev \
  libxinerama-dev \
  libxrandr-dev \
  libxrender-dev \
  libxslt1-dev \
  libxt-dev \
  libxv-dev \
  libxxf86vm-dev \
  mesa-common-dev \
  nasm \
  pkg-config \
  python-dev \
  python-pip \
  python-setuptools \
  swig \
  yasm \
  zlib1g-dev

# Clone Kodi repository
git clone https://github.com/J-ctrl804/xbmc.git

# Change to Kodi directory
cd xbmc

# Create build directory
mkdir build
cd build

# Configure Kodi
cmake ..

# Build Kodi
make

# Install Kodi
make install

# Clean up
cd ../..
rm -rf xbmc

echo "Kodi installation complete"
