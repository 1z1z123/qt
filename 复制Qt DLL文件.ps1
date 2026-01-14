# 复制 Qt DLL 文件到 exe 目录的 PowerShell 脚本

# 配置路径
$QtBinDir = "E:\Qt2\6.5.3\mingw_64\bin"
$QtPluginsDir = "E:\Qt2\6.5.3\mingw_64\plugins"

# 选择要复制到的目录（Release 或 Debug）
Write-Host "请选择要复制 DLL 的版本：" -ForegroundColor Yellow
Write-Host "1. Release 版本 (release 目录)"
Write-Host "2. Debug 版本 (debug 目录)"
$choice = Read-Host "请输入选择 (1 或 2)"

if ($choice -eq "1") {
    $ExeDir = Join-Path $PSScriptRoot "build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\release"
    Write-Host "`n目标目录：Release 版本" -ForegroundColor Green
} else {
    $ExeDir = Join-Path $PSScriptRoot "build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\debug"
    Write-Host "`n目标目录：Debug 版本" -ForegroundColor Green
}

# 检查目录是否存在
if (-not (Test-Path $ExeDir)) {
    Write-Host "错误：目录不存在：$ExeDir" -ForegroundColor Red
    Write-Host "请先编译项目生成 exe 文件！" -ForegroundColor Red
    exit 1
}

# 检查 exe 文件是否存在
$ExeFile = Join-Path $ExeDir "MedicalSystem.exe"
if (-not (Test-Path $ExeFile)) {
    Write-Host "警告：未找到 MedicalSystem.exe 文件" -ForegroundColor Yellow
    Write-Host "目录：$ExeDir" -ForegroundColor Yellow
}

Write-Host "`n开始复制 DLL 文件..." -ForegroundColor Cyan

# 必需的 Qt DLL 文件列表
$QtDlls = @(
    "Qt6Core.dll",
    "Qt6Gui.dll",
    "Qt6Widgets.dll",
    "Qt6Sql.dll",
    "Qt6Network.dll"
)

# 复制 Qt DLL 文件
foreach ($dll in $QtDlls) {
    $source = Join-Path $QtBinDir $dll
    $dest = Join-Path $ExeDir $dll
    if (Test-Path $source) {
        Copy-Item $source -Destination $dest -Force
        Write-Host "  ✓ 已复制: $dll" -ForegroundColor Green
    } else {
        Write-Host "  ✗ 未找到: $dll" -ForegroundColor Red
    }
}

# 复制平台插件
$PlatformsDir = Join-Path $ExeDir "platforms"
New-Item -ItemType Directory -Path $PlatformsDir -Force | Out-Null
$PlatformDll = Join-Path $QtPluginsDir "platforms\qwindows.dll"
if (Test-Path $PlatformDll) {
    Copy-Item $PlatformDll -Destination $PlatformsDir -Force
    Write-Host "  ✓ 已复制平台插件: platforms\qwindows.dll" -ForegroundColor Green
} else {
    Write-Host "  ✗ 未找到平台插件" -ForegroundColor Red
}

# 复制 MinGW 运行时 DLL（如果存在）
$MinGWDlls = @(
    "libgcc_s_seh-1.dll",
    "libstdc++-6.dll",
    "libwinpthread-1.dll"
)

foreach ($dll in $MinGWDlls) {
    $source = Join-Path $QtBinDir $dll
    $dest = Join-Path $ExeDir $dll
    if (Test-Path $source) {
        Copy-Item $source -Destination $dest -Force
        Write-Host "  ✓ 已复制: $dll" -ForegroundColor Green
    }
}

Write-Host "`n完成！所有 DLL 文件已复制到：$ExeDir" -ForegroundColor Green
Write-Host "`n现在可以运行 MedicalSystem.exe 了！" -ForegroundColor Cyan

