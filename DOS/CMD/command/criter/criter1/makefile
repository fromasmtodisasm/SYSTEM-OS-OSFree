#
# A Makefile for ATTRIB
# (c) osFree project,
# author, date
#

PROJ = criter1
DESC = Critical Error & Dummy ^Break handler & Kernel Swap Context
#defines object file names in format objname.$(O)
srcfiles = $(p)..$(SEP)criter$(e)

# defines additional options for C compiler
ADD_ASMOPT = -dAUTO_FAIL  -dMODEL=l -i=$(PATH)..$(SEP)..$(SEP)strings$(SEP)critstrs -i=$(MYDIR)..
ADD_LINKOPT = lib suppl.lib
#COM = 1

!include $(%ROOT)/mk/appsdos.mk

TARGETS = $(PATH)$(PROJ).exe
