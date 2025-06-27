---------------------------------------
-- Detlef von Reusner
-- APU and Engine Start Switches for PMDG B737-700
-- FS2020

-- V 1.01

-- For PMDG B737-700 FS2020
-- Illumination options per user properties: Day,Night,Real,Dial.   Default is "Real".
-- - Dial means, illumination controlled per background and floodlight dials on the left forward electronic panel.
-- - Real means, you must install the Generic Ambient Light Dimmer instrument. Daylight is real then and night illumination
--   depends on the dome white switch on the aft overhead panel. You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".

-- History:
-- Jun 27 2022: initial Version
-- Sep 27 2022: Illumination modes added


img_add_fullscreen("bg.png")

local gPropIllumination = user_prop_get(user_prop_add_enum("Illumination","Day,Night,Real,Dial","Real","Select illumination"))

local gImgSwitch = img_add("switch.png", 157, 52, 50, 50) -- until y == 92

img_add("rotary-base.png", 29, 43, 70, 70)
local gImgEngStartLeftSwitch = img_add("rotary-switch.png", 29, 43, 70, 70)

img_add("rotary-base.png", 279, 43, 70, 70)
local gImgEngStartRightSwitch = img_add("rotary-switch.png", 279, 43, 70, 70)

EVENT_PMDG_B737_FUELON = 11688
EVENT_PMDG_B737_APU_START_ON = 11801
EVENT_PMDG_B737_APU_START_OFF = 11802
EVENT_PMDG_B737_ELECTRICAL_APU_GEN1_OFF = 2802
EVENT_PMDG_B737_ELECTRICAL_APU_GEN2_OFF = 2902

EVENT_PMDG_B737_ENGINE_START_LEFT_DEC = 11908
EVENT_PMDG_B737_ENGINE_START_LEFT_INC = 11907
EVENT_PMDG_B737_ENGINE_START_RIGHT_DEC = 12108
EVENT_PMDG_B737_ENGINE_START_RIGHT_INC = 12107

---------------

local gNightColor = img_add_fullscreen("night-color.png")

--------------- 

opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 500, 150, function()
  _rect(0, 0, 400, 150)
  _fill("black")
end)
opacity(gBlackMask, 0.) -- 0 == full brightness, .9 == darkest value that makes sense


local gDaylight
local gScalesLight

-------------- APU Start Switch ----------------
-- ORIGINAL PMDG CODE:
-- local gAPUvalue = 0
-- function cbSetAPUSwitch(v)
-- -- 0 off, 50 on, 70 start jumped back, 85 start
--   gAPUvalue = v
--   if v>70 then
--     img_move(gImgSwitch, 157, 52 + 40)
--   else
--     img_move(gImgSwitch, 157, 52 + (40*v/100))
--   end
-- end
-- msfs_variable_subscribe("L:switch_118_73X", "Number", cbSetAPUSwitch)
-- function cbDown()
--   if gAPUvalue < 50 then
--     msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_APU_START_ON)
--   else
--     msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_APU_START_ON)
--   end
-- end
-- function cbUp()
--   msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_APU_START_OFF)
-- end

-- iFly Conversion:
local gAPUvalue = 0

function cbSetAPUSwitch(v)
-- iFly: 0=OFF, 10=ON, 20=START
  gAPUvalue = v
  if v >= 20 then
    img_move(gImgSwitch, 157, 52 + 40) -- START position
  else
    img_move(gImgSwitch, 157, 52 + (40*v/20)) -- Scale to 0-40 pixels
  end
end

msfs_variable_subscribe("L:VC_APU_SW_VAL", "number", cbSetAPUSwitch)

function cbDown()
  if gAPUvalue == 0 then
    msfs_variable_write("L:VC_APU_SW_VAL", "number", 10) -- Set to ON
  else
    msfs_variable_write("L:VC_APU_SW_VAL", "number", 20) -- Set to START
  end
end

function cbUp()
  msfs_variable_write("L:VC_APU_SW_VAL", "number", 0) -- Set to OFF
end

--button_add("button-visible.png", nil, 143, 105, 111, 40, cbDown, nil)
button_add(nil, nil, 143, 105, 111, 40, cbDown, nil)


--button_add("button-visible.png", nil, 143, 33, 111, 40, cbUp, nil)
button_add(nil, nil, 143, 33, 111, 40, cbUp, nil)
------------ Engine Start Switches ----------------------
-- ORIGINAL PMDG CODE:
-- local gEngLeftValue
-- local gEngRightValue
-- function cbTurnEngineStartSwitchLeft(rotac)
--   if rotac>0 then
--     msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_ENGINE_START_LEFT_INC)
--   else
--     msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_ENGINE_START_LEFT_DEC)
--   end
-- end
-- function cbSetEngineStartSwitchLeft(v)
-- -- 0 GRD, 10 OFF, 20 CONT, 30 FLT
--   gEngLeftValue = v
--   rotate(gImgEngStartLeftSwitch, v*3-30)
-- end
-- msfs_variable_subscribe("L:switch_119_73X", "Number", cbSetEngineStartSwitchLeft)

-- iFly Conversion:
local gEngLeftValue = 10 -- Default to OFF position
local gEngRightValue = 10 -- Default to OFF position

function cbTurnEngineStartSwitchLeft(rotac)
  local currentPos = gEngLeftValue
  if rotac > 0 then
    currentPos = math.min(currentPos + 10, 30) -- Max is FLT (30)
  else
    currentPos = math.max(currentPos - 10, 0) -- Min is GRD (0)
  end
  msfs_variable_write("L:VC_Engine_1_Start_SW_VAL", "number", currentPos)
end

function cbSetEngineStartSwitchLeft(v)
-- iFly: 0=GRD, 10=OFF, 20=CONT, 30=FLT
  gEngLeftValue = v
  rotate(gImgEngStartLeftSwitch, v*3-30) -- Same rotation logic as original
end

msfs_variable_subscribe("L:VC_Engine_1_Start_SW_VAL", "number", cbSetEngineStartSwitchLeft)

dial_add(nil, 30, 45, 70, 70, cbTurnEngineStartSwitchLeft)

-- ORIGINAL PMDG CODE:
-- function cbTurnEngineStartSwitchRight(rotac)
--   if rotac>0 then
--     msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_ENGINE_START_RIGHT_INC)
--   else
--     msfs_event("K:ROTOR_BRAKE", EVENT_PMDG_B737_ENGINE_START_RIGHT_DEC)
--   end
-- end
-- function cbSetEngineStartSwitchRight(v)
-- -- 0 GRD, 10 OFF, 20 CONT, 30 FLT
--   gEngRightValue = v
--   rotate(gImgEngStartRightSwitch, v*3-30)
-- end
-- msfs_variable_subscribe("L:switch_121_73X", "Number", cbSetEngineStartSwitchRight)

-- iFly Conversion:
function cbTurnEngineStartSwitchRight(rotac)
  local currentPos = gEngRightValue
  if rotac > 0 then
    currentPos = math.min(currentPos + 10, 30) -- Max is FLT (30)
  else
    currentPos = math.max(currentPos - 10, 0) -- Min is GRD (0)
  end
  msfs_variable_write("L:VC_Engine_2_Start_SW_VAL", "number", currentPos)
end

function cbSetEngineStartSwitchRight(v)
-- iFly: 0=GRD, 10=OFF, 20=CONT, 30=FLT
  gEngRightValue = v
  rotate(gImgEngStartRightSwitch, v*3-30) -- Same rotation logic as original
end

msfs_variable_subscribe("L:VC_Engine_2_Start_SW_VAL", "number", cbSetEngineStartSwitchRight)

dial_add(nil, 280, 45, 70, 70, cbTurnEngineStartSwitchRight)

-- ================== illumination ========================

local gRealIlluminationCounter = 1
-- debug -------
local gTxtDebug = txt_add("", "font:arimo_regular.ttf;color:yellow;size:20", 10, 100, 390, 20)
-- --------------------

function cbLightChange()
  -- based on two inputs:
  --   gDaylight 0..1: for dark to bright sunshine
  --   gScalesLight 0..1: for no artificial light to full scales light and full illumination
  
  if gDaylight==nil or gScalesLight==nil then return end
  -- print("daylight: " .. gDaylight .. "   scales: ".. gScalesLight)
  
  -- txt_set(gTxtDebug, "daylight: " .. gDaylight .. "   scales: ".. gScalesLight)
  
  local night_color, brightness

  opacity(gNightColor, .4*gScalesLight - .4*gDaylight)

  brightness = var_cap((gDaylight + gScalesLight), 0, 1)
  opacity(gBlackMask, 1-brightness)
end



function cbRealIllumination(v)
  -- txt_set(gTxtDebug, "Illu: "..v.." count: "..gRealIlluminationCounter)
  if gRealIlluminationCounter == 0 then
    gDaylight = .99
    gScalesLight = 0
  else
    gDaylight=1-v
  end
  gRealIlluminationCounter = 1
  cbLightChange()
end

function cbScalesIllumination(v)
  if v==0 then
    gScalesLight = .3  -- dimmed
  elseif v==50 then
    gScalesLight = .06 -- off
  else
    gScalesLight = .8 -- full on
  end
  cbLightChange()
end

if gPropIllumination == "Day" then
  gDaylight = .99
  gScalesLight = 0
  cbLightChange()
  
elseif gPropIllumination == "Night" then
  gDaylight = 0.15
  gScalesLight = .15
  cbLightChange()
  
elseif gPropIllumination == "Real" then
  si_variable_subscribe("sivar_ambient_darkness", "FLOAT", cbRealIllumination)
  -- ORIGINAL PMDG CODE:
  -- msfs_variable_subscribe("L:switch_258_73X", "number", cbScalesIllumination)
  
  -- iFly Conversion:
  msfs_variable_subscribe("L:VC_LIGHTING_PANEL_SCALES_SW_VAL", "number", cbScalesIllumination)
  
else -- Dial
  -- ORIGINAL PMDG CODE:
  -- msfs_variable_subscribe("A:LIGHT POTENTIOMETER:2", "Number",  function(v) gDaylight = v; cbLightChange() end)
  -- msfs_variable_subscribe("A:LIGHT POTENTIOMETER:3", "Number",  function(v) gScalesLight = v; cbLightChange() end)
  
  -- iFly Conversion:
  msfs_variable_subscribe("A:LIGHT POTENTIOMETER:2", "Number",  function(v) gDaylight = v; cbLightChange() end)
  msfs_variable_subscribe("A:LIGHT POTENTIOMETER:3", "Number",  function(v) gScalesLight = v; cbLightChange() end)
end
---------------------
