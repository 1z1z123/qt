#include "mainwindow.h"
#include "models/patientmodel.h"
#include "models/doctormodel.h"
#include "models/departmentmodel.h"
#include "models/medicalrecordmodel.h"
#include "models/prescriptionmodel.h"
#include "models/medicinemodel.h"
#include "models/inventorymodel.h"
#include "models/appointmentmodel.h"
#include "models/schedulemodel.h"
#include "dialogs/patientdialog.h"
#include "dialogs/doctordialog.h"
#include "dialogs/departmentdialog.h"
#include "dialogs/medicalrecorddialog.h"
#include "dialogs/prescriptiondialog.h"
#include "dialogs/medicinedialog.h"
#include "dialogs/inventorydialog.h"
#include "dialogs/appointmentdialog.h"
#include "dialogs/scheduledialog.h"
#include "threads/reportgenerator.h"
#include "threads/statisticsthread.h"
#include "network/networkmanager.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QFileDialog>
#include <QDebug>
#include <QAbstractItemView>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setupMenuBar();
    setupToolBar();
    setupTabs();
    
    statusBar()->showMessage("就绪", 2000);
    setWindowTitle("社区医疗信息管理系统");
    resize(1200, 800);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    m_tabWidget = new QTabWidget(this);
    setCentralWidget(m_tabWidget);
}

void MainWindow::setupMenuBar()
{
    QMenu *fileMenu = menuBar()->addMenu("文件(&F)");
    fileMenu->addAction("同步数据(&S)", this, &MainWindow::onSyncData);
    fileMenu->addAction("备份数据(&B)", this, &MainWindow::onBackupData);
    fileMenu->addSeparator();
    fileMenu->addAction("退出(&X)", this, &QWidget::close);
    
    QMenu *reportMenu = menuBar()->addMenu("报表(&R)");
    reportMenu->addAction("生成报表(&G)", this, &MainWindow::onGenerateReport);
    reportMenu->addAction("查看统计(&S)", this, &MainWindow::onViewStatistics);
    
    QMenu *helpMenu = menuBar()->addMenu("帮助(&H)");
    helpMenu->addAction("关于(&A)", [this]() {
        QMessageBox::about(this, "关于", 
                          "社区医疗信息管理系统 v1.0\n\n"
                          "功能模块：\n"
                          "- 病人信息管理\n"
                          "- 医生与科室管理\n"
                          "- 就诊记录与处方\n"
                          "- 药品与库存\n"
                          "- 预约与排班");
    });
}

void MainWindow::setupToolBar()
{
    QToolBar *toolBar = addToolBar("主工具栏");
    toolBar->addAction("生成报表", this, &MainWindow::onGenerateReport);
    toolBar->addAction("查看统计", this, &MainWindow::onViewStatistics);
    toolBar->addSeparator();
    toolBar->addAction("同步数据", this, &MainWindow::onSyncData);
    toolBar->addAction("备份数据", this, &MainWindow::onBackupData);
}

void MainWindow::setupTabs()
{
    setupPatientTab();
    setupDoctorTab();
    setupDepartmentTab();
    setupMedicalRecordTab();
    setupPrescriptionTab();
    setupMedicineTab();
    setupInventoryTab();
    setupAppointmentTab();
    setupScheduleTab();
}

void MainWindow::setupPatientTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addPatientBtn = new QPushButton("添加", this);
    m_editPatientBtn = new QPushButton("编辑", this);
    m_deletePatientBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addPatientBtn);
    buttonLayout->addWidget(m_editPatientBtn);
    buttonLayout->addWidget(m_deletePatientBtn);
    buttonLayout->addStretch();
    
    m_patientTableView = new QTableView(this);
    m_patientModel = new PatientModel(this);
    m_patientTableView->setModel(m_patientModel);
    m_patientTableView->horizontalHeader()->setStretchLastSection(true);
    m_patientTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addPatientBtn, &QPushButton::clicked, this, &MainWindow::onAddPatient);
    connect(m_editPatientBtn, &QPushButton::clicked, this, &MainWindow::onEditPatient);
    connect(m_deletePatientBtn, &QPushButton::clicked, this, &MainWindow::onDeletePatient);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_patientTableView);
    
    m_tabWidget->addTab(widget, "病人管理");
}

void MainWindow::setupDoctorTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addDoctorBtn = new QPushButton("添加", this);
    m_editDoctorBtn = new QPushButton("编辑", this);
    m_deleteDoctorBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addDoctorBtn);
    buttonLayout->addWidget(m_editDoctorBtn);
    buttonLayout->addWidget(m_deleteDoctorBtn);
    buttonLayout->addStretch();
    
    m_doctorTableView = new QTableView(this);
    m_doctorModel = new DoctorModel(this);
    m_doctorTableView->setModel(m_doctorModel);
    m_doctorTableView->horizontalHeader()->setStretchLastSection(true);
    m_doctorTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addDoctorBtn, &QPushButton::clicked, this, &MainWindow::onAddDoctor);
    connect(m_editDoctorBtn, &QPushButton::clicked, this, &MainWindow::onEditDoctor);
    connect(m_deleteDoctorBtn, &QPushButton::clicked, this, &MainWindow::onDeleteDoctor);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_doctorTableView);
    
    m_tabWidget->addTab(widget, "医生管理");
}

void MainWindow::setupDepartmentTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addDepartmentBtn = new QPushButton("添加", this);
    m_editDepartmentBtn = new QPushButton("编辑", this);
    m_deleteDepartmentBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addDepartmentBtn);
    buttonLayout->addWidget(m_editDepartmentBtn);
    buttonLayout->addWidget(m_deleteDepartmentBtn);
    buttonLayout->addStretch();
    
    m_departmentTableView = new QTableView(this);
    m_departmentModel = new DepartmentModel(this);
    m_departmentTableView->setModel(m_departmentModel);
    m_departmentTableView->horizontalHeader()->setStretchLastSection(true);
    m_departmentTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addDepartmentBtn, &QPushButton::clicked, this, &MainWindow::onAddDepartment);
    connect(m_editDepartmentBtn, &QPushButton::clicked, this, &MainWindow::onEditDepartment);
    connect(m_deleteDepartmentBtn, &QPushButton::clicked, this, &MainWindow::onDeleteDepartment);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_departmentTableView);
    
    m_tabWidget->addTab(widget, "科室管理");
}

void MainWindow::setupMedicalRecordTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addMedicalRecordBtn = new QPushButton("添加", this);
    m_editMedicalRecordBtn = new QPushButton("编辑", this);
    m_deleteMedicalRecordBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addMedicalRecordBtn);
    buttonLayout->addWidget(m_editMedicalRecordBtn);
    buttonLayout->addWidget(m_deleteMedicalRecordBtn);
    buttonLayout->addStretch();
    
    m_medicalRecordTableView = new QTableView(this);
    m_medicalRecordModel = new MedicalRecordModel(this);
    m_medicalRecordTableView->setModel(m_medicalRecordModel);
    m_medicalRecordTableView->horizontalHeader()->setStretchLastSection(true);
    m_medicalRecordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addMedicalRecordBtn, &QPushButton::clicked, this, &MainWindow::onAddMedicalRecord);
    connect(m_editMedicalRecordBtn, &QPushButton::clicked, this, &MainWindow::onEditMedicalRecord);
    connect(m_deleteMedicalRecordBtn, &QPushButton::clicked, this, &MainWindow::onDeleteMedicalRecord);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_medicalRecordTableView);
    
    m_tabWidget->addTab(widget, "就诊记录");
}

void MainWindow::setupPrescriptionTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addPrescriptionBtn = new QPushButton("添加", this);
    m_editPrescriptionBtn = new QPushButton("编辑", this);
    m_deletePrescriptionBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addPrescriptionBtn);
    buttonLayout->addWidget(m_editPrescriptionBtn);
    buttonLayout->addWidget(m_deletePrescriptionBtn);
    buttonLayout->addStretch();
    
    m_prescriptionTableView = new QTableView(this);
    m_prescriptionModel = new PrescriptionModel(this);
    m_prescriptionTableView->setModel(m_prescriptionModel);
    m_prescriptionTableView->horizontalHeader()->setStretchLastSection(true);
    m_prescriptionTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addPrescriptionBtn, &QPushButton::clicked, this, &MainWindow::onAddPrescription);
    connect(m_editPrescriptionBtn, &QPushButton::clicked, this, &MainWindow::onEditPrescription);
    connect(m_deletePrescriptionBtn, &QPushButton::clicked, this, &MainWindow::onDeletePrescription);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_prescriptionTableView);
    
    m_tabWidget->addTab(widget, "处方管理");
}

void MainWindow::setupMedicineTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addMedicineBtn = new QPushButton("添加", this);
    m_editMedicineBtn = new QPushButton("编辑", this);
    m_deleteMedicineBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addMedicineBtn);
    buttonLayout->addWidget(m_editMedicineBtn);
    buttonLayout->addWidget(m_deleteMedicineBtn);
    buttonLayout->addStretch();
    
    m_medicineTableView = new QTableView(this);
    m_medicineModel = new MedicineModel(this);
    m_medicineTableView->setModel(m_medicineModel);
    m_medicineTableView->horizontalHeader()->setStretchLastSection(true);
    m_medicineTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addMedicineBtn, &QPushButton::clicked, this, &MainWindow::onAddMedicine);
    connect(m_editMedicineBtn, &QPushButton::clicked, this, &MainWindow::onEditMedicine);
    connect(m_deleteMedicineBtn, &QPushButton::clicked, this, &MainWindow::onDeleteMedicine);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_medicineTableView);
    
    m_tabWidget->addTab(widget, "药品管理");
}

void MainWindow::setupInventoryTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addInventoryBtn = new QPushButton("添加", this);
    m_editInventoryBtn = new QPushButton("编辑", this);
    m_deleteInventoryBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addInventoryBtn);
    buttonLayout->addWidget(m_editInventoryBtn);
    buttonLayout->addWidget(m_deleteInventoryBtn);
    buttonLayout->addStretch();
    
    m_inventoryTableView = new QTableView(this);
    m_inventoryModel = new InventoryModel(this);
    m_inventoryTableView->setModel(m_inventoryModel);
    m_inventoryTableView->horizontalHeader()->setStretchLastSection(true);
    m_inventoryTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addInventoryBtn, &QPushButton::clicked, this, &MainWindow::onAddInventory);
    connect(m_editInventoryBtn, &QPushButton::clicked, this, &MainWindow::onEditInventory);
    connect(m_deleteInventoryBtn, &QPushButton::clicked, this, &MainWindow::onDeleteInventory);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_inventoryTableView);
    
    m_tabWidget->addTab(widget, "库存管理");
}

void MainWindow::setupAppointmentTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addAppointmentBtn = new QPushButton("添加", this);
    m_editAppointmentBtn = new QPushButton("编辑", this);
    m_deleteAppointmentBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addAppointmentBtn);
    buttonLayout->addWidget(m_editAppointmentBtn);
    buttonLayout->addWidget(m_deleteAppointmentBtn);
    buttonLayout->addStretch();
    
    m_appointmentTableView = new QTableView(this);
    m_appointmentModel = new AppointmentModel(this);
    m_appointmentTableView->setModel(m_appointmentModel);
    m_appointmentTableView->horizontalHeader()->setStretchLastSection(true);
    m_appointmentTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addAppointmentBtn, &QPushButton::clicked, this, &MainWindow::onAddAppointment);
    connect(m_editAppointmentBtn, &QPushButton::clicked, this, &MainWindow::onEditAppointment);
    connect(m_deleteAppointmentBtn, &QPushButton::clicked, this, &MainWindow::onDeleteAppointment);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_appointmentTableView);
    
    m_tabWidget->addTab(widget, "预约管理");
}

void MainWindow::setupScheduleTab()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_addScheduleBtn = new QPushButton("添加", this);
    m_editScheduleBtn = new QPushButton("编辑", this);
    m_deleteScheduleBtn = new QPushButton("删除", this);
    buttonLayout->addWidget(m_addScheduleBtn);
    buttonLayout->addWidget(m_editScheduleBtn);
    buttonLayout->addWidget(m_deleteScheduleBtn);
    buttonLayout->addStretch();
    
    m_scheduleTableView = new QTableView(this);
    m_scheduleModel = new ScheduleModel(this);
    m_scheduleTableView->setModel(m_scheduleModel);
    m_scheduleTableView->horizontalHeader()->setStretchLastSection(true);
    m_scheduleTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    connect(m_addScheduleBtn, &QPushButton::clicked, this, &MainWindow::onAddSchedule);
    connect(m_editScheduleBtn, &QPushButton::clicked, this, &MainWindow::onEditSchedule);
    connect(m_deleteScheduleBtn, &QPushButton::clicked, this, &MainWindow::onDeleteSchedule);
    
    layout->addLayout(buttonLayout);
    layout->addWidget(m_scheduleTableView);
    
    m_tabWidget->addTab(widget, "排班管理");
}

// 病人管理槽函数
void MainWindow::onAddPatient()
{
    PatientDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_patientModel->refresh();
    }
}

void MainWindow::onEditPatient()
{
    QModelIndex index = m_patientTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个病人");
        return;
    }
    
    int patientId = m_patientModel->data(m_patientModel->index(index.row(), 0)).toInt();
    PatientDialog dialog(patientId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_patientModel->refresh();
    }
}

void MainWindow::onDeletePatient()
{
    QModelIndex index = m_patientTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个病人");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的病人吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        int patientId = m_patientModel->data(m_patientModel->index(index.row(), 0)).toInt();
        if (m_patientModel->removeRow(index.row())) {
            m_patientModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 医生管理槽函数
void MainWindow::onAddDoctor()
{
    DoctorDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_doctorModel->refresh();
    }
}

void MainWindow::onEditDoctor()
{
    QModelIndex index = m_doctorTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个医生");
        return;
    }
    
    int doctorId = m_doctorModel->data(m_doctorModel->index(index.row(), 0)).toInt();
    DoctorDialog dialog(doctorId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_doctorModel->refresh();
    }
}

void MainWindow::onDeleteDoctor()
{
    QModelIndex index = m_doctorTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个医生");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的医生吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_doctorModel->removeRow(index.row())) {
            m_doctorModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 科室管理槽函数
void MainWindow::onAddDepartment()
{
    DepartmentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_departmentModel->refresh();
    }
}

void MainWindow::onEditDepartment()
{
    QModelIndex index = m_departmentTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个科室");
        return;
    }
    
    int deptId = m_departmentModel->data(m_departmentModel->index(index.row(), 0)).toInt();
    DepartmentDialog dialog(deptId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_departmentModel->refresh();
    }
}

void MainWindow::onDeleteDepartment()
{
    QModelIndex index = m_departmentTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个科室");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的科室吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_departmentModel->removeRow(index.row())) {
            m_departmentModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 就诊记录槽函数
void MainWindow::onAddMedicalRecord()
{
    MedicalRecordDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_medicalRecordModel->refresh();
    }
}

void MainWindow::onEditMedicalRecord()
{
    QModelIndex index = m_medicalRecordTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条就诊记录");
        return;
    }
    
    int recordId = m_medicalRecordModel->data(m_medicalRecordModel->index(index.row(), 0)).toInt();
    MedicalRecordDialog dialog(recordId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_medicalRecordModel->refresh();
    }
}

void MainWindow::onDeleteMedicalRecord()
{
    QModelIndex index = m_medicalRecordTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条就诊记录");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的就诊记录吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_medicalRecordModel->removeRow(index.row())) {
            m_medicalRecordModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 处方槽函数
void MainWindow::onAddPrescription()
{
    PrescriptionDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_prescriptionModel->refresh();
    }
}

void MainWindow::onEditPrescription()
{
    QModelIndex index = m_prescriptionTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条处方");
        return;
    }
    
    int prescriptionId = m_prescriptionModel->data(m_prescriptionModel->index(index.row(), 0)).toInt();
    PrescriptionDialog dialog(prescriptionId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_prescriptionModel->refresh();
    }
}

void MainWindow::onDeletePrescription()
{
    QModelIndex index = m_prescriptionTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条处方");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的处方吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_prescriptionModel->removeRow(index.row())) {
            m_prescriptionModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 药品槽函数
void MainWindow::onAddMedicine()
{
    MedicineDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_medicineModel->refresh();
    }
}

void MainWindow::onEditMedicine()
{
    QModelIndex index = m_medicineTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个药品");
        return;
    }
    
    int medicineId = m_medicineModel->data(m_medicineModel->index(index.row(), 0)).toInt();
    MedicineDialog dialog(medicineId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_medicineModel->refresh();
    }
}

void MainWindow::onDeleteMedicine()
{
    QModelIndex index = m_medicineTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个药品");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的药品吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_medicineModel->removeRow(index.row())) {
            m_medicineModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 库存槽函数
void MainWindow::onAddInventory()
{
    InventoryDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_inventoryModel->refresh();
    }
}

void MainWindow::onEditInventory()
{
    QModelIndex index = m_inventoryTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条库存记录");
        return;
    }
    
    int inventoryId = m_inventoryModel->data(m_inventoryModel->index(index.row(), 0)).toInt();
    InventoryDialog dialog(inventoryId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_inventoryModel->refresh();
    }
}

void MainWindow::onDeleteInventory()
{
    QModelIndex index = m_inventoryTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条库存记录");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的库存记录吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_inventoryModel->removeRow(index.row())) {
            m_inventoryModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 预约槽函数
void MainWindow::onAddAppointment()
{
    AppointmentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_appointmentModel->refresh();
    }
}

void MainWindow::onEditAppointment()
{
    QModelIndex index = m_appointmentTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个预约");
        return;
    }
    
    int appointmentId = m_appointmentModel->data(m_appointmentModel->index(index.row(), 0)).toInt();
    AppointmentDialog dialog(appointmentId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_appointmentModel->refresh();
    }
}

void MainWindow::onDeleteAppointment()
{
    QModelIndex index = m_appointmentTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一个预约");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的预约吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_appointmentModel->removeRow(index.row())) {
            m_appointmentModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

// 排班槽函数
void MainWindow::onAddSchedule()
{
    ScheduleDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_scheduleModel->refresh();
    }
}

void MainWindow::onEditSchedule()
{
    QModelIndex index = m_scheduleTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条排班记录");
        return;
    }
    
    int scheduleId = m_scheduleModel->data(m_scheduleModel->index(index.row(), 0)).toInt();
    ScheduleDialog dialog(scheduleId, this);
    if (dialog.exec() == QDialog::Accepted) {
        m_scheduleModel->refresh();
    }
}

void MainWindow::onDeleteSchedule()
{
    QModelIndex index = m_scheduleTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择一条排班记录");
        return;
    }
    
    int ret = QMessageBox::question(this, "确认", "确定要删除选中的排班记录吗？",
                                     QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        if (m_scheduleModel->removeRow(index.row())) {
            m_scheduleModel->refresh();
            statusBar()->showMessage("删除成功", 2000);
        }
    }
}

void MainWindow::onGenerateReport()
{
    ReportGenerator *generator = new ReportGenerator(this);
    connect(generator, &ReportGenerator::reportGenerated, this, [this](const QString &filePath) {
        QMessageBox::information(this, "成功", QString("报表已生成：%1").arg(filePath));
    });
    connect(generator, &ReportGenerator::reportError, this, [this](const QString &error) {
        QMessageBox::critical(this, "错误", QString("生成报表失败：%1").arg(error));
    });
    
    QString fileName = QFileDialog::getSaveFileName(this, "保存报表", "", "CSV Files (*.csv);;All Files (*)");
    if (!fileName.isEmpty()) {
        generator->generateReport(fileName);
    }
}

void MainWindow::onViewStatistics()
{
    StatisticsThread *thread = new StatisticsThread(this);
    connect(thread, &StatisticsThread::statisticsReady, this, [this](const QMap<QString, QVariant> &stats) {
        QString msg = QString("统计信息：\n"
                             "病人总数：%1\n"
                             "医生总数：%2\n"
                             "科室总数：%3\n"
                             "就诊记录数：%4\n"
                             "处方总数：%5\n"
                             "药品总数：%6")
                     .arg(stats["patients"].toInt())
                     .arg(stats["doctors"].toInt())
                     .arg(stats["departments"].toInt())
                     .arg(stats["medical_records"].toInt())
                     .arg(stats["prescriptions"].toInt())
                     .arg(stats["medicines"].toInt());
        QMessageBox::information(this, "统计信息", msg);
    });
    thread->start();
}

void MainWindow::onSyncData()
{
    NetworkManager::instance().syncData();
    QMessageBox::information(this, "同步", "数据同步完成");
}

void MainWindow::onBackupData()
{
    QString fileName = QFileDialog::getSaveFileName(this, "备份数据库", "", "SQLite Files (*.db);;All Files (*)");
    if (!fileName.isEmpty()) {
        NetworkManager::instance().backupDatabase(fileName);
        QMessageBox::information(this, "备份", "数据库备份完成");
    }
}

