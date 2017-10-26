# toast-printer

A printer which takes an image file and prints the image in "greyscale" onto a slice of bread. Made at HackNY XIII in Spring 2016.

A Python script breaks down an image into a grid, finds the average darkness of each section of the grid and converts that into the number of seconds a heating element should be placed over that section of bread to toast it to appropriate darkness.

An Arduino is connected to two motors, which are hooked up to a heating element by wires. Using Pythagorean theorem the respective lengths of wire (legs of the triangle) are shortened moving the heating element up, down, left, and right over over the slice of bread. Adding a delay ensures the bread at that location is toasted to appropriate darkness.

Please do not replicate without proper safety procedures in place, this is definitely a fire and/or shock hazard.
