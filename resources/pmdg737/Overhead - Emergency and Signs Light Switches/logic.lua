-- Detlef von Reusner
-- PMDG B737-700 Overhead Panel - Emergency and Signs Light Switches
-- FS2020

-- Dec 1 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua

-- History:

-- Oct 17 2022: Intital version.
-- Dec 1 2022: Illumination updated



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
  x = x-15
  y = y
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

function AddBlackVerGuardSwitch(x, y, p1, p2, p3, cb_switch, cb_guard)

  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local x_touch, y_touch, w_touch, h_touch
  local img, meta, w, h, dx, dy -- dx, dy offset for switch
  dx = 20
  dy = 38
  
  img = "vert-black-cover-open.png"
  meta = resource_info(img)
  if meta == nil then print(img.." not found"); return 0 end
  w = meta.WIDTH
  h = meta.HEIGHT
  s.img_open = img_add(img, x, y, w, h)
  s.no_head = true -- needed to not interfere with new switch illumination
  visible(s.img_open, false)

  x_touch = x
  y_touch = y
  w_touch = w
  h_touch = h/4-1

  do -- create buttons for guard open/close and switch increment/decrement
    local n = gSwitchCount
    button_add(gTouchField, nil, x_touch, y_touch, w_touch, h_touch, function() cb_guard(n, -1) end, nil)
    button_add(gTouchField, nil, x_touch, y+3*(h_touch+1), w_touch, h_touch, function() cb_guard(n, 1) end, nil)
    button_add(gTouchField, nil, x_touch, y+h_touch+1, w_touch, h_touch, function() cb_switch(n, -1) end, nil)
    button_add(gTouchField, nil, x_touch, y+2*(h_touch+1), w_touch, h_touch, function() cb_switch(n, 1) end, nil)
  end
  
  s.img = {} -- stores the images for all switch positions
  do
    local w, h
    img = "small-vert-switch-up.png"
    meta = resource_info(img)
    if meta == nil then print(img.." not found"); return 0 end
    w = meta.WIDTH
    h = meta.HEIGHT
    if p1 then
      img = "small-vert-switch-up.png"
      s.img[1] = img_add(img, x+dx, y+dy, w, h)
      visible(s.img[1], false)
    end
    if p2 then
      img = "small-vert-switch-middle.png"
      s.img[2] = img_add(img, x+dx, y+dy, w, h)
      visible(s.img[2], false)
    end
    if p3 then
      img = "small-vert-switch-down.png"
      s.img[3] = img_add(img, x+dx, y+dy, w, h)
      visible(s.img[3], false)
    end
  end

  img = "vert-black-cover-closed.png"
  s.img_closed = img_add(img, x, y, w, h)
  visible(s.img_closed, true)
  
  s.closed = true
  s.pos = nil
  return gSwitchCount
end

function SetSwitchPosition(switch, target)
  -- log("switch / target "..switch.."/"..target)
  local s = gSwitch[switch]
  if target == nil then return end

  if s.img.pin == nil then -- old format, no pin/head separation
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

function CloseGuard(switch, yes)
  local s = gSwitch[switch]
  visible(s.img_closed, yes)
  visible(s.img_open, not yes)
  s.closed = yes
end

-- ====================== operate switches ==================

------------------ EMERGENCY EXIT LIGHTS Switch ---------------------------
local gSwitchEmergencyExit
local cbSwitchEmergencyExitVAL = 1  -- Default to OFF

-- Switch interaction callback
function cbSwitchEmergencyExit(switch, dir)
    local s = gSwitch[switch]
    if s.closed then
        -- Open the guard cover
        msfs_variable_write("L:VC_Emergency_Exit_Light_Cover_SW_VAL", "number", 1)
        return
    end

    cbSwitchEmergencyExitVAL = cbSwitchEmergencyExitVAL + dir
    if cbSwitchEmergencyExitVAL < 1 then cbSwitchEmergencyExitVAL = 1 end
    if cbSwitchEmergencyExitVAL > 3 then cbSwitchEmergencyExitVAL = 3 end

    local simValue = (cbSwitchEmergencyExitVAL - 1) * 10
    msfs_variable_write("L:VC_Emergency_Exit_Light_SW_VAL", "number", simValue)
end

-- Guard interaction callback
function cbGuardEmergencyExit(switch, dir)
    local s = gSwitch[switch]
    if not s.closed and dir > 0 then
        -- Increment switch if guard is open
        cbSwitchEmergencyExitVAL = cbSwitchEmergencyExitVAL + 1
        if cbSwitchEmergencyExitVAL > 3 then cbSwitchEmergencyExitVAL = 3 end
        local simValue = (cbSwitchEmergencyExitVAL - 1) * 10
        msfs_variable_write("L:VC_Emergency_Exit_Light_SW_VAL", "number", simValue)
        return
    end

    -- Toggle guard cover
    local coverState = dir > 1 and 1 or 0
    msfs_variable_write("L:VC_Emergency_Exit_Light_Cover_SW_VAL", "number", coverState)
end
-- Subscribe to switch position
msfs_variable_subscribe("L:VC_Emergency_Exit_Light_SW_VAL", "number", function(v)
    cbSwitchEmergencyExitVAL = math.floor(v / 10) + 1
    if cbSwitchEmergencyExitVAL < 1 then cbSwitchEmergencyExitVAL = 1 end
    if cbSwitchEmergencyExitVAL > 3 then cbSwitchEmergencyExitVAL = 3 end
    SetSwitchPosition(gSwitchEmergencyExit, cbSwitchEmergencyExitVAL)
end)

-- Subscribe to guard cover state
msfs_variable_subscribe("L:VC_Emergency_Exit_Light_Cover_SW_VAL", "number", function(v)
    CloseGuard(gSwitchEmergencyExit, v == 0)
end)

-- Create the guarded switch
gSwitchEmergencyExit = AddBlackVerGuardSwitch(80, 54, true, true, true, cbSwitchEmergencyExit, cbGuardEmergencyExit)


---------------------- Chime only switch ----------------

local gSwitchChimeOnly
local cbSwitchChimeOnlyVAL = 1  -- Default to OFF

-- Callback for switch interaction
function cbSwitchChimeOnly(switch, dir)
    cbSwitchChimeOnlyVAL = cbSwitchChimeOnlyVAL + dir

    if cbSwitchChimeOnlyVAL < 1 then cbSwitchChimeOnlyVAL = 1 end
    if cbSwitchChimeOnlyVAL > 3 then cbSwitchChimeOnlyVAL = 3 end

    -- Convert 1,2,3 to 0,10,20
    local simValue = (cbSwitchChimeOnlyVAL - 1) * 10
    msfs_variable_write("L:VC_No_Smoking_SW_VAL", "number", simValue)
end

-- Subscribe to simulator variable and update switch position
msfs_variable_subscribe("L:VC_No_Smoking_SW_VAL", "number", function(v)
    cbSwitchChimeOnlyVAL = math.floor(v / 10) + 1

    -- Clamp to valid range
    if cbSwitchChimeOnlyVAL < 1 then cbSwitchChimeOnlyVAL = 1 end
    if cbSwitchChimeOnlyVAL > 3 then cbSwitchChimeOnlyVAL = 3 end
    SetSwitchPosition(gSwitchChimeOnly, cbSwitchChimeOnlyVAL)
end)

-- Create the switch
gSwitchChimeOnly = AddVerticalSwitch(gImgVertSwitch, 19, 217, true, true, true, cbSwitchChimeOnly)


---------------------- Fasten belts switch ----------------

local gSwitchFastenBelts
local cbSwitchFastenBeltsVAL = 1  -- Default to OFF

-- Callback for switch interaction
function cbSwitchFastenBelts(switch, dir)
    cbSwitchFastenBeltsVAL = cbSwitchFastenBeltsVAL + dir

    if cbSwitchFastenBeltsVAL < 1 then cbSwitchFastenBeltsVAL = 1 end
    if cbSwitchFastenBeltsVAL > 3 then cbSwitchFastenBeltsVAL = 3 end

    -- Convert 1,2,3 to 0,10,20
    local simValue = (cbSwitchFastenBeltsVAL - 1) * 10
    msfs_variable_write("L:VC_Fasten_Belts_SW_VAL", "number", simValue)
end

-- Subscribe to simulator variable and update switch position
msfs_variable_subscribe("L:VC_Fasten_Belts_SW_VAL", "number", function(v)
    cbSwitchFastenBeltsVAL = math.floor(v / 10) + 1

    -- Clamp to valid range
    if cbSwitchFastenBeltsVAL < 1 then cbSwitchFastenBeltsVAL = 1 end
    if cbSwitchFastenBeltsVAL > 3 then cbSwitchFastenBeltsVAL = 3 end

    SetSwitchPosition(gSwitchFastenBelts, cbSwitchFastenBeltsVAL)
end)

-- Create the switch
gSwitchFastenBelts = AddVerticalSwitch(gImgVertSwitch, 113, 217, true, true, true, cbSwitchFastenBelts)




-- local gSwitchFastenBelts

-- function cbSwitchFastenBelts(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 10401)
--   else
--     msfs_event("ROTOR_BRAKE", 10402)
--   end
-- end

-- msfs_variable_subscribe("L:switch_104_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFastenBelts, math.floor(v / 50) + 1)
-- end)

-- gSwitchFastenBelts = AddVerticalSwitch(gImgVertSwitch, 113, 217, true, true, true, cbSwitchFastenBelts)

-- =================================

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 200, 340, function()
  _rect(0, 0, 200, 340)
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
   gTouchField = "touch-field-off.png"
end

-- =====================================================

function toint(n)
  -- needed because math.floor() returns floats
    local s = tostring(n)
    local i, j = s:find('%.')
    if i then
        return tonumber(s:sub(1, i-1))
    else
        return n
    end
end

-- =================== Draw lines ==================


function DrawAllLines()
  _move_to(6, 190)
  _line_to(190, 190)
  
  _stroke(gColorPrint, 3)

end

local gImgLines = canvas_add(0, 0, 200, 340, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintSmall = "font:roboto_bold.ttf; size:20"
local gFontPrintTiny = "font:roboto_bold.ttf; size:16"
local gFontPrintMicro = "font:roboto_bold.ttf; size:10"


function PrintText(text, x, y, style, size, black_bg)
  local count = string.len(text)
  if black_bg == nil then black_bg = true end
  if black_bg then
    _rect(x-3, y, count/2*size+7, size)
    _fill(gColorBg)
  end
  _txt(text, style, x, y-1)
end

function PrintVertText(text, x, y, style, size, black_bg)
  local count = string.len(text)
  local step = size*.7
  if black_bg == nil then black_bg = true end
  if black_bg then
    _rect(x, y, size, count*step+step/2)
    _fill(gColorBg)
  end
  for k=1,count do
    _txt(string.sub(text, k, k), style, x+5, y+(k-1)*step)
  end
end


function DrawAllTexts()
  local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  local size = 24
  PrintText("EMER EXIT LIGHTS",  22, 8,  style, size, false)
  PrintText("FASTEN",  118, 199,  style, size, false)
  PrintText("BELTS",  124, 218,  style, size, false)


  size = 20
  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("OFF",  143, 81,  style, size, false)
  PrintText("ARMED",  143, 109,  style, size, false)
  PrintText("ON",  143, 137,  style, size, false)
  
  PrintText("OFF",  85, 248,  style, size, false)
  PrintText("AUTO",  82, 270,  style, size, false)
  PrintText("ON",  89, 292,  style, size, false)

  size = 16
  style = gFontPrintTiny..";color:"..gColorPrint.."; halign:left"
  PrintText("CHIME", 32, 200, style, size, false)
  PrintText("ONLY", 35, 216, style, size, false)

  size = 10
  style = gFontPrintMicro..";color:"..gColorPrint.."; halign:left"
  PrintText("BAC27DCC3265", 44, 232, style, size, false)
end


local gImgTexts = canvas_add(0, 0, 200, 340, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 200, 340)


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

local gBlackMask2 = canvas_add(0, 0, 200, 340, function()
  _rect(0, 0, 200, 340)
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

function AddVerticalText(text, font, color, x, y, w, h)
  local z, font_height
  font_height = 13
  y = y+(h - string.len(text)*font_height)/2
  for k=1,40 do
    z = string.sub(text, k, k)
    if z=="" then return end
    txt_add(z, font..color..";halign:center", x, y+(k-1)*font_height, font_height, font_height) 
  end
end

function AddVertLight(lvar, img, x, y, text1, text2)
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
  
  -- if text2 == nil then -- one line only
    -- txt_add(text1, font..color..";halign:center", x+w/15, y+h/3, w*7/8, h) 
  -- else
    -- txt_add(text1, font..color..";halign:center", x+w/15, y+h/5, w*7/8, h) 
    -- txt_add(text2, font..color..";halign:center", x+w/15, y+h/2, w*7/8, h) 
  -- end
  
  if text2 == nil then -- one line only
    AddVerticalText(text1, font, color, x+w/5*2, y, w, h)
  else
    AddVerticalText(text1, font, color, x+w/5, y, w, h)
    AddVerticalText(text2, font, color, x+w/9*5, y, w, h)
  end
  
  gLight[gLightCount].img_shade = canvas_add(x+2, y+2, 46, 81, function ()
    _rect(0, 0, 46, 81)
    _fill("black")
  end)
  if lvar ~= nil then
    local n = gLightCount
    msfs_variable_subscribe(lvar, "number", function(v)
      if v == 0 then
        v = .2
      else
        v = var_cap(4*v, 0.6, 1)
      end
      opacity(gLight[n].img_shade, 1-v)
    end)
  end
  return gLightCount
end

-- ======================== add lights ======================

AddVertLight("L:switch_102_73X", "light-amber-vert.png", 16, 86,  "NOT", "ARMED")

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
