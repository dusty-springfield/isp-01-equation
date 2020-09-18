# Equation Solver
<p>Program solving quadratic equations</p>
<p>[@dspringfield](t.me/dspringfield)</p>

## Required
* C/C++ compiler
* CMake
* Doxygen

## Build
All manipulation should be done in the root of project. <br>
Initially execute `cmake -B ./build`
 
 ### Program
 To run program:
 * Execute `cmake --build ./build -t main`
 * Run by executing `./build/src/main`
 
 ### Tests
 To run custom tests:
 * Execute `cmake --build ./build -t my_test`
 * Run by executing `./build/test/my_test` <br><br>
 
 To run gtest:
  * Execute `cmake --build ./build -t g_test`
  * Run by executing `./build/test/g_test` 
 
 ### Documentations
 To generate html documentation of project:
 * Execute `cmake --build ./build -t docs`
 * Open `./build/html/index.html`