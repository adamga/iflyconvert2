-- Detlef von Reusner
-- PMDG B737-700 Overhead Cabin Pressurization Panel
-- FS2020

-- V1.00

-- Dec 1 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Oct 13 2022: Initial version
-- Dec 1 2022: Illumination updated



img_add_fullscreen("bg.png")

gImgDialMode = img_add("selector-knob.png", 257, 306, 60, 60)

-------------------- LANDING ALTITUDE SELECTOR knob ---------------------

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- dial_add("knob.png", 96, 308, 60, 60, function(rotac)
--   if rotac>0 then
--     fs2020_event("ROTOR_BRAKE", 22007)
--   else
--     fs2020_event("ROTOR_BRAKE", 22008)
--   end
-- end)

-- ================ CONVERTED iFLY CODE ================
local currentLandAlt = 0
dial_add("knob.png", 96, 308, 60, 60, function(rotac)
  if rotac>0 then
    if currentLandAlt < 100 then
      currentLandAlt = currentLandAlt + 10
      msfs_variable_write("L:VC_Landing_Altitude_SW_VAL", "number", currentLandAlt)
    end
  else
    if currentLandAlt > 0 then
      currentLandAlt = currentLandAlt - 10
      msfs_variable_write("L:VC_Landing_Altitude_SW_VAL", "number", currentLandAlt)
    end
  end
end)

msfs_variable_subscribe("L:VC_Landing_Altitude_SW_VAL", "number", function(v)
  currentLandAlt = v
end)

-------------------- FLIGHT ALTITUDE SELECTOR knob ----------------

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- dial_add("knob.png", 96, 167, 60, 60, function(rotac)
--   if rotac>0 then
--     fs2020_event("ROTOR_BRAKE", 21807)
--   else
--     fs2020_event("ROTOR_BRAKE", 21808)
--   end
-- end)

-- ================ CONVERTED iFLY CODE ================
local currentFlightAlt = 0
dial_add("knob.png", 96, 167, 60, 60, function(rotac)
  if rotac>0 then
    if currentFlightAlt < 100 then
      currentFlightAlt = currentFlightAlt + 10
      msfs_variable_write("L:VC_Flight_Altitude_SW_VAL", "number", currentFlightAlt)
    end
  else
    if currentFlightAlt > 0 then
      currentFlightAlt = currentFlightAlt - 10
      msfs_variable_write("L:VC_Flight_Altitude_SW_VAL", "number", currentFlightAlt)
    end
  end
end)

msfs_variable_subscribe("L:VC_Flight_Altitude_SW_VAL", "number", function(v)
  currentFlightAlt = v
end)

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

function AddSmallHorizontalSwitch(x, y, p1, p2, p3, call_back)
  -- e.g.:  if p1, p2 and p3 are true, this switch has all three positions
  x = x - 0
  y = y - 0
  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local w, h, img, meta

  img = "small-hor-switch-left.png" -- all three switch position pictures assumed the same size
  meta = resource_info(img)
  if meta == nil then print(img.." not found"); return 0 end
  w = meta.WIDTH
  h = meta.HEIGHT

  local x_touch, y_touch, w_touch, h_touch
  x_touch = x
  y_touch = y
  w_touch = w/2-1
  h_touch = h
  do
    local n = gSwitchCount
    button_add(gTouchField, nil, x_touch, y_touch, w_touch, h_touch, function() call_back(n, -1) end, nil) -- dec button
    button_add(gTouchField, nil, x_touch+w_touch+1, y_touch, w_touch, h_touch, function() call_back(n, 1) end, nil) -- inc button
  end
  
  s.img = {} -- stores the images for all switch positions
  if p1 then
    img = "small-hor-switch-left.png"
    s.img[1] = img_add(img, x, y, w, h)
    visible(s.img[1], false)
  end
  if p2 then
    img = "small-hor-switch-middle.png"
    s.img[2] = img_add(img, x, y, w, h)
    visible(s.img[2], false)
  end
  if p3 then
    img = "small-hor-switch-right.png"
    s.img[3] = img_add(img, x, y, w, h)
    visible(s.img[3], false)
  end
  s.pos = nil
  return gSwitchCount
end


function AddHorizontalSpringSwitch(x, y, p1, p2, p3, call_back)
  -- e.g.:  if p1, p2 and p3 are true, this switch has all three positions
  x = x - 0
  y = y - 0
  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local w, h, img, meta

  img = "switch-left.png" -- all three switch position pictures assumed the same size
  meta = resource_info(img)
  if meta == nil then print(img.." not found"); return 0 end
  w = meta.WIDTH
  h = meta.HEIGHT

  local x_touch, y_touch, w_touch, h_touch
  x_touch = x
  y_touch = y
  w_touch = w/2-1
  h_touch = h
  do
    local n = gSwitchCount
    button_add(gTouchField, nil, x_touch, y_touch, w_touch, h_touch, function() call_back(n, -1) end, function() call_back(n, 0) end) -- dec button
    button_add(gTouchField, nil, x_touch+w_touch+1, y_touch, w_touch, h_touch, function() call_back(n, 1) end, function() call_back(n, 0) end) -- inc button
  end
  
  s.img = {} -- stores the images for all switch positions
  if p1 then
    img = "switch-left.png"
    s.img[1] = img_add(img, x, y, w, h)
    visible(s.img[1], false)
  end
  if p2 then
    img = "switch-middle.png"
    s.img[2] = img_add(img, x, y, w, h)
    visible(s.img[2], false)
  end
  if p3 then
    img = "switch-right.png"
    s.img[3] = img_add(img, x, y, w, h)
    visible(s.img[3], false)
  end
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

-- ====================== operate switches ==================

---------------------- OUTFLOW VALVE Switch springloaded to neutral ----------------
local gSwitchOutflowValve

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchOutflowValve(switch, dir)
--   if dir > 0 then
--     fs2020_event("ROTOR_BRAKE", 22202)
--   elseif dir < 0 then
--     fs2020_event("ROTOR_BRAKE", 22201)
--   else
--     fs2020_event("ROTOR_BRAKE", 22204)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbSwitchOutflowValve(switch, dir)
  if dir > 0 then
    msfs_variable_write("L:VC_Outflow_Valve_SW_VAL", "number", 20)  -- OPEN position
  elseif dir < 0 then
    msfs_variable_write("L:VC_Outflow_Valve_SW_VAL", "number", 0)   -- CLOSE position
  else
    msfs_variable_write("L:VC_Outflow_Valve_SW_VAL", "number", 10)  -- NEUTRAL position
  end
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_222_73X", "number", function(v)
--   SetSwitchPosition(gSwitchOutflowValve, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Outflow_Valve_SW_VAL", "number", function(v)
  SetSwitchPosition(gSwitchOutflowValve, math.floor(v/10)+1)
end)

gSwitchOutflowValve = AddHorizontalSpringSwitch(236, 200, true, true, true, cbSwitchOutflowValve)
SetSwitchPosition(gSwitchOutflowValve, 2)


-- ===================================

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 480, function()
  _rect(0, 0, 400, 480)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense

local gColorAmber = string.format(";color:#%02x%02x%02x", 243, 163, 90)
local gColorBlue = string.format(";color:#%02x%02x%02x", 250, 250, 250)
local gColorGreen = string.format(";color:#%02x%02x%02x", 98, 208, 103)

local gColorPrint = "#E0E0E0FF"
local gColorBg = "#101010FF"

local gColorDisplay = string.format(";color:#%02x%02x%02xff", 240, 240, 240)

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
  _move_to(215, 70)
  _line_to(215, 376)
  _stroke(gColorPrint, 3)
  
  _move_to(215, 265)
  _line_to(397, 265)
  _stroke(gColorPrint, 3)

  -- numbers for manual pressure adjustment
  _move_to(34, 446)
  _line_to(349, 446)
  _stroke(gColorPrint, 2)
  
  _move_to(83, 424)
  _line_to(83, 470)
  _stroke(gColorPrint, 2)

  _move_to(141, 424)
  _line_to(141, 456)
  _stroke(gColorPrint, 2)

  local x, step
  x = 128
  step = 55
  for k=1,4 do
    x=x+step
    _move_to(x, 424)
    _line_to(x, 456)
  end
  

  local x, y
  x = 257+30 -- center
  y = 306+30
  _rotate(-60, x, y)
  for k=1,3 do
    _move_to(x+30, y)
    _line_to(x+38, y)
    _stroke(gColorPrint, 2)
    _rotate(-30, x, y)
  end
  _rotate(x, y, -210)
  
  -- DrawPath(250, 356, {216, 356,   216, 238,   322, 238,   322, 356})  -- always clockwise!
  -- DrawPath(79, 356,  {79, 238,    185, 238,   185, 356,   150, 356})
end

local gImgLines = canvas_add(0, 0, 400, 480, DrawAllLines)

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintMedium = "font:roboto_bold.ttf; size:20"
local gFontPrintSmall = "font:roboto_bold.ttf; size:18"
local gFontPrintTiny = "font:roboto_bold.ttf; size:14"


function PrintText(text, x, y, style, size, black_bg)
  black_bg = (black_bg == true)
  local count = string.len(text)
  if black_bg then
    _rect(x-3, y, count/2*size+7, size)
    _fill(gColorBg)
  end
  _txt(text, style, x, y-1)
end

function PrintVertText(text, x, y, style, size, black_bg)
  black_bg = (black_bg == true)
  local count = string.len(text)
  local step = size*.7
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
  PrintText("AUTO", 98, 67, style, size)
  PrintText("MANUAL", 254, 67, style, size)
  
  style = gFontPrintMedium..";color:"..gColorPrint.."; halign:left"
  size = 20
  PrintText("FLT/ALT", 90, 145, style, size)
  PrintText("LAND ALT", 85, 285, style, size)
  
  PrintText("AUTO", 230, 284, style, size)
  PrintText("ALTN", 267, 269, style, size)
  PrintText("MAN", 300, 284, style, size)

  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:center"
  size = 18
  PrintVertText("VALVE", 355, 120, style, size)
  PrintVertText("CLOSE", 240, 193, style, size)
  PrintVertText("OPEN", 345, 202, style, size)

  style = gFontPrintTiny..";color:"..gColorPrint.."; halign:left"
  size = 14
  local step = 55
  local x = 34
  local y = 428
  PrintText("CAB ALT", x, y, style, size); x=x+step
  PrintText("LAND ALT", x-2, y, style, size); x=x+step
  PrintText("2000", x+6, y, style, size); x=x+step
  PrintText("4000", x, y, style, size); x=x+step
  PrintText("6000", x, y, style, size); x=x+step
  PrintText("8000", x, y, style, size); x=x+step
  x = 34
  y = 456
  PrintText("FLT ALT", x, y, style, size); x=x+step*1.5
  PrintText("<FL160", x, y, style, size); x=x+step
  PrintText("FL220", x, y, style, size); x=x+step
  PrintText("FL260", x, y, style, size); x=x+step
  PrintText("FL320", x, y, style, size); x=x+step
  PrintText("FL410", x, y, style, size); x=x+step
end


local gImgTexts = canvas_add(0, 0, 400, 480, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 480)

-- ====================== OUTFLOW VALVE POSITION Indicator Needle Gauge ==============

gImgNeedle = img_add("needle.png", 251, 96, 88, 88)
img_add("gauge.png", 251, 96, 88, 88)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_221_73X", "number", function(v)
--   local angle = (v-30)/26*45
--   if angle <  -53 then
--     angle = -53
--   elseif angle > 53 then
--     angle = 53
--   end
--   rotate(gImgNeedle, angle)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Outflow_VALVE_Position_Indicator_VAL", "number", function(v)
  local angle = (v-30)/26*45
  if angle <  -53 then
    angle = -53
  elseif angle > 53 then
    angle = 53
  end
  rotate(gImgNeedle, angle)
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

------------------ PRESSURIZATION MODE Controller ----------------
-- Three position switch. Default position is AUTO --> 0 = AUTO, 10 == ALTN, 20 = MAN 

function DrawNeedle()
  _move_to(30, 0)
  _line_to(30, 30)
  _stroke("black", 8)
  
  _move_to(30, 0)
  _line_to(30, 28)
  _stroke(gColorPrint, 4)
end

local gImgModeNeedle = canvas_add(257, 306, 60, 60, DrawNeedle)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- dial_add(nil, 257, 306, 60, 60, function(rotac)
--   if rotac>0 then
--     fs2020_event("ROTOR_BRAKE", 22307)
--   else
--     fs2020_event("ROTOR_BRAKE", 22308)
--   end
-- end)

-- ================ CONVERTED iFLY CODE ================
local currentPressMode = 0
dial_add(nil, 257, 306, 60, 60, function(rotac)
  if rotac>0 then
    if currentPressMode < 20 then
      currentPressMode = currentPressMode + 10
      msfs_variable_write("L:VC_Pressurization_Mode_SW_VAL", "number", currentPressMode)
    end
  else
    if currentPressMode > 0 then
      currentPressMode = currentPressMode - 10
      msfs_variable_write("L:VC_Pressurization_Mode_SW_VAL", "number", currentPressMode)
    end
  end
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_223_73X", "number", function(v)
--   local angle = v/10*30-30
--   rotate(gImgDialMode, angle, "LOG", .2)
--   rotate(gImgModeNeedle, angle, "LOG", .2)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Pressurization_Mode_SW_VAL", "number", function(v)
  local angle = v/10*30-30
  rotate(gImgDialMode, angle, "LOG", .2)
  rotate(gImgModeNeedle, angle, "LOG", .2)
  currentPressMode = v
end)

------------------ helper

-- function toint(n)
  -- -- needed because math.floor() returns floats
    -- local s = tostring(n)
    -- local i, j = s:find('%.')
    -- if i then
        -- return tonumber(s:sub(1, i-1))
    -- else
        -- return n
    -- end
-- end

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 480, function()
  _rect(0, 0, 400, 480)
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
        v = .2
      else
        v = var_cap(4*v, 0.6, 1)
      end
      opacity(gLight[n].img_shade, 1-v)
    end)
  end
  return gLightCount
end

-- ====================== Displays ==============

local gTxtFlight = txt_add("41000", "font:digital-7-mono.ttf; size:30;"..gColorDisplay..";halign:right;", 85, 103, 80, 35)
local gTxtLand = txt_add("-200", "font:digital-7-mono.ttf; size:30;"..gColorDisplay..";halign:right;", 85, 243, 80, 35)

--msfs_variable_subscribe("AIR_DisplayLandAlt", "string", function(v)
--msfs_variable_subscribe("PMDG_NG3_Data:AIR_DisplayLandAlt", "STRING", function(v)
--  if v == 99000. then
--    txt_set(gTxtLand, "-----")
--  else
--    txt_set(gTxtLand, math.floor(v))
--  end
--end)
local monval = ""

msfs_variable_subscribe("AIR_DisplayLandAlt", "CHAR_ARRAY", function(v)
    monval = v
    txt_set(gTxtLand, v)
end)

msfs_variable_subscribe("AIR_DisplayFltAlt", "string", function(v)
  if v == 99000. then
    txt_set(gTxtFlight, "-----")
  end
end)

-- ======================== add lights ======================

AddLight("L:switch_213_73X", "light-amber-4.png", 29, 9, "AUTO", "FAIL")
AddLight("L:switch_214_73X", "light-amber-4.png", 115, 9, "OFF SCHED", "DESCENT")
AddLight("L:switch_215_73X", "light-green-3.png", 209, 9, "ALTN")
AddLight("L:switch_216_73X", "light-green-3.png", 287, 9, "MANUAL")

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
  canvas_draw(gImgModeNeedle, DrawNeedle)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  -- DrawSwitches()
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)
