<?php
/**
 * @file
 * Default theme implementation for displaying a weather forecast.
 *
 * Available variables:
 *
 * @var mixed $period
 * Contains the value set in "Forecast Period" or false if no data.
 *
 * @var string $summary
 * A brief text summary of the forecast data.
 *
 * @var int $time
 * A UNIX timestamp representing the time of the forecast.
 *
 * @var float $temperature
 * A floating point numerical value representing the current temperature.
 *
 * @var string $icon
 * A token representing the current forecast, typically used as a CSS class
 * name.
 *
 * @var float $precipProbability
 * A value between 0 and 1 representing the probability of precipitation
 * occurring during the forecast period.
 *
 * @var float $precipIntensity
 * A numerical value representing the average expected intensity in inches of
 * liquid per hour of precipitation occurring during the forecast period,
 * conditional on probability.
 *
 * @var array $alerts
 * An array of weather alerts such as advisories and warnings, each containing
 * the following keys:
 * - title: A short text summary of the alert.
 * - expires: The UNIX time at which the alert will cease to be valid.
 * - description: A detailed text description of the alert from the appropriate
 *   weather service.
 * - uri: An HTTP(S) URI that contains detailed information about the alert.
 */
?>

<?php if ($period): ?>
  <div class="ds-forecast">

    <?php
      // This template is optimized for use with the Weather Icons set found
      // at https://erikflowers.github.io/weather-icons/. The CSS and fonts
      // found in that project should be included in your theme if you'd like
      // to use the default template. Otherwise, override this template to
      // use any icons you like, or none at all.
    ?>
      <i class="wi wi-forecast-io-<?php print $icon; ?>"></i>
      <span class="forecast-summary">
        <?php print $summary; ?>
        <?php if ($temperature): ?>
          <?php print ($period == 'currently' ? '' : 'Currently ') . round($temperature) . '&deg;'; ?>
        <?php endif; ?>
      </span>
      <div class="forecast-details">
        <?php if ($temperature): ?>
          <div class="ds-detail temperature"><?php print round($temperature) . ' &deg;C'; ?></div>
        <?php endif; ?>
        <?php if ($wind_speed): ?>
          <div class="ds-label"><?php print t('Wind'); ?></div>
          <div class="ds-detail wind-speed"><?php print round($wind_speed) . ' m/s'; ?>
            <?php if ($wind_rose): ?>
              <span class="ds-detail wind-direction"><?php print $wind_rose; ?></span>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>
    <?php if ($alerts): ?>
      <?php foreach ($alerts as $alert): ?>
        |
        <span class="forecast-alert">
          <a href="<?php print $alert['uri']; ?>" target="_blank"><?php print $alert['title']; ?></a>
        </span>
      <?php endforeach; ?>
    <?php endif; ?>
  
  </div>
<?php endif; ?>
