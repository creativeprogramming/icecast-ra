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

/* format_mp3.h
**
** mp3 format plugin
**
*/
#ifndef __FORMAT_MP3_H__
#define __FORMAT_MP3_H__

#include "format.h"
#include "mpeg.h"

#define CLIENT_WANTS_FLV            (CLIENT_FORMAT_BIT<<10)

typedef struct {
    refbuf_t *associated;
    unsigned short interval;
    short metadata_offset;
    unsigned short since_meta_block;
    void         *specific;
} mp3_client_data;


typedef struct {
    /* These are for inline metadata */
    int inline_metadata_interval;
    int offset;
    int interval;
    char *url_artist;
    char *url_title;
    char *url;
    char *inline_url;
    int update_metadata;
    int queue_block_size;

    mpeg_sync file_sync;
    refbuf_t *metadata;
    refbuf_t *read_data;
    int read_count;

    unsigned build_metadata_len;
    unsigned build_metadata_offset;
    char build_metadata[4081];
} mp3_state;

int format_mp3_get_plugin (format_plugin_t *plugin, client_t *client);

#endif  /* __FORMAT_MP3_H__ */
