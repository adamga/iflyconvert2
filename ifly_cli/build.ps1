# iFly CLI PowerShell Build Script
# Alternative build script for users who prefer PowerShell

param(
    [switch]$Clean,
    [switch]$Install,
    [switch]$Help
)

function Show-Help {
    Write-Host "iFly CLI Build Script" -ForegroundColor Green
    Write-Host "Usage: .\build.ps1 [options]" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Options:" -ForegroundColor Cyan
    Write-Host "  -Clean     Clean build artifacts"
    Write-Host "  -Install   Install to parent directory after build"
    Write-Host "  -Help      Show this help message"
    Write-Host ""
    Write-Host "Examples:" -ForegroundColor Cyan
    Write-Host "  .\build.ps1                    # Build only"
    Write-Host "  .\build.ps1 -Install           # Build and install"
    Write-Host "  .\build.ps1 -Clean             # Clean artifacts"
    Write-Host "  .\build.ps1 -Clean -Install    # Clean, build, and install"
}

function Test-Compiler {
    $clPath = Get-Command cl -ErrorAction SilentlyContinue
    if (-not $clPath) {
        Write-Host "Error: Visual Studio Build Tools not found." -ForegroundColor Red
        Write-Host "Please run this from a Visual Studio Developer PowerShell prompt." -ForegroundColor Yellow
        Write-Host "Or install Visual Studio Build Tools." -ForegroundColor Yellow
        return $false
    }
    return $true
}

function Invoke-Clean {
    Write-Host "Cleaning build artifacts..." -ForegroundColor Yellow
    
    $filesToRemove = @("*.obj", "*.exe", "*.pdb", "*.ilk")
    
    foreach ($pattern in $filesToRemove) {
        $files = Get-ChildItem -Path . -Name $pattern -ErrorAction SilentlyContinue
        if ($files) {
            Remove-Item $files -Force
            Write-Host "Removed: $($files -join ', ')" -ForegroundColor Gray
        }
    }
    
    Write-Host "Clean completed." -ForegroundColor Green
}

function Invoke-Build {
    Write-Host "Building iFly CLI Tool..." -ForegroundColor Green
    
    if (-not (Test-Compiler)) {
        return $false
    }
    
    $compilerArgs = @(
        "/std:c++17",
        "/EHsc",
        "/W3",
        "/DWIN32_LEAN_AND_MEAN",
        "/DNOMINMAX",
        "/I.",
        "/I../737MAX_SDK",
        "/I../737MAX_SDK/sdk",
        "main.cpp",
        "/Feifly_cli.exe",
        "/link",
        "user32.lib",
        "kernel32.lib"
    )
    
    Write-Host "Compiling with: cl $($compilerArgs -join ' ')" -ForegroundColor Gray
    
    $process = Start-Process -FilePath "cl" -ArgumentList $compilerArgs -NoNewWindow -Wait -PassThru
    
    if ($process.ExitCode -eq 0) {
        Write-Host "Build successful!" -ForegroundColor Green
        return $true
    } else {
        Write-Host "Build failed with exit code: $($process.ExitCode)" -ForegroundColor Red
        return $false
    }
}

function Invoke-Install {
    $exePath = ".\ifly_cli.exe"
    
    if (Test-Path $exePath) {
        Write-Host "Installing to parent directory..." -ForegroundColor Yellow
        Copy-Item $exePath ".." -Force
        Write-Host "Installation completed." -ForegroundColor Green
        return $true
    } else {
        Write-Host "Error: ifly_cli.exe not found. Build first." -ForegroundColor Red
        return $false
    }
}

function Show-Usage {
    Write-Host ""
    Write-Host "Build completed successfully!" -ForegroundColor Green
    Write-Host "The ifly_cli.exe has been created." -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Usage examples:" -ForegroundColor Yellow
    Write-Host "  .\ifly_cli.exe help" -ForegroundColor Gray
    Write-Host "  .\ifly_cli.exe list" -ForegroundColor Gray
    Write-Host "  .\ifly_cli.exe connect" -ForegroundColor Gray
    Write-Host "  .\ifly_cli.exe set landing_light_1 on" -ForegroundColor Gray
    Write-Host ""
}

# Main script execution
if ($Help) {
    Show-Help
    exit 0
}

if ($Clean) {
    Invoke-Clean
}

if (-not $Clean) {
    $buildSuccess = Invoke-Build
    
    if ($buildSuccess) {
        # Clean up object files
        Remove-Item "*.obj" -ErrorAction SilentlyContinue
        
        if ($Install) {
            Invoke-Install
        }
        
        Show-Usage
    } else {
        Write-Host "Build failed. Please check the error messages above." -ForegroundColor Red
        exit 1
    }
}

Write-Host "Script completed." -ForegroundColor Green
