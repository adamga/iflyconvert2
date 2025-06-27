-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Cabin Altitude Panel
-- FS2020

-- Dec 1 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Nov 17 2022: Initial version
-- Dec 1 2022: Illumination updated

--[[
MonitorVariable("L:switch_181_73X", "Number") -- 181 - CABIN Altimeter Short Needle
MonitorVariable("L:switch_182_73X", "Number") -- 182 - CABIN Altimeter Long Needle
MonitorVariable("L:switch_183_73X", "Number") -- 183 - ALT HORN CUTOUT Switch
MonitorVariable("L:switch_184_73X", "number") -- 184 - CABIN Rate of CLIMB Indicator Needle, KF0 = -4; KF10 = -3; KF20 = -2; KF30 = -1; KF40 = -0.5; KF50 = 0; KF60 = +0.5; KF70 = +1; KF80 = +2; KF90 = +3; KF100 = +4 -->

]]--


img_add_fullscreen("bg.png")


--------------- 
local PI = 4*math.atan(1)


local gColorPrint = "#E0E0E0FF"
local gColorBlue = "#0000FFFF" -- later changed
local gColorRed = "#FF0000FF"

local gColorBg = "#101010FF"



local gFontLight = "font:arimo_bold.ttf; size:14"


local gDebugShowTouchFields = false

local gTouchField
if gDebugShowTouchFields then
   gTouchField = "touch-field-on.png"
else
   gTouchField = nil
end

-- =============== Night mask ==================

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 410, function()
  _rect(0, 0, 400, 410)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense

-- =========== climb rate ======

function AngleClimbrate(v)
  -- compute angle from Lvar value

  if v<500 then
    v=500-v
    if v<300 then
      angle = -v/100*39
    else
      angle = -(3*39+(v-300)/100*27)
    end
  else
    v = v-500
    if v<300 then
      angle = v/100*39
    else
      angle = 3*39+(v-300)/100*27
    end
  end
  -- print(v.." gets you "..angle)
  return angle
end

function AngleCabinAlt(v)
  -- compute angle from Lvar value

  local angle
  angle = v/1140*360 * (2-v/1000) -- compressed
  -- print(v.." gets you "..angle)
  return angle
end

function PrintArcText(text, style, cx, cy, radius, start, steps)
  -- angle starts at 0 == 12 clock here
  -- steps is letter distance in pixels
  local angle = start
  local k = 1
  
  _rotate(angle, cx, cy)
  local s = string.sub(text, k, k)
  while s ~= "" do
    _txt(s, style, cx-steps[k]/5, cy-radius)
    delta = math.asin(steps[k]/radius)/PI*180
    -- print("delta is "..delta)
    _rotate(delta, cx, cy)
    angle = angle+delta
    k = k+1
    s = string.sub(text, k, k)
  end
  _rotate(-angle, cx, cy)
end

function PrintArcTextBottom(text, style, cx, cy, radius, start, steps)
  -- angle starts at 0 == 12 clock here
  -- steps is letter distance in pixels
  local angle = -start
  local k = 1
  
  _rotate(angle, cx, cy)
  local s = string.sub(text, k, k)
  while s ~= "" do
    _txt(s, style, cx-steps[k]/5, cy+radius)
    delta = -math.asin(steps[k]/radius)/PI*180*.5
    -- print("delta is "..delta)
    _rotate(delta, cx, cy)
    angle = angle+delta
    k = k+1
    s = string.sub(text, k, k)
  end
  _rotate(-angle, cx, cy)
end

-- =================== Draw lines ==================

function DrawAllLines()
  local w = 30
  _circle(305+w/2, 115+w/2, w/2+4) -- alt horn cutout
  _stroke(gColorPrint, 2)
  
  --------------------- scale climb rate top ----------
  
  local cx, cy, r, v, angle, delta
  dir = 1
  r = 132/2
  cx = 96+r
  cy = 255+r
  
  _rotate(180, cx, cy)

  angle = 0
  for v=500,1000,100 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+47, cy)
    _stroke(gColorPrint, 2)
  end
  _rotate(-angle, cx, cy)

  angle = 0
  for v=500,700,20 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+41, cy)
    _stroke(gColorPrint, 1)
  end
  _rotate(-angle, cx, cy)

  angle = 0
  for v=700,800,10 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+41, cy)
    _stroke(gColorPrint, 1)
  end
  _rotate(-angle, cx, cy)

  angle = 0
  for v=750,950,50 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+42  , cy)
    _stroke(gColorPrint, 2)
  end
  _rotate(-angle, cx, cy)

  --------------------- scale climb rate bottom ----------

  angle = 0
  for v=500,0,-100 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+47, cy)
    _stroke(gColorPrint, 2)
  end
  _rotate(-angle, cx, cy)

  angle = 0
  for v=500,300,-20 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+41, cy)
    _stroke(gColorPrint, 1)
  end
  _rotate(-angle, cx, cy)

  angle = 0
  for v=300,200,-10 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+41, cy)
    _stroke(gColorPrint, 1)
  end
  _rotate(-angle, cx, cy)

  angle = 0
  for v=250,50,-50 do
    delta = AngleClimbrate(v) - angle
    angle = AngleClimbrate(v)
    _rotate(delta, cx, cy)
    _move_to(cx+36, cy)
    _line_to(cx+42  , cy)
    _stroke(gColorPrint, 2)
  end
  _rotate(-angle+180, cx, cy)
  
  _move_to(204, 314)
  _line_to(205, 321)
  _line_to(204, 327)
  _stroke(gColorPrint, 2)
  
  ------------- arrows -----------

  _rotate(18, cx, cy)
  _triangle(cx-49, cy,  cx-46, cy-9, cx-43, cy)
  _fill(gColorPrint)
  _move_to(cx-46, cy)
  _line_to(cx-46, cy+7)
  _stroke(gColorPrint,   2)
  _rotate(-18, cx, cy)
  
  _rotate(-18, cx, cy)
  _triangle(cx-49, cy,  cx-46, cy+9, cx-43, cy)
  _fill(gColorPrint)
  _move_to(cx-46, cy)
  _line_to(cx-46, cy-7)
  _stroke(gColorPrint,   2)
  _rotate(18, cx, cy)
  

  -------------- arced texts cabin climb ----------
  
  local style = "font:arimo_bold.ttf; size:12; halign:left; color:"..gColorPrint
  local steps = {9, 9, 10, 6, 9, 6, 9, 9, 6, 11, 10}
  PrintArcText("CABIN CLIMB", style, cx, cy, 35, -75, steps)

  style = "font:arimo_bold.ttf; size:12; halign:left; color:"..gColorBlue
  steps = {9, 9, 9, 9, 7, 9, 9, 7, 10, 9, 9, 7, 13, 6, 9}
  PrintArcTextBottom("1000 FT PER MIN", style, cx, cy, 24, -80, steps)
  
  -- ============= outer scale diff pressure ============
  
  r = 200/2
  cx = 54+r
  cy = 21+r
  
  _arc(cx, cy, -176, -156, 71) -- cabin pressur limit line
  _stroke(gColorRed, 6)

  _rotate(20, cx, cy)
  _move_to(cx-71, cy)
  _line_to(cx-84, cy)
  _stroke(gColorRed, 5)
  _rotate(-20, cx, cy)


  style = "font:arimo_bold.ttf; size:12; halign:left; color:"..gColorPrint
  steps = {7, 4, 7, 7, 6, 7, 7, 7, 7, 7}
  PrintArcText("DIFF PRESS", style, cx, cy, 100, -51, steps)
  steps = {8, 8, 7}
  PrintArcText("PSI", style, cx, cy, 86, -20, steps)


  angle = 0
  for v=1,11 do
    delta = 360/11
    angle = angle+delta
    _rotate(delta, cx, cy)
    _move_to(cx, cy-68)
    _line_to(cx, cy-76)
    _stroke(gColorPrint, 2)
  end
  _rotate(-angle, cx, cy)
  
  angle = 0
  for v=1,55 do
    delta = 360/55
    angle = angle+delta
    _rotate(delta, cx, cy)
    _move_to(cx, cy-68)
    _line_to(cx, cy-74)
    _stroke(gColorPrint, 1)
  end
  _rotate(-angle, cx, cy)

  --------------- inner scale cabin pressure -----------

  angle = 0
  for v=0,1000,100 do
    delta = AngleCabinAlt(v) - angle
    angle = AngleCabinAlt(v)
    _rotate(delta, cx, cy)
    _move_to(cx, cy-38)
    _line_to(cx, cy-44)
    _stroke(gColorPrint, 2)
  end
  _rotate(-angle, cx, cy)
  
  angle = 0
  for v=0,700,20 do
    delta = AngleCabinAlt(v) - angle
    angle = AngleCabinAlt(v)
    _rotate(delta, cx, cy)
    _move_to(cx, cy-38)
    _line_to(cx, cy-42)
    _stroke(gColorPrint, 1)
  end
  _rotate(-angle, cx, cy)
  
end

local gImgLines = canvas_add(0, 0, 400, 410, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:20"
local gFontPrintSmall = "font:roboto_regular.ttf; size:18"
local gFontPrintTiny = "font:roboto_regular.ttf; size:14"
local gFontPrintMicro = "font:roboto_regular.ttf; size:10"


function PrintText(text, x, y, style, size, background)
  background = (background == nil)
  local count = string.len(text)
  if background then
    _rect(x-3, y, count/2*size+7, size)
    _fill(gColorBg)
  end
  _txt(text, style, x, y-1)
end



function DrawAllTexts()
  local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  local width = 20
  PrintText("ALT", 305, 53, style, width, false)
  PrintText("HORN", 297, 70, style, width, false)
  PrintText("CUTOUT", 290, 87, style, width, false)

  PrintText("+", 300, 180, style, width, false)
  
  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  width = 18
  PrintText("0", 104, 312, style, width, false)
  PrintText(".5", 111, 280, style, width, false)
  PrintText(".5", 111, 344, style, width, false)
  PrintText("1", 147, 259, style, width, false)
  PrintText("1", 147, 366, style, width, false)
  PrintText("2", 182, 263, style, width, false)
  PrintText("2", 182, 362, style, width, false)
  PrintText("3", 204, 282, style, width, false)
  PrintText("3", 204, 344, style, width, false)
  PrintText("4", 214, 312, style, width, false)

  style = gFontPrintTiny..";color:"..gColorPrint.."; halign:left"
  width = 14
  PrintText("UP", 101, 295, style, width, false)
  PrintText("DN", 101, 330, style, width, false)

  ----- diff pressure -----------

  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  width = 18
  PrintText("0", 151, 29, style, width, false)
  PrintText("1", 197, 43, style, width, false)
  PrintText("2", 228, 79, style, width, false)
  PrintText("3", 234, 125, style, width, false)
  PrintText("4", 215, 168, style, width, false)
  PrintText("5", 174, 196, style, width, false)
  PrintText("6", 126, 196, style, width, false)
  PrintText("7", 85, 171, style, width, false)
  PrintText("8", 66, 125, style, width, false)
  PrintText("9", 74, 76, style, width, false)
  PrintText("10", 97, 43, style, width, false)


  ----- cabin pressure --------
  
  PrintText("0", 150, 60, style, width, false)
  PrintText("5", 195, 88, style, width, false)
  PrintText("10", 196, 135, style, width, false)
  PrintText("15", 163, 162, style, width, false)
  PrintText("20", 127, 163, style, width, false)
  PrintText("25", 100, 141, style, width, false)
  PrintText("30", 93, 117, style, width, false)
  PrintText("35", 94, 99, style, width, false)
  PrintText("40", 99, 85, style, width, false)
  PrintText("50", 110, 72, style, width, false)
  
  style = gFontPrintTiny..";color:"..gColorPrint.."; halign:left"
  width = 14
  PrintText("CABIN", 139, 86, style, width, false)
  PrintText("ALT", 146, 94, style, width, false)
  
  style = gFontPrintMicro..";color:"..gColorPrint.."; halign:left"
  width = 10
  PrintText("X 1000 FT", 136, 145, style, width, false)

end


local gImgTexts = canvas_add(0, 0, 400, 410, DrawAllTexts)

-- ================== Needles =================

-------------------- climb rate --------------

function DrawNeedleClimbrate()
  local r=66
  _move_to(r-3, r)
  _line_to(r-3, r-28)
  _line_to(r, r-40)
  _line_to(r+3, r-28)
  _line_to(r+3, r)
  _line_to(r-3, r)
  _fill(gColorPrint)
end

local gNeedleClimbrate = canvas_add(96, 255, 132, 132, DrawNeedleClimbrate)
img_add("needle-cover.png", 96+66-15, 255+66-15, 30, 30)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_184_73X", "number", function(v)
--   rotate(gNeedleClimbrate, AngleClimbrate(v)-90)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_CABIN_Rate_Indicator_Pointer_VAL", "number", function(v)
  rotate(gNeedleClimbrate, AngleClimbrate(v)-90)
end)

----------------- diff press ------------

function DrawNeedleDiffPress()
  local r=100
  _move_to(r-4, r)
  _line_to(r-4, r-40)
  _line_to(r+4, r-40)
  _line_to(r+4, r)
  _line_to(r-4, r)
  _fill("#404040c0") -- transparent
--  _fill("#ffffff60") -- transparent

  _move_to(r-4, r-40)
  _line_to(r, r-66)
  _line_to(r+4, r-40)
  _line_to(r-4, r-40)
  _fill(gColorPrint)
end

local gNeedleDiffPress = canvas_add(54, 21, 200, 200, DrawNeedleDiffPress)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_182_73X", "number", function(v)
--   rotate(gNeedleDiffPress, v/1100*360)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_CABIN_Diff_Indicator_Pointer_VAL", "number", function(v)
  rotate(gNeedleDiffPress, v/1100*360)
end)

-------------------- cabin alt  --------------

function DrawNeedleCabinAlt()
  local r=65
  _move_to(r-6, r)
  _line_to(r, r-34)
  _line_to(r+6, r)
  _line_to(r-6, r)
  _fill(gColorPrint)
end

local gNeedleCabinAlt = canvas_add(89, 56, 130, 130, DrawNeedleCabinAlt)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_181_73X", "number", function(v)
--   rotate(gNeedleCabinAlt, AngleCabinAlt(v)) 
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_CABIN_Alt_Indicator_Pointer_VAL", "number", function(v)
  rotate(gNeedleCabinAlt, AngleCabinAlt(v)) 
end)

img_add("needle-cover.png", 139, 106, 30, 30)


-- ====================== Alt Horn Cutout Button ==================

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- button_add("button-released.png", "button-pressed.png", 305, 115, 30, 30,
--   function() msfs_event("ROTOR_BRAKE", 18301) end,
--   function() msfs_event("ROTOR_BRAKE", 18304) end)

-- ================ CONVERTED iFLY CODE ================
button_add("button-released.png", "button-pressed.png", 305, 115, 30, 30,
  function() msfs_variable_write("L:VC_Altitude_HORN_Cutout_SW_VAL", "number", 10) end,
  function() msfs_variable_write("L:VC_Altitude_HORN_Cutout_SW_VAL", "number", 0) end)

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 410, function()
  _rect(0, 0, 400, 410)
  _fill("black")
end)
opacity(gBlackMask2, 0)


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
  canvas_draw(gNeedleClimbrate, DrawNeedleClimbrate)
  canvas_draw(gNeedleDiffPress, DrawNeedleDiffPress)
  canvas_draw(gNeedleCabinAlt, DrawNeedleCabinAlt)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)
