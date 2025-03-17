# Arduino LED Boards

This repository provides code and further information about a project in which LED circuit board for LED stripes was designed and constructed. It contains the corresponding firmware, schematics, and documentation.


## LED Board vol. 1: RGB Common Anode


RGB LEDs with a common anode share a single positive connection (e.g., 5V or 12V), while the brightness of the red, green, and blue channels is controlled through separate ground (GND) connections. The color and intensity are adjusted using pulse-width modulation (PWM), regulating the current flow to each color channel. The corresponding LED board vol. 1 is used to address 

With six PWM pins available on the Arduino Nano, a single board can control two independent LED sequences by utilizing all possible color combinations. Additionally, a separate LED strip can be controlled in a simpler manner, only allowing the corresponding RGB colors to be turned on or off.

In the context of RC model planes, board vol. 1 can be used to create advanced, independent color effects for each wing, while the fuselage is limited to basic color switching, for instance.

A code snippet for board vol. 1 is provided in the repository, including an example on how to address the LED strips and a framework for programming custom LED sequences.


## LED Board vol. 2: ws2812

... coming soon