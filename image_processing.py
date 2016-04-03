#Imports
from PIL import Image
import numpy
import math
import serial
numpy.set_printoptions(threshold=numpy.nan)

def process_image(file_path):
    #Open Image
    im = Image.open(file_path)

    #Width and Height
    size = im.size
    width = size[0]
    height = size[1]

    #For thumbnailing if image is too big
    dimensions = (288, 295)
    if (width >= 295 or height >= 288):
        im.thumbnail(dimensions)

    #Convert image to Grayscale
    im = im.convert('L')

    #Width and Height
    size = im.size
    width = size[0]
    height  = size[1]

    #Padding Code
    y = numpy.asarray(im.getdata(),dtype=numpy.float64).reshape((im.size[1],im.size[0]))

    new_array = numpy.empty((y.shape[0], y.shape[1]), None)
    for i in range(len(y)):
        for j in range(len(y[i])):
            if y[i][j] >= 127.5:
                new_array[i][j] = 0
            else:
                new_array[i][j] = 1
    new_image = Image.fromarray(new_array, None)


    start_width = int(math.ceil((float(295 - width)/2)))
    end_width =  int(math.ceil((float(295 - width)/2)) + width)

    start_height = int(math.ceil((float(288 - height)/2)))
    end_height =  int(math.ceil((float(288 - height)/2))) + height
    # Initialize Toast Array
    tup = (288, 295)
    toast_array = numpy.zeros(tup)
    for i in range(start_height, end_height):
        for j in range(start_width, end_width):
            toast_array[i][j] = new_array[i-start_height][j-start_width]

    return toast_array

def write_to_serial(_array):
    ser = serial.Serial('dev/tty.usbserial', 9600)
    for i in range(0, 288):
        for j in range(0, 295):
            data = "" + i + "," + j + "," + _array[i][j]
            ser.write(data.encode("utf-8"))

write_to_serial(process_image("fabulous.png"))
