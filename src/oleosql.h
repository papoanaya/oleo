/*
 *  $Id: oleosql.h,v 1.1.1.1 2000/08/10 21:02:51 papo Exp $
 *
 *  This file is part of Oleo, the GNU spreadsheet.
 *
 *  Copyright � 1999 by the Free Software Foundation, Inc.
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

#ifndef	_OLEO_SQL_H_
#define	_OLEO_SQL_H_

struct DatabaseGlobalType {
	char	*host,
		*name,
		*user;
};

extern void DatabaseSetHost(const char *);
extern void DatabaseSetName(const char *);
extern void DatabaseSetUser(const char *);

extern int DatabaseInitialised(void);
extern char *DatabaseGetHost(void);
extern char *DatabaseGetName(void);
extern char *DatabaseGetUser(void);

#endif
