/**
 * FreeRDP: A Remote Desktop Protocol Client
 * RDP Caches
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <freerdp/utils/stream.h>
#include <freerdp/utils/memory.h>

#include "cache.h"

rdpCache* cache_new(rdpSettings* settings)
{
	rdpCache* cache;

	cache = (rdpCache*) xzalloc(sizeof(rdpCache));

	if (cache != NULL)
	{
		cache->settings = settings;
		cache->brush = brush_new(settings);
		cache->offscreen = offscreen_new(settings);
		cache->color_table = color_table_new(settings);
	}

	return cache;
}

void cache_free(rdpCache* cache)
{
	if (cache != NULL)
	{
		brush_free(cache->brush);
		offscreen_free(cache->offscreen);
		color_table_free(cache->color_table);
		xfree(cache);
	}
}