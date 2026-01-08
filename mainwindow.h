#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QStatusBar>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>

// Forward declarations
class PatientModel;
class DoctorModel;
class DepartmentModel;
class MedicalRecordModel;
class PrescriptionModel;
class MedicineModel;
class InventoryModel;
class AppointmentModel;
class ScheduleModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddPatient();
    void onEditPatient();
    void onDeletePatient();
    
    void onAddDoctor();
    void onEditDoctor();
    void onDeleteDoctor();
    
    void onAddDepartment();
    void onEditDepartment();
    void onDeleteDepartment();
    
    void onAddMedicalRecord();
    void onEditMedicalRecord();
    void onDeleteMedicalRecord();
    
    void onAddPrescription();
    void onEditPrescription();
    void onDeletePrescription();
    
    void onAddMedicine();
    void onEditMedicine();
    void onDeleteMedicine();
    
    void onAddInventory();
    void onEditInventory();
    void onDeleteInventory();
    
    void onAddAppointment();
    void onEditAppointment();
    void onDeleteAppointment();
    
    void onAddSchedule();
    void onEditSchedule();
    void onDeleteSchedule();
    
    void onGenerateReport();
    void onViewStatistics();
    void onSyncData();
    void onBackupData();

private:
    void setupUI();
    void setupMenuBar();
    void setupToolBar();
    void setupTabs();
    void setupPatientTab();
    void setupDoctorTab();
    void setupDepartmentTab();
    void setupMedicalRecordTab();
    void setupPrescriptionTab();
    void setupMedicineTab();
    void setupInventoryTab();
    void setupAppointmentTab();
    void setupScheduleTab();
    
    QTabWidget *m_tabWidget;
    
    // 病人管理
    QTableView *m_patientTableView;
    QPushButton *m_addPatientBtn, *m_editPatientBtn, *m_deletePatientBtn;
    PatientModel *m_patientModel;
    
    // 医生管理
    QTableView *m_doctorTableView;
    QPushButton *m_addDoctorBtn, *m_editDoctorBtn, *m_deleteDoctorBtn;
    DoctorModel *m_doctorModel;
    // 科室管理
    QTableView *m_departmentTableView;
    QPushButton *m_addDepartmentBtn, *m_editDepartmentBtn, *m_deleteDepartmentBtn;
    DepartmentModel *m_departmentModel;
    
    // 就诊记录
    QTableView *m_medicalRecordTableView;
    QPushButton *m_addMedicalRecordBtn, *m_editMedicalRecordBtn, *m_deleteMedicalRecordBtn;
    MedicalRecordModel *m_medicalRecordModel;
    
    // 处方
    QTableView *m_prescriptionTableView;
    QPushButton *m_addPrescriptionBtn, *m_editPrescriptionBtn, *m_deletePrescriptionBtn;
    PrescriptionModel *m_prescriptionModel;
    
    // 药品
    QTableView *m_medicineTableView;
    QPushButton *m_addMedicineBtn, *m_editMedicineBtn, *m_deleteMedicineBtn;
    MedicineModel *m_medicineModel;
    
    // 库存
    QTableView *m_inventoryTableView;
    QPushButton *m_addInventoryBtn, *m_editInventoryBtn, *m_deleteInventoryBtn;
    InventoryModel *m_inventoryModel;
    
    // 预约
    QTableView *m_appointmentTableView;
    QPushButton *m_addAppointmentBtn, *m_editAppointmentBtn, *m_deleteAppointmentBtn;
    AppointmentModel *m_appointmentModel;
    
    // 排班
    QTableView *m_scheduleTableView;
    QPushButton *m_addScheduleBtn, *m_editScheduleBtn, *m_deleteScheduleBtn;
    ScheduleModel *m_scheduleModel;
};

#endif // MAINWINDOW_H

