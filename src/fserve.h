/* Icecast
 *
 * This program is distributed under the GNU General Public License, version 2.
 * A copy of this license is included with this source.
 *
 * Copyright 2000-2004, Jack Moffitt <jack@xiph.org, 
 *                      Michael Smith <msmith@xiph.org>,
 *                      oddsock <oddsock@xiph.org>,
 *                      Karl Heyes <karl@xiph.org>
 *                      and others (see AUTHORS for details).
 */

#ifndef __FSERVE_H__
#define __FSERVE_H__

#include <stdio.h>
#include "cfgfile.h"

typedef void (*fserve_callback_t)(client_t *, void *);

typedef struct _fbinfo
{
    int flags;
    unsigned int limit;
    char *mount;
    char *fallback;
} fbinfo;

#define FS_USE_ADMIN            01
#define FS_FALLBACK             02
#define FS_FALLBACK_EOF         04
#define FS_OVERRIDE             010

void fserve_initialize(void);
void fserve_shutdown(void);
int fserve_client_create(client_t *httpclient, const char *path);
char *fserve_content_type (const char *path);
void fserve_recheck_mime_types (ice_config_t *config);

int  fserve_setup_client (client_t *client);
int  fserve_setup_client_fb (client_t *client, fbinfo *finfo);
int  fserve_set_override (const char *mount, const char *dest);
int  fserve_list_clients (client_t *client, const char *mount, int response, int show_listeners);
int  fserve_list_clients_xml (xmlNodePtr srcnode, fbinfo *finfo);
int  fserve_kill_client (client_t *client, const char *mount, int response);
int  fserve_query_count (fbinfo *finfo);


extern int fserve_running;

#endif


