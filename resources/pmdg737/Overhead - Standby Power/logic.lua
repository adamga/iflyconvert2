-- Detlef von Reusner
-- PMDG B737-700 Overhead Panel - Standby Power
-- FS2020

-- Dec 2 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 9 2022: Initial version
-- Dec 2 2022: Illumination updated



img_add_fullscreen("bg.png")


local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 280, function()
  _rect(0, 0, 400, 280)
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


-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintSmall = "font:roboto_bold.ttf; size:20"


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
  PrintText("STANDBY POWER",  130, 107,  style, 24, false)
  PrintText("+",  140, 235,  style, 24, false)


  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("BATT", 142, 198, style, 20, false)
  PrintText("OFF", 190, 198, style, 20, false)
  PrintText("AUTO", 229, 198, style, 20, false)
  PrintText("DISCONNECT", 35, 149, style, 20, false)
  PrintText("DISCONNECT", 273, 149, style, 20, false)
end


local gImgTexts = canvas_add(0, 0, 400, 280, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 280)

-- =============================== switch lib functions ====================

local gSwitch = {}
local gSwitchCount = 0


function ShowTouchField(x, y, w, h)
  if not gDebugShowTouchFields then return end
  canvas_add(x, y, w, h, function()
    _rect(0, 0, w, h)
    _fill("#FF000020")
  end)
end

function AddHorGuardSwitch(x, y, p1, p2, p3, cb_switch, cb_guard)
  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local x_touch, y_touch, w_touch, h_touch
  local img, meta, w, h, dx, dy -- dx, dy offset for switch
  dx = 34
  dy = 20
  
  img = "black-hor-guard-open.png"
  meta = resource_info(img)
  if meta == nil then print(img.." not found"); return 0 end
  w = meta.WIDTH
  h = meta.HEIGHT
  s.img_open = img_add(img, x, y, w, h)
  visible(s.img_open, false)

  x_touch = x
  y_touch = y
  w_touch = w/4-1
  h_touch = h

  do -- create buttons for guard open/close and switch increment/decrement
    local n = gSwitchCount
    button_add(gTouchField, nil, x_touch, y_touch, w_touch, h_touch, function() cb_guard(n, -1) end, nil)
    button_add(gTouchField, nil, x+3*(w_touch+1), y_touch, w_touch, h_touch, function() cb_guard(n, 1) end, nil)
    button_add(gTouchField, nil, x_touch+w_touch+1, y_touch, w_touch, h_touch, function() cb_switch(n, -1) end, nil)
    button_add(gTouchField, nil, x_touch+2*(w_touch+1), y_touch, w_touch, h_touch, function() cb_switch(n, 1) end, nil)
  end
  
  s.img = {} -- stores the images for all switch positions
  do
    local w, h
    img = "small-hor-switch-left.png"
    meta = resource_info(img)
    if meta == nil then print(img.." not found"); return 0 end
    w = meta.WIDTH
    h = meta.HEIGHT
    if p1 then
      img = "small-hor-switch-left.png"
      s.img[1] = img_add(img, x+dx, y+dy, w, h)
      visible(s.img[1], false)
    end
    if p2 then
      img = "small-hor-switch-middle.png"
      s.img[2] = img_add(img, x+dx, y+dy, w, h)
      visible(s.img[2], false)
    end
    if p3 then
      img = "small-hor-switch-right.png"
      s.img[3] = img_add(img, x+dx, y+dy, w, h)
      visible(s.img[3], false)
    end
  end

  img = "black-hor-guard-closed.png"
  s.img_closed = img_add(img, x, y, w, h)
  visible(s.img_closed, true)
  
  s.closed = true
  s.pos = nil
  return gSwitchCount
end

function AddRedVerGuardSwitch(x, y, p1, p2, p3, cb_switch, cb_guard)
  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local x_touch, y_touch, w_touch, h_touch
  local img, meta, w, h, dx, dy -- dx, dy offset for switch
  dx = 20
  dy = 38
  
  img = "vert-red-guard-open.png"
  meta = resource_info(img)
  if meta == nil then print(img.." not found"); return 0 end
  w = meta.WIDTH
  h = meta.HEIGHT
  s.img_open = img_add(img, x, y, w, h)
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

  img = "vert-red-guard-closed.png"
  s.img_closed = img_add(img, x, y, w, h)
  visible(s.img_closed, true)
  
  s.closed = true
  s.pos = nil
  return gSwitchCount
end

function SetSwitchPosition(switch, target)
  local s = gSwitch[switch]
  if target == nil then return end
  visible(s.img[target], true)
  if s.pos ~= nil then visible(s.img[s.pos], false) end
  s.pos = target
end

function CloseGuard(switch, yes)
  local s = gSwitch[switch]
  visible(s.img_closed, yes)
  visible(s.img_open, not yes)
  s.closed = yes
end
-- ====================== operate switches ==================

------------------ Generator left disconnect switch with guard cover ---------------------------
-- ORIGINAL PMDG CODE:
-- local gSwitchDisconnect1
-- function cbSwitchDisconnect1(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 1301) -- open cover with any button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 1201)
-- end
-- msfs_variable_subscribe("L:switch_12_73X", "number", function(v)
--   if v==0 then
--     SetSwitchPosition(gSwitchDisconnect1, 1)
--   else
--     SetSwitchPosition(gSwitchDisconnect1, 2)
--   end
-- end)
-- function cbGuardDisconnect1(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 1201) -- incr switch with cover open button
--     return
--   end
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 1301)
--   else
--     msfs_event("ROTOR_BRAKE", 1302)
--   end
-- end

-- iFly Conversion:
local gSwitchDisconnect1

function cbSwitchDisconnect1(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    fs2020_variable_write("L:VC_IDG_1_Disc_SW_Cover_VAL", "number", 10) -- open cover with any button
    return
  end
  fs2020_variable_write("L:VC_IDG_1_Disc_SW_VAL", "number", 10)
end

fs2020_variable_subscribe("L:VC_IDG_1_Disc_SW_VAL", "number", function(v)
  if v==0 then
    SetSwitchPosition(gSwitchDisconnect1, 1) -- NORM position
  else
    SetSwitchPosition(gSwitchDisconnect1, 2) -- DISC position
  end
end)

function cbGuardDisconnect1(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    fs2020_variable_write("L:VC_IDG_1_Disc_SW_VAL", "number", 10) -- incr switch with cover open button
    return
  end
  if dir>0 then
    fs2020_variable_write("L:VC_IDG_1_Disc_SW_Cover_VAL", "number", 10) -- open cover
  else
    fs2020_variable_write("L:VC_IDG_1_Disc_SW_Cover_VAL", "number", 0) -- close cover
  end
end

gSwitchDisconnect1 = AddRedVerGuardSwitch(57, 150, true, true, false, cbSwitchDisconnect1, cbGuardDisconnect1)

fs2020_variable_subscribe("L:VC_IDG_1_Disc_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchDisconnect1, v==0)
end)

------------------ Generator Right disconnect switch with guard cover ---------------------------
-- ORIGINAL PMDG CODE:
-- local gSwitchDisconnect2
-- function cbSwitchDisconnect2(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 1501) -- open cover with any button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 1401)
-- end
-- msfs_variable_subscribe("L:switch_14_73X", "number", function(v)
--   if v==0 then
--     SetSwitchPosition(gSwitchDisconnect2, 1)
--   else
--     SetSwitchPosition(gSwitchDisconnect2, 2)
--   end
-- end)
-- function cbGuardDisconnect2(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 1401) -- incr switch with cover open button
--     return
--   end
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 1501)
--   else
--     msfs_event("ROTOR_BRAKE", 1502)
--   end
-- end

-- iFly Conversion:
local gSwitchDisconnect2

function cbSwitchDisconnect2(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    fs2020_variable_write("L:VC_IDG_2_Disc_SW_Cover_VAL", "number", 10) -- open cover with any button
    return
  end
  fs2020_variable_write("L:VC_IDG_2_Disc_SW_VAL", "number", 10)
end

fs2020_variable_subscribe("L:VC_IDG_2_Disc_SW_VAL", "number", function(v)
  if v==0 then
    SetSwitchPosition(gSwitchDisconnect2, 1) -- NORM position
  else
    SetSwitchPosition(gSwitchDisconnect2, 2) -- DISC position
  end
end)

function cbGuardDisconnect2(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    fs2020_variable_write("L:VC_IDG_2_Disc_SW_VAL", "number", 10) -- incr switch with cover open button
    return
  end
  if dir>0 then
    fs2020_variable_write("L:VC_IDG_2_Disc_SW_Cover_VAL", "number", 10) -- open cover
  else
    fs2020_variable_write("L:VC_IDG_2_Disc_SW_Cover_VAL", "number", 0) -- close cover
  end
end

gSwitchDisconnect2 = AddRedVerGuardSwitch(291, 150, true, true, false, cbSwitchDisconnect2, cbGuardDisconnect2)

fs2020_variable_subscribe("L:VC_IDG_2_Disc_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchDisconnect2, v==0)
end)

------------------ Standby Power Switch with Guard ---------------------------
-- ORIGINAL PMDG CODE:
-- local gSwitchStandbyPower
-- function cbSwitchStandbyPower(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 1101) -- open cover with any button
--     return
--   end
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 1002)
--   else
--     msfs_event("ROTOR_BRAKE", 1001)
--   end
-- end
-- msfs_variable_subscribe("L:switch_10_73X", "number", function(v)
--   if v==0 then
--     SetSwitchPosition(gSwitchStandbyPower, 1)
--   elseif v==50 then
--     SetSwitchPosition(gSwitchStandbyPower, 2)
--   else
--     SetSwitchPosition(gSwitchStandbyPower, 3)
--   end
-- end)
-- function cbGuardStandbyPower(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 1002) -- decr switch with cover open button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 1101)
-- end

-- iFly Conversion:
local gSwitchStandbyPower

function cbSwitchStandbyPower(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    fs2020_variable_write("L:VC_STANDBY_POWER_SW_Cover_VAL", "number", 10) -- open cover with any button
    return
  end
  if dir>0 then
    fs2020_variable_write("L:VC_STANDBY_POWER_SW_VAL", "number", 30) -- AUTO
  else
    fs2020_variable_write("L:VC_STANDBY_POWER_SW_VAL", "number", 10) -- BATT
  end
end

fs2020_variable_subscribe("L:VC_STANDBY_POWER_SW_VAL", "number", function(v)
  if v==10 then
    SetSwitchPosition(gSwitchStandbyPower, 1) -- BATT position
  elseif v==20 then
    SetSwitchPosition(gSwitchStandbyPower, 2) -- OFF position (center)
  else
    SetSwitchPosition(gSwitchStandbyPower, 3) -- AUTO position
  end
end)

function cbGuardStandbyPower(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    fs2020_variable_write("L:VC_STANDBY_POWER_SW_VAL", "number", 30) -- set to AUTO with cover open button
    return
  end
  fs2020_variable_write("L:VC_STANDBY_POWER_SW_Cover_VAL", "number", 10) -- toggle cover
end

gSwitchStandbyPower = AddHorGuardSwitch(145, 138, true, true, true, cbSwitchStandbyPower, cbGuardStandbyPower)

fs2020_variable_subscribe("L:VC_STANDBY_POWER_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchStandbyPower, v==0)
end)

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 280, function()
  _rect(0, 0, 400, 280)
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
-- AddLight("L:switch_07_73X", "light-amber-1.png", 49, 43, "DRIVE")
-- AddLight("L:switch_09_73X", "light-amber-2.png", 266, 43, "DRIVE")
-- AddLight("L:switch_08_73X", "light-amber-2.png", 157, 14, "STANDBY", "POWER OFF")

-- iFly Conversion:
AddLight("L:VC_ELECTRICAL_LIGHT_DRIVE_1_VAL", "light-amber-1.png", 49, 43, "DRIVE")
AddLight("L:VC_ELECTRICAL_LIGHT_DRIVE_2_VAL", "light-amber-2.png", 266, 43, "DRIVE")
AddLight("L:VC_ELECTRICAL_LIGHT_STANDBY_PWR_OFF_VAL", "light-amber-2.png", 157, 14, "STANDBY", "POWER OFF")

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
  canvas_draw(gImgTexts, DrawAllTexts)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)

