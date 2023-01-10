# My personal keymap

I built this keymap to learn a new layout (which is Colemak-DHm), get used to ortholinear keyboards and eventually switch to a split keyboard like Gergoplex. That's why this layout uses just 36 keys. Heavily inspired by [Miryoku](https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org#miryoku-) by *manna-harbour*.

# (Un)used keys of the BM40

![Keymap Enabled Keys](https://raw.githubusercontent.com/joaopedropio/joaopedropio.github.io/master/blank.png)

# Main Keymap

To simplify things up, I use only 3 layers (besides the gaming layer which I'll talk more about later): Base, Raise (numbers, "simple" symbols and arrows) and Lower (F keys and "programming" symbols). Every layer has home row mods (especifically, [GACS](https://precondition.github.io/home-row-mods#gacs)).

![Colemak-DHm Base Layer](https://raw.githubusercontent.com/joaopedropio/joaopedropio.github.io/master/base.png)

# Gamming layer (standard planck mit layout)

To enter/leave gamming layer just press the Right key.

![Planck MIT Layour](https://raw.githubusercontent.com/joaopedropio/joaopedropio.github.io/master/planck_mit.png)

# Compile/Flash

```console
$ qmk compile -kb kprepublic/bm40hsrgb/rev2 -km joaopedropio
$ qmk flash -kb kprepublic/bm40hsrgb/rev2 -km joaopedropio
```

# Complete diagram

<div align="center">
  
 ![Complete Diagram](https://raw.githubusercontent.com/joaopedropio/joaopedropio.github.io/2685813e92f6e956600f3dda4e3cf3bb1641c587/bm40_layout_diagram.svg)

</div>
