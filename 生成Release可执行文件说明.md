# 如何生成 Release 模式的可执行文件

## 方法一：在 Qt Creator 中切换模式（推荐）

### 步骤：

1. **打开 Qt Creator**

2. **切换到 Release 模式**
   - 在 Qt Creator 左下角，找到构建模式选择器
   - 当前显示为 "Debug" 模式
   - 点击下拉菜单，选择 **"Release"** 模式
   - 或者点击菜单：**项目** → **构建配置** → **Release**

3. **清理项目（可选但推荐）**
   - 菜单：**构建** → **清理项目 "MedicalSystem"**
   - 这样可以确保重新编译所有文件

4. **构建 Release 版本**
   - 菜单：**构建** → **构建项目 "MedicalSystem"**
   - 或者按快捷键：`Ctrl + Shift + B`
   - 或者点击左下角的 **构建** 按钮（锤子图标）

5. **等待编译完成**
   - **重要：** 切换模式后，必须点击"构建"按钮才会开始编译
   - 查看编译输出窗口（底部"编译输出"标签页），确认没有错误
   - 如果看到错误信息，需要先解决错误
   - 看到 "构建完成" 或 "构建项目 'MedicalSystem' 完成" 提示
   - 如果有错误，会显示红色的错误信息，需要先修复

6. **检查编译是否成功**
   
   ⚠️ **关键检查点：**
   - 如果 `release` 目录下只有 `object_script.MedicalSystem.Release` 文件，说明编译没有完成
   - 成功编译后，`release` 目录下应该有 `MedicalSystem.exe` 文件
   - 如果编译输出窗口有错误（红色文字），需要先解决错误才能生成exe文件

7. **找到可执行文件**
   
   根据你的项目配置，Release 版本的 .exe 文件通常在以下位置：
   
   根据你的项目配置，Release 版本的 .exe 文件通常在以下位置：
   
   **路径1（如果使用独立的Release目录）：**
   ```
   C:\Users\Administrator\Desktop\dzy\build\Desktop_Qt_6_5_3_MinGW_64_bit-Release\release\MedicalSystem.exe
   ```
   
   **路径2（如果在Debug目录下的release子目录）：**
   ```
   C:\Users\Administrator\Desktop\dzy\build\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\release\MedicalSystem.exe
   ```
   
   **验证是否编译成功：**
   - 如果 `release` 目录下只有 `object_script.MedicalSystem.Release` 文件，说明 Release 模式还没有成功编译
   - 成功编译后，应该能看到 `MedicalSystem.exe` 文件

## 方法二：通过命令行编译

1. 打开命令提示符（CMD）或 PowerShell
2. 进入项目目录：
   ```cmd
   cd C:\Users\Administrator\Desktop\dzy
   ```
3. 创建Release构建目录：
   ```cmd
   mkdir build-release
   cd build-release
   ```
4. 运行 qmake（Release模式）：
   ```cmd
   E:\Qt2\6.5.3\mingw_64\bin\qmake.exe ..\MedicalSystem.pro -config release
   ```
5. 编译：
   ```cmd
   mingw32-make
   ```
6. 可执行文件在：`build-release\release\MedicalSystem.exe`

## 注意事项

⚠️ **重要：Release 版本需要 Qt 运行库**

生成的 .exe 文件需要以下 DLL 文件才能运行（如果目标机器没有安装 Qt）：
- Qt6Core.dll
- Qt6Gui.dll
- Qt6Widgets.dll
- Qt6Sql.dll
- Qt6Network.dll
- 以及相关的平台插件

可以使用 Qt 自带的部署工具或手动复制这些 DLL。

## 验证 Release 版本

- Release 版本通常比 Debug 版本小很多
- Release 版本运行速度更快
- Release 版本不包含调试信息

## 如果找不到 Release 目录或 exe 文件

### 问题1：release 目录下只有 object_script 文件，没有 exe 文件

**原因：** Release 模式没有成功编译完成

**解决方法：**
1. 确认在 Qt Creator 左下角选择了 "Release" 模式
2. 点击菜单：**构建** → **构建项目 "MedicalSystem"**
3. 查看编译输出窗口，检查是否有错误信息
4. 如果有错误（红色文字），需要先修复错误
5. 重新编译，直到看到 "构建完成" 提示
6. 再次检查 `release` 目录，应该能看到 `MedicalSystem.exe` 文件

### 问题2：构建输出目录路径不对

如果 build 目录下没有独立的 Release 文件夹（如 `Desktop_Qt_6_5_3_MinGW_64_bit-Release`），说明 Qt Creator 配置为在同一个构建目录下编译 Debug 和 Release。

这种情况下：
- Debug 版本的 exe 在：`build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/MedicalSystem.exe`
- Release 版本的 exe 在：`build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/release/MedicalSystem.exe`

### 问题3：运行时提示缺少 DLL

如果生成的 exe 文件运行时提示缺少 Qt DLL（如 `Qt6Network.dll`），这是正常的，因为：
- 生成的 exe 文件需要 Qt 运行库才能运行
- 如果要在没有安装 Qt 的电脑上运行，需要将相关的 DLL 文件一起复制
- 详细说明见上面的"注意事项"部分

