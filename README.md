# fractal-pattern-generation-code-using-the-Mandelbrot-and-Julia-sets
 C program will generate one Mandelbrot and one Julia fractal pattern. Both will be 
written to disk in the Portable Pix Map (PPM) image format. Mandelbrot fractals are 
generated using an iterative complex function of the following form:
𝒁𝒏+𝟏 = 𝒁𝒏
𝟐 + 𝑪
𝒁𝟎 = 𝟎,
where Z and C are complex numbers. These complex numbers can be thought of as 
points on a two-dimensional complex plane of size 2×2. The real and imaginary parts of 
these complex numbers represent the x and y coordinates of points on the complex 
plane, respectively.
When our intended output image is projected onto the 2×2 complex plane, complex 
number C represents an individual pixel on the image. As a result, for each individual 
pixel on the image, we can calculate successive values for Z based on the above
equations. We can also keep track of the length of Z as it gets updated in each iteration 
and stop the iterative process when the square of the length of Z exceeds 4. The 
number of iterations required to breach this condition will then determine the color value 
associated with the pixel represented by the complex number C. 
The two-level nested loop shown above iterates through every single pixel on the 
intended output image as it projects onto a 2×2 complex plane. For each pixel, it sets 
the value of complex number Z to zero and determines the corresponding complex 
number C by a simple projection of the image dimensions onto the complex plane. The 
color of this pixel is then calculated by the fractal() function. Note that the fractal()
function implements the same logic we used as part of Lab exercises 8 and 9. The color 
number determined by the fractal() function must be converted to a red-green-blue 
combination for the corresponding pixel. This conversion is done using the function
convert(). The red-green-blue combination is the color of the pixel represented by 
complex number C and is subsequently written to the output file.
The logic for generating the Julia fractal pattern is very similar to the one outlined 
above. The subtle difference is that the complex number C is set equal to a constant 
and remains unchanged. The complex number Z is used instead to iterate over all 
individual pixels of the image in the same way that C iterates over the image pixels in 
the Mandelbrot set. The constant value of C used will be equal to -0.8 + 0.156i
