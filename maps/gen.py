import numpy
import sys

sizeX = 70
sizeY = 80

def correct(array):
    for x, y in enumerate(array):
        for a, b in enumerate(y):
            if (array[x][a] == 2 or array[x][a] == 3):
                array[x][a] = 0
            if (a == 0 or a == sizeX-1 or x == 0 or x == sizeY-1):
                array[x][a] = 1
            sys.stdout.write(f"{array[x][a]}")
            if (a == sizeX-1):
                sys.stdout.write("\n")

def main():
    array = numpy.random.randint(4, size=(sizeY, sizeX))
    correct(array)

main()
