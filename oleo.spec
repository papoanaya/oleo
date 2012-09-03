Summary         : the GNU spreadsheet for X11 and terminals
Name            : oleo
Version         : 1.99.16
Release         : 2
Group           : Office/Spreadsheet
Copyright       : GPL
Packager        : danny.backx@skynet.be
# Icon            : src/oleo_icon.xpm
BuildRoot       : /tmp/oleo-1.99.16
Source          : ftp://alpha.gnu.org/gnu/oleo/oleo-1.99.16.tar.gz

%description
...

%prep
%setup
#%patch -p1

%build
./configure
make

%install
DESTDIR=$RPM_BUILD_ROOT; export DESTDIR
[ -n "`echo $DESTDIR | sed -n 's:^/tmp/[^.].*$:OK:p'`" ] && rm -rf $DESTDIR ||
(echo "Invalid BuildRoot: '$DESTDIR'! Check this .spec ..."; exit 1) || exit 1

make install DESTDIR="$DESTDIR" datadir="$DESTDIR/usr/local/share" gnulocaledir="$DESTDIR/usr/local/share/locale" xdefaultsdir="$DESTDIR/usr/local/share/oleo"

gzip $DESTDIR/usr/local/info/*

%clean
DESTDIR=$RPM_BUILD_ROOT;export DESTDIR;[ -n "$UID" ]&&[ "$UID" -gt 0 ]&&exit 0
[ -n "`echo $DESTDIR | sed -n 's:^/tmp/[^.].*$:OK:p'`" ] && rm -rf $DESTDIR ||
(echo "Invalid BuildRoot: '$DESTDIR'! Check this .spec ..."; exit 1) || exit 1


%files
%doc AUTHORS COPYING ChangeLog FAQ NEWS README THANKS TODO doc/oleo.html
/usr/local/bin/oleo
/usr/local/share/locale/en/LC_MESSAGES/oleo.mo
/usr/local/share/locale/fr/LC_MESSAGES/oleo.mo
/usr/local/share/locale/nl/LC_MESSAGES/oleo.mo
/usr/local/share/oleo/Oleo
/usr/local/share/oleo/fr/Oleo
/usr/local/share/oleo/nl/Oleo
/usr/local/info/oleo.info.gz
/usr/local/info/oleo.info-1.gz
/usr/local/info/oleo.info-2.gz
/usr/local/info/oleo.info-3.gz

