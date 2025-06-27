-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Exterior Light Switches Left
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

-------------------------
local gNightColor

if gPropCorner=="Cut" then
  img_add_fullscreen("bg-cut.png")
  gNightColor = img_add_fullscreen("night-color-cut.png")
else
  img_add_fullscreen("bg.png")
  gNightColor = img_add_fullscreen("night-color.png")
end

-- =============================== switch lib functions ====================

local gColorPrint = "#E0E0E0FF"
local gColorBg = "#101010FF"
local gSwitchColorHi = "#f0f0f0ff"
local gSwitchColorLo = "#b8b8b8ff"

local gFontLight = "font:arimo_bold.ttf; size:14"


local gDebugShowTouchFields = false

local gTouchField
if gDebugShowTouchFields then
   gTouchField = "touch-field-on.png"
else
   gTouchField = nil
end


local gSwitch = {}
local gSwitchCount = 0
local gImgLandingSwitch = {"switch-landing-light-up.png", "switch-landing-light-mid.png", "switch-landing-light-down.png", }

local gImgVertSwitch = {"switch-up-pin.png", "switch-middle-pin.png", "switch-down-pin.png"}

function ShowTouchField(x, y, w, h)
  if not gDebugShowTouchFields then return end
  canvas_add(x, y, w, h, function()
    _rect(0, 0, w, h)
    _fill("#FF000020")
  end)
end

function AddVerticalSwitch(switch_image, x, y, p1, p2, p3, call_back, no_head)
  -- e.g.:  if p1, p2 and p3 are true, this switch has all three positions
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
  s.no_head = no_head
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
  
  if not s.no_head and (s.img.head[1]==nil) then return end -- not yet initialized

  visible(s.img.pin[target], true)
  if not s.no_head then visible(s.img.head[target], true) end
  if s.pos~=nil and s.pos~=target  then
    visible(s.img.pin[s.pos], false)
    if not s.no_head then visible(s.img.head[s.pos], false) end
  end
  s.pos = target
end

-- ====================== operate switches ==================

---------------------- RUNWAY TURNOFF LIGHT LEFT Switch ----------------

local gSwitchRunwayTurnoffLightLeft

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchRunwayTurnoffLightLeft(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 11501)
--   else
--     msfs_event("ROTOR_BRAKE", 11502)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentRunwayTurnoffLeftPosition = 0 -- Default to OFF (0)
function cbSwitchRunwayTurnoffLightLeft(switch, dir)
  if dir > 0 then
    currentRunwayTurnoffLeftPosition = math.min(currentRunwayTurnoffLeftPosition + 10, 10) -- Only OFF and ON positions
  else
    currentRunwayTurnoffLeftPosition = math.max(currentRunwayTurnoffLeftPosition - 10, 0)
  end
  msfs_variable_write("L:VC_Runway_Turnoff_Light_L_SW_VAL", "number", currentRunwayTurnoffLeftPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_115_73X", "number", function(v)
--   SetSwitchPosition(gSwitchRunwayTurnoffLightLeft, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Runway_Turnoff_Light_L_SW_VAL", "number", function(v)
  currentRunwayTurnoffLeftPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchRunwayTurnoffLightLeft, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchRunwayTurnoffLightLeft, 3) -- ON position
  end
end)

gSwitchRunwayTurnoffLightLeft = AddVerticalSwitch(gImgVertSwitch, 341, 29, true, false, true, cbSwitchRunwayTurnoffLightLeft)

---------------------- RUNWAY TURNOFF LIGHT RIGHT Switch ----------------

local gSwitchRunwayTurnoffLightRight

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchRunwayTurnoffLightRight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 11601)
--   else
--     msfs_event("ROTOR_BRAKE", 11602)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentRunwayTurnoffRightPosition = 0 -- Default to OFF (0)
function cbSwitchRunwayTurnoffLightRight(switch, dir)
  if dir > 0 then
    currentRunwayTurnoffRightPosition = math.min(currentRunwayTurnoffRightPosition + 10, 10) -- Only OFF and ON positions
  else
    currentRunwayTurnoffRightPosition = math.max(currentRunwayTurnoffRightPosition - 10, 0)
  end
  msfs_variable_write("L:VC_Runway_Turnoff_Light_R_SW_VAL", "number", currentRunwayTurnoffRightPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_116_73X", "number", function(v)
--   SetSwitchPosition(gSwitchRunwayTurnoffLightRight, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Runway_Turnoff_Light_R_SW_VAL", "number", function(v)
  currentRunwayTurnoffRightPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchRunwayTurnoffLightRight, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchRunwayTurnoffLightRight, 3) -- ON position
  end
end)

gSwitchRunwayTurnoffLightRight = AddVerticalSwitch(gImgVertSwitch, 419, 29, true, false, true, cbSwitchRunwayTurnoffLightRight)

---------------------- TAXI LIGHT Switch ----------------

local gSwitchTaxiLight

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchTaxiLight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 11701)
--     msfs_event("PMDGNG3:EVT_CONTROL_STAND_ENG1_START_LEVER",1)
--   else
--     msfs_event("ROTOR_BRAKE", 11702)
--     msfs_event("PMDGNG3:EVT_CONTROL_STAND_ENG1_START_LEVER",1)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentTaxiLightPosition = 0 -- Default to OFF (0)
function cbSwitchTaxiLight(switch, dir)
  if dir > 0 then
    currentTaxiLightPosition = math.min(currentTaxiLightPosition + 10, 10) -- Only OFF and ON positions
  else
    currentTaxiLightPosition = math.max(currentTaxiLightPosition - 10, 0)
  end
  msfs_variable_write("L:VC_Taxi_Light_SW_VAL", "number", currentTaxiLightPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_117_73X", "number", function(v)
--   SetSwitchPosition(gSwitchTaxiLight, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Taxi_Light_SW_VAL", "number", function(v)
  currentTaxiLightPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchTaxiLight, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchTaxiLight, 3) -- ON position
  end
end)

gSwitchTaxiLight = AddVerticalSwitch(gImgVertSwitch, 497, 29, true, false, true, cbSwitchTaxiLight)


---------------------- FIXED LANDING LIGHT LEFT Switch ----------------

local gSwitchFixedLandingLightLeft

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFixedLandingLightLeft(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 11301)
--   else
--     msfs_event("ROTOR_BRAKE", 11302)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentLandingLightLeftPosition = 0 -- Default to OFF (0)
function cbSwitchFixedLandingLightLeft(switch, dir)
  if dir > 0 then
    currentLandingLightLeftPosition = math.min(currentLandingLightLeftPosition + 10, 10) -- Only OFF and ON positions
  else
    currentLandingLightLeftPosition = math.max(currentLandingLightLeftPosition - 10, 0)
  end
  msfs_variable_write("L:VC_Landing_Light_1_SW_VAL", "number", currentLandingLightLeftPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_113_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFixedLandingLightLeft, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Landing_Light_1_SW_VAL", "number", function(v)
  currentLandingLightLeftPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchFixedLandingLightLeft, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchFixedLandingLightLeft, 3) -- ON position
  end
end)

gSwitchFixedLandingLightLeft = AddVerticalSwitch(gImgLandingSwitch, 131, 44, true, false, true, cbSwitchFixedLandingLightLeft, true)

---------------------- FIXED LANDING LIGHT RIGHT Switch ----------------

local gSwitchFixedLandingLightRight

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbSwitchFixedLandingLightRight(switch, dir)
--   if dir > 0 then
--     msfs_event("ROTOR_BRAKE", 11401)
--   else
--     msfs_event("ROTOR_BRAKE", 11402)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentLandingLightRightPosition = 0 -- Default to OFF (0)
function cbSwitchFixedLandingLightRight(switch, dir)
  if dir > 0 then
    currentLandingLightRightPosition = math.min(currentLandingLightRightPosition + 10, 10) -- Only OFF and ON positions
  else
    currentLandingLightRightPosition = math.max(currentLandingLightRightPosition - 10, 0)
  end
  msfs_variable_write("L:VC_Landing_Light_2_SW_VAL", "number", currentLandingLightRightPosition)
end

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- msfs_variable_subscribe("L:switch_114_73X", "number", function(v)
--   SetSwitchPosition(gSwitchFixedLandingLightRight, math.floor(v/50)+1)
-- end)

-- ================ CONVERTED iFLY CODE ================
msfs_variable_subscribe("L:VC_Landing_Light_2_SW_VAL", "number", function(v)
  currentLandingLightRightPosition = v
  if v == 0 then
    SetSwitchPosition(gSwitchFixedLandingLightRight, 1) -- OFF position
  else
    SetSwitchPosition(gSwitchFixedLandingLightRight, 3) -- ON position
  end
end)

gSwitchFixedLandingLightRight = AddVerticalSwitch(gImgLandingSwitch, 211, 44, true, false, true, cbSwitchFixedLandingLightRight, true)

-----------------------

opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 600, 150, function()
  _rect(0, 0, 600, 150)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense


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

  PrintText("LANDING", 167, 8, style, 24, false)
  PrintText("RUNWAY", 384, 2, style, 24, false)
  PrintText("TURNOFF", 383, 21, style, 24, false)
  PrintText("L", 383, 41, style, 24, false)
  PrintText("R", 459, 41, style, 24, false)
  PrintText("TAXI", 519, 8, style, 24, false) 

  PrintText("L", 163, 126, style, 24, false)
  PrintText("R", 245, 126, style, 24, false)

  style = gFontPrintSmall..";color:"..gColorPrint

  PrintText("OFF", 193, 28, style, 18, false)
  PrintText("ON", 198, 125, style, 18, false)

  PrintText("OFF", 415, 54, style, 18, false)
  PrintText("ON", 418, 110, style, 18, false)

  PrintText("OFF", 493, 54, style, 18, false)
  PrintText("ON", 498, 110, style, 18, false)
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
