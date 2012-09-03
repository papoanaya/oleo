#
# This directory contains files to be installed as application defaults
# files for oleo. One of the purposes is to internationalise the Motif
# interface, which is not easily done with the GNU Gettext facilities in
# the po/ directory.
#
# $Header: /opt/home/papo/cvs/oleo/Xresources/Makefile.am,v 1.1.1.1 2001/02/10 08:26:54 papo Exp $
#

xdefaultsdir =	$(prefix)/share/oleo

noinst_DATA=	Oleo.nl Oleo.fr Oleo.en
EXTRA_DIST =	Oleo.nl Oleo.fr Oleo.en

nldir =		$(xdefaultsdir)/nl
frdir =		$(xdefaultsdir)/fr
endir =		$(xdefaultsdir)

install-data-hook:
		$(mkinstalldirs) $(nldir) $(frdir) $(endir)
		$(INSTALL_DATA) $(srcdir)/Oleo.nl $(nldir)/Oleo
		$(INSTALL_DATA) $(srcdir)/Oleo.fr $(frdir)/Oleo
		$(INSTALL_DATA) $(srcdir)/Oleo.en $(endir)/Oleo

MAINTAINERCLEANFILES = Makefile.in
