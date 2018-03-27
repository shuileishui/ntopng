/*
 *
 * (C) 2018 - ntop.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef _TS_EXPORTER_H_
#define _TS_EXPORTER_H_

#include "ntop_includes.h"

class TimeSeriesExporter {
 private:
  time_t flushTime;
  FILE *fd;
  char fname[PATH_MAX];
  NetworkInterface *iface;
  char *url;
  u_int num_cached_entries; 
  Mutex m;
  
  void createDump();
  
 public:
  TimeSeriesExporter(NetworkInterface *_if, char *_url);
  ~TimeSeriesExporter();

  void exportData(char *data);
  void flush();
};

#endif /* _TS_EXPORTER_H_ */