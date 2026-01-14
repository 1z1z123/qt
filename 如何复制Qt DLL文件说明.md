# 如何复制 Qt DLL 文件到可执行文件目录

## 问题说明

生成的 `MedicalSystem.exe` 文件需要 Qt 运行时库（DLL 文件）才能运行。如果运行时提示缺少 `Qt6Network.dll` 或其他 Qt DLL，需要将这些 DLL 文件复制到 exe 文件所在的目录。

## 方法一：手动复制 DLL 文件（推荐用于提交作业）

### 步骤：

1. **找到 Qt DLL 文件位置**
   ```
   E:\Qt2\6.5.3\mingw_64\bin\
   ```

2. **找到你的 exe 文件位置**
   
   根据你的构建配置，exe 文件在：
   - Release 版本：`C:\Users\Administrator\Desktop\dzy\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\release\MedicalSystem.exe`
   - Debug 版本：`C:\Users\Administrator\Desktop\dzy\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\debug\MedicalSystem.exe`

3. **复制必需的 DLL 文件**
   
   从 `E:\Qt2\6.5.3\mingw_64\bin\` 目录复制以下文件到 exe 文件所在目录：
   
   **必需的 DLL 文件：**
   - `Qt6Core.dll`
   - `Qt6Gui.dll`
   - `Qt6Widgets.dll`
   - `Qt6Sql.dll`
   - `Qt6Network.dll`
   
   **平台插件（必需）：**
   还需要创建 `platforms` 文件夹，并复制：
   - 从 `E:\Qt2\6.5.3\mingw_64\plugins\platforms\` 复制 `qwindows.dll` 到 `exe目录\platforms\qwindows.dll`

4. **复制 MinGW 运行时 DLL（如果目标电脑没有安装 MinGW）**
   
   从 `E:\Qt2\6.5.3\mingw_64\bin\` 或 MinGW 安装目录复制：
   - `libgcc_s_seh-1.dll`
   - `libstdc++-6.dll`
   - `libwinpthread-1.dll`

### 快速复制方法：

**使用 PowerShell（在项目目录下运行）：**

```powershell
# 设置变量
$QtBinDir = "E:\Qt2\6.5.3\mingw_64\bin"
$ExeDir = "C:\Users\Administrator\Desktop\dzy\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\release"

# 复制 Qt DLL 文件
Copy-Item "$QtBinDir\Qt6Core.dll" -Destination $ExeDir
Copy-Item "$QtBinDir\Qt6Gui.dll" -Destination $ExeDir
Copy-Item "$QtBinDir\Qt6Widgets.dll" -Destination $ExeDir
Copy-Item "$QtBinDir\Qt6Sql.dll" -Destination $ExeDir
Copy-Item "$QtBinDir\Qt6Network.dll" -Destination $ExeDir

# 创建 platforms 文件夹并复制平台插件
New-Item -ItemType Directory -Path "$ExeDir\platforms" -Force | Out-Null
Copy-Item "$QtBinDir\..\plugins\platforms\qwindows.dll" -Destination "$ExeDir\platforms\"

# 复制 MinGW 运行时 DLL
Copy-Item "$QtBinDir\libgcc_s_seh-1.dll" -Destination $ExeDir -ErrorAction SilentlyContinue
Copy-Item "$QtBinDir\libstdc++-6.dll" -Destination $ExeDir -ErrorAction SilentlyContinue
Copy-Item "$QtBinDir\libwinpthread-1.dll" -Destination $ExeDir -ErrorAction SilentlyContinue
```

## 方法二：使用 windeployqt 工具（自动部署）

Qt 提供了 `windeployqt` 工具，可以自动复制所有必需的 DLL 文件。

### 步骤：

1. **打开命令提示符（CMD）或 PowerShell**

2. **运行 windeployqt 工具**
   ```cmd
   E:\Qt2\6.5.3\mingw_64\bin\windeployqt.exe C:\Users\Administrator\Desktop\dzy\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\release\MedicalSystem.exe
   ```

3. **工具会自动：**
   - 复制所有必需的 Qt DLL 文件
   - 复制平台插件到 `platforms` 文件夹
   - 复制其他必需的依赖项

**注意：** windeployqt 可能会复制一些你不需要的 DLL（如 Qt6Qml.dll 等），如果你不需要 QML 支持，可以手动删除这些文件。

## 验证

复制完成后，双击 `MedicalSystem.exe` 文件，应该可以正常运行了。

## 提交作业时的建议

如果要提交给老师，建议：

1. **创建一个文件夹**，例如：`MedicalSystem_Release`
2. **将以下文件复制到该文件夹：**
   - `MedicalSystem.exe`
   - 所有必需的 DLL 文件（Qt6Core.dll, Qt6Gui.dll, Qt6Widgets.dll, Qt6Sql.dll, Qt6Network.dll）
   - `platforms` 文件夹（包含 qwindows.dll）
   - MinGW 运行时 DLL（如果需要）
3. **可选：** 将数据库文件（如果使用外部数据库）也一起复制

这样老师就可以直接运行你的程序了。

