-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Hydraulics switches
-- FS2020


-- Dec 2 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 14 2022: Initial version
-- Dec 2 2022: Illumination updated



img_add_fullscreen("bg.png")


--------------- 

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 240, function()
  _rect(0, 0, 400, 240)
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
  _move_to(204, 135)
  _line_to(204, 204)
  _stroke(gColorPrint, 2)
  
end

local gImgLines = canvas_add(0, 0, 400, 240, DrawAllLines)

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

function DrawAllTexts()
  local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"

  PrintText("ENG  1", 37, 129, style, 24)
  PrintText("ELEC 2", 124, 129, style, 24)

  PrintText("ELEC 1", 219, 129, style, 24)
  PrintText("ENG 2", 310, 129, style, 24)

  PrintText("A", 102, 210, style, 24)
  PrintText("B", 287, 210, style, 24)

  PrintText("HYD PUMPS", 146, 210, style, 24)

  
  style = gFontPrintSmall..";color:"..gColorPrint

  PrintText("OFF", 94, 155, style, 18)
  PrintText("ON", 99, 188, style, 18)

  PrintText("OFF", 277, 155, style, 18)
  PrintText("ON", 283, 188, style, 18)
  
  PrintText("+", 189, 157, style, 18, false)
end


local gImgTexts = canvas_add(0, 0, 400, 240, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 240)

-- =============================== switch lib functions ====================
local gSwitchColorHi = "#f0f0f0ff"
local gSwitchColorLo = "#b8b8b8ff"

local gImgVertSwitch = {"switch-up-pin.png", "switch-middle-pin.png", "switch-down-pin.png"}

local gSwitch = {}
local gSwitchCount = 0


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

---------------------- Hydraulics A Pump Switch Eng 1 ----------------

local gSwitchHydAPumpEng1

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchHydAPumpEng1(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 16501)
--   else
--     msfs_event("ROTOR_BRAKE", 16502)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentHydAPumpEng1Position = 10 -- Default to ON (10)
function cbSwitchHydAPumpEng1(switch, dir)
  if dir > 0 then
    currentHydAPumpEng1Position = math.min(currentHydAPumpEng1Position + 10, 10) -- Only OFF and ON positions
  else
    currentHydAPumpEng1Position = math.max(currentHydAPumpEng1Position - 10, 0)
  end
  msfs_variable_write("L:VC_ENG_1_HYD_SW_VAL", "number", currentHydAPumpEng1Position)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_165_73X", "number", function(v)
--   SetSwitchPosition(gSwitchHydAPumpEng1, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_ENG_1_HYD_SW_VAL", "number", function(v)
  currentHydAPumpEng1Position = v
  SetSwitchPosition(gSwitchHydAPumpEng1, math.floor(v/10)+1)
end)

gSwitchHydAPumpEng1 = AddVerticalSwitch(gImgVertSwitch, 89, 135, true, false, true, cbSwitchHydAPumpEng1)

---------------------- Hydraulics A Pump Switch Elec 2 ----------------

local gSwitchHydAPumpElec2

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchHydAPumpElec2(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 16701)
--   else
--     msfs_event("ROTOR_BRAKE", 16702)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentHydAPumpElec2Position = 0 -- Default to OFF (0)
function cbSwitchHydAPumpElec2(switch, dir)
  if dir > 0 then
    currentHydAPumpElec2Position = math.min(currentHydAPumpElec2Position + 10, 10) -- Only OFF and ON positions
  else
    currentHydAPumpElec2Position = math.max(currentHydAPumpElec2Position - 10, 0)
  end
  msfs_variable_write("L:VC_ELEC_2_HYD_SW_VAL", "number", currentHydAPumpElec2Position)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_167_73X", "number", function(v)
--   SetSwitchPosition(gSwitchHydAPumpElec2, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_ELEC_2_HYD_SW_VAL", "number", function(v)
  currentHydAPumpElec2Position = v
  SetSwitchPosition(gSwitchHydAPumpElec2, math.floor(v/10)+1)
end)

gSwitchHydAPumpElec2 = AddVerticalSwitch(gImgVertSwitch, 180, 135, true, false, true, cbSwitchHydAPumpElec2)

---------------------- Hydraulics B Pump Switch Elec 1 ----------------

local gSwitchHydBPumpElec1

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchHydBPumpElec1(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 16801)
--   else
--     msfs_event("ROTOR_BRAKE", 16802)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentHydBPumpElec1Position = 0 -- Default to OFF (0)
function cbSwitchHydBPumpElec1(switch, dir)
  if dir > 0 then
    currentHydBPumpElec1Position = math.min(currentHydBPumpElec1Position + 10, 10) -- Only OFF and ON positions
  else
    currentHydBPumpElec1Position = math.max(currentHydBPumpElec1Position - 10, 0)
  end
  msfs_variable_write("L:VC_ELEC_1_HYD_SW_VAL", "number", currentHydBPumpElec1Position)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_168_73X", "number", function(v)
--   SetSwitchPosition(gSwitchHydBPumpElec1, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_ELEC_1_HYD_SW_VAL", "number", function(v)
  currentHydBPumpElec1Position = v
  SetSwitchPosition(gSwitchHydBPumpElec1, math.floor(v/10)+1)
end)

gSwitchHydBPumpElec1 = AddVerticalSwitch(gImgVertSwitch, 272, 135, true, false, true, cbSwitchHydBPumpElec1)

---------------------- Hydraulics B Pump Switch Eng 2 ----------------

local gSwitchHydBPumpEng2

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchHydBPumpEng2(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 16601)
--   else
--     msfs_event("ROTOR_BRAKE", 16602)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentHydBPumpEng2Position = 10 -- Default to ON (10)
function cbSwitchHydBPumpEng2(switch, dir)
  if dir > 0 then
    currentHydBPumpEng2Position = math.min(currentHydBPumpEng2Position + 10, 10) -- Only OFF and ON positions
  else
    currentHydBPumpEng2Position = math.max(currentHydBPumpEng2Position - 10, 0)
  end
  msfs_variable_write("L:VC_ENG_2_HYD_SW_VAL", "number", currentHydBPumpEng2Position)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_166_73X", "number", function(v)
--   SetSwitchPosition(gSwitchHydBPumpEng2, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_ENG_2_HYD_SW_VAL", "number", function(v)
  currentHydBPumpEng2Position = v
  SetSwitchPosition(gSwitchHydBPumpEng2, math.floor(v/10)+1)
end)

gSwitchHydBPumpEng2 = AddVerticalSwitch(gImgVertSwitch, 362, 135, true, false, true, cbSwitchHydBPumpEng2)

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

local gBlackMask2 = canvas_add(0, 0, 400, 240, function()
  _rect(0, 0, 400, 240)
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
    -- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
    -- msfs_variable_subscribe(lvar, "number", function(v)
    --   if v == 0 then
    --     v = .1
    --   else
    --     v = var_cap(4*v, 0.6, 1)
    --   end
    --   opacity(gLight[n].img_shade, 1-v)
    -- end)
    
    -- ================ CONVERTED iFLY CODE ================
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

-- ================ ORIGINAL PMDG ADDLIGHT CALLS (COMMENTED OUT) ================
-- AddLight("L:switch_159_73X", "light-amber-1.png", 102, 7,  "OVERHEAT")
-- AddLight("L:switch_160_73X", "light-amber-2.png", 204, 7,  "OVERHEAT")
-- 
-- AddLight("L:switch_161_73X", "light-amber-3.png", 21, 71,  "LOW", "PRESSURE")
-- AddLight("L:switch_163_73X", "light-amber-4.png", 107, 71,  "LOW", "PRESSURE")
-- AddLight("L:switch_164_73X", "light-amber-2.png", 209, 71,  "LOW", "PRESSURE")
-- AddLight("L:switch_162_73X", "light-amber-1.png", 295, 71,  "LOW", "PRESSURE")

-- ================ CONVERTED iFLY ADDLIGHT CALLS ================
AddLight("L:VC_HYDRAULIC_LIGHT_ELEC_1_OVERHEAT_LIGHT_VAL", "light-amber-1.png", 102, 7,  "OVERHEAT")
AddLight("L:VC_HYDRAULIC_LIGHT_ELEC_2_OVERHEAT_LIGHT_VAL", "light-amber-2.png", 204, 7,  "OVERHEAT")

AddLight("L:VC_HYDRAULIC_LIGHT_ENG_1_LOW_PRESSURE_LIGHT_VAL", "light-amber-3.png", 21, 71,  "LOW", "PRESSURE")
AddLight("L:VC_HYDRAULIC_LIGHT_ELEC_1_LOW_PRESSURE_LIGHT_VAL", "light-amber-4.png", 107, 71,  "LOW", "PRESSURE")
AddLight("L:VC_HYDRAULIC_LIGHT_ELEC_2_LOW_PRESSURE_LIGHT_VAL", "light-amber-2.png", 209, 71,  "LOW", "PRESSURE")
AddLight("L:VC_HYDRAULIC_LIGHT_ENG_2_LOW_PRESSURE_LIGHT_VAL", "light-amber-1.png", 295, 71,  "LOW", "PRESSURE")

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
