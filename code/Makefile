#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := lightController.cpp strip.cpp MSGEQ7.cpp

# header files in this project
HEADERS := MSGEQ7.hpp strip.hpp lightController.hpp

# other places to look for files for this project
SEARCH  := 

SERIAL_PORT_DUE   ?= COM9

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due
