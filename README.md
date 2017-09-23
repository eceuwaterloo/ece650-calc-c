Calculator example in C++

To compile:
```
git clone --recursive https://github.com/eceuwaterloo/ece650-calc-c-doctest
cd ece650-c-calc-doctest
mkdir build
cd build
cmake ..
cmake --build .
```
(The `--recursive` flag makes git initialize the doctest submodule.)

To execute tests run either:
`ctest`
or
`./tests`
in the `build` directory.