-- Detlef von Reusner
-- PMDG B737-700 Overhead Panel - Flight Control
-- FS2020

-- Dec 2 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 20 2022: Initial version
-- Dec 2 2022: Illumination updated



img_add_fullscreen("bg.png")

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 560, function()
  _rect(0, 0, 400, 560)
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

-- ====================== Texts =================

local gFontPrintBig = "font:roboto_bold.ttf; size:24"
local gFontPrintSmall = "font:roboto_bold.ttf; size:20"
local gFontPrintTiny = "font:roboto_bold.ttf; size:18"


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

-- commented out: uncomment if bigger texts are needed
-- function DrawAllTexts()
  -- local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  -- PrintText("FLT CONTROL",  62, 7,  style, 24, false)
  -- PrintText("STANDBY HYD",  235, 7,  style, 24, false)

  -- PrintText("A",  71, 25,  style, 24, false)
  -- PrintText("B",  148, 25,  style, 24, false)

  -- PrintText("ALTERNATE FLAPS",  222, 188,  style, 24, false)
  -- PrintText("SPOILER",  80, 228,  style, 24, false)
  
  -- PrintText("A",  77, 246,  style, 24, false)
  -- PrintText("B",  143, 246,  style, 24, false)
  
  -- PrintText("YAW DAMPER",  56, 383,  style, 24, false)


  -- style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  -- PrintText("STBY", 9, 57, style, 20, false)
  -- PrintText("RUD", 9, 74, style, 20, false)
  -- PrintText("STBY", 199, 57, style, 20, false)
  -- PrintText("RUD", 205, 74, style, 20, false)
  
  -- PrintText("OFF", 16, 94, style, 20, false)
  -- PrintText("A ON", 11, 117, style, 20, false)
  
  -- PrintText("OFF", 200, 94, style, 20, false)
  -- PrintText("B ON", 200, 117, style, 20, false)
  
  -- PrintText("OFF", 276, 241, style, 20, false)
  -- PrintText("ARM", 274, 267, style, 20, false)
  
  -- PrintText("UP", 351, 210, style, 20, false)
  -- PrintText("OFF", 362, 238, style, 20, false)
  -- PrintText("DOWN", 323, 271, style, 20, false)
  
  -- PrintText("OFF", 17, 307, style, 20, false)
  -- PrintText("ON", 17, 331, style, 20, false)
  
  -- PrintText("OFF", 188, 307, style, 20, false)
  -- PrintText("ON", 188, 331, style, 20, false)
  
  -- PrintText("OFF", 63, 477, style, 20, false)
  -- PrintText("ON", 69, 526, style, 20, false)
-- end

function DrawAllTexts()
  local style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  PrintText("FLT CONTROL",  62, 7,  style, 24, false)

  PrintText("A",  71, 25,  style, 24, false)
  PrintText("B",  148, 25,  style, 24, false)

  PrintText("SPOILER",  80, 228,  style, 24, false)
  
  PrintText("A",  77, 246,  style, 24, false)
  PrintText("B",  143, 246,  style, 24, false)
  


  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("STANDBY HYD",  255, 9,  style, 20, false)

  PrintText("ALTERNATE FLAPS",  232, 188,  style, 20, false)
  
  
  PrintText("YAW DAMPER",  64, 387,  style, 20, false)

  style = gFontPrintTiny..";color:"..gColorPrint.."; halign:left"
  
  PrintText("STBY", 11, 57, style, 18, false)
  PrintText("RUD", 18, 72, style, 18, false)
  PrintText("STBY", 199, 57, style, 18, false)
  PrintText("RUD", 199, 72, style, 18, false)
  
  PrintText("OFF", 19, 94, style, 18, false)
  PrintText("A ON", 14, 117, style, 18, false)
  
  PrintText("OFF", 200, 94, style, 18, false)
  PrintText("B ON", 200, 117, style, 18, false)
  
  PrintText("OFF", 276, 241, style, 18, false)
  PrintText("ARM", 276, 269, style, 20, false)
  
  PrintText("UP", 326, 205, style, 18, false)
  PrintText("OFF", 362, 237, style, 18, false)
  PrintText("DOWN", 318, 268, style, 18, false)
  
  PrintText("OFF", 20, 305, style, 18, false)
  PrintText("ON", 25, 331, style, 18, false)
  
  PrintText("OFF", 185, 305, style, 18, false)
  PrintText("ON", 185, 331, style, 18, false)

  PrintText("OFF", 65, 477, style, 20, false)
  PrintText("ON", 71, 526, style, 20, false)
end


local gImgTexts = canvas_add(0, 0, 400, 560, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 560)

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
  s.no_head = true -- needed to not interfere with new switch illumination
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

  img = "vert-black-cover-closed.png"
  s.img_closed = img_add(img, x, y, w, h)
  visible(s.img_closed, true)
  
  s.closed = true
  s.pos = nil
  return gSwitchCount
end

function AddRedVerGuardSwitch(x, y, p1, p2, p3, cb_switch, cb_guard)
  -- different rotation

  gSwitchCount = gSwitchCount+1
  gSwitch[gSwitchCount] = {}
  local s = gSwitch[gSwitchCount]

  local x_touch, y_touch, w_touch, h_touch
  local img, meta, w, h, dx, dy -- dx, dy offset for switch
  dx = 20
  dy = 38
  
  img = "vert-open-guard-red.png"
  meta = resource_info(img)
  s.no_head = true -- needed to not interfere with new switch illumination
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
    button_add(gTouchField, nil, x_touch, y_touch, w_touch, h_touch, function() cb_guard(n, 1) end, nil) -- 1
    button_add(gTouchField, nil, x_touch, y+3*(h_touch+1), w_touch, h_touch, function() cb_guard(n, -1) end, nil) -- 4
    button_add(gTouchField, nil, x_touch, y+h_touch+1, w_touch, h_touch, function() cb_switch(n, -1) end, nil) -- 2
    button_add(gTouchField, nil, x_touch, y+2*(h_touch+1), w_touch, h_touch, function() cb_switch(n, 1) end, nil) -- 3
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

  img = "vert-closed-guard-red.png"
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

function CloseGuard(switch, yes)
  local s = gSwitch[switch]
  visible(s.img_closed, yes)
  visible(s.img_open, not yes)
  s.closed = yes
end
-- ====================== operate switches ==================

------------------ Flight control A switch with guard cover ---------------------------
local gSwitchFlightControlA
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFlightControlA(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 7901) -- open cover with any button
--     return
--   end
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 7801)
--   else
--     msfs_event("ROTOR_BRAKE", 7802)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentFlightControlAPosition = 10 -- Default to middle position (10)
function cbSwitchFlightControlA(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    -- Open cover
    fs2020_variable_write("L:VC_Flight_Control_A_SW_Cover_VAL", "number", 10)
    return
  end
  if dir>0 then
    currentFlightControlAPosition = math.min(currentFlightControlAPosition + 10, 20)
  else
    currentFlightControlAPosition = math.max(currentFlightControlAPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Flight_Control_A_SW_VAL", "number", currentFlightControlAPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_78_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFlightControlA, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Flight_Control_A_SW_VAL", "number", function(v)
  currentFlightControlAPosition = v
  SetSwitchPosition(gSwitchFlightControlA, math.floor(v/10)+1)
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbGuardFlightControlA(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 7801) -- incr switch with cover open button
--     return
--   end
--   -- msfs_event("ROTOR_BRAKE", 1301)
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 7901)
--   else
--     msfs_event("ROTOR_BRAKE", 7902)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbGuardFlightControlA(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    -- Increment switch when cover is open
    currentFlightControlAPosition = math.min(currentFlightControlAPosition + 10, 20)
    fs2020_variable_write("L:VC_Flight_Control_A_SW_VAL", "number", currentFlightControlAPosition)
    return
  end
  -- Toggle guard cover
  if dir>0 then
    fs2020_variable_write("L:VC_Flight_Control_A_SW_Cover_VAL", "number", 10) -- Open
  else
    fs2020_variable_write("L:VC_Flight_Control_A_SW_Cover_VAL", "number", 0)  -- Close
  end
end

gSwitchFlightControlA = AddBlackVerGuardSwitch(54, 38, true, true, true, cbSwitchFlightControlA, cbGuardFlightControlA)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_79_73X", "number", function(v)
--   CloseGuard(gSwitchFlightControlA, v==0)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Flight_Control_A_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchFlightControlA, v==0)
end)

------------------ Flight control B switch with guard cover ---------------------------
local gSwitchFlightControlB
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFlightControlB(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 8101) -- open cover with any button
--     return
--   end
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 8001)
--   else
--     msfs_event("ROTOR_BRAKE", 8002)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentFlightControlBPosition = 10 -- Default to middle position (10)
function cbSwitchFlightControlB(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    -- Open cover
    fs2020_variable_write("L:VC_Flight_Control_B_SW_Cover_VAL", "number", 10)
    return
  end
  if dir>0 then
    currentFlightControlBPosition = math.min(currentFlightControlBPosition + 10, 20)
  else
    currentFlightControlBPosition = math.max(currentFlightControlBPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Flight_Control_B_SW_VAL", "number", currentFlightControlBPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_80_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFlightControlB, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Flight_Control_B_SW_VAL", "number", function(v)
  currentFlightControlBPosition = v
  SetSwitchPosition(gSwitchFlightControlB, math.floor(v/10)+1)
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbGuardFlightControlB(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 8001) -- incr switch with cover open button
--     return
--   end
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 8101)
--   else
--     msfs_event("ROTOR_BRAKE", 8102)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbGuardFlightControlB(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    -- Increment switch when cover is open
    currentFlightControlBPosition = math.min(currentFlightControlBPosition + 10, 20)
    fs2020_variable_write("L:VC_Flight_Control_B_SW_VAL", "number", currentFlightControlBPosition)
    return
  end
  -- Toggle guard cover
  if dir>0 then
    fs2020_variable_write("L:VC_Flight_Control_B_SW_Cover_VAL", "number", 10) -- Open
  else
    fs2020_variable_write("L:VC_Flight_Control_B_SW_Cover_VAL", "number", 0)  -- Close
  end
end

gSwitchFlightControlB = AddBlackVerGuardSwitch(133, 38, true, true, true, cbSwitchFlightControlB, cbGuardFlightControlB)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_81_73X", "number", function(v)
--   CloseGuard(gSwitchFlightControlB, v==0)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Flight_Control_B_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchFlightControlB, v==0)
end)

------------------ Spoiler A switch with guard cover ---------------------------
local gSwitchSpoilerA
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchSpoilerA(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 6601) -- open cover with any button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 6501)
--   -- if dir>0 then
--     -- msfs_event("ROTOR_BRAKE", 8001)
--   -- else
--     -- msfs_event("ROTOR_BRAKE", 8002)
--   -- end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentSpoilerAPosition = 10 -- Default to middle position (10)
function cbSwitchSpoilerA(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    -- Open cover
    fs2020_variable_write("L:VC_Spoiler_A_SW_Cover_VAL", "number", 10)
    return
  end
  -- Toggle spoiler A position
  if currentSpoilerAPosition == 10 then
    currentSpoilerAPosition = 20 -- ARM
  else
    currentSpoilerAPosition = 10 -- OFF
  end
  fs2020_variable_write("L:VC_Spoiler_A_SW_VAL", "number", currentSpoilerAPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_65_73X", "number", function(v)
--   SetSwitchPosition(gSwitchSpoilerA, math.floor(v/100)+2)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Spoiler_A_SW_VAL", "number", function(v)
  currentSpoilerAPosition = v
  SetSwitchPosition(gSwitchSpoilerA, math.floor(v/10)+1)
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbGuardSpoilerA(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 6501) -- incr switch with cover open button
--     return
--   end
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 6601)
--   else
--     msfs_event("ROTOR_BRAKE", 6602)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbGuardSpoilerA(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    -- Toggle spoiler when cover is open
    if currentSpoilerAPosition == 10 then
      currentSpoilerAPosition = 20 -- ARM
    else
      currentSpoilerAPosition = 10 -- OFF
    end
    fs2020_variable_write("L:VC_Spoiler_A_SW_VAL", "number", currentSpoilerAPosition)
    return
  end
  -- Toggle guard cover
  if dir>0 then
    fs2020_variable_write("L:VC_Spoiler_A_SW_Cover_VAL", "number", 10) -- Open
  else
    fs2020_variable_write("L:VC_Spoiler_A_SW_Cover_VAL", "number", 0)  -- Close
  end
end

gSwitchSpoilerA = AddBlackVerGuardSwitch(56, 254, false, true, true, cbSwitchSpoilerA, cbGuardSpoilerA)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_66_73X", "number", function(v)
--   CloseGuard(gSwitchSpoilerA, v==0)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Spoiler_A_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchSpoilerA, v==0)
end)

------------------ Spoiler B switch with guard cover ---------------------------
local gSwitchSpoilerB
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchSpoilerB(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 6801) -- open cover with any button
--     return
--   end
--   msfs_event("ROTOR_BRAKE", 6701)
--   -- if dir>0 then
--     -- msfs_event("ROTOR_BRAKE", 8001)
--   -- else
--     -- msfs_event("ROTOR_BRAKE", 8002)
--   -- end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentSpoilerBPosition = 10 -- Default to middle position (10)
function cbSwitchSpoilerB(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    -- Open cover
    fs2020_variable_write("L:VC_Spoiler_B_SW_Cover_VAL", "number", 10)
    return
  end
  -- Toggle spoiler B position
  if currentSpoilerBPosition == 10 then
    currentSpoilerBPosition = 20 -- ARM
  else
    currentSpoilerBPosition = 10 -- OFF
  end
  fs2020_variable_write("L:VC_Spoiler_B_SW_VAL", "number", currentSpoilerBPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_67_73X", "number", function(v)
--   SetSwitchPosition(gSwitchSpoilerB, math.floor(v/100)+2)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Spoiler_B_SW_VAL", "number", function(v)
  currentSpoilerBPosition = v
  SetSwitchPosition(gSwitchSpoilerB, math.floor(v/10)+1)
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbGuardSpoilerB(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 6701) -- incr switch with cover open button
--     return
--   end
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 6801)
--   else
--     msfs_event("ROTOR_BRAKE", 6802)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbGuardSpoilerB(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    -- Toggle spoiler when cover is open
    if currentSpoilerBPosition == 10 then
      currentSpoilerBPosition = 20 -- ARM
    else
      currentSpoilerBPosition = 10 -- OFF
    end
    fs2020_variable_write("L:VC_Spoiler_B_SW_VAL", "number", currentSpoilerBPosition)
    return
  end
  -- Toggle guard cover
  if dir>0 then
    fs2020_variable_write("L:VC_Spoiler_B_SW_Cover_VAL", "number", 10) -- Open
  else
    fs2020_variable_write("L:VC_Spoiler_B_SW_Cover_VAL", "number", 0)  -- Close
  end
end

gSwitchSpoilerB = AddBlackVerGuardSwitch(116, 254, false, true, true, cbSwitchSpoilerB, cbGuardSpoilerB)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_68_73X", "number", function(v)
--   CloseGuard(gSwitchSpoilerB, v==0)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Spoiler_B_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchSpoilerB, v==0)
end)

------------------ Alternate flaps master switch with guard cover ---------------------------
local gSwitchAlternateFlapsMaster
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchAlternateFlapsMaster(switch, dir)
--   local s = gSwitch[switch]
--   if s.closed then
--     msfs_event("ROTOR_BRAKE", 7401) -- open cover with any button
--     return
--   end
-- --  msfs_event("ROTOR_BRAKE", 7301)
--   if dir>0 then
--     msfs_event("ROTOR_BRAKE", 7301)
--   else
--     msfs_event("ROTOR_BRAKE", 7302)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentAlternateFlapsMasterPosition = 0 -- Default to OFF (0)
function cbSwitchAlternateFlapsMaster(switch, dir)
  local s = gSwitch[switch]
  if s.closed then
    -- Open cover
    fs2020_variable_write("L:VC_Altn_Flap_Master_SW_Cover_VAL", "number", 10)
    return
  end
  if dir>0 then
    currentAlternateFlapsMasterPosition = math.min(currentAlternateFlapsMasterPosition + 10, 20)
  else
    currentAlternateFlapsMasterPosition = math.max(currentAlternateFlapsMasterPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Altn_Flap_Master_SW_VAL", "number", currentAlternateFlapsMasterPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_73_73X", "number", function(v) SetSwitchPosition(gSwitchAlternateFlapsMaster, toint(math.floor(v/50)+1)) end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Altn_Flap_Master_SW_VAL", "number", function(v) 
  currentAlternateFlapsMasterPosition = v
  SetSwitchPosition(gSwitchAlternateFlapsMaster, toint(math.floor(v/10)+1)) 
end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbGuardAlternateFlapsMaster(switch, dir)
--   local s = gSwitch[switch]
--   if not s.closed and dir>0 then
--     msfs_event("ROTOR_BRAKE", 7301) -- incr switch with cover open button
--     return
--   end
--   if dir>1 then
--     msfs_event("ROTOR_BRAKE", 7401)
--   else
--     msfs_event("ROTOR_BRAKE", 7402)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
function cbGuardAlternateFlapsMaster(switch, dir)
  local s = gSwitch[switch]
  if not s.closed and dir>0 then
    -- Increment switch when cover is open
    currentAlternateFlapsMasterPosition = math.min(currentAlternateFlapsMasterPosition + 10, 20)
    fs2020_variable_write("L:VC_Altn_Flap_Master_SW_VAL", "number", currentAlternateFlapsMasterPosition)
    return
  end
  -- Toggle guard cover
  if dir>0 then
    fs2020_variable_write("L:VC_Altn_Flap_Master_SW_Cover_VAL", "number", 10) -- Open
  else
    fs2020_variable_write("L:VC_Altn_Flap_Master_SW_Cover_VAL", "number", 0)  -- Close
  end
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_74_73X", "number", function(v)
--   CloseGuard(gSwitchAlternateFlapsMaster, v==0)
--   -- if v==1 then SetSwitchPosition(gSwitchAlternateFlapsMaster, 1) end -- default position after opening the guard
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Altn_Flap_Master_SW_Cover_VAL", "number", function(v)
  CloseGuard(gSwitchAlternateFlapsMaster, v==0)
  -- if v==1 then SetSwitchPosition(gSwitchAlternateFlapsMaster, 1) end -- default position after opening the guard
end)

gSwitchAlternateFlapsMaster = AddRedVerGuardSwitch(215, 204, true, false, true, cbSwitchAlternateFlapsMaster, cbGuardAlternateFlapsMaster)

CloseGuard(gSwitchAlternateFlapsMaster, false)
-- request_callback(cbSimSwitchAlternateFlapsMaster)

---------------------- Alternate Flaps Up Down Switch ----------------
local gSwitchAlternateFlapsUpDown
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchAlternateFlapsUpDown(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 7501)
--     timer_start(300, 300, 1, function() msfs_event("ROTOR_BRAKE", 7504) end)
--   else
--     msfs_event("ROTOR_BRAKE", 7502)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentAlternateFlapsUpDownPosition = 10 -- Default to middle position (10)
function cbSwitchAlternateFlapsUpDown(switch, dir)
  if dir > 0 then
    currentAlternateFlapsUpDownPosition = math.min(currentAlternateFlapsUpDownPosition + 10, 20)
    fs2020_variable_write("L:VC_Altn_Flap_SW_VAL", "number", currentAlternateFlapsUpDownPosition)
    -- Auto-return to center after 300ms
    timer_start(300, 300, 1, function() 
      currentAlternateFlapsUpDownPosition = 10
      fs2020_variable_write("L:VC_Altn_Flap_SW_VAL", "number", currentAlternateFlapsUpDownPosition)
    end)
  else
    currentAlternateFlapsUpDownPosition = math.max(currentAlternateFlapsUpDownPosition - 10, 0)
    fs2020_variable_write("L:VC_Altn_Flap_SW_VAL", "number", currentAlternateFlapsUpDownPosition)
  end
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_75_73X", "number", function(v)
--   SetSwitchPosition(gSwitchAlternateFlapsUpDown, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Altn_Flap_SW_VAL", "number", function(v)
  currentAlternateFlapsUpDownPosition = v
  SetSwitchPosition(gSwitchAlternateFlapsUpDown, math.floor(v/10)+1)
end)

gSwitchAlternateFlapsUpDown = AddVerticalSwitch(gImgVertSwitch, 361, 203, true, true, true, cbSwitchAlternateFlapsUpDown)

---------------------- Yaw Damper Switch ----------------
local gSwitchYawDamper
-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchYawDamper(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 6301)
--   else
--     msfs_event("ROTOR_BRAKE", 6302)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentYawDamperPosition = 10 -- Default to ON (10)
function cbSwitchYawDamper(switch, dir)
  if dir > 0 then
    currentYawDamperPosition = math.min(currentYawDamperPosition + 10, 10) -- Only OFF and ON positions
  else
    currentYawDamperPosition = math.max(currentYawDamperPosition - 10, 0)
  end
  fs2020_variable_write("L:VC_Yaw_Damper_SW_VAL", "number", currentYawDamperPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_63_73X", "number", function(v)
--   SetSwitchPosition(gSwitchYawDamper, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
fs2020_variable_subscribe("L:VC_Yaw_Damper_SW_VAL", "number", function(v)
  currentYawDamperPosition = v
  SetSwitchPosition(gSwitchYawDamper, math.floor(v/10)+1)
end)

gSwitchYawDamper = AddVerticalSwitch(gImgVertSwitch, 139, 468, true, false, true, cbSwitchYawDamper)

-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 560, function()
  _rect(0, 0, 400, 560)
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

-- Original PMDG AddLight calls:
-- AddLight("L:switch_84_73X", "light-amber-1.png", 272, 32, "LOW", "QUANTITY")
-- AddLight("L:switch_83_73X", "light-amber-2.png", 272, 83, "LOW", "PRESSURE")
-- AddLight("L:switch_82_73X", "light-amber-3.png", 272, 134, "STBY", "RUD ON")
-- AddLight("L:switch_76_73X", "light-amber-4.png", 35, 174, "LOW", "PRESSURE")
-- AddLight("L:switch_77_73X", "light-amber-2.png", 121, 174, "LOW", "PRESSURE")
-- AddLight("L:switch_72_73X", "light-amber-3.png", 272, 328, "FEEL", "DIFF PRESS")
-- AddLight("L:switch_71_73X", "light-amber-1.png", 272, 379, "SPEED TRIM", "FAIL")
-- AddLight("L:switch_70_73X", "light-amber-4.png", 272, 430, "MACH", "TRIM FAIL")
-- AddLight("L:switch_69_73X", "light-amber-3.png", 272, 481, "AUTO", "SLAT FAIL")
-- AddLight("L:switch_64_73X", "light-amber-2.png", 71, 409, "YAW", "DAMPER")

-- iFly 737 MAX 8 Converted AddLight calls:
AddLight("L:VC_FLTCTRL_LIGHT_STBY_HYD_LOW_QUANTITY_LIGHT_VAL", "light-amber-1.png", 272, 32, "LOW", "QUANTITY")
AddLight("L:VC_FLTCTRL_LIGHT_STBY_HYD_LOW_PRESSURE_LIGHT_VAL", "light-amber-2.png", 272, 83, "LOW", "PRESSURE")
AddLight("L:VC_FLTCTRL_LIGHT_STBY_RUD_ON_LIGHT_VAL", "light-amber-3.png", 272, 134, "STBY", "RUD ON")
AddLight("L:VC_FLTCTRL_LIGHT_FLT_CTL_A_LOW_PRESSURE_LIGHT_VAL", "light-amber-4.png", 35, 174, "LOW", "PRESSURE")
AddLight("L:VC_FLTCTRL_LIGHT_FLT_CTL_B_LOW_PRESSURE_LIGHT_VAL", "light-amber-2.png", 121, 174, "LOW", "PRESSURE")
AddLight("L:VC_FLTCTRL_LIGHT_FEEL_DIFF_PRESS_LIGHT_VAL", "light-amber-3.png", 272, 328, "FEEL", "DIFF PRESS")
AddLight("L:VC_FLTCTRL_LIGHT_SPEED_TRIM_FAIL_LIGHT_VAL", "light-amber-1.png", 272, 379, "SPEED TRIM", "FAIL")
AddLight("L:VC_FLTCTRL_LIGHT_MACH_TRIM_FAIL_LIGHT_VAL", "light-amber-4.png", 272, 430, "MACH", "TRIM FAIL")
AddLight("L:VC_FLTCTRL_LIGHT_AUTO_SLAT_FAIL_LIGHT_VAL", "light-amber-3.png", 272, 481, "AUTO", "SLAT FAIL")
AddLight("L:VC_FLTCTRL_LIGHT_YAW_DAMPER_LIGHT_VAL", "light-amber-2.png", 71, 409, "YAW", "DAMPER")

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
  -- canvas_draw(gImgLines, DrawAllLines)
  canvas_draw(gImgTexts, DrawAllTexts)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  DrawSwitches()
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)
