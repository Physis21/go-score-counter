if [ $# -eq 0 ]; then
    cd build/lib && ctest
else
    cd build/lib && ctest $1
fi
