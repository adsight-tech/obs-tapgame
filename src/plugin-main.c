/*
Plugin Name
Copyright (C) <Year> <Developer> <Email Address>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/

#include <obs-module.h>
#include <obs-frontend-api.h>
#include <util/config-file.h>

#include "plugin-macros.generated.h"

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

bool obs_module_load(void)
{
	blog(LOG_INFO, "11 :: scartill plugin loaded successfully (version %s)",
	     PLUGIN_VERSION);

	config_t *conf = obs_frontend_get_profile_config();

	if (!conf)
		blog(LOG_INFO, "scartill :: Not such config");

	bool enabled = config_get_bool(conf, "Output", "DelayEnable");
	int64_t delay = config_get_int(conf, "Output", "DelaySec");
	blog(LOG_INFO, "scartill :: %d delay %d", enabled, delay);

	return true;
}

void obs_module_unload()
{
	blog(LOG_INFO, "plugin unloaded");
}