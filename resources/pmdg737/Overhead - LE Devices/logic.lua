-- Detlef von Reusner
-- PMDG B737-700 Aft Overhead panel - LE devices
-- FS2020

-- Nov 28 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Sep 10 2022: Initial version
-- Nov 28 2022: Illumination updated


img_add_fullscreen("bg.png")

--------------- 

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 185, function()
  _rect(0, 0, 400, 185)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense

local gColorAmber = string.format(";color:#%02x%02x%02x", 243, 163, 90)
local gColorBlue = string.format(";color:#%02x%02x%02x", 250, 250, 250)
local gColorGreen = string.format(";color:#%02x%02x%02x", 98, 208, 103)

local gColorPrint = "#E0E0E0FF"
local gColorBg = "#101010FF"


local gFontLight = "font:arimo_bold.ttf; size:14"


local gDebugShowTouchFields = false

local gTouchField
if gDebugShowTouchFields then
   gTouchField = "touch-field-on.png"
else
   gTouchField = nil
end


-- =================== Draw lines ==================

function DrawAllLines()
  -- slats left --
  _move_to(46, 94)
  _line_to(46, 137)
  _line_to(58, 137)

  _move_to(117, 137)
  _line_to(126, 137)
  _line_to(126, 119)

  -- slats right --
  _move_to(275, 119)
  _line_to(275, 137)
  _line_to(288, 137)
  
  _move_to(347, 137)
  _line_to(355, 137)
  _line_to(355, 93)
  
  -- flaps --
  _move_to(126, 48)
  _line_to(126, 32)
  _line_to(173, 32)
  
  _move_to(234, 32)
  _line_to(275, 32)
  _line_to(275, 46)
  
  -- test button --
  _move_to(179, 148)
  _line_to(168, 148)
  _line_to(168, 174)
  _line_to(180, 174)
  
  _move_to(223, 174)
  _line_to(235, 174)
  _line_to(235, 148)
  _line_to(223, 148)  

  _stroke(gColorPrint, 2)
  
end

local gImgLines = canvas_add(0, 0, 400, 185, DrawAllLines)


-- =============== Draw Texts =====================
local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintMedium = "font:roboto_bold.ttf; size:22"
local gFontPrintSmall = "font:roboto_bold.ttf; size:18"


function PrintText(text, x, y, style, size, black_bg)
  black_bg = (black_bg == true)
  local count = string.len(text)
  
  _rect(x-3, y, count/2*size+7, size)
  if black_bg then _fill(gColorBg) end
  _txt(text, style, x, y-1)
end

function PrintVertText(text, x, y, style, size)
  local count = string.len(text)
  local step = size*.7
  _rect(x, y, size, count*step+step/2)
  _fill(gColorBg)
  for k=1,count do
    _txt(string.sub(text, k, k), style, x+5, y+(k-1)*step)
  end
end

function DrawAllTexts()
  local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  PrintText("LE DEVICES",  152, 2,  style, 24)

  style = gFontPrintMedium..";color:"..gColorPrint.."; halign:left"
  PrintText("FLAPS", 178, 22, style, 22)
  PrintText("SLATS", 61, 127, style, 22)
  PrintText("SLATS", 291, 127, style, 22)


  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("TRANSIT", 172, 73, style, 18)
  PrintText("EXT", 190, 90, style, 18)
  PrintText("FULL EXT", 171, 106, style, 18)
  PrintText("TEST", 185, 165, style, 18)
  PrintText("+", 198, 47, style, 18)

  PrintText("1", 133, 37, style, 18)
  PrintText("2", 154, 45, style, 18)
  PrintText("3", 238, 45, style, 18)
  PrintText("4", 256, 37, style, 18)

  PrintText("1", 55, 96, style, 18)
  PrintText("2", 71, 102, style, 18)
  PrintText("3", 91, 108, style, 18)
  PrintText("4", 110, 113, style, 18)

  PrintText("5", 282, 113, style, 18)
  PrintText("6", 302, 108, style, 18)
  PrintText("7", 321, 102, style, 18)
  PrintText("8", 341, 96, style, 18)
end


local gImgTexts = canvas_add(0, 0, 400, 400, DrawAllTexts)


-- ===================== images above lines ================

-- img_add("frames.png", 0, 0, 400, 185)

-- ================== Leading Edge Annunciator Test Switch (Button) ==============

button_add("test-button-pressed.png", "test-button-released.png", 188, 134, 25, 25,
  function() msfs_event("ROTOR_BRAKE", 22401) end,
  function() msfs_event("ROTOR_BRAKE", 22404) end)

-- ============================ functions for lights =======================

local gLed = {}

-- function AddLed(lvar, led_on, led_off, x, y, w, h)
  -- img_add(led_off, x, y, w, h)
  -- gLed[lvar] = img_add(led_on, x, y, w, h)

  -- visible(gLed[lvar], false) -- default off
  -- msfs_variable_subscribe(lvar, "number", function(v)
    -- visible(gLed[lvar], v~=0)
  -- end)
-- end


function AddLed(lvar, led_on, led_off, x, y, w, h)
  -- paints the Off-pictures only. See ActivateLeds()
  img_add(led_off, x, y, w, h)
  gLed[lvar] = {}
  local led = gLed[lvar]
  led.img = led_on -- store picture file name for activating the led later
  led.x = x
  led.y = y
  led.w = w
  led.h = h
end

function ActivateLeds()
  -- call this function later, so that it is on top of the black dimming layer, allowing only the off-picture to get dimmed
  for lvar, led in pairs(gLed) do
    led.img = img_add(led.img, led.x, led.y, led.w, led.h)
    visible(led.img, false) -- default off
    msfs_variable_subscribe(lvar, "number", function(v) visible(led.img, v~=0) end)
  end
end

-- ======================== add lights ======================
 
-- starting top left
local gLvarLeft = {2256, 2255, 2254, 2253, 2251, 2252,
  2247, 2248, 2249, 2250, 2241, 2242,
  2246, 2245, 2244, 2243}

-- reverse order, starting bottom left 
local gLvarRight = {2259, 2260, 2261, 2262,
  2257, 2258, 2266, 2265, 2264, 2263,
  2267, 2268, 2269, 2270, 2271, 2272}
--------------- left side leds

x0 = 47
y = 30
w = 18
h = 21
dx = w+2
dy = 7
k_lvar = 1

x = x0
for col=1,6 do
  AddLed("L:switch_"..gLvarLeft[k_lvar].."_73X", "amber-left-on.png", "amber-left-off.png", x, y, w, h)
  x=x+dx
  y=y+dy
  k_lvar = k_lvar+1
end
y=y-6*dy+h-3

x = x0
for col=1,4 do
  AddLed("L:switch_"..gLvarLeft[k_lvar].."_73X", "green-left-on.png", "green-left-off.png", x, y, w, h)
  x=x+dx
  y=y+dy
  k_lvar = k_lvar+1
end
for col=1,2 do
  AddLed("L:switch_"..gLvarLeft[k_lvar].."_73X", "green-left-long-on.png", "green-left-long-off.png", x, y, 18, 39)
  x=x+dx
  y=y+dy
  k_lvar = k_lvar+1
end
y=y-6*dy+h-3

x = x0
for col=1,4 do
  AddLed("L:switch_"..gLvarLeft[k_lvar].."_73X", "green-left-on.png", "green-left-off.png", x, y, w, h)
  x=x+dx
  y=y+dy
  k_lvar = k_lvar+1
end

--------------- right side leds

x0 = 235
w = 18
h = 21
dx = w+2
dy = 7
k_lvar = 1

x = x0+2*dx
y = y+7-2*dy
for col=1,4 do
  AddLed("L:switch_"..gLvarRight[k_lvar].."_73X", "green-right-on.png", "green-right-off.png", x, y, w, h)
  x=x+dx
  y=y-dy
  k_lvar = k_lvar+1
end
y=y+6*dy-h+3

x = x0
for col=1,2 do
  AddLed("L:switch_"..gLvarRight[k_lvar].."_73X", "green-right-long-on.png", "green-right-long-off.png", x, y, 18, 39)
  x=x+dx
  y=y-dy
  k_lvar = k_lvar+1
end

for col=1,4 do
  AddLed("L:switch_"..gLvarRight[k_lvar].."_73X", "green-right-on.png", "green-right-off.png", x, y, w, h)
  x=x+dx
  y=y-dy
  k_lvar = k_lvar+1
end
y=y+6*dy-h+3

x = x0
for col=1,6 do
  AddLed("L:switch_"..gLvarRight[k_lvar].."_73X", "amber-right-on.png", "amber-right-off.png", x, y, w, h)
  x=x+dx
  y=y-dy
  k_lvar = k_lvar+1
end

local gLedShade = img_add_fullscreen("shade-leds.png")
-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 185, function()
  _rect(0, 0, 400, 185)
  _fill("black")
end)
opacity(gBlackMask2, 0)

-- ================== Draw On-pictures of the lights =============

ActivateLeds()

-- ================== illumination ========================

local gDebugIllumination = false

if gDebugIllumination then
  debug_bg = canvas_add(4, 15, 396, 70, function()
    _rect(0, 0, 396, 70)
    _fill("#00000080")
  end)
end
local gTxtDebug = txt_add("", "font:arimo_bold.ttf;color:white;size:16", 2, 25, 400, 20)
local gTxtDebug2 = txt_add("", "font:arimo_bold.ttf;color:white;size:16", 2, 40, 400, 20)
local gTxtDebug3 = txt_add("", "font:arimo_bold.ttf;color:white;size:16", 2, 55, 400, 20)

function DrawAllCanvas(color_print, r, g, b, switch_brightness)
  gColorPrint = color_print
  canvas_draw(gImgLines, DrawAllLines)
  canvas_draw(gImgTexts, DrawAllTexts)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  
  opacity(gLedShade, 1-switch_brightness)
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)
