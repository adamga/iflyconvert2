-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Fuel pump and valve switches
-- FS2020

-- Nov 28 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 10 2022: Initial version
-- Aug 22 2022: temperature gauge value corrected
-- Nov 28 2022: Illumination updated


img_add_fullscreen("bg.png")

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

---------------------- Fuel pump left aft switch ----------------
local gSwitchFuelPumpLeftAft
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFuelPumpLeftAft(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 3701)
--   else
--     msfs_event("ROTOR_BRAKE", 3702)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentLeftAftPosition = 10 -- Default to AUTO (10)
function cbSwitchFuelPumpLeftAft(switch, dir)
  if dir > 0 then
    currentLeftAftPosition = math.min(currentLeftAftPosition + 10, 20)
  else
    currentLeftAftPosition = math.max(currentLeftAftPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Fuel_L_AFT_SW_VAL", "number", currentLeftAftPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_37_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFuelPumpLeftAft, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Fuel_L_AFT_SW_VAL", "number", function(v)
  currentLeftAftPosition = v
  SetSwitchPosition(gSwitchFuelPumpLeftAft, math.floor(v/10)+1)
end)

gSwitchFuelPumpLeftAft = AddVerticalSwitch(gImgVertSwitch, 90, 485, true, false, true, cbSwitchFuelPumpLeftAft)

---------------------- Fuel pump left fwd switch ----------------
local gSwitchFuelPumpLeftFwd
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFuelPumpLeftFwd(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 3801)
--   else
--     msfs_event("ROTOR_BRAKE", 3802)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentLeftFwdPosition = 10 -- Default to AUTO (10)
function cbSwitchFuelPumpLeftFwd(switch, dir)
  if dir > 0 then
    currentLeftFwdPosition = math.min(currentLeftFwdPosition + 10, 20)
  else
    currentLeftFwdPosition = math.max(currentLeftFwdPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Fuel_L_FWD_SW_VAL", "number", currentLeftFwdPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_38_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFuelPumpLeftFwd, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Fuel_L_FWD_SW_VAL", "number", function(v)
  currentLeftFwdPosition = v
  SetSwitchPosition(gSwitchFuelPumpLeftFwd, math.floor(v/10)+1)
end)

gSwitchFuelPumpLeftFwd = AddVerticalSwitch(gImgVertSwitch, 177, 485, true, false, true, cbSwitchFuelPumpLeftFwd)

---------------------- Fuel pump right fwd switch ----------------
local gSwitchFuelPumpRightFwd
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFuelPumpRightFwd(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 3901)
--   else
--     msfs_event("ROTOR_BRAKE", 3902)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentRightFwdPosition = 10 -- Default to AUTO (10)
function cbSwitchFuelPumpRightFwd(switch, dir)
  if dir > 0 then
    currentRightFwdPosition = math.min(currentRightFwdPosition + 10, 20)
  else
    currentRightFwdPosition = math.max(currentRightFwdPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Fuel_R_FWD_SW_VAL", "number", currentRightFwdPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_39_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFuelPumpRightFwd, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Fuel_R_FWD_SW_VAL", "number", function(v)
  currentRightFwdPosition = v
  SetSwitchPosition(gSwitchFuelPumpRightFwd, math.floor(v/10)+1)
end)

gSwitchFuelPumpRightFwd = AddVerticalSwitch(gImgVertSwitch, 275, 485, true, false, true, cbSwitchFuelPumpRightFwd)

---------------------- Fuel pump right aft switch ----------------
local gSwitchFuelPumpRightAft
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFuelPumpRightAft(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 4001)
--   else
--     msfs_event("ROTOR_BRAKE", 4002)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentRightAftPosition = 10 -- Default to AUTO (10)
function cbSwitchFuelPumpRightAft(switch, dir)
  if dir > 0 then
    currentRightAftPosition = math.min(currentRightAftPosition + 10, 20)
  else
    currentRightAftPosition = math.max(currentRightAftPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Fuel_R_AFT_SW_VAL", "number", currentRightAftPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_40_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFuelPumpRightAft, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Fuel_R_AFT_SW_VAL", "number", function(v)
  currentRightAftPosition = v
  SetSwitchPosition(gSwitchFuelPumpRightAft, math.floor(v/10)+1)
end)

gSwitchFuelPumpRightAft = AddVerticalSwitch(gImgVertSwitch, 361, 485, true, false, true, cbSwitchFuelPumpRightAft)

---------------------- Fuel pump center left switch ----------------
local gSwitchFuelPumpCenterLeft
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFuelPumpCenterLeft(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 4501)
--   else
--     msfs_event("ROTOR_BRAKE", 4502)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentCenterLeftPosition = 10 -- Default to AUTO (10)
function cbSwitchFuelPumpCenterLeft(switch, dir)
  if dir > 0 then
    currentCenterLeftPosition = math.min(currentCenterLeftPosition + 10, 20)
  else
    currentCenterLeftPosition = math.max(currentCenterLeftPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Fuel_CENTER_L_SW_VAL", "number", currentCenterLeftPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_45_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFuelPumpCenterLeft, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Fuel_CENTER_L_SW_VAL", "number", function(v)
  currentCenterLeftPosition = v
  SetSwitchPosition(gSwitchFuelPumpCenterLeft, math.floor(v/10)+1)
end)

gSwitchFuelPumpCenterLeft = AddVerticalSwitch(gImgVertSwitch, 177, 322, true, false, true, cbSwitchFuelPumpCenterLeft)

---------------------- Fuel pump center right switch ----------------
local gSwitchFuelPumpCenterRight
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFuelPumpCenterRight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 4601)
--   else
--     msfs_event("ROTOR_BRAKE", 4602)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentCenterRightPosition = 10 -- Default to AUTO (10)
function cbSwitchFuelPumpCenterRight(switch, dir)
  if dir > 0 then
    currentCenterRightPosition = math.min(currentCenterRightPosition + 10, 20)
  else
    currentCenterRightPosition = math.max(currentCenterRightPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Fuel_CENTER_R_SW_VAL", "number", currentCenterRightPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_46_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFuelPumpCenterRight, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Fuel_CENTER_R_SW_VAL", "number", function(v)
  currentCenterRightPosition = v
  SetSwitchPosition(gSwitchFuelPumpCenterRight, math.floor(v/10)+1)
end)

gSwitchFuelPumpCenterRight = AddVerticalSwitch(gImgVertSwitch, 274, 322, true, false, true, cbSwitchFuelPumpCenterRight)

-- ================================

img_add("rotary-base-shadow.png", 168, 190, 70, 70)
gImgCrossfeedSwitch = img_add("rotary-handle.png", 168, 190, 70, 70)



local gNightColor = img_add_fullscreen("night-color.png")

opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 580, function()
  _rect(0, 0, 400, 580)
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

-------------- global variables --------------


-- =================== Draw lines ==================

function DrawPath(x, y, path)
  -- path = {x1, y1, x2, y2} and so on.
  -- If path is only one point, the line must go right or down.
  -- Otherwise the path must go clockwise.
  
  local count = #path/2
  local x0, x1, x2, y0, y1, y2, dx, dy
  x0 = x
  y0 = y

 
  if count == 1 then
    x1 = path[1] -- line target
    y1 = path[2]

    if x==x1 then -- vertical
      _move_to(x, y+2)
      _line_to(x, y1-2)
      _stroke(gColorBg, 15)
      _move_to(x, y-3)
      _line_to(x, y1+3)
      _stroke(gColorBg, 8)

      _move_to(x-4, y)
      _line_to(x-4, y1)
      _stroke(gColorPrint, 2)
      _move_to(x+4, y)
      _line_to(x+4, y1)
      _stroke(gColorPrint, 2)
    else -- horizontal
      _move_to(x+2, y)
      _line_to(x1-2, y)
      _stroke(gColorBg, 15)
      _move_to(x-3, y)
      _line_to(x1+3, y)
      _stroke(gColorBg, 8)

      _move_to(x, y-4)
      _line_to(x1, y-4)
      _stroke(gColorPrint, 2)
      _move_to(x, y+4)
      _line_to(x1, y+4)
      _stroke(gColorPrint, 2)
    end
  else
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
end

function DrawAllLines()
  -- _move_to(40, 392)
  -- _line_to(358, 392)
  -- _stroke(gColorPrint, 2)

  DrawPath(65, 442, {65, 401,   151, 401,   151, 442})  -- always clockwise!
  DrawPath(65, 196,  {65, 398})

  DrawPath(244, 442, {244, 401,   340, 401,   340, 442})
  DrawPath(340, 196, {340, 398})
  
--  DrawPath(157, 285, {157, 225, 247, 225, 247, 285})  -- ok with old illimination
  DrawPath(157, 285, {157, 225, 170, 225})
  DrawPath(235, 225, {247, 225, 247, 285})

  DrawPath(69, 225, {153, 225})
  DrawPath(253, 225, {336, 225})
end

local gImgLines = canvas_add(0, 0, 400, 580, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
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
  PrintText("CROSS", 105, 193, style, 24)
  PrintText("FEED", 241, 193, style, 24)
  PrintText("FUEL PUMP", 143, 316, style, 24)
  
  PrintText("CTR", 183, 388, style, 24)
  
  PrintText("AFT", 47, 470, style, 24)
  PrintText("FWD", 133, 470, style, 24)
  PrintText("FWD", 230, 470, style, 24)
  PrintText("AFT", 315, 470, style, 24)

  PrintText("L", 101, 361, style, 24)
  PrintText("R", 286, 361, style, 24)

  PrintText("FUEL", 177, 503, style, 24)
  PrintText("PUMPS", 170, 548, style, 24)

  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("OFF", 186, 340, style, 18)
  PrintText("ON", 190, 371, style, 18)
  
  PrintText("+", 85, 244, style, 18)
  
  PrintText("OFF", 93, 506, style, 18)
  PrintText("ON", 99, 537, style, 18)
  
  PrintText("OFF", 278, 506, style, 18)
  PrintText("ON", 283, 537, style, 18)
  
  PrintText("1", 104, 557, style, 18)
  PrintText("2", 288, 557, style, 18)
  
--  PrintVertText("OFF", 135, 176, style, 18)
end


local gImgTexts = canvas_add(0, 0, 400, 580, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 580)

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
    fs2020_variable_subscribe(lvar, "number", function(v)
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

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- AddLight("L:switch_55_73X", "light-blue-1.png", 36, 9, "ENG VALVE", "CLOSED")
-- AddLight("L:switch_53_73X", "light-blue-2.png", 36, 61, "SPAR VALVE", "CLOSED")
-- AddLight("L:switch_56_73X", "light-blue-1.png", 279, 9, "ENG VALVE", "CLOSED")
-- AddLight("L:switch_54_73X", "light-blue-1.png", 279, 61, "SPAR VALVE", "CLOSED")
-- AddLight("L:switch_50_73X", "light-amber-2.png", 36, 131, "FILTER", "BYPASS")
-- AddLight("L:switch_52_73X", "light-amber-1.png", 279, 131, "FILTER", "BYPASS")
-- AddLight("L:switch_51_73X", "light-blue-2.png", 157, 131, "VALVE", "OPEN")
-- AddLight("L:switch_47_73X", "light-amber-3.png", 115, 261, "LOW", "PRESSURE")
-- AddLight("L:switch_48_73X", "light-amber-1.png", 201, 261, "LOW", "PRESSURE")
-- AddLight("L:switch_41_73X", "light-amber-1.png", 22, 417, "LOW", "PRESSURE")
-- AddLight("L:switch_42_73X", "light-amber-3.png", 108, 417, "LOW", "PRESSURE")
-- AddLight("L:switch_43_73X", "light-amber-2.png", 207, 417, "LOW", "PRESSURE")
-- AddLight("L:switch_44_73X", "light-amber-1.png", 293, 417, "LOW", "PRESSURE")

-- ================ CONVERTED iFLY CODE ================
AddLight("L:VC_FUEL_LIGHT_ENG_VALVE_CLOSED_1_LIGHT_VAL", "light-blue-1.png", 36, 9, "ENG VALVE", "CLOSED")
AddLight("L:VC_FUEL_LIGHT_SPAR_VALVE_CLOSED_1_LIGHT_VAL", "light-blue-2.png", 36, 61, "SPAR VALVE", "CLOSED")
AddLight("L:VC_FUEL_LIGHT_ENG_VALVE_CLOSED_2_LIGHT_VAL", "light-blue-1.png", 279, 9, "ENG VALVE", "CLOSED")
AddLight("L:VC_FUEL_LIGHT_SPAR_VALVE_CLOSED_2_LIGHT_VAL", "light-blue-1.png", 279, 61, "SPAR VALVE", "CLOSED")

AddLight("L:VC_FUEL_LIGHT_FILTER_BYPASS_1_LIGHT_VAL", "light-amber-2.png", 36, 131, "FILTER", "BYPASS")
AddLight("L:VC_FUEL_LIGHT_FILTER_BYPASS_2_LIGHT_VAL", "light-amber-1.png", 279, 131, "FILTER", "BYPASS")
AddLight("L:VC_FUEL_LIGHT_VALVE_OPEN_LIGHT_VAL", "light-blue-2.png", 157, 131, "VALVE", "OPEN")

AddLight("L:VC_FUEL_LIGHT_CTR_L_LOW_PRESSURE_LIGHT_VAL", "light-amber-3.png", 115, 261, "LOW", "PRESSURE")
AddLight("L:VC_FUEL_LIGHT_CTR_R_LOW_PRESSURE_LIGHT_VAL", "light-amber-1.png", 201, 261, "LOW", "PRESSURE")

AddLight("L:VC_FUEL_LIGHT_AFT_1_LOW_PRESSURE_LIGHT_VAL", "light-amber-1.png", 22, 417, "LOW", "PRESSURE")
AddLight("L:VC_FUEL_LIGHT_FWD_1_LOW_PRESSURE_LIGHT_VAL", "light-amber-3.png", 108, 417, "LOW", "PRESSURE")
AddLight("L:VC_FUEL_LIGHT_FWD_2_LOW_PRESSURE_LIGHT_VAL", "light-amber-2.png", 207, 417, "LOW", "PRESSURE")
AddLight("L:VC_FUEL_LIGHT_AFT_2_LOW_PRESSURE_LIGHT_VAL", "light-amber-1.png", 293, 417, "LOW", "PRESSURE")

-- ============================= rotary switch cross feed ===================

local gStateCrossfeedSwitch

function DrawLine(x, y, x1, y1)
  -- The line from x/y to x1/y1 must go right or down.
 
  if x==x1 then -- vertical
    _move_to(x, y+2)
    _line_to(x, y1-2)
    _stroke(gColorBg, 15)
    _move_to(x, y-3)
    _line_to(x, y1+3)
    _stroke(gColorBg, 8)

    _move_to(x-4, y)
    _line_to(x-4, y1)
    _stroke(gColorPrint, 2)
    _move_to(x+4, y)
    _line_to(x+4, y1)
    _stroke(gColorPrint, 2)
  else -- horizontal
    _move_to(x+2, y)
    _line_to(x1-2, y)
    _stroke(gColorBg, 15)
    _move_to(x-3, y)
    _line_to(x1+3, y)
    _stroke(gColorBg, 8)

    _move_to(x, y-4)
    _line_to(x1, y-4)
    _stroke(gColorPrint, 2)
    _move_to(x, y+4)
    _line_to(x1, y+4)
    _stroke(gColorPrint, 2)
  end
end

function DrawCrossfeedLine()
  if gStateCrossfeedSwitch == 100 then
    DrawLine(35, 10, 35, 60)
  else
    DrawLine(10, 35, 60, 35)
  end
end


local gCanvasCrossfeedSwitch = canvas_add(168, 190, 70, 70, DrawCrossfeedLine)

msfs_variable_subscribe("L:switch_49_73X", "number", function(v)
  gStateCrossfeedSwitch = v
  if v==100 then
    img_rotate(gImgCrossfeedSwitch, 0)
  else
    img_rotate(gImgCrossfeedSwitch, 90)
  end
  canvas_draw(gCanvasCrossfeedSwitch, DrawCrossfeedLine)
end)

dial_add(nil, 168, 190, 70, 70, nil) -- to get a circular touch field
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- button_add(nil, nil, 168, 190, 70, 70, function() msfs_event("ROTOR_BRAKE", 4901) end)

-- ================ CONVERTED iFLY CODE ================
local currentCrossfeedPosition = 0 -- Default to CLOSED (0)
button_add(nil, nil, 168, 190, 70, 70, function()
  -- Toggle crossfeed valve: 0=CLOSED, 10=OPEN
  if currentCrossfeedPosition == 0 then
    currentCrossfeedPosition = 10
  else
    currentCrossfeedPosition = 0
  end
  fs2020_variable_write("L:VC_Fuel_Crossfeed_SW_VAL", "number", currentCrossfeedPosition)
end)

-- =========================== Fuel temp gauge =======================
local gImgNeedle

gImgNeedle = img_add("needle-day.png", 190, 18, 20, 94)
img_add("needle-base.png", 191, 55, 20, 20)

msfs_variable_subscribe("L:switch_57_73X", "number", function(v)
--  img_rotate(gImgNeedle, (v-32)*5/9 /100*254) -- Fahrenheit to gauge scale
--  img_rotate(gImgNeedle, (v-60)*1.1 /100*254) -- Fahrenheit to gauge scale
  local degc, degperc
  degc = (v-23)/73.7*80-40 -- celsius
  degperc = 254/100
  img_rotate(gImgNeedle, degc*degperc)
end)


-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 580, function()
  _rect(0, 0, 400, 580)
  _fill("black")
end)
opacity(gBlackMask2, 0)

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
  canvas_draw(gCanvasCrossfeedSwitch, DrawCrossfeedLine)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  DrawSwitches()
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)




