/*
 *  $Id: csv.c,v 1.2 2012/09/03 01:52:24 papo Exp $
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

static char rcsid[] = "$Id: csv.c,v 1.2 2012/09/03 01:52:24 papo Exp $";

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

void CsvJobHeader(char *str, int npages, FILE *fp)
{

}

void CsvJobTrailer(int npages, FILE *fp)
{

}

void CsvPageHeader(char *str, FILE *fp)
{
}

void CsvPageFooter(char *str, FILE *fp)
{
  fprintf(fp,"\n");

}

void CsvField(char *str, int wid, int rightborder,
			int xpoints, int xchars, FILE *fp)
{
    char   format[16];

    if (rightborder==1) {
      sprintf(format,"\"%%s\"");
    } else {
      sprintf(format,"\"%%s\",");
    }

    fprintf(fp, format, str);

}

void CsvBorders(FILE *fp)
{
}

void CsvFont(char *family, char *slant, int size, FILE *fp)
{
}

void CsvNewLine(int ht, FILE *fp)
{
  fprintf(fp,"\n");
}

void CsvPaperSize(int wid, int ht, FILE *fp)
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

void CsvSetEncoding(char *encoding)
{
}

void CsvSetBorder(int width, int height, FILE *fp)
{
	border_width = width;
	border_height = height;
}

struct PrintDriver CsvPrintDriver = {
	"Csv",
	&CsvJobHeader,
	&CsvJobTrailer,
	&CsvPageHeader,
	&CsvPageFooter,
	&CsvField,
	&CsvBorders,
	&CsvFont,
	&CsvNewLine,
	&CsvPaperSize,
	&CsvSetEncoding,
	&CsvSetBorder
};

#ifdef	TEST
#include "oleo_icon.xpm"

main(int argc, char *argv[])
{
	struct PrintDriver	*pd = &CsvPrintDriver;
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
