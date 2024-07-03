#include "mainwindow.hpp"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) /*конструктор*/ {
  ui->setupUi(this);
  ui->lineEdit_setXSize->setText(QString::number(cols));
  ui->lineEdit_setYSize->setText(QString::number(rows));
  matrix = new int*[rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols]{0};
  }
  set_diap();
  isSort = true;
  ui->lbl_xsize->setText("Размер по х == ");
  ui->lbl_ysize->setText("Размер по y == ");
  ui->lineEdit_maxIters->setText(QString::number(max_iters));
  connect(timer, SIGNAL(timeout()), this, SLOT(on_pbt_create_clicked()));

  setWindowTitle(fileName);
  file.setFileName(filePath);
  init_msgBox_save();
}

MainWindow::~MainWindow() /*деструктор*/ {
  for (int i = 0; i < rows; ++i) {
	delete[] matrix[i];
  }
  delete[] matrix;
  delete ui;
}

//--------------------------------------------------
// мои функции

// табличные
void MainWindow::initialize() /*иницаиализация*/ {
  isUpdating = true;
  ui->table_main->setRowCount(rows);
  ui->table_main->setColumnCount(cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      ui->table_main->setItem(i, j, new QTableWidgetItem(QString::number(matrix[i][j])));
    }
  }
  isInits = true;
  isUpdating = false;
}

void MainWindow::fill_matrix() /*заполнение матрицы псевдослучайными значениями*/ {
  isSort = false;
  if (diap_max == diap_min) {
    for (int i = 0; i < rows; ++i) {  // цикл заполнения матрицы
      for (int j = 0; j < cols; ++j) {
        matrix[i][j] = diap_min;
      }
    }
    return;
  }
  unsigned int diff = diap_max - diap_min;
  for (int i = 0; i < rows; ++i) {  // цикл заполнения матрицы
    for (int j = 0; j < cols; ++j) {
      matrix[i][j] = diap_min + (QRandomGenerator::global()->generate() % diff);
    }
  }
}

void MainWindow::update_matrix() /*обновление матрицы*/ {
  isUpdating = true;
  if (!isInits) initialize();
  for (int i = 0; i < rows; ++i) {  // цикл вывода матрицы на экран
    for (int j = 0; j < cols; ++j) {
      ui->table_main->item(i, j)->setText(QString::number(matrix[i][j]));
    }
  }
  savingStatus(false);
  set_maxminmid();
  isUpdating = false;
}

int MainWindow::max() /*поиск максимума*/ {
  int max = matrix[0][0];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] > max) max = matrix[i][j];
    }
  }
  return max;
}

int MainWindow::min() /*поиск минимума*/ {
  int min = matrix[0][0];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] < min) min = matrix[i][j];
    }
  }
  return min;
}

double MainWindow::mid() /*поиск среднего*/ {
  double mid = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      mid += matrix[i][j];
    }
  }
  mid /= (rows * cols);
  return mid;
}

void MainWindow::set_maxminmid() /*функция поиска всех предельных значений*/ {
  ui->lbl_FindMax->setText("Максимум == " + QString::number(max()));
  ui->lbl_FindMin->setText("Минимум == " + QString::number(min()));
  ui->lbl_FindMid->setText("Среднее == " + QString::number(mid()));
}

void MainWindow::set_diap() /*установка диапазона допустимых значений*/ {
  bool ok1;
  bool ok2;
  int min = ui->lineEdit_DiapMin->text().toInt(&ok1);
  int max = ui->lineEdit_DiapMax->text().toInt(&ok2);
  if ((!ok1 || !ok2) || (max < min)) {
    ui->lineEdit_DiapMin->setText(QString::number(diap_min));
    ui->lineEdit_DiapMax->setText(QString::number(diap_max));
  } else {
    diap_min = min;
    diap_max = max;
  }
}

void MainWindow::matrix2dto1d() /*перевод матрицы из двумерной в одномерную*/ {
  for (int i = 1; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix[0][i * cols + j] = matrix[i][j];
    }
  }
}

void MainWindow::matrix1dto2d() /*перевод матрицы из одномерной в двумерную*/ {
  for (int i = 1; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix[i][j] = matrix[0][i * cols + j];
    }
  }
}

int MainWindow::binarySearch(int key) /*бинарный поиск*/ {
  int left = 0;
  int right = cols - 1;
  int dir = 0;
  if (matrix[0][left] == matrix[0][right])
    return -1;
  else if (matrix[0][left] > matrix[0][right])
    dir = 0;
  else
    dir = 1;
  if (dir == 1) {
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[0][mid] == key)
        return mid;
      else if (matrix[0][mid] < key)
        left = mid + 1;
      else
        right = mid - 1;
    }
  } else {
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[0][mid] == key)
        return mid;
      else if (matrix[0][mid] > key)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
}

void MainWindow::deleteMatrix(int** _matrix, int _sizeY) {
  for (int i = 0; i < _sizeY; ++i) {
	delete[] _matrix[i];
  }
  delete[] _matrix;
}

//--------------------------------------------------
// функции сохнанения

bool MainWindow::prepairToSaveInTXT() /*  подготовка строки к записи в файл*/ {
  if (rows < 1 || cols < 1) {
    return false;
  }
  saveString = QString::number(rows) + "/";
  saveString += QString::number(cols) + "/";
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
	  saveString += QString::number(matrix[i][j]) + "/";
    }
  }
  qDebug() << saveString;
  saveString += QString::fromUtf8(QCryptographicHash::hash((saveString + SALT).toUtf8(),
														   QCryptographicHash::Md5).toHex());  // MD5 cash method
  qDebug() << saveString;
  return true;
}

bool MainWindow::prepairToSaveInBIN() {
  if (rows < 1 || cols < 1) {
    return false;
  }
  saveBin.clear();
  saveBin.append((char*)&rows, sizeof(rows));
  saveBin.append((char*)&cols, sizeof(cols));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
	  saveBin.append((char*)&matrix[i][j], sizeof(int));
    }
  }

  saveBin = (QCryptographicHash::hash(saveBin, QCryptographicHash::Md5)) + saveBin;
  return true;
}

Errors MainWindow::decodFromTXT() /*декодирование строки в данные*/ {
  bool isOk = false;
  QStringList saveList = saveString.split(QLatin1Char('/'));
  saveString.chop(32);  // 32 потому что столько знаков занимает хэш
  qDebug() << saveString;
  if (QCryptographicHash::hash((saveString + SALT).toUtf8(), QCryptographicHash::Md5).toHex() != saveList.last()) return WRONGCONTROLHASH;

  if (saveList.isEmpty()) return EMPTYFILE;
  if (saveList.size() < 4) return WRONGFORMAT;
  int sizey = saveList.at(0).toInt(&isOk);
  if (!isOk || sizey < 1) return WRONGFORMAT;

  int sizex = saveList.at(1).toInt(&isOk);
  if (!isOk || sizex < 1) return WRONGFORMAT;

  if (sizex * sizey > 1000000) return WRONGFORMAT;  // чтобы нельзя было открыть ОЧЕНЬ большой массив

  int** newmatrix = new int*[sizey];
  for (int i = 0; i < sizey; ++i) {
	newmatrix[i] = new int[sizex]{0};
  }

  for (int i = 0; i < sizey; ++i) {
    for (int j = 0; j < sizex; ++j) {
	  newmatrix[i][j] = saveList.at(i * sizex + j + 2).toInt(&isOk);  // +2 потому что первые два элемента заняты под размерность
      if (!isOk) {
		deleteMatrix(newmatrix, sizey);
        return WRONGFORMAT;
      }
    }
  }

  deleteMatrix(matrix, rows);

  cols = sizex;
  rows = sizey;
  matrix = newmatrix;
  isSaved = true;
  isSort = false;
  initialize();
  return NOERRORS;
}

Errors MainWindow::decodFromBIN() {
  if (saveBin.size() < 16) return WRONGFORMAT;

  if (saveBin.left(16) != QCryptographicHash::hash(saveBin.right(saveBin.size() - 16), QCryptographicHash::Md5)) return WRONGCONTROLHASH;

  int sizex = 0;
  int sizey = 0;
  memcpy((void*)&sizex, saveBin.data() + 16, sizeof(int));
  memcpy((void*)&sizey, saveBin.data() + 16 + sizeof(int), sizeof(int));

  //  saveString.chop (32); // 32 потому что столько знаков занимает хэш
  //  qDebug() << saveString;
  //  if (QCryptographicHash::hash ((saveString+SALT).toUtf8 (),QCryptographicHash::Md5).toHex ()
  //      != saveList.last ()) return WRONGCONTROLHASH;

  //  if (saveList.isEmpty ()) return EMPTYFILE;
  //  if (saveList.size () < 4) return WRONGFORMAT;
  //  int sizey = saveList.at(0).toInt(&isOk);
  //  if (!isOk || sizey < 1) return WRONGFORMAT;

  //  int sizex = saveList.at (1).toInt(&isOk);
  //  if (!isOk || sizex < 1) return WRONGFORMAT;

  //  if (sizex*sizey > 1000000) return WRONGFORMAT; // чтобы нельзя было открыть ОЧЕНЬ большой массив

  int** newmatrix = new int*[sizey];
  for (int i = 0; i < sizey; ++i) {
	newmatrix[i] = new int[sizex]{0};
  }

  for (int i = 0; i < sizey; ++i) {
    for (int j = 0; j < sizex; ++j) {
	  memcpy((void*)&newmatrix[i][j], saveBin.data() + 16 + sizeof(int) * 2 + sizeof(int) * (i * sizex + j), sizeof(int));
	  // newmatrix[i][j] = saveList.at (i*sizex + j + 2).toInt(&isOk); // +2 потому что первые два элемента заняты под размерность

	  // newmatrix[i][j] = saveList.at (i*sizex + j + 2).toInt(&isOk); // +2 потому что первые два элемента заняты под размерность
    }
  }

  deleteMatrix(matrix, rows);

  cols = sizex;
  rows = sizey;
  matrix = newmatrix;
  isSaved = true;
  isSort = false;
  initialize();
  return NOERRORS;
}

bool MainWindow::save() /*функция сохранения*/ {
  /*
   * Возвращает false при некорректном выборе метода или ошибке открытия/закрытия и пр.
   *            true при корректном и вообще когда все классно
   */
  if (!file.exists()) {
	if (!setNewPath()) {
      return false;
    };
  };
  switch (saveFormat) {
    case TXT:
	  saveTXT();
      break;
    case BIN:
	  saveBIN();
      break;
    default:
	  QMessageBox::information(this, "Ой", "Ошибка формата", QMessageBox::Ok);
      return false;
      break;
  }
}

bool MainWindow::saveTXT() {
  prepairToSaveInTXT();
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
	if (file.write(saveString.toLocal8Bit())) {
	  file.close();
      QFileInfo fileInfo(filePath);
	  fileName = fileInfo.baseName();
	  savingStatus(true);
      return true;
    } else {
	  file.close();
	  QMessageBox::information(this, "Ой", "Файл не удалость записать", QMessageBox::Ok);
      return false;
    }
  } else {
	QMessageBox::information(this, "Ой", "Файл не удалость открыть", QMessageBox::Ok);
    return false;
  }
}

bool MainWindow::saveBIN() {
  prepairToSaveInBIN();
  if (file.open(QIODevice::WriteOnly)) {
	if (file.write(saveBin)) {
	  file.close();
      QFileInfo fileInfo(filePath);
	  fileName = fileInfo.baseName();
	  savingStatus(true);
      return true;
    } else {
	  file.close();
	  QMessageBox::information(this, "Ой", "Файл не удалость записать", QMessageBox::Ok);
      return false;
    }
  } else {
	QMessageBox::information(this, "Ой", "Файл не удалость открыть", QMessageBox::Ok);
    return false;
  }
}

bool MainWindow::setNewPath() /*установка нового пути к файлу*/ {
  /*
   * Возвращает false при некорректном выборе метода или ошибке открытия/закрытия и пр.
   *            true при корректном и вообще когда все классно
   */
  QString newFilePath = QFileDialog::getSaveFileName(this, "Сохранить файл", ".", "BIN (*.bin);;Text (*.txt)");
  if (newFilePath.isEmpty()) {
	QMessageBox::information(this, "Упс", "Файл не выбран", QMessageBox::Ok);
	return false;
  } else {
	filePath = newFilePath;
	file.setFileName(filePath);
	QFileInfo fileInfo(filePath);
	if (fileInfo.suffix() == "txt") {
	  saveFormat = TXT;
	} else {
	  saveFormat = BIN;
	}
	qDebug() << saveFormat << " <- saveFormat - setNewPath()";
	return true;
  }
}

bool MainWindow::open() /*функция открытия*/ {
  // 0. Выбрать файл

  QString newFilePath = QFileDialog::getOpenFileName(this, "Сохранить файл", ".", "BIN (*.bin);;Text (*.txt)");
  if (newFilePath.isEmpty()) {
	QMessageBox::information(this, "Упс", "Файл не выбран", QMessageBox::Ok);
	return false;
  }

  filePath = newFilePath;
  file.setFileName(filePath);
  QFileInfo fileInfo(filePath);
  fileName = fileInfo.baseName();

  // 1. Открыть файл
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
	QMessageBox::information(this, "Ой", "Файл не удалост открыть", QMessageBox::Ok);
	return false;
  };

  // 2. Прочитать
  QByteArray buffer = file.readAll();  // читаем содержимое файла

  // 3. Закрыть файл
  file.close();

  if (fileInfo.suffix() == "txt") {
	saveFormat = TXT;
  } else {
	saveFormat = BIN;
  }

  Errors error = NOERRORS;

  switch (saveFormat) {
    case TXT:
	  saveString = QString::fromLocal8Bit(buffer);
	  error = decodFromTXT();
      break;
    case BIN:
      saveBin = buffer;
	  error = decodFromBIN();
      break;
    default:
	  QMessageBox::information(this, "Ой", "Ошибка формата", QMessageBox::Ok);
      return false;
      break;
  }

  switch (error) {
    case NOERRORS:
	  QMessageBox::information(this, "Все хорошо", "Файл загружен", QMessageBox::Ok);
	  savingStatus(true);
      break;
    case EMPTYFILE:
	  QMessageBox::information(this, "Ой", "Файл пустой", QMessageBox::Ok);
      break;
    case WRONGFORMAT:
	  QMessageBox::information(this, "Ой", "Файл неверного формата", QMessageBox::Ok);
      break;
    case WRONGCONTROLHASH:
	  QMessageBox::information(this, "Ой", "Файл не прошел хэш", QMessageBox::Ok);
      break;

    default:
      break;
  }

  return true;
}

void MainWindow::savingStatus(bool status) /*функция изменения статуса сохранения*/ {
  isSaved = status;

  if (status) {
	// isSaved = true;
	setWindowTitle(fileName);

  } else {
	// isSaved = false;
	setWindowTitle("*" + fileName);
  }
}

void MainWindow::init_msgBox_save() {  // инициализационная функция для самописного messagebox
  msgBox_save.setWindowTitle("Моя таблица");
  msgBox_save.setText("Хотите сохранить изменения в файле '" + fileName + "' ?");
  msgBox_save.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
  msgBox_save.setIcon(QMessageBox::Question);
}

bool MainWindow::msgBox_save_call() {  // функция вызова окна подтверждения для сохранения
  /*
   *Возвращает: true - при выполнении сохранения (или намеренный отказ от него)
   *            false - при невыполнении сохранения
   */
  switch (msgBox_save.exec()) {
    case QMessageBox::Save:
	  return save();
    case QMessageBox::Discard:
      return true;
    case QMessageBox::Cancel:
    default:
      return false;
  }
}

//--------------------------------------------------
// Функции сортировки

void MainWindow::bubble(char big_to) /*пузырек*/ {
  bool is_changed;
  switch (big_to) {
    case 'u':
      for (int c = 0; c < cols; ++c) {
        do {
          is_changed = 0;
          for (int i = 0; i < rows - 1; ++i) {
            if (matrix[i][c] < matrix[i + 1][c]) {
              std::swap(matrix[i][c], matrix[i + 1][c]);
              ++qsorts;
              is_changed = 1;
            }
          }
        } while (is_changed);
      }
      break;
    case 'd':
      for (int c = 0; c < cols; ++c) {
        do {
          is_changed = 0;
          for (int i = 0; i < rows - 1; ++i) {
            if (matrix[i][c] > matrix[i + 1][c]) {
              std::swap(matrix[i][c], matrix[i + 1][c]);
              ++qsorts;
              is_changed = 1;
            }
          }
        } while (is_changed);
      }
      break;
    case 'l':
      for (int r = 0; r < rows; ++r) {
        do {
          is_changed = 0;
          for (int i = 0; i < cols - 1; ++i) {
            if (matrix[r][i] < matrix[r][i + 1]) {
              std::swap(matrix[r][i], matrix[r][i + 1]);
              ++qsorts;
              is_changed = 1;
            }
          }
        } while (is_changed);
      }
      break;
    case 'r':
      for (int r = 0; r < rows; ++r) {
        do {
          is_changed = 0;
          for (int i = 0; i < cols - 1; ++i) {
            if (matrix[r][i] > matrix[r][i + 1]) {
              std::swap(matrix[r][i], matrix[r][i + 1]);
              ++qsorts;
              is_changed = 1;
            }
          }
        } while (is_changed);
      }
      break;
  }
}

void MainWindow::gnome(char big_to) /*гном*/ {
  int i;
  int j;

  switch (big_to) {
    case 'u':
      for (int c = 0; c < cols; ++c) {
        i = 1;
        j = 2;
        while (i < rows) {
          if (matrix[i - 1][c] > matrix[i][c]) {
            i = j;
            ++j;
          } else {
            std::swap(matrix[i - 1][c], matrix[i][c]);
            ++qsorts;
            --i;
            if (i <= 0) {
              i = j;
              ++j;
            }
          }
        }
      }
      break;
    case 'd':
      for (int c = 0; c < cols; ++c) {
        i = 1;
        j = 2;
        while (i < rows) {
          if (matrix[i - 1][c] < matrix[i][c]) {
            i = j;
            ++j;
          } else {
            std::swap(matrix[i - 1][c], matrix[i][c]);
            ++qsorts;
            --i;
            if (i <= 0) {
              i = j;
              ++j;
            }
          }
        }
      }
      break;
    case 'l':
      for (int r = 0; r < rows; ++r) {
        i = 1;
        j = 2;
        while (i < cols) {
          if (matrix[r][i - 1] > matrix[r][i]) {
            i = j;
            ++j;
            ;
          } else {
            std::swap(matrix[r][i - 1], matrix[r][i]);
            ++qsorts;
            --i;
            if (i == 0) {
              i = j;
              ++j;
            }
          }
        }
      }
      break;
    case 'r':
      for (int r = 0; r < rows; ++r) {
        i = 1;
        j = 2;
        while (i < cols) {
          if (matrix[r][i - 1] < matrix[r][i]) {
            i = j;
            ++j;
          } else {
            std::swap(matrix[r][i - 1], matrix[r][i]);
            ++qsorts;
            --i;
            if (i == 0) {
              i = j;
              ++j;
            }
          }
        }
      }
      break;
  }
}

void MainWindow::quick_Hoara(char big_to) /*быстрая сортировка Хоара (старт)*/ {
  switch (big_to) {
    case 'u':
      for (int i = 0; i < cols; ++i) {
        quick_Hoara(i, 0, rows - 1, big_to);
      }
      break;
    case 'd':
      for (int i = 0; i < cols; ++i) {
        quick_Hoara(i, 0, rows - 1, big_to);
      }
      break;
    case 'l':
      for (int i = 0; i < rows; ++i) {
        quick_Hoara(i, 0, cols - 1, big_to);
      }
      break;
    case 'r':
      for (int i = 0; i < rows; ++i) {
        quick_Hoara(i, 0, cols - 1, big_to);
      }
      break;
  }
}

void MainWindow::quick_Hoara(int i, int start, int end, char big_to) /*БСХ основная*/ {
  int rightStart;
  switch (big_to) {
    case 'u':
      if (start >= end) return;
      rightStart = prep_Hoara(i, start, end, big_to);
      quick_Hoara(i, start, rightStart - 1, big_to);
      quick_Hoara(i, rightStart, end, big_to);
      break;
    case 'd':
      if (start >= end) return;
      rightStart = prep_Hoara(i, start, end, big_to);
      quick_Hoara(i, start, rightStart - 1, big_to);
      quick_Hoara(i, rightStart, end, big_to);
      break;
    case 'l':
      if (start >= end) return;
      rightStart = prep_Hoara(i, start, end, big_to);
      quick_Hoara(i, start, rightStart - 1, big_to);
      quick_Hoara(i, rightStart, end, big_to);
      break;
    case 'r':
      if (start >= end) return;
      rightStart = prep_Hoara(i, start, end, big_to);
      quick_Hoara(i, start, rightStart - 1, big_to);
      quick_Hoara(i, rightStart, end, big_to);
      break;
  }
}

int MainWindow::prep_Hoara(int i, int left, int right, char big_to) /*БСХ дополнительная*/ {
  int pivot;
  switch (big_to) {
    case 'u':
      pivot = matrix[(left + right) / 2][i];
      while (left <= right) {
        while (matrix[left][i] > pivot) left++;
        while (matrix[right][i] < pivot) right--;
        if (left <= right) {
          std::swap(matrix[left][i], matrix[right][i]);
          ++qsorts;
          ++left;
          --right;
        }
      }
      return left;
      break;
    case 'd':
      pivot = matrix[(left + right) / 2][i];
      while (left <= right) {
        while (matrix[left][i] < pivot) left++;
        while (matrix[right][i] > pivot) right--;
        if (left <= right) {
          std::swap(matrix[left][i], matrix[right][i]);
          ++qsorts;
          ++left;
          --right;
        }
      }
      return left;
      break;
    case 'l':
      pivot = matrix[i][(left + right) / 2];
      while (left <= right) {
        while (matrix[i][left] > pivot) left++;
        while (matrix[i][right] < pivot) right--;
        if (left <= right) {
          std::swap(matrix[i][left], matrix[i][right]);
          ++qsorts;
          ++left;
          --right;
        }
      }
      return left;
      break;
    case 'r':
      pivot = matrix[i][(left + right) / 2];
      while (left <= right) {
        while (matrix[i][left] < pivot) left++;
        while (matrix[i][right] > pivot) right--;
        if (left <= right) {
          std::swap(matrix[i][left], matrix[i][right]);
          ++qsorts;
          ++left;
          --right;
        }
      }
      return left;
      break;
  }
}

void MainWindow::comb(char big_to) /*расческа*/ {
  double factor = 1.2473309;
  int step;
  switch (big_to) {
    case 'u':
      for (int i = 0; i < cols; ++i) {
        step = rows - 1;
        while (step > 0) {
          for (int j = 0; j < rows - step; ++j) {
            if (matrix[j][i] < matrix[step + j][i]) {
              std::swap(matrix[j][i], matrix[step + j][i]);
              ++qsorts;
            }
          }
          step /= factor;
        }
      }
      break;
    case 'd':
      for (int i = 0; i < cols; ++i) {
        step = rows - 1;
        while (step > 0) {
          for (int j = 0; j < rows - step; ++j) {
            if (matrix[j][i] > matrix[step + j][i]) {
              std::swap(matrix[j][i], matrix[step + j][i]);
              ++qsorts;
            }
          }
          step /= factor;
        }
      }
      break;
    case 'l':
      for (int i = 0; i < rows; ++i) {
        step = cols - 1;
        while (step > 0) {
          for (int j = 0; j < cols - step; ++j) {
            if (matrix[i][j] < matrix[i][step + j]) {
              std::swap(matrix[i][j], matrix[i][step + j]);
              ++qsorts;
            }
          }
          step /= factor;
        }
      }
      break;
    case 'r':
      for (int i = 0; i < rows; ++i) {
        step = cols - 1;
        while (step > 0) {
          for (int j = 0; j < cols - step; ++j) {
            if (matrix[i][j] > matrix[i][step + j]) {
              std::swap(matrix[i][j], matrix[i][step + j]);
              ++qsorts;
            }
          }
          step /= factor;
        }
      }
      break;
  }
}

void MainWindow::bogosort(char big_to) /*обезьянья ака богосорт*/ {
  int bogo;

  switch (big_to) {
    case 'u':
      while (!sort_is_done('u') && max_iters >= qsorts) {
        for (int i = 0; i < cols; ++i) {
          for (int j = 0; j < rows; ++j) {
            bogo = QRandomGenerator::global()->generate() % rows;
            std::swap(matrix[j][i], matrix[bogo][i]);
            ++qsorts;
          }
        }
      }

      break;
    case 'd':
      while (!sort_is_done('d') && max_iters >= qsorts) {
        for (int i = 0; i < cols; ++i) {
          for (int j = 0; j < rows; ++j) {
            bogo = QRandomGenerator::global()->generate() % rows;
            std::swap(matrix[j][i], matrix[bogo][i]);
            ++qsorts;
          }
        }
      }

      break;
    case 'l':
      while (!sort_is_done('l') && max_iters > qsorts) {
        for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
            bogo = QRandomGenerator::global()->generate() % cols;
            std::swap(matrix[i][j], matrix[i][bogo]);
            ++qsorts;
          }
        }
      }

      break;
    case 'r':
      while (!sort_is_done('r') && max_iters > qsorts) {
        for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
            bogo = QRandomGenerator::global()->generate() % cols;
            std::swap(matrix[i][j], matrix[i][bogo]);
            ++qsorts;
          }
        }
      }

      break;
  }
}

bool MainWindow::sort_is_done(char big_to) /*проверка на отсортированность*/ {
  switch (big_to) {
    case 'u':
      for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows - 1; ++j) {
          if (matrix[j][i] < matrix[j + 1][i]) return 0;
        }
      }
      return 1;
    case 'd':
      for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows - 1; ++j) {
          if (matrix[j][i] > matrix[j + 1][i]) return 0;
        }
      }
      return 1;
    case 'l':
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
          if (matrix[i][j] < matrix[i][j + 1]) return 0;
        }
      }
      return 1;
    case 'r':
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
          if (matrix[i][j] > matrix[i][j + 1]) return 0;
        }
      }
      return 1;
  }

  return false;
}

void MainWindow::delete_copies() /*удаление дубликатов*/ {
  quniqs = 1;
  int* ptrMain = &matrix[0][0];
  int* ptrSecond = ptrMain;
  int size = cols;
  for (int i = 0; i < size; ++i) {
    if (*ptrMain == *ptrSecond)
      ++ptrSecond;
    else {
      ++ptrMain;
      *ptrMain = *ptrSecond;
      ++ptrSecond;
      ++quniqs;
    }
  }
  // isSort = false;
}

void MainWindow::resetFinding() /*сброс поиска*/ {
  isUpdating = true;
  if (!isInits) initialize();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      ui->table_main->item(i, j)->setText(QString::number(matrix[i][j]));
      ui->table_main->item(i, j)->setBackgroundColor(Qt::white);
    }
  }
  isUpdating = false;
  QPalette myq_palette;
  myq_palette.setColor(QPalette::Base, Qt::white);
  ui->lineEdit_finding->setPalette(myq_palette);
  ui->lbl_finding->setText("Элементов найдено: ");
}

//--------------------------------------------------
// Функция вызова команды сортировки

void MainWindow::on_pbt_sort_clicked() {
  time->start();
  bool ok;
  resetFinding();
  //----
  qsorts = 0;

  if (ui->rbtn_bubble1->isChecked())
	bubble(dir1);
  else if (ui->rbtn_gnome1->isChecked())
	gnome(dir1);
  else if (ui->rbtn_quick1->isChecked())
	quick_Hoara(dir1);
  else if (ui->rbtn_comb1->isChecked())
	comb(dir1);
  else if (ui->rbtn_bogo1->isChecked()) {
    int a = ui->lineEdit_maxIters->text().toInt(&ok);
    if (ok && a >= 0) {
	  if (a > 10000000) {
        ui->lineEdit_maxIters->setText("Слишком много хочешь!");
        return;
      }
      max_iters = a;
    }
    ui->lineEdit_maxIters->setText(QString::number(max_iters));
    bogosort(dir1);
  }

  ui->lbl_qsorts1->setText("<html><head/><body><p>Количество сортировок 1:<br/>" + QString::number(qsorts) + "</p></body></html>");

  //------
  qsorts = 0;

  if (ui->rbtn_bubble2->isChecked())
	bubble(dir2);
  else if (ui->rbtn_gnome2->isChecked())
	gnome(dir2);
  else if (ui->rbtn_quick2->isChecked())
	quick_Hoara(dir2);
  else if (ui->rbtn_comb2->isChecked())
	comb(dir2);
  else if (ui->rbtn_bogo2->isChecked()) {
    int a = ui->lineEdit_maxIters->text().toInt(&ok);
    if (ok && a >= 0) {
	  if (a > 10000000) {
        ui->lineEdit_maxIters->setText("Слишком много хочешь!");
        return;
      }
      max_iters = a;
    }
    ui->lineEdit_maxIters->setText(QString::number(max_iters));
    bogosort(dir2);
  }

  ui->lbl_qsorts2->setText("<html><head/><body><p>Количество сортировок 2:<br/>" + QString::number(qsorts) + "</p></body></html>");

  if (ui->rbtn_1d->isChecked() && sort_is_done(dir1)) isSort = true;

  //------
  update_matrix();
  ui->lbl_statusSort->setText("Времени затрачено (мс): " + QString::number(time->elapsed()));
  savingStatus(false);
}

//--------------------------------------------------
// Функции работы с QTableWidjet

void MainWindow::on_table_main_cellChanged(int row, int column) {
  if (isUpdating) return;
  bool ok;
  int current = ui->table_main->item(row, column)->text().toInt(&ok);
  if (ok) {
	savingStatus(false);
    matrix[row][column] = current;
    set_maxminmid();
    if (cols == 1) {
      isSort = true;
      return;
    }
    if (ui->rbtn_1d->isChecked()) {
      if (dir1 == 'r') {
        if (column == 0) {
          if (matrix[row][column] > matrix[row][column + 1]) {
            isSort = false;
            return;
          }
        } else if (column == cols - 1) {
          if (matrix[row][column - 1] > matrix[row][column]) {
            isSort = false;
            return;
          }
        } else {
		  if (matrix[row][column - 1] > matrix[row][column] || matrix[row][column] > matrix[row][column + 1]) {
            isSort = false;
            return;
          }
        }
        isSort = true;
        return;
      } else if (dir1 == 'l') {
        if (column == 0) {
          if (matrix[row][column] < matrix[row][column + 1]) {
            isSort = false;
            return;
          }
        } else if (column == cols - 1) {
          if (matrix[row][column - 1] < matrix[row][column]) {
            isSort = false;
            return;
          }
        } else {
		  if (matrix[row][column - 1] < matrix[row][column] || matrix[row][column] < matrix[row][column + 1]) {
            isSort = false;
            return;
          }
        }
        isSort = true;
        return;
      }
    }

  } else {
	ui->table_main->item(row, column)->setText(QString::number(matrix[row][column]));
  }
}

//--------------------------------------------------
// Функции обработки нажатий выбора направлений

void MainWindow::on_pbt_dir1_clicked() {
  dir1 = ' ';
  ui->pbt_dir1->setText("");
}

void MainWindow::on_pbt_dir2_clicked() {
  dir2 = ' ';
  ui->pbt_dir2->setText("");
}

void MainWindow::on_pbt_dir1u_clicked() {
  dir1 = 'u';
  ui->pbt_dir1->setText("↑");
}

void MainWindow::on_pbt_dir1d_clicked() {
  dir1 = 'd';
  ui->pbt_dir1->setText("↓");
}

void MainWindow::on_pbt_dir1l_clicked() {
  dir1 = 'l';
  ui->pbt_dir1->setText("←");
}

void MainWindow::on_pbt_dir1r_clicked() {
  dir1 = 'r';
  ui->pbt_dir1->setText("→");
}

void MainWindow::on_pbt_dir2u_clicked() {
  dir2 = 'u';
  ui->pbt_dir2->setText("↑");
}

void MainWindow::on_pbt_dir2d_clicked() {
  dir2 = 'd';
  ui->pbt_dir2->setText("↓");
}

void MainWindow::on_pbt_dir2l_clicked() {
  dir2 = 'l';
  ui->pbt_dir2->setText("←");
}

void MainWindow::on_pbt_dir2r_clicked() {
  dir2 = 'r';
  ui->pbt_dir2->setText("→");
}

//--------------------------------------------------
// Обработки нажатия на кнопки

void MainWindow::on_pbt_FillTable_clicked() {
  if (!isInits) return;
  time->start();
  set_diap();
  fill_matrix();
  update_matrix();
  resetFinding();
  savingStatus(false);
  ui->lbl_statusFill->setText("Времени затрачено (мс): " + QString::number(time->elapsed()));
}

void MainWindow::on_pbt_clear_clicked() {
  // ui->table_main->clear();
  for (int i = 0; i < rows; ++i) {  // цикл заполнения матрицы нулями
    for (int j = 0; j < cols; ++j) {
      matrix[i][j] = 0;
    }
  }
  update_matrix();
  resetFinding();
  savingStatus(false);
}

void MainWindow::on_pbt_deleteCopy_clicked() {
  time->start();

  if (ui->rbtn_2d->isChecked()) {
    ui->lbl_countUnic->setText("Выберите одномерный массив!!!");
    return;
  }
  if (ui->chBox_autosort->isChecked()) {
    ui->pbt_dir1l->click();
    ui->rbtn_comb1->click();
    ui->pbt_sort->click();
    delete_copies();
  } else {
    if (isSort) {
      delete_copies();
    } else {
      ui->lbl_countUnic->setText("Отсортируйте одномерный массив!!!");
      return;
    }
  }

  ui->lbl_countUnic->setText("Уникальных значений: " + QString::number(quniqs));
  ui->lineEdit_setXSize->setText(QString::number(quniqs));

  int** newMatrix = new int*[1];
  newMatrix[0] = new int[quniqs];
  memcpy(newMatrix[0], matrix[0], quniqs * 4);
  for (int i = 0; i < rows; ++i) {
	delete[] matrix[i];
  }
  delete[] matrix;
  rows = 1;
  cols = quniqs;
  matrix = newMatrix;
  initialize();

  ui->lbl_statusDelete->setText("Времени затрачено (мс): " + QString::number(time->elapsed()));
  savingStatus(false);
}

void MainWindow::on_rbtn_1d_clicked() {
  on_lineEdit_setYSize_textEdited("1");
  ui->lineEdit_setYSize->setText("1");
  ui->lineEdit_setYSize->setEnabled(false);
  // ui->pbt_create->click ();
  // initialize ();
  // update_matrix();
  isSort = false;
  ui->lbl_sort2->setEnabled(false);
  ui->rbtn_bubble2->setEnabled(false);
  ui->rbtn_gnome2->setEnabled(false);
  ui->rbtn_quick2->setEnabled(false);
  ui->rbtn_comb2->setEnabled(false);
  ui->rbtn_bogo2->setEnabled(false);
  on_pbt_dir1_clicked();
  on_pbt_dir2_clicked();
  ui->pbt_dir1u->setEnabled(false);
  ui->pbt_dir1d->setEnabled(false);
  ui->pbt_dir2->setEnabled(false);
  ui->pbt_dir2u->setEnabled(false);
  ui->pbt_dir2r->setEnabled(false);
  ui->pbt_dir2l->setEnabled(false);
  ui->pbt_dir2d->setEnabled(false);
}

void MainWindow::on_rbtn_2d_clicked() {
  // ui->pbt_create->click ();
  isSort = false;
  ui->lineEdit_setYSize->setEnabled(true);
  ui->lbl_sort2->setEnabled(true);
  ui->rbtn_bubble2->setEnabled(true);
  ui->rbtn_gnome2->setEnabled(true);
  ui->rbtn_quick2->setEnabled(true);
  ui->rbtn_comb2->setEnabled(true);
  ui->rbtn_bogo2->setEnabled(true);
  ui->pbt_dir1u->setEnabled(true);
  ui->pbt_dir1d->setEnabled(true);
  ui->pbt_dir2->setEnabled(true);
  ui->pbt_dir2u->setEnabled(true);
  ui->pbt_dir2r->setEnabled(true);
  ui->pbt_dir2l->setEnabled(true);
  ui->pbt_dir2d->setEnabled(true);
}

void MainWindow::on_pbt_findingReset_clicked() {
  ui->lineEdit_finding->setText("");
  resetFinding();
}

void MainWindow::on_pbt_finding_clicked() {
  resetFinding();
  bool ok;
  int qelements = 0;
  QPalette myq_palette;
  int findValue = ui->lineEdit_finding->text().toInt(&ok);
  if (!ok) {
    myq_palette.setColor(QPalette::Base, Qt::red);
    ui->lineEdit_finding->setPalette(myq_palette);
  } else {
    if (isSort && ui->rbtn_1d->isChecked()) {
      int middle = binarySearch(findValue);
      for (int i = middle - 1; i >= 0; --i) {
        if (matrix[0][i] == findValue) {
          ui->table_main->item(0, i)->setBackgroundColor(Qt::green);
          ++qelements;
        } else
          break;
      }
      for (int i = middle; i < cols; ++i) {
        if (matrix[0][i] == findValue) {
          ui->table_main->item(0, i)->setBackgroundColor(Qt::green);
          ++qelements;
        } else
          break;
      }
    } else {
      if (ui->chBox_colorsDiff->isChecked()) {
		if (false) {  // дописать
          double step = 128.0 / (max() - min());
          for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
			  ui->table_main->item(i, j)->setBackgroundColor(
				  QColor::fromRgb(128 + (matrix[i][j] - findValue) * step, (findValue - matrix[i][j]) * step, 0));
            }
          }
        } else {
		  double stepup = 128.0 / (max() - findValue);
		  double stepdown = 128.0 / (findValue - min());
          for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
              if (matrix[i][j] > findValue) {
				ui->table_main->item(i, j)->setBackgroundColor(
					QColor::fromRgb(127 + (matrix[i][j] - findValue) * stepup, 128 - (matrix[i][j] - findValue) * stepup, 0));
              } else if (matrix[i][j] == findValue) {
                ++qelements;
				ui->table_main->item(i, j)->setBackgroundColor(QColor::fromRgb(100, 100, 100));
              } else if (matrix[i][j] < findValue) {
				ui->table_main->item(i, j)->setBackgroundColor(
					QColor::fromRgb(128 - (findValue - matrix[i][j]) * stepdown, 127 + (findValue - matrix[i][j]) * stepdown, 0));
              }
            }
          }
        }

      } else {
        for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == findValue) {
              ui->table_main->item(i, j)->setBackgroundColor(Qt::green);
              ++qelements;
            }
          }
        }
      }
    }
    if (qelements == 0) {
      myq_palette.setColor(QPalette::Base, Qt::blue);
      ui->lineEdit_finding->setPalette(myq_palette);
      ui->lbl_finding->setText("Элементов не найдено");

    } else {
      myq_palette.setColor(QPalette::Base, Qt::green);
      ui->lineEdit_finding->setPalette(myq_palette);
	  ui->lbl_finding->setText("Элементов найдено: " + QString::number(qelements));
    }
  }
}

void MainWindow::on_lineEdit_setXSize_textEdited(const QString& _string) {
  if (_string == "") {
    newCols = 1;
	timer->start(1000);
    return;
  }

  bool ok;
  newCols = _string.toInt(&ok);

  if (!ok || newCols * rows > 1000000) {
    ui->lineEdit_setXSize->setText(QString::number(cols));
    return;
  } else if (newCols < 1) {
    ui->lineEdit_setXSize->setText("1");
    newCols = 1;
  }
  timer->start(1000);
}

void MainWindow::on_lineEdit_setYSize_textEdited(const QString& _string) {
  if (_string == "") {
    newRows = 1;
	timer->start(1000);
    return;
  }
  bool ok;
  newRows = _string.toInt(&ok);
  if (!ok || newRows * cols > 1000000) {
    ui->lineEdit_setYSize->setText(QString::number(rows));
    return;
  } else if (newRows < 1) {
    ui->lineEdit_setYSize->setText("1");
    newRows = 1;
  }
  timer->start(1000);
}

void MainWindow::on_pbt_create_clicked() {
  timer->stop();
  time->start();
  if (newRows == rows && newCols == cols) return;
  isSort = false;
  savingStatus(false);

  deleteMatrix(matrix, rows);
  rows = newRows;
  cols = newCols;
  matrix = new int*[rows];
  for (int i = 0; i < rows; ++i) {
	matrix[i] = new int[cols]{0};
  }
  initialize();
  ui->lbl_statusCreate->setText("Времени затрачено (мс): " + QString::number(time->elapsed()));
}

//--------------------------------------------------
// Менюшки:

void MainWindow::on_menuFile_save_triggered() { save(); }

void MainWindow::on_menuFile_open_triggered() {
  if (isSaved)
	open();
  else {
	if (msgBox_save_call()) open();
  }
}

void MainWindow::on_menuFile_create_triggered() {
  if (isSaved) {
    filePath = "";
    fileName = "Example";

    newRows = 1;
    newCols = 1;
	on_pbt_create_clicked();
	savingStatus(true);
  } else {
	if (msgBox_save_call()) {
      filePath = "";
      fileName = "Example";

      newRows = 1;
      newCols = 1;
	  on_pbt_create_clicked();

	  savingStatus(true);
	} else
	  return;
  }
}

void MainWindow::on_menuFile_saveAs_triggered() {
  if (setNewPath()) {
	;
	save();
  }
  // if (setNewPath ()) qDebug() << 1;
}

void MainWindow::on_menuFile_exit_triggered() { close(); }

void MainWindow::closeEvent(QCloseEvent* e) /*событие закртия окна*/ {
  if (isSaved)
	e->accept();
  else {
	if (msgBox_save_call())
	  e->accept();
	else
	  e->ignore();
  }
}
