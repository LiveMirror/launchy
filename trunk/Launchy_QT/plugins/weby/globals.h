/*
Launchy: Application Launcher
Copyright (C) 2007  Josh Karlin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef GLOBALS_H
#define GLOBALS_H
#include <QString>

struct WebySite {
    QString base;
    QString name;
    QString query;
	QString suggest;
    bool def;
    
    WebySite() { def = false; }

    WebySite(QString b, QString n, QString q, bool d = true, QString s = "") :
	base(b), name(n), query(q), def(d), suggest(s) {}
};

struct Bookmark {
	QString url;
	QString shortcut;
	QString name;
};

#endif
