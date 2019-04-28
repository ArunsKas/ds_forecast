**Last edit**

Module code edited and extended by arunas.paulauskas@gmail.com

**Summary**

The Dark Sky Forecast module provides a block that displays a subset of the most
commonly used data points provided by the Dark Sky Forecast API. This module is
intended to provide a very brief summary of the current weather forecast for a
configured geo-location, including any weather advisories, alerts, or warnings.

**Requirements**

This module requires an API key for accessing the Dark Sky Forecast API. A key
can be obtained at https://developer.forecast.io.

**Installation**

Install as usual, according to http://drupal.org/node/895232.

**Configuration**

Customize the menu settings in `Configuration > Weather > Settings`.

`API key` is required for accessing weather data. If you do not have an API key,
you must obtain one from https://developer.forecast.io.

`Latitude` and `Longitude` must be set to the geolocation for which you want to
retrieve forecast data.

`Forecast Period` defaults to "Current" for retrieving only the current
weather conditions. Other options are:

* _Minutely_ provides forecast conditions for the next 60 minutes.
* _Hourly_ provides forecast conditions for the next 24 hours.
* _Daily_ provides forecast conditions for the next 7 days.

`Cache Lifetime` is the amount of time in seconds to cache retrieved forecast
data. The Dark Sky API provides 1,000 API calls per day at no cost. This is
subject to change at the discretion of The Dark Sky Company, LLC. The minimum
recommended value is 90 seconds. This allows the forecast for current
conditions to remain accurate at any given time, while keeping the number of
API calls under 1,000 per day. This module ignores all caching settings under
`Configuration > Development > Performance`.

**Customization**

This module provides a default template `forecast.tpl.php` that may be
overridden in your theme. Data available to the template is documented in the
default template file.

`forecast.tpl.php` is optimized for use with the Weather Icons set, which is
purely optional and not included with this module. If you'd like to use it on
your site, you can find it at https://erikflowers.github.io/weather-icons. If
you would prefer to use another icon set or no set at all, you should override
`forecast.tpl.php` in your theme.

**Contact**

Current maintainer is Erik Taylor - https://drupal.org/user/871384 (eriktaylor)
