#ifndef STREAMS_H
#define STREAMS_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define STREAM_DEF_SIZE 512

enum { ERROR = -1, SUCCESS = 0 };

typedef struct {
  char *buffer;
  size_t size;
  size_t next;
} stream_t;

void stream_init(stream_t **stream);
void stream_init_size(stream_t **stream, const size_t stream_size);

void stream_serialize(stream_t *stream, const char *data,
                      const size_t data_size);
void stream_deserialize(char *dest, stream_t *stream, size_t size);

#endif