/*
 *  $Id: groff.c,v 1.11 2012/08/28 18:09:50 papo Exp $
 *
 *  This file is part of Oleo, the GNU spreadsheet.
 *
 *  Copyright © 1999, 2000, 2001 by the Free Software Foundation, Inc.
 *  Written by Danny Backx <danny@gnu.org>.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

static char rcsid[] = "$Id: groff.c,v 1.11 2012/08/28 18:09:50 papo Exp $";

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef	WITH_DMALLOC
#include <dmalloc.h>
#endif

#include <stdio.h>

#include "global.h"

#include "print.h"

static float	border_width = 20.0,
		border_height = 20.0;


/* Fonts */
static char	*courier = "\\f[C]";
static char	*proportional = "\\f[C]";
static char	*noproportional = "\\f[P]";
static char	*italic = "\\f[I]";
static char	*noitalic = "\\f[P]";

void GroffJobHeader(char *str, int npages, FILE *fp)
{
	/* Reset Printer */
	/* Set unit to 50/3600 = 1/72 of an inch which is 1 point */

	/* Set printing area */

	/* Select font */

	/* Set print position */
  /* fprintf(fp,"\n.nf\n"); */
  /* Tabulation needs to be computed */
  /*  fprintf(fp,"\n.ta T 0.5i\n"); */
  fprintf(fp,".PH \"'%s''Page %%'\"\n",str);

}

void GroffJobTrailer(int npages, FILE *fp)
{

}

void GroffPageHeader(char *str, FILE *fp)
{

  fprintf(fp,"\n.TS\n");
  fprintf(fp,"tab(~);\n");
  fprintf(fp,"%s.\n",str);

}

void GroffPageFooter(char *str, FILE *fp)
{
  /* fprintf(fp,"\n.fi\n"); */
  fprintf(fp,"\n.TE\n");
	
}

void GroffField(char *str, int wid, int rightborder,
			int xpoints, int xchars, FILE *fp)
{
	char	format[16];

    /*sprintf(format, "%%%ds\\f[R]\t", wid); */

    sprintf(format,"%%s\\f[R]~");
	fprintf(fp, format, str);

}

void GroffBorders(FILE *fp)
{
}

void GroffFont(char *family, char *slant, int size, FILE *fp)
{
  if (slant != NULL) {
    if (strcmp(slant,"italic")==0) {
      fprintf(fp,"\\f[I]"); 
    } else if(strcmp(slant,"bold-italic")==0) {
      fprintf(fp,"\\f[BI]");
    } else if(strcmp(slant,"bold")==0) {
      fprintf(fp,"\\f[B]");
    } else {
      fprintf(fp,"\\f[R]"); 
    }
  }

  if (size > 4 && size < 40) {
    fprintf(fp,"\\s(%d",size);
  }
  
  /*  fprintf(stderr,"%s\n",family);  */

  if (family != NULL) {
    if (strcmp(family,"times") == 0) {
      fprintf(fp,"\\f[R]");
    } else if ((strcmp(family,"courier")) == 0 || 
               (strcmp(family,"Courier")) ==0 ) {
      fprintf(fp,"\\f[C]");
    } else if ((strcmp(family,"courier-bold")) == 0 || 
               (strcmp(family,"Courier-Bold")) ==0 ) {
      fprintf(fp,"\\f[CB]");
    } else if ((strcmp(family,"Times-Bold")) == 0 || 
               (strcmp(family,"times-bold")) ==0 ) {
      fprintf(fp,"\\f[B]");
    } else if (strcmp(family,"helvetica") == 0 ||
               strcmp(family,"Helvetica") == 0) {
      fprintf(fp,"\\f[H]");
    } else if (strcmp(family,"helvetica-bold") == 0 ||
               strcmp(family,"Helvetica-Bold") == 0) {
      fprintf(fp,"\\f[HB]");
    }

  }
          

}

void GroffNewLine(int ht, FILE *fp)
{
  fprintf(fp,"\n.br\n");
}

void GroffPaperSize(int wid, int ht, FILE *fp)
{
	int	hi, lo;

	hi = ht / 256;
	lo = ht % 256;

	/* Page Length */

	/* Margins */

	/* Top margin - FIX ME currently half an inch */
	hi = (72 / 2) / 256;
	lo = (72 / 2) % 256;

	/* Bottom margin - FIX ME currently half an inch */
	hi = (ht - 72/2) / 256;
	lo = (ht - 72/2) % 256;
}

void GroffSetEncoding(char *encoding)
{
}

void GroffSetBorder(int width, int height, FILE *fp)
{
	border_width = width;
	border_height = height;
}

struct PrintDriver GroffPrintDriver = {
	"Groff",
	&GroffJobHeader,
	&GroffJobTrailer,
	&GroffPageHeader,
	&GroffPageFooter,
	&GroffField,
	&GroffBorders,
	&GroffFont,
	&GroffNewLine,
	&GroffPaperSize,
	&GroffSetEncoding,
	&GroffSetBorder
};

#ifdef	TEST
#include "oleo_icon.xpm"

main(int argc, char *argv[])
{
	struct PrintDriver	*pd = &GroffPrintDriver;
	FILE			*fp = fopen("test.out", "w");

	int			i;

	fprintf(stderr, "Testing print driver for '%s'\n", pd->name);
	pd->job_header("This is a title", 1, fp);
	pd->font("times", "italic", 8, fp);
	pd->page_header("Page 1", fp);
	pd->field("Field 1", 10, 0, 1, 0,fp);
	pd->font("times", "bold", 8, fp);
	pd->field("Field 2", 10, 0, 1, 0,fp);
	pd->font("times", "bold-italic", 8, fp);
	pd->field("Field 3", 10, 0, 1, 0,fp);

	pd->newline(8, fp);
	pd->font("cg times", NULL, 8, fp);
	pd->field("Field 4 - this is in CG Times", 40, 0, 1, 0,fp);

	/* Start graphics */

	/* End graphics */

	/* Get it over with */
	pd->page_footer("End page 1", fp);
	pd->job_trailer(1, fp);

	fclose(fp);

	exit(0);
}
#endif
