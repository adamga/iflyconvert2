-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Pitot and Window Heat
-- FS2020

-- Dec 2 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 19 2022: Initial version
-- Dec 2 2022: Illumination updated


img_add_fullscreen("bg.png")

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
  x = x - 76
  y = y - 20
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
  s.no_head = (string.find(switch_image[1], "pin", 1, true) == nil)
  s.img.pin = {}
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

  if s.img.pin == nil then -- old format, no pin/head separation
    if s.img[target] == nil then return end
    visible(s.img[target], true)
    if s.pos~=nil and s.pos~=target  then
      visible(s.img[s.pos], false)
    end
  else
    if not s.no_head and (s.img.head[1]==nil) then return end -- not yet initialized

    visible(s.img.pin[target], true)
    if not s.no_head then visible(s.img.head[target], true) end
    if s.pos~=nil and s.pos~=target  then
      visible(s.img.pin[s.pos], false)
      if not s.no_head then visible(s.img.head[s.pos], false) end
    end
  end
  s.pos = target
end

-- ====================== operate switches ==================

---------------------- Window Heat Left Side Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWindowHeatLeftSide
-- function cbSwitchWindowHeatLeftSide(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 13501)
--   else
--     msfs_event("ROTOR_BRAKE", 13502)
--   end
-- end
-- msfs_variable_subscribe("L:switch_135_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWindowHeatLeftSide, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWindowHeatLeftSide

function cbSwitchWindowHeatLeftSide(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Window_Heat_1_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Window_Heat_1_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Window_Heat_1_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWindowHeatLeftSide, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchWindowHeatLeftSide, 3) -- ON position
  end
end)

gSwitchWindowHeatLeftSide = AddVerticalSwitch(gImgVertSwitch, 90, 156, true, false, true, cbSwitchWindowHeatLeftSide)

---------------------- Window Heat Left Fwd Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWindowHeatLeftFwd
-- function cbSwitchWindowHeatLeftFwd(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 13601)
--   else
--     msfs_event("ROTOR_BRAKE", 13602)
--   end
-- end
-- msfs_variable_subscribe("L:switch_136_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWindowHeatLeftFwd, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWindowHeatLeftFwd

function cbSwitchWindowHeatLeftFwd(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Window_Heat_2_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Window_Heat_2_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Window_Heat_2_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWindowHeatLeftFwd, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchWindowHeatLeftFwd, 3) -- ON position
  end
end)

gSwitchWindowHeatLeftFwd = AddVerticalSwitch(gImgVertSwitch, 158, 156, true, false, true, cbSwitchWindowHeatLeftFwd)

---------------------- Window Heat Test Switch, spring loaded ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWindowHeatTest
-- function cbSwitchWindowHeatTest(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 13701)
--     timer_start(300, 300, 1, function() msfs_event("ROTOR_BRAKE", 13704) end) -- spring back
--   else
--     msfs_event("ROTOR_BRAKE", 13702)
--     timer_start(300, 300, 1, function() msfs_event("ROTOR_BRAKE", 13704) end)
--   end
-- end
-- msfs_variable_subscribe("L:switch_137_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWindowHeatTest, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWindowHeatTest

function cbSwitchWindowHeatTest(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Window_Heat_Test_SW_VAL", "number", 20)
    timer_start(300, 300, 1, function() fs2020_variable_write("L:VC_Window_Heat_Test_SW_VAL", "number", 10) end) -- spring back
  else
    fs2020_variable_write("L:VC_Window_Heat_Test_SW_VAL", "number", 0)
    timer_start(300, 300, 1, function() fs2020_variable_write("L:VC_Window_Heat_Test_SW_VAL", "number", 10) end)
  end
end

fs2020_variable_subscribe("L:VC_Window_Heat_Test_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWindowHeatTest, 1) -- OVHT position
  elseif v == 10 then
    SetSwitchPosition(gSwitchWindowHeatTest, 2) -- PWR TEST position (center)
  else
    SetSwitchPosition(gSwitchWindowHeatTest, 3) -- TEST position
  end
end)

gSwitchWindowHeatTest = AddVerticalSwitch(gImgVertSwitch, 226, 166, true, true, true, cbSwitchWindowHeatTest)

---------------------- Window Heat Right Fwd Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWindowHeatRightFwd
-- function cbSwitchWindowHeatRightFwd(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 13801)
--   else
--     msfs_event("ROTOR_BRAKE", 13802)
--   end
-- end
-- msfs_variable_subscribe("L:switch_138_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWindowHeatRightFwd, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWindowHeatRightFwd

function cbSwitchWindowHeatRightFwd(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Window_Heat_3_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Window_Heat_3_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Window_Heat_3_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWindowHeatRightFwd, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchWindowHeatRightFwd, 3) -- ON position
  end
end)

gSwitchWindowHeatRightFwd = AddVerticalSwitch(gImgVertSwitch, 294, 156, true, false, true, cbSwitchWindowHeatRightFwd)

---------------------- Window Heat Right Side Switch ----------------

local gSwitchWindowHeatRightSide

function cbSwitchWindowHeatRightSide(switch, dir)
  if dir > 0 then
---------------------- Window Heat Right Side Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchWindowHeatRightSide
-- function cbSwitchWindowHeatRightSide(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 13901)
--   else
--     msfs_event("ROTOR_BRAKE", 13902)
--   end
-- end
-- msfs_variable_subscribe("L:switch_139_73X", "number", function(v)
--   SetSwitchPosition(gSwitchWindowHeatRightSide, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchWindowHeatRightSide

function cbSwitchWindowHeatRightSide(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Window_Heat_4_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Window_Heat_4_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Window_Heat_4_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchWindowHeatRightSide, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchWindowHeatRightSide, 3) -- ON position
  end
end)

gSwitchWindowHeatRightSide = AddVerticalSwitch(gImgVertSwitch, 362, 156, true, false, true, cbSwitchWindowHeatRightSide)

---------------------- Probe Heat A Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchProbeHeatA
-- function cbSwitchProbeHeatA(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 14001)
--   else
--     msfs_event("ROTOR_BRAKE", 14002)
--   end
-- end
-- msfs_variable_subscribe("L:switch_140_73X", "number", function(v)
--   SetSwitchPosition(gSwitchProbeHeatA, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchProbeHeatA

function cbSwitchProbeHeatA(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Probe_Heat_1_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Probe_Heat_1_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Probe_Heat_1_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchProbeHeatA, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchProbeHeatA, 3) -- ON position
  end
end)

gSwitchProbeHeatA = AddVerticalSwitch(gImgVertSwitch, 192, 300, true, false, true, cbSwitchProbeHeatA)

---------------------- Probe Heat B Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gSwitchProbeHeatB
-- function cbSwitchProbeHeatB(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 14101)
--   else
--     msfs_event("ROTOR_BRAKE", 14102)
--   end
-- end
-- msfs_variable_subscribe("L:switch_141_73X", "number", function(v)
--   SetSwitchPosition(gSwitchProbeHeatB, math.floor(v/50)+1)
-- end)

-- iFly Conversion:
local gSwitchProbeHeatB

function cbSwitchProbeHeatB(switch, dir)
  if dir > 0 then
    fs2020_variable_write("L:VC_Probe_Heat_2_SW_VAL", "number", 10)
  else
    fs2020_variable_write("L:VC_Probe_Heat_2_SW_VAL", "number", 0)
  end
end

fs2020_variable_subscribe("L:VC_Probe_Heat_2_SW_VAL", "number", function(v)
  if v == 0 then
    SetSwitchPosition(gSwitchProbeHeatB, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchProbeHeatB, 3) -- ON position
  end
end)

gSwitchProbeHeatB = AddVerticalSwitch(gImgVertSwitch, 259, 300, true, false, true, cbSwitchProbeHeatB)
--------------- 

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 460, function()
  _rect(0, 0, 400, 460)
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
  _move_to(150, 264)
  _line_to(255, 264)
  _stroke(gColorPrint, 2)
  
end

local gImgLines = canvas_add(0, 0, 400, 460, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintSmall = "font:roboto_bold.ttf; size:18"


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

  PrintText("L", 92, 135, style, 24, false)
  PrintText("WINDOW HEAT", 140, 135, style, 24, false)
  PrintText("R", 298, 135, style, 24, false)
  PrintText("SIDE", 44, 152, style, 24, false)
  PrintText("FWD", 114, 152, style, 24, false)
  PrintText("FWD", 247, 152, style, 24, false)
  PrintText("SIDE", 317, 152, style, 24, false)
  PrintText("PWR TEST", 160, 242, style, 24, false)
  PrintText("PROBE", 175, 263, style, 24, false)
  PrintText("HEAT", 177, 375, style, 24, false)
  PrintText("OVHT", 176, 163, style, 24, false)
  PrintText("+", 195, 398, style, 24, false)

  style = gFontPrintSmall..";color:"..gColorPrint

  
  PrintText("OFF", 87, 170, style, 18, false)
  PrintText("ON", 87, 208, style, 18, false)
  
  PrintText("OFF", 291, 170, style, 18, false)
  PrintText("ON", 291, 208, style, 18, false)
  
  PrintText("OFF", 188, 305, style, 18, false)
  PrintText("ON", 191, 353, style, 18, false)
  
end


local gImgTexts = canvas_add(0, 0, 400, 460, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 460)

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

    if not s.no_head then
      canvas_draw(s.img.head[1], DrawHeadUp)
      canvas_draw(s.img.head[2], DrawHeadMiddle)
      canvas_draw(s.img.head[3], DrawHeadDown)
    end
  end
end

for k = 1,gSwitchCount do
  local s = gSwitch[k]
  
  if not s.no_head then
    s.img.head = {}
    s.img.head[1] = canvas_add(s.x, s.y, s.w, s.h, DrawHeadUp)
    visible(s.img.head[1], false)
    
    s.img.head[2] = canvas_add(s.x, s.y, s.w, s.h, DrawHeadMiddle)
    visible(s.img.head[2], false)
    
    s.img.head[3] = canvas_add(s.x, s.y, s.w, s.h, DrawHeadDown)
    visible(s.img.head[3], false)
  end
end

----------------------------- show switches, needed only in case the sim is not running

for k = 1,gSwitchCount do
  SetSwitchPosition(k, 1)
end

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 460, function()
  _rect(0, 0, 400, 460)
  _fill("black")
end)
opacity(gBlackMask2, 0)

-- ============================ lib functions for lights =======================

local gLight = {}
local gLightCount = 0

function AddLight(lvar, img, x, y, text1, text2)
  gLightCount = gLightCount + 1
  gLight[gLightCount] = {}
  
  
  local w, h, color, font
  if string.find(img, "amber", 1, true) ~= nil then
    color = gColorAmber
  elseif string.find(img, "blue", 1, true) ~= nil then
    color = gColorBlue
  elseif string.find(img, "green", 1, true) ~= nil then
    color = gColorGreen
  else
    color = ";color:#FFFFFF"
  end
  font = gFontLight

  meta = resource_info(img)
  w = meta.WIDTH
  h = meta.HEIGHT

  img_add(img, x, y, w, h)
  
  if text2 == nil then -- one line only
    txt_add(text1, font..color..";halign:center", x+w/15, y+h/3, w*7/8, h) 
  else
    txt_add(text1, font..color..";halign:center", x+w/15, y+h/5, w*7/8, h) 
    txt_add(text2, font..color..";halign:center", x+w/15, y+h/2, w*7/8, h) 
  end
  
  gLight[gLightCount].img_shade = canvas_add(x+2, y+2, 81, 46, function ()
    _rect(0, 0, 81, 46)
    _fill("black")
  end)
  if lvar ~= nil then
    local n = gLightCount
    msfs_variable_subscribe(lvar, "number", function(v)
      if v == 0 then
        v = .1
      else
        v = var_cap(4*v, 0.6, 1)
      end
      opacity(gLight[n].img_shade, 1-v)
    end)
  end
  return gLightCount
end

-- ======================== add lights ======================
-- ORIGINAL PMDG CODE:
-- AddLight("L:switch_127_73X", "light-amber-1.png", 29, 13,  "OVERHEAT")
-- AddLight("L:switch_128_73X", "light-amber-2.png", 115, 13,  "OVERHEAT")
-- AddLight("L:switch_129_73X", "light-amber-4.png", 201, 13,  "OVERHEAT")
-- AddLight("L:switch_130_73X", "light-amber-3.png", 287, 13,  "OVERHEAT")
-- AddLight("L:switch_131_73X", "light-green-1.png", 29, 73,  "ON")
-- AddLight("L:switch_132_73X", "light-green-2.png", 115, 73,  "ON")
-- AddLight("L:switch_133_73X", "light-green-3.png", 201, 73,  "ON")
-- AddLight("L:switch_134_73X", "light-green-4.png", 287, 73,  "ON")
-- AddLight("L:switch_142_73X", "light-amber-2.png", 40, 249,  "CAPT", "PITOT")
-- AddLight("L:switch_143_73X", "light-amber-1.png", 40, 300,  "L ELEV", "PITOT")   
-- AddLight("L:switch_144_73X", "light-amber-4.png", 40, 351,  "L ALPHA", "VANE")
-- AddLight("L:switch_145_73X", "light-amber-3.png", 40, 402,  "TEMP", "PROBE")
-- AddLight("L:switch_146_73X", "light-amber-4.png", 276, 249,  "F/O", "PITOT")
-- AddLight("L:switch_147_73X", "light-amber-2.png", 276, 300,  "R ELEV", "PITOT")   
-- AddLight("L:switch_148_73X", "light-amber-3.png", 276, 351,  "R ALPHA", "VANE")
-- AddLight("L:switch_149_73X", "light-amber-1.png", 276, 402,  "AUX", "PITOT")

-- iFly Conversion:
-- Window Heat OVERHEAT lights
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_OVERHEAT_1_VAL", "light-amber-1.png", 29, 13,  "OVERHEAT")  -- Left Side
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_OVERHEAT_2_VAL", "light-amber-2.png", 115, 13,  "OVERHEAT") -- Left Fwd
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_OVERHEAT_3_VAL", "light-amber-4.png", 201, 13,  "OVERHEAT") -- Right Fwd
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_OVERHEAT_4_VAL", "light-amber-3.png", 287, 13,  "OVERHEAT") -- Right Side

-- Window Heat ON lights
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_HEAT_ON_1_VAL", "light-green-1.png", 29, 73,  "ON")  -- Left Side
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_HEAT_ON_2_VAL", "light-green-2.png", 115, 73,  "ON") -- Left Fwd
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_HEAT_ON_3_VAL", "light-green-3.png", 201, 73,  "ON") -- Right Fwd
AddLight("L:VC_ANTIICE_LIGHT_WINDOW_HEAT_ON_4_VAL", "light-green-4.png", 287, 73,  "ON") -- Right Side

-- Pitot Heat lights
AddLight("L:VC_ANTIICE_LIGHT_CAPT_PITOT_VAL", "light-amber-2.png", 40, 249,  "CAPT", "PITOT")
AddLight("L:VC_ANTIICE_LIGHT_L_ELEV_PITOT_VAL", "light-amber-1.png", 40, 300,  "L ELEV", "PITOT")   
AddLight("L:VC_ANTIICE_LIGHT_L_ALPHA_VANE_VAL", "light-amber-4.png", 40, 351,  "L ALPHA", "VANE")
AddLight("L:VC_ANTIICE_LIGHT_TEMP_PROBE_VAL", "light-amber-3.png", 40, 402,  "TEMP", "PROBE")

AddLight("L:VC_ANTIICE_LIGHT_FO_PITOT_VAL", "light-amber-4.png", 276, 249,  "F/O", "PITOT")
AddLight("L:VC_ANTIICE_LIGHT_R_ELEV_PITOT_VAL", "light-amber-2.png", 276, 300,  "R ELEV", "PITOT")   
AddLight("L:VC_ANTIICE_LIGHT_R_ALPHA_VANE_VAL", "light-amber-3.png", 276, 351,  "R ALPHA", "VANE")
AddLight("L:VC_ANTIICE_LIGHT_AUX_PITOT_VAL", "light-amber-1.png", 276, 402,  "AUX", "PITOT")


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
