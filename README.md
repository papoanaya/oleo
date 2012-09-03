Oleo
====

Luis' version of GNU oleo. GNU oleo has not maintainer and 
I cannot take the job, but I'm sharing my development though.

The following enhancements have been done:

  1. Export to GROFF TBL 
  2. Export to CSV


Comments
--------

There is a `sqlite.h` and `sqlite.c` files but no work has been done in
either of those. The database support needs some changes being that
it was left incomplete with test code in it. 

Even though that printing is supposed to be generic, in reality it was
designed for text and postscript. The print routine needs to be
improved.

The interface could use an upgrade, but it will require some study on
ncurses. For now, this is it.

