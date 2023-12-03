## X-2: 5x12 Ortholinear, ARM-powered Adaptation of peej's Lumberjack PCB

peej's [lumberjack-keyboard](https://github.com/peej/lumberjack-keyboard) is a cool and creative
design, which continues the style of "show the components" used by keyboards like
the [plaid](https://github.com/hsgw/plaid).

One downside to it is that DIP microcontrollers are relatively weak.
Development boards are a spiritual-successor to DIP microcontrollers,
so I wanted to adapt the striking Lumberjack design to a more
powerful development board.

Design goals:

- Using STM32 dev board. (ARM-powered!).
- Adapt the Lumberjack design.
  - In a "show the components" style.
  - Fits in tray-mount GH60 case.
  - (Relatively) easy to solder.

Pictures:

<img src="https://raw.githubusercontent.com/rgoulter/keyboard-labs/master/docs/images/photo-keyboard-x-2_rev2021.1-mx-top.JPG" width=600 />

_X-2 PCB assembled, using a Bluepill devboard, with MX switches, in a cheap GH-60 case._

<img src="https://raw.githubusercontent.com/rgoulter/keyboard-labs/master/docs/images/photo-keyboard-x-2_rev2021.1-choc-top.JPG" width=600 />

_X-2 PCB assembled, using a WeAct Studio MiniF4 "Blackpill" devboard, with Choc switches, in a layered acrylic case._

<img src="https://github.com/rgoulter/keyboard-labs/raw/master/docs/images/keyboard-x2-lumberjack-arm-rev2021.1-top.svg" width=600 /> <img src="https://github.com/rgoulter/keyboard-labs/raw/master/docs/images/keyboard-x2-lumberjack-arm-rev2021.1-bottom.svg" width=600 />

_2D Renders of the PCB, revision rev2021.1_



## X-2 HSRGB: 5x12 Ortholinear, ARM-powered Adaptation of peej's Lumberjack PCB, with HotSwap and per-key RGB

A fancier version of the X-2 above. With all the benefits of the X-2 (fits in GH-60 case, powerful microcontroller),
but with a RGB lighting, which makes the keyboard a bit fancier.

Design goals:

- Same as X-2:
  - Using STM32 dev board. (ARM-powered!).
  - Adapt the Lumberjack design.
    - In a "show the components" style.
    - Fits in tray-mount GH60 case.
    - (Relatively) easy to solder.
- Additional fancy features:
  - HotSwap: the PCB uses Kailh's MX Hotswap sockets. This allows being able to swap out which switches
    are used by the keyboard, without needing to resolder (or resort to using PCB rivets).
  - RGB lighting: the PCB allows for putting RGB lights under each key, as well as RGB underglow.

Pictures:

<img src="https://raw.githubusercontent.com/rgoulter/keyboard-labs/master/docs/images/photo-keyboard-x-2-hsrgb_rev2022.1-front.JPG" width=600 />

_X-2 HSRGB PCB assembled, using a Bluepill devboard, with MX switches, in a cheap GH-60 case. Using MX switches with transparent housing, like Kailh's Jellyfish switches, enhances the RGB lighting._

<img src="https://raw.githubusercontent.com/rgoulter/keyboard-labs/master/docs/images/photo-keyboard-x-2-hsrgb_rev2022.1-back.JPG" width=600 />

_X-2 HSRGB PCB assembled, view of the back._
