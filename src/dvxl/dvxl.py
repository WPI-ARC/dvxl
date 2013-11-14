#!/usr/bin/python

#####################################################
#                                                   #
#   Copyright (c) 2013, Calder Phillips-Grafflin    #
#                                                   #
#   Python library for reading and writting DVXL    #
#   deformable object voxel files.                  #
#                                                   #
#####################################################

class DVXL(object):

    def __init__(self):
        self.xDim = 0
        self.yDim = 0
        pass

class DVXLParser(object):

    def __init__(self):
        pass

    def ParseDVXL(self, filepath):
        return DVXL()
