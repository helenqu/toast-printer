from PIL import Image
import numpy
numpy.set_printoptions(threshold=numpy.nan)

im = Image.open("test2.png")
im = im.convert('L') #makes it greyscale
y = numpy.asarray(im.getdata(),dtype=numpy.float64).reshape((im.size[1],im.size[0]))
new_array = numpy.empty((y.shape[0], y.shape[1]), None)

for i in range(len(y)):
    for j in range(len(y[i])):
        if y[i][j] >= 127.5:
            new_array[i][j] = 1
        else:
            new_array[i][j] = 0
