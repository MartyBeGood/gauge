# G.A.U.G.E

**G**enerally **A**ccurate **U**nified **G**rind & **E**xtraction

## What's it gonna be?

A shamelessly over-engineered pair of add-on devices that add Grind-By-Weight to a grinder and Brew-By-Weight to an espresso machine. Hopefully. Eventually.

It'll consist of S.P.I.N and F.L.O.W.

### S.P.I.N

**S**izes **P**ortafilter **I**nput **N**icely.

The grinder unit, made up of

- The spin-agent, an ESP32 with
  - 4 load cells (so you can build a structure that'll definitely fit around your grinder and hold your portafilter under it)
  - 1 relay (that'll need to go somewhere so it can control the grinder motor)
- The spin-controller, an ESP32 with a touchscreen
  - So you can select & pre-save target weights, calibrate the load cells etc.

It'll communicate its last ground dose via BLE.

### F.L.O.W

**F**ulfils **L**iquid **O**utput **W**ishes

The brewing unit, made up of

- The flow-agent, an ESP32 with
  - 1 or 4 load cells (so you can build a platform that fits between the drip tray and the portafilter, leaving enough room for your cups)
  - 1 relay (that'll be in parallel to one of the buttons on your espresso machine, so it can start & stop the machine)
- The flow-controller, an ESP32 with a touchscreen
  - So you can select what kind of extraction ratio/output dose you'd like

It'll talk to a S.P.I.N unit to get its last ground dose, so you can set drink preferences by extraction ratio (ristretto/espresso/lungo etc.)

## Okay, but why?

Because...

- I like _good_ coffee
- Grinding by time is guesswork at best
- Brewing by time is the same kind of guesswork
- I don't like having to do guesswork before my first coffee
- Products off the shelf that do x-by-weight don't talk to each other AND cost a fortune
- I have a few ESPs laying around and clearly not enough other hobbies

## Dev Setup

-  Clone this repo
-  cd into it
  - If you have [mise-en-place](https://mise.jdx.dev) installed, it should set up most dependencies for you
  - If you don't, make sure you have the tools listed in [mise.toml](./mise.toml)
- Install the [Platformio CLI](https://docs.platformio.org/en/latest/core/installation/methods/index.html)
  - With mise, it's `pip install platformio`
  - Otherwise, follow the install guides
- With VSCode and the platformio extension, you're now good to go.
- If you prefer clangd completion in any editor/IDE, run `pio run -t compiledb -e <the-env-you-want-to-work-on>`. It'll build the compilation DB and set up clangd to look at the right one.

## Is it any good?

~~[Yes.](https://news.ycombinator.com/item?id=3067434)~~

Not yet. I've just-about understood how to talk to my hardware at this point.
4-point scales, I2C and BLE communication will be fun to figure out. And that's before I start with LVGL and building UIs.
