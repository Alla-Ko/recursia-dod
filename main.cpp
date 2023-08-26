#include <iostream>
#include <vector>
using namespace std;
int readNumber();
double readDouble();
void Zirky(int n);
int Suma_vid_do(int a, int b);
//а в степені b
template <class T> T stepin(T a, int b) {
  if (b < 1) {
    cout << "Невірний степінь!\n";
    return 0;
  }
  if (b == 1)
    return a;
  else {
    return a * stepin(a, b - 1);
  }
}

int main() {
  int aaaa;
  cout << "\x1b[32m"; //зелений
  cout << "Написати рекурсивну функцію знаходження ступеня числа\n\n";
  cout << "\x1b[37m"; //білий
  cout << "Введіть число і степінь, до якого його потрібно піднести\n";
  double a = readDouble();
  int b = readNumber();

  cout << a << " в степені " << b << " становить " << stepin(a, b) << endl
       << endl;

  cout << "\x1b[32m"; //зелений
  cout << "Написати рекурсивну функцію, яка виводить N зірок у ряд, число N "
          "задає користувач. Проілюструйте роботу функції прикладом\n\n";
  cout << "\x1b[37m"; //білий

  cout << "Скільки зірочок вивести?\n";
  int zir = readNumber();
  Zirky(zir);
  cout << endl;

  cout << "\x1b[32m"; //зелений
  cout << "Написати рекурсивну функцію, яка обчислює суму всіх чисел у "
          "діапазоні від a до b. Користувач вводить a і b.  Проілюструйте "
          "роботу функції прикладом\n\n";
  cout << "\x1b[37m"; //білий
  
  cout<<"Введіть два числа, між якими (включно) все буде просумоване\n";
  int s=readNumber();
  int d=readNumber();
  cout <<"Сума чисел від "<<s<<" до "<<d<<" становить "<<Suma_vid_do(s, d);
  cout << endl;

  
}

//ввід числа
int readNumber() {
  int a;
  while (true) {
    // cout << "Введіть число:";
    cin >> a;
    if (cin.fail()) // если предыдущее извлечение оказалось неудачным
    {
      cin.clear(); //  возвращаем cin в 'обычный' режим работы
      cin.ignore(
          32767,
          '\n'); // и удаляем значения предыдущего ввода из входного буфера
      cout << "Щось пішло не так, спробуйте ще раз\n";
    } else {
      cin.ignore(32767, '\n'); // удаляем лишние значения
      return a;
    }
  }
}
double readDouble() {
  double a;
  while (true) {
    cin >> a;
    if (cin.fail()) // если предыдущее извлечение оказалось неудачным
    {
      cin.clear(); //  возвращаем cin в 'обычный' режим работы
      cin.ignore(
          32767,
          '\n'); // и удаляем значения предыдущего ввода из входного буфера
      cout << "Щось пішло не так, спробуйте ще раз\n";
    } else {
      cin.ignore(32767, '\n'); // удаляем лишние значения
      return a;
    }
  }
}
//друк зірок
void Zirky(int n) {
  if (n < 0)
    cout << "Не знущайтеся над програмою\n";
  if (n < 1) {
    cout << "\n";
  } else {
    cout << "*";
    Zirky(n - 1);
  }
}
//Сума чисел між двома
int Suma_vid_do(int a, int b)
{
    if (a > b)swap(a, b);
    if (a == b)return a;
    if (b - a == 1)return a + b;
    return(a + b + Suma_vid_do(a + 1, b - 1));
}