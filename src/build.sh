#!/bin/sh

#删除文件
rm -rf build
rm -rf media_data

#创建编译目录并编译
mkdir build
cd build
cmake ./..
make

#拷贝编译可执行文件
cp -af ./media_data ./..
cd ..
