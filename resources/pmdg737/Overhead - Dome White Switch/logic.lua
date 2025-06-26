-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Dome White Light Switch
-- FS2020

-- Nov 28 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua

-- History:

-- Sep 27 2022: Initial version
-- Nov 23 2022: Knob for scales illumination
-- Nov 28 2022: Illumination updated


local gPropIllumination = user_prop_get(user_prop_add_enum("Illumination","Day,Night,Real,Dial","Real","Select illumination"))

local gPropCorner = user_prop_get(user_prop_add_enum("Corner","Cut,Rect","Cut","Select corner shape")) 

img_add_fullscreen("bg.png")

-----------------
local gImgKnobPanelLight = img_add("selector-knob.png", 190, 55, 66, 66)

-- =============================== switch lib functions ====================

local gSwitch = {}
local gSwitchCount = 0

local gSwitchColorHi = "#f0f0f0ff"
local gSwitchColorLo = "#b8b8b8ff"

local gImgVertSwitch = {"switch-up-pin.png", "switch-middle-pin.png", "switch-down-pin.png"}


function ShowTouchField(x, y, w, h)
  if not gDebugShowTouchFields then return end
  canvas_add(x, y, w, h, function()
    _rect(0, 0, w, h)
    _fill("#FF000020")
  end)
end



function AddVerticalSwitch(switch_image, x, y, p1, p2, p3, call_back)
  -- e.g.:  if p1, p2 and p3 are true, this switch has all three positions
  x = x - 20
  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local w, h, img, meta

  img = switch_image[1] -- all three switch position pictures assumed the same size
  meta = resource_info(img)
  if meta == nil then print(img.." not found"); return 0 end
  w = meta.WIDTH
  h = meta.HEIGHT

  s.x = x
  s.y = y
  s.w = w
  s.h = h

  local x_touch, y_touch, w_touch, h_touch
  x_touch = x + w/8
  y_touch = y
  w_touch = w * 3/4
  h_touch = h/2-1

  do
    local n = gSwitchCount
    button_add(gTouchField, nil, x_touch, y_touch, w_touch, h_touch, function() call_back(n, -1) end, nil) -- dec button
    button_add(gTouchField, nil, x_touch, y_touch+1+h_touch, w_touch, h_touch, function() call_back(n, 1) end, nil) -- inc button
  end
  
  s.img = {} -- stores the images for all switch positions
  s.img.pin = {}
  s.img.head = {}
  s.img.head[1]=nil -- will be initialized later
  s.img.head[2]=nil
  s.img.head[3]=nil
  if p1 then
    img = switch_image[1]
    s.img.pin[1] = img_add(img, x, y, w, h)
    visible(s.img.pin[1], false)
  end
  if p2 then
    img = switch_image[2]
    s.img.pin[2] = img_add(img, x, y, w, h)
    visible(s.img.pin[2], false)
  end
  if p3 then
    img = switch_image[3]
    s.img.pin[3] = img_add(img, x, y, w, h)
    visible(s.img.pin[3], false)
  end
  s.pos = nil
  return gSwitchCount
end

function SetSwitchPosition(switch, target)
  -- log("switch / target "..switch.."/"..target)
  local s = gSwitch[switch]
  if target == nil then return end
  
  if s.img.head[1]==nil then return end -- not yet initialized

  visible(s.img.pin[target], true)
  visible(s.img.head[target], true)
  if s.pos~=nil and s.pos~=target  then
    visible(s.img.pin[s.pos], false)
    visible(s.img.head[s.pos], false)
  end
  s.pos = target
end


-- ====================== operate switches ==================

---------------------- Dome White Switch  ----------------

local gSwitchDomeWhite

function cbSwitchDomeWhite(switch, dir)
  if dir > 0 then
    msfs_event("ROTOR_BRAKE", 25801)
  else
    msfs_event("ROTOR_BRAKE", 25802)
  end
end

msfs_variable_subscribe("L:switch_258_73X", "number", function(v)
  SetSwitchPosition(gSwitchDomeWhite, math.floor(v/50)+1)
end)

gSwitchDomeWhite = AddVerticalSwitch(gImgVertSwitch, 41, 26, true, true, true, cbSwitchDomeWhite)
------------

local gNightColor = img_add_fullscreen("night-color.png")

--------------- 

opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 300, 150, function()
  _rect(0, 0, 300, 150)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense


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

--------------------------------------
local PI = 4*math.atan(1)

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

-- =================== Draw lines ==================

local gFontPrintBig = "font:roboto_bold.ttf; size:20"
local gFontPrintSmall = "font:roboto_bold.ttf; size:18"

function DrawAllLines()
  local cx, cy, r
  r = 66/2
  cx = 190+r -- center selector knob
  cy = 55+r
  _arc(cx, cy, -185, -135,  r+10)
  _stroke(gColorPrint, 2)
  _arc(cx, cy, -47, 0,  r+10)
  _stroke(gColorPrint, 2)
  
  local steps={11, 11, 8, 11, 11, 11}
  PrintArcText("BRIGHT", gFontPrintSmall..";color:"..gColorPrint.."; halign:left", cx, cy, r+20, -30, steps)

  ----------- arrow -------
  
  _triangle(cx+r+10-4, cy-3,   cx+r+10+4, cy-3,   cx+r+10, cy-3+11)
  _fill(gColorPrint)


  ----------- OFF mark --------
  _rotate(-240, cx, cy)
  _move_to(cx+r, cy)
  _line_to(cx+r+10, cy)
  _stroke(gColorPrint, 2)
  _rotate(240, cx, cy)
  
  _move_to(192, 125)
  _line_to(202, 125)
  _stroke(gColorPrint, 2)
  
end

local gImgLines = canvas_add(0, 0, 300, 150, DrawAllLines)

-- ====================== Texts =================

-------------------------------------------------------



function PrintText(text, x, y, style, size, background)
  background = (background == nil)
  local count = string.len(text)
  if background then
    _rect(x-3, y, count/2*size+7, size)
    _fill(gColorBg)
  end
  _txt(text, style, x, y-1)
end

---------------------------------------------------------

function DrawAllTexts()
  local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  local size = 20
  PrintText("DOME WHITE", 33, 10, style, size, false)
  PrintText("PANEL", 198, 10, style, size, false)

  style = gFontPrintSmall..";color:"..gColorPrint
  size = 18
  PrintText("DIM", 55, 38, style, size, false)
  PrintText("OFF", 102, 77, style, size, false)
  PrintText("BRIGHT", 45, 122, style, size, false)

  PrintText("OFF", 161, 116, style, size, false)
end


local gImgTexts = canvas_add(0, 0, 300, 150, DrawAllTexts)

-- ===================== images above lines ================

--img_add("frames.png", 0, 0, 300, 150)


----------------- Add switch head pictures -------------
function DrawHeadUp()
  local dx=35
  local dy=9
  _rect(0+dx, 0+dy, 30, 46, 15)
  -- _fill("#b8b8b8ff")
  _fill(gSwitchColorLo)
  -- _fill_gradient_linear(0+dx, 10+dy, 30, 40, "#ffffffff", "#606060ff")    crashes AM 27.11.2022

  _ellipse(15+dx, 12+dy, 14, 12)
  -- _fill("#d0d0d0ff")
  _fill(gSwitchColorHi)
  -- _fill_gradient_radial(5+dx, 6+dy, 3, 40, "#f0f0f0ff", "#a0a0a0ff")
end

function DrawHeadMiddle()
  local dx=35
  local dy=37
  _circle(15+dx, 23+dy, 15)
  -- _fill("#d0d0d0ff")
  _fill(gSwitchColorHi)
  -- _fill_gradient_radial(15+dx, 23+dy, 6, 30, "#f0f0f0ff", "#000000ff")
end

function DrawHeadDown()
  local dx = 35
  local dy = 63
  _rect(0+dx, 0+dy, 30, 46, 15)
  -- _fill_gradient_linear(0+dx, 40+dy, 30, 10, "#ffffffff", "#808080ff")    crashes AM 27.11.2022
  -- _fill("#b8b8b8ff")
  _fill(gSwitchColorLo)
  _ellipse(15+dx, 33+dy, 14, 12)
  -- _fill("#d0d0d0ff")
  _fill(gSwitchColorHi)
  -- _fill_gradient_radial(5+dx, 33+dy, 3, 35, "#f0f0f0ff", "#909090ff")
end

function DrawSwitches()
  for k = 1,gSwitchCount do
    local s = gSwitch[k]
    
    canvas_draw(s.img.head[1], DrawHeadUp)
    canvas_draw(s.img.head[2], DrawHeadMiddle)
    canvas_draw(s.img.head[3], DrawHeadDown)
  end
end

for k = 1,gSwitchCount do
  local s = gSwitch[k]
  
  s.img.head[1] = canvas_add(s.x, s.y, s.w, s.h, DrawHeadUp)
  visible(s.img.head[1], false)
  
  s.img.head[2] = canvas_add(s.x, s.y, s.w, s.h, DrawHeadMiddle)
  visible(s.img.head[2], false)
  
  s.img.head[3] = canvas_add(s.x, s.y, s.w, s.h, DrawHeadDown)
  visible(s.img.head[3], false)
end

-- ========================== Dial Panel Light Control =================

function cbPanelLight(rotac)
  if rotac>0 then
    msfs_event("ROTOR_BRAKE", 9507)
  else
    msfs_event("ROTOR_BRAKE", 9508)
  end
end

dial_add(nil, 190, 55, 66, 66, cbPanelLight)

function DrawPointer()
  _rect(33-3, 4, 6, 25)
  _fill("black")
  _rect(33-1, 4, 2, 23)
  _fill(gColorPrint)
end

local gPointer = canvas_add(190, 55, 66, 66, DrawPointer)

msfs_variable_subscribe("L:switch_95_73X", "number", function(v)
  gPosLeft = v
  local angle = v-150
  rotate(gImgKnobPanelLight, angle, "LOG", .1)
  rotate(gPointer, angle, "LOG", .1)
end)


----------------------------- show switches, needed only in case the sim is not running

for k = 1,gSwitchCount do
  if gSwitch[k].img[1] ~= nil then
    SetSwitchPosition(k, 1)
  elseif gSwitch[k].img[2] ~= nil then
    SetSwitchPosition(k, 2)
  else
    SetSwitchPosition(k, 3)
  end
end

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 300, 150, function()
  _rect(0, 0, 300, 150)
  _fill("black")
end)
opacity(gBlackMask2, 0)

-- ================== illumination ========================


function DrawAllCanvas(color_print, r, g, b, switch_brightness)
  gColorPrint = color_print
  canvas_draw(gImgLines, DrawAllLines)
  canvas_draw(gImgTexts, DrawAllTexts)
  canvas_draw(gPointer, DrawPointer)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  DrawSwitches()
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)


