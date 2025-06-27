-- Detlef von Reusner
-- PMDG B737-700 Overhead panel generator switches (and ground power)
-- FS2020

-- Nov 28 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 3 2022: Initial version
-- Aug 9 2022: Illumination option: Real, needs Ambient Light Dimmer instrument for daylight. Scales light per overhead dome switch.
-- Sep 4 2022: Height extended to 405 pixels because of graphical mismatches
-- Oct 4 2022: Switch overlap with lights corrected. "Real" illumination as default.
-- Nov 28 2022: Illumination updated



img_add_fullscreen("bg-day.png")



local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 405, function()
  _rect(0, 0, 400, 405)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense

local gColorAmber = string.format(";color:#%02x%02x%02x", 243, 163, 90)
local gColorBlue = string.format(";color:#%02x%02x%02x", 250, 250, 250)
local gColorGreen = string.format(";color:#%02x%02x%02x", 98, 208, 103)

local gColorPrint = "#E0E0E0FF"
local gColorBg = "#101010FF"

local gSwitchColorHi = "#f0f0f0ff"
local gSwitchColorLo = "#b8b8b8ff"

local gImgVertSwitch = {"switch-up-pin.png", "switch-middle-pin.png", "switch-down-pin.png"}
local gSwitch = {}
local gSwitchCount = 0



local gFontLight = "font:arimo_bold.ttf; size:14"


local gDebugShowTouchFields = false

local gTouchField
if gDebugShowTouchFields then
   gTouchField = "touch-field-on.png"
else
   gTouchField = "touch-field-off.png"
end


-- =================== Draw lines ==================

function DrawPath(x, y, path)
  -- path = {x1, y1, x2, y2} and so on
  local count = #path/2
  local x0, x1, x2, y0, y1, y2, dx, dy
  x0 = x
  y0 = y
  -- background 
  _move_to(x, y)
  for k=0,count-1 do
    _line_to(path[2*k+1], path[2*k+2])
  end
  _stroke(gColorBg, 15)

  -- ----------------- outer line
  
  for k=0,count-1 do
    x1 = path[2*k+1] -- line target
    y1 = path[2*k+2]
    x2 = path[2*k+3] -- next line target
    y2 = path[2*k+4]
    if y1 == y then -- horizontal
      if x1 > x then
        dx = 4
      else
        dx = -4
      end
      if y2 == nil then
        -- no change
      elseif y2<y1 then -- next line up
        dy = 4
      else
        dy = -4
      end
      if k==0 then
        _move_to(x+dx, y+dy)
      end
      _line_to(x1+dx, y+dy)
    else -- vertical
      if y1>y then
        dy = 4
      else
        dy = -4
      end
      if x2 == nil then
        -- no change
      elseif x2>x1 then
        dx = -4
      else
        dy = 4
      end
      if k==0 then
        _move_to(x+dx, y+dy)
      end
      _line_to(x+dx, y1+dy)
    end
    x = x1
    y = y1
  end
  _stroke(gColorPrint, 2)
  
  -- ------------------- inner line
  x = x0
  y = y0
  for k=0,count-1 do
    x1 = path[2*k+1] -- line target
    y1 = path[2*k+2]
    x2 = path[2*k+3] -- next line target
    y2 = path[2*k+4]
    if y1 == y then -- horizontal
      if x1 > x then
        dx = -4
      else
        dx = 4
      end
      if y2 == nil then
        -- no change
      elseif y2<y1 then -- next line up
        dy = -4
      else
        dy = 4
      end
      if k==0 then
        _move_to(x+dx, y+dy)
      end
      _line_to(x1+dx, y+dy)
    else -- vertical
      if y1>y then
        dy = -4
      else
        dy = 4
      end
      if x2 == nil then
        -- no change
      elseif x2>x1 then
        dx = 4
      else
        dy = -4
      end
      if k==0 then
        _move_to(x+dx, y+dy)
      end
      _line_to(x+dx, y1+dy)
    end
    x = x1
    y = y1
  end
  _stroke(gColorPrint, 2)
end

function DrawAllLines()
  _move_to(40, 390)
  _line_to(156, 390)
  _stroke(gColorPrint, 2)

  _move_to(240, 390)
  _line_to(358, 390)
  _stroke(gColorPrint, 2)

  -- DrawPath(250, 343, {216, 343,   216, 238,   322, 238,   322, 343})  -- always clockwise!
  -- DrawPath(79, 343,  {79, 238,    185, 238,   185, 343,   150, 343})
  DrawPath(250, 356, {216, 356,   216, 238,   322, 238,   322, 356})  -- always clockwise!
  DrawPath(79, 356,  {79, 238,    185, 238,   185, 356,   150, 356})
end

local gImgLines = canvas_add(0, 0, 400, 405, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintMedium = "font:roboto_bold.ttf; size:22"
local gFontPrintSmall = "font:roboto_bold.ttf; size:18"


function PrintText(text, x, y, style, size)
  local count = string.len(text)
  _rect(x-3, y, count/2*size+7, size)
  _fill(gColorBg)
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
  PrintText("BUSTRANS",  154, 145,  style, 24)
  PrintText("GRD", 132, 96, style, 24)
  PrintText("PWR", 230, 96, style, 24)
  PrintText("GEN1", 56, 380, style, 24)
  PrintText("GEN2", 302, 380, style, 24)
  
  local style = gFontPrintMedium..";color:"..gColorPrint.."; halign:left"
  PrintText("APUGEN", 165, 367, style, 22)
  PrintText("APU", 186, 383, style, 22)

  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("OFF", 100, 326, style, 18)
  PrintText("ON", 105, 364, style, 18)
  PrintText("OFF", 275, 326, style, 18)
  PrintText("ON", 277, 364, style, 18)


  PrintText("OFF", 154, 76, style, 18)
  PrintText("ON", 158, 122, style, 18)
  
  PrintVertText("OFF", 135, 176, style, 18)
  PrintVertText("AUTO", 253, 169, style, 18)
end


local gImgTexts = canvas_add(0, 0, 400, 405, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 405)

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

-- ======================== add lights ======================

-- ================ ORIGINAL PMDG ADDLIGHT CALLS (COMMENTED OUT) ================
-- AddLight("L:switch_20_73X", "light-amber-1.png", 35, 151, "TRANSFER", "BUS OFF")
-- 
-- 
-- AddLight("L:switch_22_73X", "light-amber-2.png", 35, 203, "SOURCE", "OFF")
-- AddLight("L:switch_24_73X", "light-blue-1.png", 35, 255, "GEN OFF", "BUS")
-- 
-- AddLight("L:switch_21_73X", "light-amber-2.png", 279, 151, "TRANSFER", "BUS OFF")
-- AddLight("L:switch_23_73X", "light-amber-1.png", 279, 203, "SOURCE", "OFF")
-- AddLight("L:switch_26_73X", "light-blue-1.png", 279, 255, "GEN OFF", "BUS")
-- 
-- AddLight("L:switch_16_73X", "light-blue-1.png", 160, 8, "GRD POWER", "AVAILABLE")
-- AddLight("L:switch_25_73X", "light-blue-1.png", 160, 254, "APU GEN", "OFF BUS")

-- ================ CONVERTED iFLY ADDLIGHT CALLS ================
AddLight("L:VC_ELECTRICAL_LIGHT_TRANSFER_BUS_OFF_1_LIGHT_VAL", "light-amber-1.png", 35, 151, "TRANSFER", "BUS OFF")


AddLight("L:VC_ELECTRICAL_LIGHT_SOURCE_OFF_1_LIGHT_VAL", "light-amber-2.png", 35, 203, "SOURCE", "OFF")
AddLight("L:VC_ELECTRICAL_LIGHT_GEN_OFF_BUS_1_LIGHT_VAL", "light-blue-1.png", 35, 255, "GEN OFF", "BUS")

AddLight("L:VC_ELECTRICAL_LIGHT_TRANSFER_BUS_OFF_2_LIGHT_VAL", "light-amber-2.png", 279, 151, "TRANSFER", "BUS OFF")
AddLight("L:VC_ELECTRICAL_LIGHT_SOURCE_OFF_2_LIGHT_VAL", "light-amber-1.png", 279, 203, "SOURCE", "OFF")
AddLight("L:VC_ELECTRICAL_LIGHT_GEN_OFF_BUS_2_LIGHT_VAL", "light-blue-1.png", 279, 255, "GEN OFF", "BUS")

AddLight("L:VC_ELECTRICAL_LIGHT_GRD_POWER_AVAILABLE_VAL", "light-blue-1.png", 160, 8, "GRD POWER", "AVAILABLE")
AddLight("L:VC_ELECTRICAL_LIGHT_APU_GEN_OFF_BUS_LIGHT_VAL", "light-blue-1.png", 160, 254, "APU GEN", "OFF BUS")

-- =============================== switch lib functions ====================

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
  s.no_head = true
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

---------------------- Gen1 switch ----------------
local gSwitchGen1

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchGen1(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 2701)
--   else
--     msfs_event("ROTOR_BRAKE", 2702)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentGen1Position = 10 -- Default to middle position (10)
function cbSwitchGen1(switch, dir)
  if dir > 0 then
    currentGen1Position = math.min(currentGen1Position + 10, 20)
  else
    currentGen1Position = math.max(currentGen1Position - 10, 0)
  end
  msfs_variable_write("L:VC_ENG_1_Generator_SW_VAL", "number", currentGen1Position)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_27_73X", "number", function(v)
--   SetSwitchPosition(gSwitchGen1, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_ENG_1_Generator_SW_VAL", "number", function(v)
  currentGen1Position = v
  SetSwitchPosition(gSwitchGen1, math.floor(v/10)+1)
end)

gSwitchGen1 = AddVerticalSwitch(gImgVertSwitch, 105, 314, true, true, true, cbSwitchGen1)

----------------- APU left switch ----------------

local gSwitchApuLeft

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchApuLeft(switch, dir)
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 2801)
--   else
--     msfs_event("ROTOR_BRAKE", 2802)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentApuLeftPosition = 10 -- Default to middle position (10)
function cbSwitchApuLeft(switch, dir)
  if dir>0 then
    currentApuLeftPosition = math.min(currentApuLeftPosition + 10, 20)
  else
    currentApuLeftPosition = math.max(currentApuLeftPosition - 10, 0)
  end
  msfs_variable_write("L:VC_APU_Generator_1_SW_VAL", "number", currentApuLeftPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_28_73X", "number", function(v)
--   SetSwitchPosition(gSwitchApuLeft, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_APU_Generator_1_SW_VAL", "number", function(v)
  currentApuLeftPosition = v
  SetSwitchPosition(gSwitchApuLeft, math.floor(v/10)+1)
end)

gSwitchApuLeft = AddVerticalSwitch(gImgVertSwitch, 174, 314, true, true, true, cbSwitchApuLeft)

----------------- APU right switch ----------------

local gSwitchApuRight

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchApuRight(switch, dir)
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 2901)
--   else
--     msfs_event("ROTOR_BRAKE", 2902)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentApuRightPosition = 10 -- Default to middle position (10)
function cbSwitchApuRight(switch, dir)
  if dir>0 then
    currentApuRightPosition = math.min(currentApuRightPosition + 10, 20)
  else
    currentApuRightPosition = math.max(currentApuRightPosition - 10, 0)
  end
  msfs_variable_write("L:VC_APU_Generator_2_SW_VAL", "number", currentApuRightPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_29_73X", "number", function(v)
--   SetSwitchPosition(gSwitchApuRight, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_APU_Generator_2_SW_VAL", "number", function(v)
  currentApuRightPosition = v
  SetSwitchPosition(gSwitchApuRight, math.floor(v/10)+1)
end)

gSwitchApuRight = AddVerticalSwitch(gImgVertSwitch, 278, 314, true, true, true, cbSwitchApuRight)

---------------------- Gen2 switch ----------------

local gSwitchGen2

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchGen2(switch, dir)
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 3001)
--   else
--     msfs_event("ROTOR_BRAKE", 3002)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentGen2Position = 10 -- Default to middle position (10)
function cbSwitchGen2(switch, dir)
  if dir>0 then
    currentGen2Position = math.min(currentGen2Position + 10, 20)
  else
    currentGen2Position = math.max(currentGen2Position - 10, 0)
  end
  msfs_variable_write("L:VC_ENG_2_Generator_SW_VAL", "number", currentGen2Position)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_30_73X", "number", function(v)
--   SetSwitchPosition(gSwitchGen2, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_ENG_2_Generator_SW_VAL", "number", function(v)
  currentGen2Position = v
  SetSwitchPosition(gSwitchGen2, math.floor(v/10)+1)
end)

gSwitchGen2 = AddVerticalSwitch(gImgVertSwitch, 349, 314, true, true, true, cbSwitchGen2)

---------------------------- Ground power available switch -------------------

local gSwitchGroundPowerAvailable

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchGroundPowerAvailable(switch, dir)
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 1701)
--   else
--     msfs_event("ROTOR_BRAKE", 1702)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentGroundPowerPosition = 10 -- Default to middle position (10)
function cbSwitchGroundPowerAvailable(switch, dir)
  if dir>0 then
    currentGroundPowerPosition = math.min(currentGroundPowerPosition + 10, 20)
  else
    currentGroundPowerPosition = math.max(currentGroundPowerPosition - 10, 0)
  end
  msfs_variable_write("L:VC_Ground_Power_SW_VAL", "number", currentGroundPowerPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_17_73X", "number", function(v)
--   SetSwitchPosition(gSwitchGroundPowerAvailable, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Ground_Power_SW_VAL", "number", function(v)
  currentGroundPowerPosition = v
  SetSwitchPosition(gSwitchGroundPowerAvailable, math.floor(v/10)+1)
end)

gSwitchGroundPowerAvailable = AddVerticalSwitch(gImgVertSwitch, 226, 67, true, true, true, cbSwitchGroundPowerAvailable)

------------------ Bus trans switch with guard cover ---------------------------
local gSwitchBusTrans

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchBusTrans(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 1901) -- open cover with any button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 1801)
--   -- if dir>0 then
--     -- msfs_event("ROTOR_BRAKE", 1801)
--   -- else
--     -- msfs_event("ROTOR_BRAKE", 1802)
--   -- end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentBusTransPosition = 10 -- Default to AUTO (10)
function cbSwitchBusTrans(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    -- Open cover
    msfs_variable_write("L:VC_Bus_Transfer_SW_Cover_VAL", "number", 10)
    return
  end
  -- Toggle Bus Transfer switch (AUTO/MAN)
  if currentBusTransPosition == 10 then
    currentBusTransPosition = 0 -- MAN
  else
    currentBusTransPosition = 10 -- AUTO
  end
  msfs_variable_write("L:VC_Bus_Transfer_SW_VAL", "number", currentBusTransPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_18_73X", "number", function(v)
--   if v==0 then
--     SetSwitchPosition(gSwitchBusTrans, 1)
--   else
--     SetSwitchPosition(gSwitchBusTrans, 2)
--   end
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Bus_Transfer_SW_VAL", "number", function(v)
  currentBusTransPosition = v
  if v==0 then
    SetSwitchPosition(gSwitchBusTrans, 1) -- MAN
  else
    SetSwitchPosition(gSwitchBusTrans, 2) -- AUTO
  end
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbGuardBusTrans(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 1801) -- incr switch with cover open button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 1901)
--   -- if dir>1 then
--     -- msfs_event("ROTOR_BRAKE", 1901)
--   -- else
--     -- msfs_event("ROTOR_BRAKE", 1902)
--   -- end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbGuardBusTrans(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    -- Toggle switch when cover is open
    if currentBusTransPosition == 10 then
      currentBusTransPosition = 0 -- MAN
    else
      currentBusTransPosition = 10 -- AUTO
    end
    msfs_variable_write("L:VC_Bus_Transfer_SW_VAL", "number", currentBusTransPosition)
    return
  end
  -- Toggle guard cover (always open when clicked)
  msfs_variable_write("L:VC_Bus_Transfer_SW_Cover_VAL", "number", 10)
end

gSwitchBusTrans = AddHorGuardSwitch(135, 169, true, true, false, cbSwitchBusTrans, cbGuardBusTrans)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_19_73X", "number", function(v)
--   CloseGuard(gSwitchBusTrans, v==0)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Bus_Transfer_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchBusTrans, v==0)
end)

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
  if gSwitch[k].img[1] ~= nil then
    SetSwitchPosition(k, 1)
  elseif gSwitch[k].img[2] ~= nil then
    SetSwitchPosition(k, 2)
  else
    SetSwitchPosition(k, 3)
  end
end

-- ======================= Dimm all, except lights ================

-- local gBlackMask2 = canvas_add(0, 0, 400, 405, function()
  -- _rect(0, 0, 400, 405)
  -- _fill("black")
-- end)
-- opacity(gBlackMask2, 0)

-- ============================ lib functions for lights =======================

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
