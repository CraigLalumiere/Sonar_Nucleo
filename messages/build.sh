set -o errexit

# clean build folder
# sometimes c files not generated if build folder already exists
rm -rf build


# make generated directories if they don't exist
# note that python files are dropped into pc_com directly, so thay are easily included by python
mkdir -p generated/c
mkdir -p generated/cpp
mkdir -p ../pc_com/messages

# empty generated directories
rm -rf generated/c/*
rm -rf generated/cpp/*
rm -rf ../pc_com/messages/*

# build the protobufs
cmake -S . -B build/messages -DCMAKE_MAKE_PROGRAM=ninja -G "Ninja"
cmake --build build/messages --target messages