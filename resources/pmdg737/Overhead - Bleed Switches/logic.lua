-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Bleed switches
-- FS2020

-- Nov 28 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 14 2022: Initial version
-- Nov 28 2022: Illumination updated



img_add_fullscreen("bg.png")

img_add("gauge-numbers.png",60,1,400,550)
img_add("gauge-frame.png",60,1,400,550)
img_add("gauge-front-text.png",60,1,400,550)

--------------- 
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


local gSwitchColorHi = "#f0f0f0ff"
local gSwitchColorLo = "#b8b8b8ff"

local gImgVertSwitch = {"switch-up-pin.png", "switch-middle-pin.png", "switch-down-pin.png"}


  
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

-- -- function SetSwitchPosition(switch, target)
  -- -- local s = gSwitch[switch]
  -- -- if target == nil then return end
  -- -- visible(s.img[target], true)
  -- -- if s.pos~=nil and s.pos~=target  then visible(s.img[s.pos], false) end
  -- -- s.pos = target
-- -- end


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

--------------------

----------------------- Recirc fan switches --------------------------

local gSwitchRecircFanLeft, gSwitchRecircFanRight

function cbSwitchRecircFanLeft(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 19601)
  -- else
  --   msfs_event("ROTOR_BRAKE", 19602)
  -- end
  
  -- iFly Conversion - Left Recirc Fan:
  if dir > 0 then
    msfs_variable_write("L:VC_RecircFan_L_SW_VAL", "number", 20) -- ON
  else
    msfs_variable_write("L:VC_RecircFan_L_SW_VAL", "number", 0) -- OFF
  end
end

function cbSwitchRecircFanRight(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 19601)
  -- else
  --   msfs_event("ROTOR_BRAKE", 19602)
  -- end
  
  -- iFly Conversion - Right Recirc Fan:
  if dir > 0 then
    msfs_variable_write("L:VC_RecircFan_R_SW_VAL", "number", 20) -- ON
  else
    msfs_variable_write("L:VC_RecircFan_R_SW_VAL", "number", 0) -- OFF
  end
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_196_73X", "number", function(v)

-- iFly Conversion - Left Recirc Fan:
msfs_variable_subscribe("L:VC_RecircFan_L_SW_VAL", "number", function(v)
  SetSwitchPosition(gSwitchRecircFanLeft, math.floor(v/10)+1)
end)

-- iFly Conversion - Right Recirc Fan:
msfs_variable_subscribe("L:VC_RecircFan_R_SW_VAL", "number", function(v)
  SetSwitchPosition(gSwitchRecircFanRight, math.floor(v/10)+1)
end)

gSwitchRecircFanLeft = AddVerticalSwitch(gImgVertSwitch, 130, 85, true, false, true, cbSwitchRecircFanLeft)
gSwitchRecircFanRight = AddVerticalSwitch(gImgVertSwitch, 300, 85, true, false, true, cbSwitchRecircFanRight)

---

local gNightMask = img_add_fullscreen("night-color.png")
opacity(gNightMask, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 550, function()
  _rect(0, 0, 400, 550)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense

local gColorAmber = string.format(";color:#%02x%02x%02x", 243, 163, 90)
local gColorBlue = string.format(";color:#%02x%02x%02x", 250, 250, 250)
local gColorGreen = string.format(";color:#%02x%02x%02x", 98, 208, 103)

local gColorBg = "#101010FF" -- qq check if needed
local gColorPrint = "#ffffff00"

local gFontLight = "font:arimo_bold.ttf; size:14"


local gDebugShowTouchFields = false

local gTouchField
if gDebugShowTouchFields then
   gTouchField = "touch-field-on.png"
else
   gTouchField = nil
end


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
    dx = 4
    dy = 0
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
  _move_to(76, 474)
  _line_to(326, 474)
  _stroke(gColorPrint, 2)

  DrawPath(69, 441, {69, 407,   171, 407,   171, 441})  -- always clockwise!
  DrawPath(69, 441, {69, 223,   329, 223,   329 , 441})
  
  _rect(8, 238, 48, 58)
  _fill(gColorBg)
  _move_to(8, 238)
  _line_to(56, 238)
  _line_to(56, 296)
  _line_to(8, 296)
  _line_to(8, 238)
  _stroke(gColorPrint, 2)
  DrawPath(56, 242, {65, 242})
  
  _rect(343, 238, 48, 58)
  _fill(gColorBg)
  _move_to(343, 238)
  _line_to(391, 238)
  _line_to(391, 296)
  _line_to(343, 296)
  _line_to(343, 238)
  _stroke(gColorPrint, 2)
  DrawPath(332, 242, {342, 242})
  
  DrawPath(69, 196, {69, 220})
  DrawPath(329, 196, {329, 220})
  DrawPath(72, 407, {167, 407})
  
end

local gImgLines = canvas_add(0, 0, 400, 550, DrawAllLines)

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
  PrintText("L RECIRC", 45, 74, style, 24)
  PrintText("FAN", 70, 95, style, 24)
  PrintText("R RECIRC", 245, 74, style, 24)
  PrintText("FAN", 270, 95, style, 24)
  
  PrintText("ISOL", 186, 154, style, 24)
  PrintText("VALVE", 180, 175, style, 24)

  PrintText("L PACK", 8, 139, style, 24)
  PrintText("R PACK", 290, 139, style, 24)
  
  PrintText("APU", 153, 463, style, 24)
  PrintText("BLEED", 212, 463, style, 24)
  PrintText("1", 62, 463, style, 24)
  PrintText("2", 325, 463, style, 24)

  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("OFF", 200, 100, style, 18)
  PrintText("AUTO", 191, 130, style, 18)
  
  PrintText("OFF", 11, 162, style, 18)
  PrintText("AUTO", 6, 181, style, 18)
  PrintText("HIGH", 8, 200, style, 18)
  
  PrintText("OFF", 359, 162, style, 18)
  PrintText("AUTO", 359, 181, style, 18)
  PrintText("HIGH", 356, 200, style, 18)

  -- PrintText("ISOLATION", 180, 157, style, 18)
  -- PrintText("VALVE", 180, 175, style, 18)
  PrintText("CLOSE", 129, 191, style, 18)
  PrintText("AUTO", 228, 199, style, 18)
  PrintText("OPEN", 184, 246, style, 18)
  
  
  PrintText("OVHT", 323, 72, style, 18)
  PrintText("TEST", 343, 120, style, 18)
  
  PrintText("WING", 15, 243, style, 18, false)
  PrintText("ANTI", 17, 257, style, 18, false)
  PrintText("ICE", 20, 271, style, 18, false)
  
  PrintText("WING", 349, 243, style, 18, false)
  PrintText("ANTI", 351, 257, style, 18, false)
  PrintText("ICE", 355, 271, style, 18, false)
  
  PrintText("TRIP", 184, 308, style, 18)
  PrintText("RESET", 182, 364, style, 18)
  
  PrintText("OFF", 104, 418, style, 18)
  PrintText("ON", 109, 451, style, 18)
  
  PrintText("OFF", 274, 418, style, 18)
  PrintText("ON", 282, 451, style, 18)
  
--  PrintVertText("OFF", 135, 176, style, 18)
end


local gImgTexts = canvas_add(0, 0, 400, 550, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 550)

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
-- AddLight("L:switch_193_73X", "light-amber-1.png", 49, 11, "DUAL", "BLEED")
-- AddLight("L:switch_194_73X", "light-blue-1.png", 135, 11,  "RAM DOOR", "FULL OPEN")
-- AddLight("L:switch_195_73X", "light-blue-2.png", 268, 11,  "RAM DOOR", "FULL OPEN")

-- AddLight("L:switch_203_73X", "light-amber-2.png", 88, 238,  "PACK", "TRIP OFF")
-- AddLight("L:switch_204_73X", "light-amber-3.png", 88, 289,  "WING-BODY", "OVERHEAT")
-- AddLight("L:switch_205_73X", "light-amber-1.png", 88, 340,  "BLEED", "TRIP OFF")

-- AddLight("L:switch_206_73X", "light-amber-4.png", 227, 238,  "PACK", "TRIP OFF")
-- AddLight("L:switch_207_73X", "light-amber-2.png", 227, 289,  "WING-BODY", "OVERHEAT")
-- AddLight("L:switch_208_73X", "light-amber-3.png", 227, 340,  "BLEED", "TRIP OFF")

-- AddLight("L:switch_213_73X", "light-amber-1.png", 29, 490,  "AUTO", "FAIL")
-- AddLight("L:switch_214_73X", "light-amber-4.png", 115, 490,  "OFF SCHED", "DESCENT")

-- AddLight("L:switch_215_73X", "light-blue-3.png", 201, 490,  "ALTN")
-- AddLight("L:switch_216_73X", "light-blue-2.png", 287, 490,  "MANUAL")

-- iFly Conversion:
AddLight("L:VC_AIRSYSTEM_LIGHT_DUAL_BLEED_LIGHT_VAL", "light-amber-1.png", 49, 11, "DUAL", "BLEED")
AddLight("L:VC_RAM_DOOR_FULL_OPEN_L_LIGHT_VAL", "light-blue-1.png", 135, 11,  "RAM DOOR", "FULL OPEN")
AddLight("L:VC_RAM_DOOR_FULL_OPEN_R_LIGHT_VAL", "light-blue-2.png", 268, 11,  "RAM DOOR", "FULL OPEN")

AddLight("L:VC_PACK_1_TRIP_OFF_LIGHT_VAL", "light-amber-2.png", 88, 238,  "PACK", "TRIP OFF")
AddLight("L:VC_WING_BODY_OVERHEAT_L_LIGHT_VAL", "light-amber-3.png", 88, 289,  "WING-BODY", "OVERHEAT")
AddLight("L:VC_AIRSYSTEM_LIGHT_BLEED_1_LIGHT_VAL", "light-amber-1.png", 88, 340,  "BLEED", "TRIP OFF")

AddLight("L:VC_PACK_2_TRIP_OFF_LIGHT_VAL", "light-amber-4.png", 227, 238,  "PACK", "TRIP OFF")
AddLight("L:VC_WING_BODY_OVERHEAT_R_LIGHT_VAL", "light-amber-2.png", 227, 289,  "WING-BODY", "OVERHEAT")
AddLight("L:VC_AIRSYSTEM_LIGHT_BLEED_2_LIGHT_VAL", "light-amber-3.png", 227, 340,  "BLEED", "TRIP OFF")

AddLight("L:VC_CABIN_ALTITUDE_AUTO_FAIL_LIGHT_VAL", "light-amber-1.png", 29, 490,  "AUTO", "FAIL")
AddLight("L:VC_CABIN_ALTITUDE_OFF_SCHED_DESCENT_LIGHT_VAL", "light-amber-4.png", 115, 490,  "OFF SCHED", "DESCENT")

AddLight("L:VC_CABIN_ALTITUDE_ALTN_LIGHT_VAL", "light-blue-3.png", 201, 490,  "ALTN")
AddLight("L:VC_CABIN_ALTITUDE_MANUAL_LIGHT_VAL", "light-blue-2.png", 287, 490,  "MANUAL")

-- ====================== operate switches ==================

---------------------- L Pack switch ----------------
local gSwitchLPack
local currentLPackPosition = 10 -- 0=OFF, 10=AUTO, 20=HIGH

function cbSwitchLPack(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 20001)
  -- else
  --   msfs_event("ROTOR_BRAKE", 20002)
  -- end
  
  -- iFly Conversion - 3-position switch: OFF/AUTO/HIGH
  if dir > 0 then
    if currentLPackPosition == 0 then
      currentLPackPosition = 10 -- OFF -> AUTO
    elseif currentLPackPosition == 10 then
      currentLPackPosition = 20 -- AUTO -> HIGH
    end
  elseif dir < 0 then
    if currentLPackPosition == 20 then
      currentLPackPosition = 10 -- HIGH -> AUTO
    elseif currentLPackPosition == 10 then
      currentLPackPosition = 0 -- AUTO -> OFF
    end
  end
  msfs_variable_write("L:VC_Pack_1_SW_VAL", "number", currentLPackPosition)
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_200_73X", "number", function(v)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_Pack_1_SW_VAL", "number", function(v)
  currentLPackPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchLPack, 1) -- OFF position (bottom)
  elseif v == 10 then
    SetSwitchPosition(gSwitchLPack, 2) -- AUTO position (middle)
  elseif v == 20 then
    SetSwitchPosition(gSwitchLPack, 3) -- HIGH position (top)
  end
end)

gSwitchLPack = AddVerticalSwitch(gImgVertSwitch, 94, 144, true, true, true, cbSwitchLPack)

-------------------------- Isolation valve switch ------------------

local gSwitchIsolationValve
local currentIsolationValvePosition = 10 -- 0=CLOSE, 10=AUTO, 20=OPEN

function cbSwitchIsolationValve(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 20201)
  -- else
  --   msfs_event("ROTOR_BRAKE", 20202)
  -- end
  
  -- iFly Conversion - 3-position switch: CLOSE/AUTO/OPEN
  if dir > 0 then
    if currentIsolationValvePosition == 0 then
      currentIsolationValvePosition = 10 -- CLOSE -> AUTO
    elseif currentIsolationValvePosition == 10 then
      currentIsolationValvePosition = 20 -- AUTO -> OPEN
    end
  elseif dir < 0 then
    if currentIsolationValvePosition == 20 then
      currentIsolationValvePosition = 10 -- OPEN -> AUTO
    elseif currentIsolationValvePosition == 10 then
      currentIsolationValvePosition = 0 -- AUTO -> CLOSE
    end
  end
  msfs_variable_write("L:VC_ISOLATION_VALVE_SW_VAL", "number", currentIsolationValvePosition)
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_202_73X", "number", function(v)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_ISOLATION_VALVE_SW_VAL", "number", function(v)
  currentIsolationValvePosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchIsolationValve, 1) -- CLOSE position (bottom)
  elseif v == 10 then
    SetSwitchPosition(gSwitchIsolationValve, 2) -- AUTO position (middle)
  elseif v == 20 then
    SetSwitchPosition(gSwitchIsolationValve, 3) -- OPEN position (top)
  end
end)

gSwitchIsolationValve = AddVerticalSwitch(gImgVertSwitch, 226, 180, true, true, true, cbSwitchIsolationValve)

----------------- R Pack switch ----------------------

local gSwitchRPack
local currentRPackPosition = 10 -- 0=OFF, 10=AUTO, 20=HIGH

function cbSwitchRPack(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 20101)
  -- else
  --   msfs_event("ROTOR_BRAKE", 20102)
  -- end
  
  -- iFly Conversion - 3-position switch: OFF/AUTO/HIGH
  if dir > 0 then
    if currentRPackPosition == 0 then
      currentRPackPosition = 10 -- OFF -> AUTO
    elseif currentRPackPosition == 10 then
      currentRPackPosition = 20 -- AUTO -> HIGH
    end
  elseif dir < 0 then
    if currentRPackPosition == 20 then
      currentRPackPosition = 10 -- HIGH -> AUTO
    elseif currentRPackPosition == 10 then
      currentRPackPosition = 0 -- AUTO -> OFF
    end
  end
  msfs_variable_write("L:VC_Pack_2_SW_VAL", "number", currentRPackPosition)
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_201_73X", "number", function(v)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_Pack_2_SW_VAL", "number", function(v)
  currentRPackPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchRPack, 1) -- OFF position (bottom)
  elseif v == 10 then
    SetSwitchPosition(gSwitchRPack, 2) -- AUTO position (middle)
  elseif v == 20 then
    SetSwitchPosition(gSwitchRPack, 3) -- HIGH position (top)
  end
end)

gSwitchRPack = AddVerticalSwitch(gImgVertSwitch, 357, 144, true, true, true, cbSwitchRPack)

--------------------- Bleed 1 switch ------------------------

local gSwitchBleed1

function cbSwitchBleed1(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 21001)
  -- else
  --   msfs_event("ROTOR_BRAKE", 21002)
  -- end
  
  -- iFly Conversion:
  if dir > 0 then
    msfs_variable_write("L:VC_Engine_1_Bleed_Air_SW_VAL", "number", 10) -- ON
  else
    msfs_variable_write("L:VC_Engine_1_Bleed_Air_SW_VAL", "number", 0) -- OFF
  end
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_210_73X", "number", function(v)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_Engine_1_Bleed_Air_SW_VAL", "number", function(v)
  SetSwitchPosition(gSwitchBleed1, math.floor(v/10)+1)
end)

gSwitchBleed1 = AddVerticalSwitch(gImgVertSwitch, 94, 399, true, false, true, cbSwitchBleed1)

----------------------- Apu bleed switch ---------------------

local gSwitchApu

function cbSwitchApu(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 21101)
  -- else
  --   msfs_event("ROTOR_BRAKE", 21102)
  -- end
  
  -- iFly Conversion:
  if dir > 0 then
    msfs_variable_write("L:VC_APU_Bleed_Air_SW_VAL", "number", 10) -- ON
  else
    msfs_variable_write("L:VC_APU_Bleed_Air_SW_VAL", "number", 0) -- OFF
  end
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_211_73X", "number", function(v)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_APU_Bleed_Air_SW_VAL", "number", function(v)
  SetSwitchPosition(gSwitchApu, math.floor(v/10)+1)
end)

gSwitchApu = AddVerticalSwitch(gImgVertSwitch, 196, 399, true, false, true, cbSwitchApu)

---------------------- Bleed 2 switch -------------------------

local gSwitchBleed2

function cbSwitchBleed2(switch, dir)
  -- ORIGINAL PMDG CODE:
  -- if dir > 0 then
  --   msfs_event("ROTOR_BRAKE", 21201)
  -- else
  --   msfs_event("ROTOR_BRAKE", 21202)
  -- end
  
  -- iFly Conversion:
  if dir > 0 then
    msfs_variable_write("L:VC_Engine_2_Bleed_Air_SW_VAL", "number", 10) -- ON
  else
    msfs_variable_write("L:VC_Engine_2_Bleed_Air_SW_VAL", "number", 0) -- OFF
  end
end

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_212_73X", "number", function(v)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_Engine_2_Bleed_Air_SW_VAL", "number", function(v)
  SetSwitchPosition(gSwitchBleed2, math.floor(v/10)+1)
end)

gSwitchBleed2 = AddVerticalSwitch(gImgVertSwitch, 357, 399, true, false, true, cbSwitchBleed2)

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


-- -- -- -- =========================== Duct pressure gauge =======================

local gImgLeftNeedle, gImgRightNeedle

gImgRightNeedle = img_add("needle-right.png", 190, 90, 20, 76)
gImgLeftNeedle = img_add("needle-left.png", 190, 90, 20, 76)

img_add("needle-base.png", 190, 116, 20, 20)

-- ORIGINAL PMDG CODE:
-- msfs_variable_subscribe("L:switch_197_73X", "number", function(v)
--   img_rotate(gImgLeftNeedle, v/10 /80*246+146) 
-- end)

-- msfs_variable_subscribe("L:switch_198_73X", "number", function(v)
--   img_rotate(gImgRightNeedle, v/10 /80*246+146)
-- end)

-- iFly Conversion:
msfs_variable_subscribe("L:VC_AIRSYSTEM_DUCT_PRESSURE_L_VAL", "number", function(v)
  img_rotate(gImgLeftNeedle, v/10 /80*246+146) 
end)

msfs_variable_subscribe("L:VC_AIRSYSTEM_DUCT_PRESSURE_R_VAL", "number", function(v)
  img_rotate(gImgRightNeedle, v/10 /80*246+146)
end)


---------------------------- Overheat test button -----------------

img_add("test-button-pressed.png", 340, 92, 25, 25)
gImgButtonOverheatTestReleased = img_add("test-button-released.png", 340, 92, 25, 25)

function cbButtonOverheatTestPressed()
  visible(gImgButtonOverheatTestReleased, false)
  -- ORIGINAL PMDG CODE:
  -- msfs_event("ROTOR_BRAKE", 19901)
  
  -- iFly Conversion:
  msfs_variable_write("L:VC_AIRSYSTEM_OVHT_TEST_SW_VAL", "number", 10)
end

function cbButtonOverheatTestReleased()
  visible(gImgButtonOverheatTestReleased, true)
end

button_add(nil, nil, 338, 90, 30, 30, cbButtonOverheatTestPressed, cbButtonOverheatTestReleased)

---------------------------- Trip reset button -----------------

img_add("test-button-pressed.png", 187, 332, 25, 25)
gImgButtonTripResetReleased = img_add("test-button-released.png", 187, 332, 25, 25)

function cbButtonTripResetPressed()
  visible(gImgButtonTripResetReleased, false)
  -- ORIGINAL PMDG CODE:
  -- msfs_event("ROTOR_BRAKE", 20901)
  
  -- iFly Conversion:
  msfs_variable_write("L:VC_AIRSYSTEM_TRIP_RESET_SW_VAL", "number", 10)
end

function cbButtonTripResetReleased()
  visible(gImgButtonTripResetReleased, true)
end

button_add(nil, nil, 185, 330, 30, 30, cbButtonTripResetPressed, cbButtonTripResetReleased)


----------------------------- show switches, needed only in case the sim is not running

for k = 1,gSwitchCount do
  SetSwitchPosition(k, 1)
end

-- ======================= Dimm all, except lights ================

-- local gBlackMask2 = canvas_add(0, 0, 400, 550, function()
  -- _rect(0, 0, 400, 550)
  -- _fill("black")
-- end)
-- opacity(gBlackMask2, 0)



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

ControlIllumination(DrawAllCanvas, gNightMask, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)


