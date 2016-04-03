#Imports
from PIL import Image
import numpy
import math
numpy.set_printoptions(threshold=numpy.nan)

#Open Image
im = Image.open("test.png")

#Width and Height
size = im.size
width = size[0]
height = size[1]
print(width)
print(height)

#For thumbnailing if image is too big
dimensions = (250, 250)
if (width >= 250 or height >= 250):
    im.thumbnail(dimensions)

#Convert image to Grayscale
im = im.convert('L')

#Width and Height
size = im.size
width = size[0]
height  = size[1]

print size
#Pading Code
# if (height < 250):
#     padding-ud = (250 - height)/2
# if (width < 250):
#     padding-lr = (250 - width)/2
#Convert Grayscale
y = numpy.asarray(im.getdata(),dtype=numpy.float64).reshape((im.size[1],im.size[0]))

new_array = numpy.empty((y.shape[0], y.shape[1]), None)
for i in range(len(y)):
    for j in range(len(y[i])):
        if y[i][j] >= 127.5:
            new_array[i][j] = 255
        else:
            new_array[i][j] = 0
new_image = Image.fromarray(new_array, None)


start_width = int(math.ceil((float(288 - width)/2)))
end_width =  int(math.ceil((float(288 - width)/2)) + width)

start_height = int(math.ceil((float(288 - height)/2)))
end_height =  int(math.ceil((float(288 - height)/2))) + height
# Initialize Toast Array
tup = (288, 288)
toast_array = numpy.zeros(tup)
print start_width, end_width, start_height, end_height
for i in range(start_height, end_height):
    for j in range(start_width, end_width):
        print i-start_height, j-start_width
        toast_array[i][j] = new_array[i-start_height][j-start_width]


new_image = Image.fromarray(toast_array, None)
new_image.show()
