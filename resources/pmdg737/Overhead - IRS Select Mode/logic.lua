-- Detlef von Reusner
-- PMDG B737-700 Aft Overhead Panel - IRS Select Mode
-- FS2020

-- Dec 2 2022

-- Illumination options per user properties: Day,Night,Real.
-- Ambient Light Dimmer Instrument needed for option "Real". (From SIMSTRUMENTATION)
-- You may set the Userprops in the Ambient Light Dimmer Instrument to "Hide and autodimm".
-- See also comments in lib file: illumination.lua


-- History:

-- Sep 2 2022: Initial version
-- Nov 2 2022: Align light changed to white
-- Dec 2 2022: Illumination updated



img_add_fullscreen("bg.png")

gImgLeftDial = img_add("selector-knob.png", 76, 201, 60, 60)
gImgRightDial = img_add("selector-knob.png", 266, 201, 60, 60)


local gNightColor = img_add_fullscreen("night-color.png")
opacity(gNightColor, 0) -- max. .2 for night color

local gBlackMask = canvas_add(0, 0, 400, 270, function()
  _rect(0, 0, 400, 270)
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

-- ================== Lines ==================

function DrawLeftScale()
  ---------- left scale ------
  local x0
  x0 = 106 -- x center position
  _rotate(100, x0, 231)
  for k=1,4 do
    _rotate(-40, x0, 231)
    _move_to(x0, 199)
    _line_to(x0, 188)
  end
  _stroke(gColorPrint, 3)
end    

function DrawRightScale()
  ------------- right scale --------------
  local x0
  x0 = 296 -- x center position
  _rotate(100, x0, 231)
  for k=1,4 do
    _rotate(-40, x0, 231)
    _move_to(x0, 199)
    _line_to(x0, 186)
  end
  _stroke(gColorPrint, 3)
end

local gImgLeftScale = canvas_add(0, 0, 400, 270, DrawLeftScale)
local gImgRightScale = canvas_add(0, 0, 400, 270, DrawRightScale)

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

function DrawAllTexts()
  local style
  style = gFontPrintBig..";color:"..gColorPrint.."; halign:left"
  PrintText("+",  195, 210,  style, 24, false)
  
  style = gFontPrintSmall..";color:"..gColorPrint.."; halign:left"
  PrintText("OFF",  41, 192,  style, 20, false)
  PrintText("ALIGN",  58, 174,  style, 20, false)
  PrintText("NAV",  114, 174,  style, 20, false)
  PrintText("ATT",  144, 192,  style, 20, false)

  local dx = 190
  PrintText("OFF",  41+dx, 192,  style, 20, false)
  PrintText("ALIGN",  58+dx, 174,  style, 20, false)
  PrintText("NAV",  114+dx, 174,  style, 20, false)
  PrintText("ATT",  144+dx, 192,  style, 20, false)
  
  PrintText("L",  134, 248,  style, 20, false)
  PrintText("R",  258, 248,  style, 20, false)

  PrintText("IRS",  189, 248,  style, 20, false)
  
  -- style = gFontPrintTiny..";color:"..gColorPrint.."; halign:left"
  -- PrintText("STBY", 11, 57, style, 18, false)
end


local gImgTexts = canvas_add(0, 0, 400, 270, DrawAllTexts)

-- ===================== images above lines ================

img_add("frames.png", 0, 0, 400, 270)

-- ====================== Switches ==================

---------------------- IRS MODE SELECTOR LEFT Switch -----------------

function DrawPointer()
  _move_to(30, 2)
  _line_to(30,25)
  _stroke("black", 8)
  _move_to(30, 2)
  _line_to(30,23)
  _stroke(gColorPrint, 4)
end

local gPointerLeft = canvas_add(76, 201, 60, 60, DrawPointer)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbLeftSwitch(rotac)
--   if rotac>0 then
--     msfs_event("ROTOR_BRAKE", 25507)
--   else
--     msfs_event("ROTOR_BRAKE", 25508)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentIRS1Position = 0 -- Default to OFF (0)
function cbLeftSwitch(rotac)
  if rotac>0 then
    currentIRS1Position = math.min(currentIRS1Position + 10, 30)
  else
    currentIRS1Position = math.max(currentIRS1Position - 10, 0)
  end
  msfs_variable_write("L:VC_IRS_1_SW_VAL", "number", currentIRS1Position)
end

dial_add(nil, 76, 201, 60, 60, cbLeftSwitch)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- -- 0 = OFF, 10 == ALIGN, 20 = NAV, 30 = ATT
-- msfs_variable_subscribe("L:switch_255_73X", "number", function(v)
--   local angle = v/10*40-60
--   rotate(gImgLeftDial, angle, "LOG", .1)
--   rotate(gPointerLeft, angle, "LOG", .1)
-- end)

-- ================ CONVERTED iFLY CODE ================
-- 0 = OFF, 10 == ALIGN, 20 = NAV, 30 = ATT
msfs_variable_subscribe("L:VC_IRS_1_SW_VAL", "number", function(v)
  currentIRS1Position = v
  local angle = v/10*40-60
  rotate(gImgLeftDial, angle, "LOG", .1)
  rotate(gPointerLeft, angle, "LOG", .1)
end)

---------------------- IRS MODE SELECTOR RIGHT Switch -----------------

local gPointerRight = canvas_add(266, 201, 60, 60, function() end)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- function cbRightSwitch(rotac)
--   if rotac>0 then
--     msfs_event("ROTOR_BRAKE", 25607)
--   else
--     msfs_event("ROTOR_BRAKE", 25608)
--   end
-- end

-- ================ CONVERTED iFLY CODE ================
local currentIRS2Position = 0 -- Default to OFF (0)
function cbRightSwitch(rotac)
  if rotac>0 then
    currentIRS2Position = math.min(currentIRS2Position + 10, 30)
  else
    currentIRS2Position = math.max(currentIRS2Position - 10, 0)
  end
  msfs_variable_write("L:VC_IRS_2_SW_VAL", "number", currentIRS2Position)
end

dial_add(nil, 266, 201, 60, 60, cbRightSwitch)

-- ================ ORIGINAL PMDG CODE (COMMENTED OUT) ================
-- -- 0 = OFF, 10 == ALIGN, 20 = NAV, 30 = ATT
-- msfs_variable_subscribe("L:switch_256_73X", "number", function(v)
--   local angle = v/10*40-60
--   rotate(gImgRightDial, angle, "LOG", .1)
--   rotate(gPointerRight, angle, "LOG", .1)
-- end)

-- ================ CONVERTED iFLY CODE ================
-- 0 = OFF, 10 == ALIGN, 20 = NAV, 30 = ATT
msfs_variable_subscribe("L:VC_IRS_2_SW_VAL", "number", function(v)
  currentIRS2Position = v
  local angle = v/10*40-60
  rotate(gImgRightDial, angle, "LOG", .1)
  rotate(gPointerRight, angle, "LOG", .1)
end)


-- ======================= Dimm all, except lights ================

local gBlackMask2 = canvas_add(0, 0, 400, 270, function()
  _rect(0, 0, 400, 270)
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

-- ======================== add lights ======================

AddLight("L:switch_246_73X", "light-amber-1.png", 157, 8, "GPS")

AddLight("L:switch_247_73X", "light-white.png", 20, 65, "ALIGN")
AddLight("L:switch_248_73X", "light-amber-3.png", 106, 65, "ON DC")
AddLight("L:switch_249_73X", "light-amber-4.png", 20, 116, "FAULT")
AddLight("L:switch_250_73X", "light-amber-1.png", 106, 116, "DC FAIL")

AddLight("L:switch_251_73X", "light-white.png", 210, 65, "ALIGN")
AddLight("L:switch_252_73X", "light-amber-3.png", 296, 65, "ON DC")
AddLight("L:switch_253_73X", "light-amber-1.png", 210, 116, "FAULT")
AddLight("L:switch_254_73X", "light-amber-2.png", 296, 116, "DC FAIL")

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
  canvas_draw(gImgLeftScale, DrawLeftScale)
  canvas_draw(gImgRightScale, DrawRightScale)
  canvas_draw(gPointerLeft, DrawPointer)
  canvas_draw(gPointerRight, DrawPointer)
  -- print(r.."  "..g.."  "..b)
  gSwitchColorHi = string.format("#%.2x%.2x%.2xff", r//1, g//1, b//1)
  gSwitchColorLo = string.format("#%.2x%.2x%.2xff", (r*.9)//1, (g*.9)//1, (b*.9)//1)
  -- DrawSwitches()
end

ControlIllumination(DrawAllCanvas, gNightColor, gBlackMask, gDebugIllumination, gTxtDebug, gTxtDebug2, gTxtDebug3)
