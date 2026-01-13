# 社区医疗信息管理系统

一个基于Qt的完整医疗信息管理系统，支持病人管理、医生管理、就诊记录、处方、药品库存、预约排班等功能。

## 功能特性

### 核心模块
- **GUI**: 基于Qt Widgets的现代化界面
- **MV (Model/View)**: 使用Qt的Model/View架构进行数据展示
- **DB**: SQLite数据库存储，支持多张表的关系管理
- **NET**: HTTP/TCP网络通信支持
- **THR**: 后台线程处理统计和报表生成
- **FILE**: 文件导出功能（CSV报表等）

### 功能模块

1. **病人信息管理**
   - 添加、编辑、删除病人信息
   - 记录病人基本信息、病史、过敏信息等
   - 支持身份证号唯一性约束

2. **医生与科室管理**
   - 医生信息管理（姓名、职称、专业等）
   - 科室信息管理
   - 医生与科室的关联关系

3. **就诊记录与处方**
   - 就诊记录管理（主诉、诊断、治疗方案）
   - 处方管理（药品、用法、用量）
   - 就诊记录与处方的关联

4. **药品与库存**
   - 药品信息管理
   - 库存管理（数量、最低/最高库存预警）
   - 批次号和过期日期管理

5. **预约与排班**
   - 病人预约管理
   - 医生排班管理
   - 预约状态跟踪

## 技术架构

### 数据库设计
使用SQLite数据库，包含以下表：
- `patients` - 病人表
- `doctors` - 医生表
- `departments` - 科室表
- `medical_records` - 就诊记录表
- `prescriptions` - 处方表
- `medicines` - 药品表
- `inventory` - 库存表
- `appointments` - 预约表
- `schedules` - 排班表

### Model/View架构
- 使用`QSqlTableModel`作为数据模型
- 使用`QTableView`进行数据展示
- 支持数据的增删改查操作

### 后台线程
- `StatisticsThread`: 统计信息计算线程
- `ReportGenerator`: 报表生成器（支持CSV导出）

### 网络通信
- `NetworkManager`: 数据同步和备份管理
- `HttpSynchronizer`: HTTP方式同步药品和诊断参考信息
- `TcpSyncServer`: TCP服务器，支持远程数据备份

## 编译要求

- Qt 5.12 或更高版本
- C++17 编译器支持
- SQLite 驱动（Qt自带）

## 编译步骤

1. 打开Qt Creator
2. 打开项目文件 `MedicalSystem.pro`
3. 配置编译套件（Kit）
4. 点击"构建"按钮进行编译

或者使用命令行：
```bash
qmake MedicalSystem.pro
make
```

Windows下：
```bash
qmake MedicalSystem.pro
nmake
```

## 运行

编译完成后，直接运行生成的可执行文件即可。首次运行会自动创建数据库文件在应用程序数据目录。

## 使用说明

### 添加数据
1. 选择对应的功能标签页
2. 点击"添加"按钮
3. 填写相关信息
4. 点击"确定"保存

### 编辑数据
1. 在列表中选中要编辑的记录
2. 点击"编辑"按钮
3. 修改信息后保存

### 删除数据
1. 在列表中选中要删除的记录
2. 点击"删除"按钮
3. 确认删除操作

### 生成报表
- 菜单栏：报表 -> 生成报表
- 选择保存位置，生成CSV格式的报表文件

### 查看统计
- 菜单栏：报表 -> 查看统计
- 显示系统各项数据的统计信息

### 数据同步
- 菜单栏：文件 -> 同步数据
- 通过HTTP协议同步远程数据

### 数据备份
- 菜单栏：文件 -> 备份数据
- 将数据库备份到指定位置

## 项目结构

```
MedicalSystem/
├── main.cpp                 # 程序入口
├── mainwindow.h/cpp         # 主窗口
├── databasemanager.h/cpp    # 数据库管理
├── models/                  # Model类
│   ├── patientmodel.h/cpp
│   ├── doctormodel.h/cpp
│   ├── departmentmodel.h/cpp
│   ├── medicalrecordmodel.h/cpp
│   ├── prescriptionmodel.h/cpp
│   ├── medicinemodel.h/cpp
│   ├── inventorymodel.h/cpp
│   ├── appointmentmodel.h/cpp
│   └── schedulemodel.h/cpp
├── dialogs/                 # 对话框类
│   ├── patientdialog.h/cpp
│   ├── doctordialog.h/cpp
│   ├── departmentdialog.h/cpp
│   ├── medicalrecorddialog.h/cpp
│   ├── prescriptiondialog.h/cpp
│   ├── medicinedialog.h/cpp
│   ├── inventorydialog.h/cpp
│   ├── appointmentdialog.h/cpp
│   └── scheduledialog.h/cpp
├── network/                 # 网络通信
│   ├── networkmanager.h/cpp
│   ├── httpsynchronizer.h/cpp
│   └── tcpsyncserver.h/cpp
├── threads/                 # 后台线程
│   ├── reportgenerator.h/cpp
│   └── statisticsthread.h/cpp
├── utils/                   # 工具类
│   └── excelreport.h/cpp
└── MedicalSystem.pro        # Qt项目文件
```

## 注意事项

1. 首次运行会自动创建数据库，数据库文件存储在应用程序数据目录
2. 网络同步功能需要配置相应的服务器地址
3. 数据删除操作不可恢复，请谨慎操作
4. 建议定期备份数据库文件

## 许可证

本项目仅供学习和参考使用。

## 更新日志

### v1.0 (2024)
- 初始版本发布
- 实现所有核心功能模块
- 支持基本的CRUD操作
- 实现报表生成和统计功能
- 支持网络同步和备份

