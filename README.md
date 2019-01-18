# lua5.3_demo
The official lua C api tutorial found in [http://www.lua.org/docs.html](http://www.lua.org/docs.html) is of version **5.1** and I couldn't find a **5.3** tutorial anywhere on the internet. Thus I decided to make it myself using **C++**.

## To compile and run
I use ubuntu 16.04 with cmake, and it can be ported to other platforms with minimal changes
1. Install **lua** library
```
sudo apt-get install liblua5.3-dev
```

2. In project directory:
```
mkdir build
cd build
cmake ..
make
```

3. Run the code
```
./lua_test
```