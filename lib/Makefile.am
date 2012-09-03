#
# $Header: /opt/home/papo/cvs/oleo/lib/Makefile.am,v 1.1.1.1 2001/02/10 08:27:04 papo Exp $
#
# Process this file with automake to produce Makefile.in
#
noinst_LIBRARIES = liboleo.a

#
# The list of files here is incomplete :
#	configure.in can add mktime.c and obstack.c through the LIBOBJS
#	mechanism
#
liboleo_a_SOURCES = getdate.y getopt.c getopt1.c random.c
liboleo_a_LIBADD = @LIBOBJS@

noinst_HEADERS = getopt.h get_date.h obstack.h

INCLUDES = -I.. -I$(srcdir) -I../intl

CLEANFILES = getdate.c
MAINTAINERCLEANFILES = Makefile.in

