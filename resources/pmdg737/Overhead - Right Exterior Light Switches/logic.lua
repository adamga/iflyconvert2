-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Exterior Light Switches Right
-- FS2020

-- Nov 28 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua

-- If you want the shape of this instrument to be a rectangle, set Userprops corner to "Rect".

-- History:

-- Sep 26 2022: Initial version
-- Nov 28 2022: Illumination updated


local gPropCorner = user_prop_get(user_prop_add_enum("Corner","Cut,Rect","Cut","Select corner shape")) 

local gNightColor
local gColorPrint = "#d0d0d0ff" -- just an initial color

local gSwitchColorHi = "#f0f0f0ff"
local gSwitchColorLo = "#b8b8b8ff"

if gPropCorner=="Cut" then
  img_add_fullscreen("bg-cut.png")
  gNightColor = img_add_fullscreen("night-color-cut.png")
else
  img_add_fullscreen("bg.png")
  gNightColor = img_add_fullscreen("night-color.png")
end

-------------

-- =============================== switch lib functions ====================

local gSwitch = {}
local gSwitchCount = 0
local gImgVertSwitch = {"switch-up-pin.png", "switch-middle-pin.png", "switch-down-pin.png"}


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

function ShowTouchField(x, y, w, h)
  if not gDebugShowTouchFields then return end
  canvas_add(x, y, w, h, function()
    _rect(0, 0, w, h)
    _fill("#FF000020")
  end)
end

-- ====================== operate switches ==================

---------------------- Logo Light Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchLogoLight
-- function cbSwitchLogoLight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 12201)
--   else
--     msfs_event("ROTOR_BRAKE", 12202)
--   end
-- end
-- msfs_variable_subscribe("L:switch_122_73X", "number", function(v)
--   SetSwitchPosition(gSwitchLogoLight, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchLogoLight

function cbSwitchLogoLight(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Logo_Light_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Logo_Light_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Logo_Light_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchLogoLight, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchLogoLight, 3) -- ON position
  end
end)

gSwitchLogoLight = AddVerticalSwitch(gImgVertSwitch, 41, 29, true, false, true, cbSwitchLogoLight)

---------------------- Position Light Switch with Strobe and Steady ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchPositionLight
-- function cbSwitchPositionLight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 12301)
--   else
--     msfs_event("ROTOR_BRAKE", 12302)
--   end
-- end
-- msfs_variable_subscribe("L:switch_123_73X", "number", function(v)
--   SetSwitchPosition(gSwitchPositionLight, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchPositionLight

function cbSwitchPositionLight(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Position_Light_SW_VAL", "number", 20)
  else
    fs2020_variable_write("L:VC_Position_Light_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Position_Light_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchPositionLight, 1) -- STEADY position
  elseif v == 10 then
    SetSwitchPosition(gSwitchPositionLight, 2) -- OFF position (center)
  else
    SetSwitchPosition(gSwitchPositionLight, 3) -- STROBE & STEADY position
  end
end)

gSwitchPositionLight = AddVerticalSwitch(gImgVertSwitch, 132, 29, true, true, true, cbSwitchPositionLight)

---------------------- ANTI COLLISION LIGHT Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchAntiCollisionLight
-- function cbSwitchAntiCollisionLight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 12401)
--   else
--     msfs_event("ROTOR_BRAKE", 12402)
--   end
-- end
-- msfs_variable_subscribe("L:switch_124_73X", "number", function(v)
--   SetSwitchPosition(gSwitchAntiCollisionLight, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchAntiCollisionLight

function cbSwitchAntiCollisionLight(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Beacon_Light_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Beacon_Light_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Beacon_Light_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchAntiCollisionLight, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchAntiCollisionLight, 3) -- ON position
  end
end)

gSwitchAntiCollisionLight = AddVerticalSwitch(gImgVertSwitch, 255, 29, true, false, true, cbSwitchAntiCollisionLight)

------------------------- WING LIGHT Switch --------------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWingLight
-- function cbSwitchWingLight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 12501)
--   else
--     msfs_event("ROTOR_BRAKE", 12502)
--   end
-- end
-- msfs_variable_subscribe("L:switch_125_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWingLight, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWingLight

function cbSwitchWingLight(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Wing_Light_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Wing_Light_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Wing_Light_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWingLight, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchWingLight, 3) -- ON position
  end
end)

gSwitchWingLight = AddVerticalSwitch(gImgVertSwitch, 334, 29, true, false, true, cbSwitchWingLight)

------------------------- WHEEL WELL LIGHT Switch --------------------

------------------------- WHEEL WELL LIGHT Switch --------------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWheelWell
-- function cbSwitchWheelWell(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 12601)
--   else
--     msfs_event("ROTOR_BRAKE", 12602)
--   end
-- end
-- msfs_variable_subscribe("L:switch_126_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWheelWell, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWheelWell

function cbSwitchWheelWell(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Wheel_Well_Light_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Wheel_Well_Light_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Wheel_Well_Light_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWheelWell, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchWheelWell, 3) -- ON position
  end
end)

gSwitchWheelWell = AddVerticalSwitch(gImgVertSwitch, 412, 29, true, false, true, cbSwitchWheelWell)


--------------- 

opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 600, 150, function()
  _rect(0, 0, 600, 150)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense


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
  _move_to(150, 264)
  _line_to(255, 264)
  _stroke(gColorPrint, 2)
  
end

local gImgLines = canvas_add(0, 0, 600, 150, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:26"
local gFontPrintSmall = "font:roboto_bold.ttf; size:22"


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

  PrintText("LOGO", 48, 3, style, 26, false)
  PrintText("POSITION", 118, 3, style, 26, false)
  
  PrintText("ANTI", 261, 3, style, 26, false)
  PrintText("COLLISION", 233, 22, style, 26, false)
  
  PrintText("WING", 340, 3, style, 26, false)
  
  PrintText("WHEEL", 414, 3, style, 26, false)
  PrintText("WELL", 419, 22, style, 26, false)

  style = gFontPrintSmall..";color:"..gColorPrint

  PrintText("OFF", 192, 80, style, 22, false)

  PrintText("OFF", 56, 45, style, 22, false)
  PrintText("ON", 59, 120, style, 22, false)
  
  PrintText("STROBE &", 124, 30, style, 22, false)
  PrintText("STEADY", 129, 45, style, 22, false)
  PrintText("STEADY", 129, 120, style, 22, false)

  PrintText("OFF", 269, 45, style, 22, false)
  PrintText("ON", 271, 120, style, 22, false)
  
  PrintText("OFF", 347, 45, style, 22, false)
  PrintText("ON", 350, 120, style, 22, false)
  
  PrintText("OFF", 425, 45, style, 22, false)
  PrintText("ON", 430, 120, style, 22, false)
  
end


local gImgTexts = canvas_add(0, 0, 600, 150, DrawAllTexts)

-- ===================== images above lines ================

--img_add("frames.png", 0, 0, 600, 150)


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

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 600, 150, function()
  _rect(0, 0, 600, 150)
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
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  DrawSwitches()
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)

