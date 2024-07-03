#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#define SALT "mmm...Delicious..."

#include <QByteArray>
#include <QCloseEvent>
#include <QCryptographicHash>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>
#include <QRandomGenerator>
#include <QStringList>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QTime>
#include <QTimer>

enum Errors { NOERRORS, EMPTYFILE, WRONGFORMAT, WRONGCONTROLHASH };

enum SaveFormat { NON, TXT, BIN };

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  void closeEvent(QCloseEvent *e) override;

 private:
  Ui::MainWindow *ui;
  int rows = 1;  // 20
  int cols = 1;  // 10
  int newRows = 1;
  int newCols = 1;
  int qElements = 0;

  int **matrix;
  int diap_min = 0;
  int diap_max = 100;
  char dir1 = ' ';
  char dir2 = ' ';
  int qsorts = 0;
  int quniqs = 0;
  int max_iters = 10000000;
  bool isUpdating = false;
  bool isSort = false;  // только для одномерного случая
  bool isInits = false;
  bool isMultistring = false;

  QTimer *timer = new QTimer();
  QTime *time = new QTime();

  // поля сохранения
  SaveFormat saveFormat = NON;
  QMessageBox msgBox_save;
  QString saveString = "";
  QByteArray saveBin;
  QString fileName = "Example";
  QString filePath = "";
  QFile file;
  bool isSaved = true;
  //

 private:
  void initialize();
  void fill_matrix();
  void update_matrix();
  int max();
  int min();
  double mid();
  void set_maxminmid();
  void set_diap();
  void matrix2dto1d();
  void matrix1dto2d();
  int binarySearch(int key);
  void deleteMatrix(int **_matrix, int _sizeY);
  // методы сохранения
  bool prepairToSaveInTXT();
  bool prepairToSaveInBIN();
  Errors decodFromTXT();
  Errors decodFromBIN();
  bool save();
  bool saveTXT();
  bool saveBIN();
  bool setNewPath();
  bool open();
  void savingStatus(bool status);
  void init_msgBox_save();
  bool msgBox_save_call();
  //

  void bubble(char big_to);
  void gnome(char big_to);
  void quick_Hoara(char big_to);
  void quick_Hoara(int start, int end, char big_to);
  void quick_Hoara(int i, int start, int end, char big_to);
  int prep_Hoara(int left, int right, char big_to);
  int prep_Hoara(int i, int left, int right, char big_to);
  void comb(char big_to);
  void bogosort(char big_to);
  bool sort_is_done(char big_to);
  void delete_copies();
  void delete_copies(int *currPtr, int i);
  void resetFinding();

 private slots:
  void on_pbt_FillTable_clicked();
  void on_table_main_cellChanged(int row, int column);
  void on_pbt_dir1_clicked();
  void on_pbt_dir1u_clicked();
  void on_pbt_dir1d_clicked();
  void on_pbt_dir1r_clicked();
  void on_pbt_dir1l_clicked();
  void on_pbt_dir2_clicked();
  void on_pbt_dir2u_clicked();
  void on_pbt_dir2d_clicked();
  void on_pbt_dir2l_clicked();
  void on_pbt_dir2r_clicked();
  void on_pbt_sort_clicked();
  void on_pbt_clear_clicked();
  void on_pbt_deleteCopy_clicked();
  void on_rbtn_1d_clicked();
  void on_rbtn_2d_clicked();
  void on_pbt_findingReset_clicked();
  void on_pbt_finding_clicked();
  void on_lineEdit_setYSize_textEdited(const QString &arg1);
  void on_lineEdit_setXSize_textEdited(const QString &arg1);
  void on_pbt_create_clicked();
  void on_menuFile_save_triggered();
  void on_menuFile_open_triggered();
  void on_menuFile_create_triggered();
  void on_menuFile_saveAs_triggered();
  void on_menuFile_exit_triggered();
};
#endif  // MAINWINDOW_HPP
