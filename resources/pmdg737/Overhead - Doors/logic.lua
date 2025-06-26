-- Detlef von Reusner
-- PMDG B737-700 Overhead panel - Doors lights
-- FS2020

-- Dec 1 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Aug 17 2022: Initial version
-- Aug 21 2022: Overwing lights corrected
-- Dec 1 2022: Illumination updated



img_add_fullscreen("bg.png")


--------------- 

local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 210, function()
  _rect(0, 0, 400, 210)
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


-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 210)


-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 210, function()
  _rect(0, 0, 400, 210)
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

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- AddLight("L:switch_8951_73X", "light-amber-1.png", 28, 37,  "AIRSTAIR")
-- AddLight("L:switch_169_73X", "light-amber-2.png", 114, 37,  "FWD", "ENTRY")
-- AddLight("L:switch_170_73X", "light-amber-3.png", 200, 37,  "FWD", "SERVICE")
-- AddLight("L:switch_171_73X", "light-amber-4.png", 286, 37,  "FWD", "CARGO")
-- AddLight("L:switch_172_73X", "light-amber-3.png", 28, 88,  "EQUIP")
-- AddLight("L:switch_173_73X", "light-amber-2.png", 114, 88,  "LEFT", "OVERWING")
-- AddLight("L:switch_174_73X", "light-amber-1.png", 200, 88,  "RIGHT", "OVERWING")
-- AddLight("L:switch_175_73X", "light-amber-4.png", 286, 88,  "AFT", "CARGO")
-- AddLight("L:switch_176_73X", "light-amber-4.png", 114, 149,  "AFT", "ENTRY")
-- AddLight("L:switch_177_73X", "light-amber-3.png", 200, 149,  "AFT", "SERVICE")

-- ================ CONVERTED iFLY CODE ================
AddLight("L:VC_GENERAL_LIGHT_AIRSTAIR_LIGHT_VAL", "light-amber-1.png", 28, 37,  "AIRSTAIR")
AddLight("L:VC_GENERAL_LIGHT_FWD_ENTRY_LIGHT_VAL", "light-amber-2.png", 114, 37,  "FWD", "ENTRY")
AddLight("L:VC_GENERAL_LIGHT_FWD_SERVICE_LIGHT_VAL", "light-amber-3.png", 200, 37,  "FWD", "SERVICE")
AddLight("L:VC_GENERAL_LIGHT_FWD_CARGO_LIGHT_VAL", "light-amber-4.png", 286, 37,  "FWD", "CARGO")

AddLight("L:VC_GENERAL_LIGHT_EQUIP_LIGHT_VAL", "light-amber-3.png", 28, 88,  "EQUIP")
AddLight("L:VC_GENERAL_LIGHT_LEFT_FWD_OVERWING_LIGHT_VAL", "light-amber-2.png", 114, 88,  "LEFT", "OVERWING")
AddLight("L:VC_GENERAL_LIGHT_RIGHT_FWD_OVERWING_LIGHT_VAL", "light-amber-1.png", 200, 88,  "RIGHT", "OVERWING")
AddLight("L:VC_GENERAL_LIGHT_AFT_CARGO_LIGHT_VAL", "light-amber-4.png", 286, 88,  "AFT", "CARGO")

AddLight("L:VC_GENERAL_LIGHT_AFT_ENTRY_LIGHT_VAL", "light-amber-4.png", 114, 149,  "AFT", "ENTRY")
AddLight("L:VC_GENERAL_LIGHT_AFT_SERVICE_LIGHT_VAL", "light-amber-3.png", 200, 149,  "AFT", "SERVICE")

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
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)
