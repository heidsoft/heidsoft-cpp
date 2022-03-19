# c++工程化训练

## 生成Makefile
```
➜  heidsoft-cpp git:(master) ✗ cmake .
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/heidsoft/Downloads/research/heidsoft-cpp
➜  heidsoft-cpp git:(master) ✗
```

## make 编译

```
➜  heidsoft-cpp git:(master) ✗ make
Consolidate compiler generated dependencies of target heidsoft.exe
[ 50%] Building CXX object CMakeFiles/heidsoft.exe.dir/main.cc.o
[100%] Linking CXX executable heidsoft.exe
[100%] Built target heidsoft.exe
```

## cmake poco 编译
```
cmake -H/Users/heidsoft/Downloads/research/poco -B/Users/heidsoft/Downloads/research/poco-build
cmake --build /Users/heidsoft/Downloads/research/poco-build
```

# 系统函数

1. [cmake_20/select](./cmake_20/readme.md#select说明)
2. [cmake_21/poll](./cmake_21/readme.md#poll说明)
3. [cmake_22/readv/writev](./cmake_22/readme.md#readv与writev)
4. [cmake_23/readn/writen](./cmake_23/readme.md#readn与writen)
5. [cmake_24/nmap](./cmake_24/readme.md#nmap说明)
