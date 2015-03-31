Kim Douglas
March 2015

============================================================================================

(1) Why is this folder here?

    Sierpinski-p5js is based on the design of a C++ program called Sierpinski_fract.

    The fractals-cpp folder is provided in the Sierpinski-p5js directory purely for 
    conceptual reference. It contains the header, implementation, and makefile
    necessary to build Sierpinski_fract, as well as the ones necessary to build a similar
    program called Original_fract.cpp

==============================================================================================
==============================================================================================
==============================================================================================

In case you're curious...

(2) Memory in the Sierpinski triangle:

On a 32-bit machine, a Sierpinski object includes the following member variables:
 
    1 x int (4 bytes)                   = 4 bytes
    6 x sf::Vector2f (8 bytes)          = 48 bytes
    3 x Sierpinski pointers (4 bytes)   = 12 bytes

    total                               = 64 bytes
    
At runtime, if the depth satisfies the loop condition, then an additional 64 bytes gets allocated for 3 Sierpinski pointers. So, the memory used is a summation of 3^(depth-1) * 64

    ex, when depth == 3 ...             = 3^(3-1)*64    =   (3^2)*64    =   9*64    =   576 bytes

=============================================================================================

(3) Memory in my Circles fractal:

On a 32-bit machine, an original circle object includes the following member variables:

    1 x int (4 bytes)                   = 4 bytes
    2 x float (8 bytes)                 = 16 bytes
    1 x sf::Vector2f (8 bytes)          = 8 bytes
    4 x Original pointers (4 bytes)     = 16 bytes
    
    total                               = 44 bytes
    
A summation occurs that is similar to the Sierpinski summation: 4^(depth-1) * 44

    ex, when depth == 3 ...             = 4^(3-1)*44    =   (4^2)*44    =   16*44   =   704 bytes
    

