# Equation Solver
Program solving quadratic equations<br> ([@dspringfield](t.me/dspringfield))

## Required
* C++ compiler
* CMake
* Doxygen

## Build
All manipulation should be done in the root folder of project. <br>
Initially execute `cmake -B ./build`
 
 ### Program
 To run program:
 * Compile `cmake --build ./build -t main`
 * Run `./build/src/main`
 
 ### Tests
 To run custom tests:
 * Compile `cmake --build ./build -t my_test`
 * Run `./build/test/my_test` <br><br>
 
 To run gtest:
  * Compile `cmake --build ./build -t g_test`
  * Run `./build/test/g_test` 
 
 ### Documentations
 To generate html documentation of project:
 * Execute `cmake --build ./build -t docs`
 * Open `./build/html/index.html`
