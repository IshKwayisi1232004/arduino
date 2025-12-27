# Photo Sensor README

In this project, my main goal was to light up an LED if the Photo Sensor senses a light source - such as sunlight, ambient indoor light or flashlight from your phone. LED will be turned off if the photocell is covered by darkness. In the code I'll need to establish a threshold value for the amount of light that needs to be exposed for the LED to turn on.

The main idea here is to gain experience using an Arbitary sensor. Which is a sensor that reads unpredictable singals/conditions. In this case, a Photo Sensor falls under this category because there is no standard routine for sunlight to be exposed to the sensor. Ex. at one point sunlight can be exposed for 5 seconds, but at another instance, sunlight is exposed to the sensor 2 minutes. This is the same idea behind the use of solar panels. Just an fyi, a Photo Sensor can not be used to power things, its meant to measure light intensity, presence, or changes based on the *photovoltaic effect*.

### Hardware Parts
* 1x Arduino Board
* 1x Breadboard
* 1x Photo Sensor
* 8x LED Lights
  - 2x Red
  - 2x Blue
  - 2x Yellow
  - 2x Green
* 8x 220k Ohms
* 1x L293D
